/* entity.cpp */

#include "entity.h"

Dictionary Entity::get_properties() {
	return properties;
}

void Entity::set_properties(const Dictionary& p_dict) {
	ERR_FAIL_COND(!p_dict.has("entity_id"));
	ERR_FAIL_COND(!p_dict.has("entity_type_id"));
	entity_id = p_dict["entity_id"];
	set_entity_type_id(p_dict["entity_type_id"]);

	if (p_dict.has("primary_id")) {
		set_primary_id(p_dict["primary_id"]);
	}
	if (p_dict.has("name")) {
		set_name(p_dict["name"]);
	}
	if (p_dict.has("semi_major_axis")) {
		set_semi_major_axis(p_dict["semi_major_axis"]);
	}
	if (p_dict.has("eccentricity")) {
		set_eccentricity(p_dict["eccentricity"]);
	}
	if (p_dict.has("longitude_of_periapsis")) {
		set_longitude_of_periapsis(p_dict["longitude_of_periapsis"]);
	}
	// if (p_dict.has("true_anomaly")) {
	// 	set_true_anomaly(p_dict["true_anomaly"]);
	// }
	properties = p_dict;
}

int Entity::get_entity_id() {
	return entity_id;
}

void Entity::set_entity_id(int p_id) {
	// somehow check for conflicts?
	entity_id = p_id;
}

int Entity::get_entity_type_id() {
	return entity_type_id;
}

void Entity::set_entity_type_id(int p_id) {
	// somehow check for conflicts?
	entity_type_id = p_id;
}

int Entity::get_primary_id() {
	return primary_id;
}

void Entity::set_primary_id(int p_id) {
	primary_id = p_id;
}

void Entity::_notification(int p_what) {

	switch(p_what) {

	}
}

// void Entity::set_primary(Node* p_primary) {
// 	primary = p_primary;
// }

// Node* Entity::get_primary() {
// 	return primary;
// }

// void Entity::set_satellites(const Array& p_satellites) {
// 	satellites = p_satellites;
// }

// Array Entity::get_satellites() {
// 	return satellites;
// }

double Entity::get_semi_major_axis() {
	return semi_major_axis;
}

double Entity::get_eccentricity() {
	return eccentricity;
}

double Entity::get_longitude_of_periapsis() {
	return longitude_of_periapsis;
}

double Entity::get_true_anomaly() {
	return true_anomaly;
}

double Entity::get_period() {
	return period;
}

double Entity::get_epoch() {
	return epoch;
}

void Entity::set_semi_major_axis(double p_km) {
	// TODO: set limits
	semi_major_axis = p_km;
}

void Entity::set_eccentricity(double p_val) {
	eccentricity = p_val;
}

void Entity::set_longitude_of_periapsis(double p_radians) {
	longitude_of_periapsis = p_radians;
}

void Entity::set_true_anomaly(double p_radians) {
	true_anomaly = p_radians;
}

void Entity::set_period(double p_seconds) {
	period = p_seconds;
}

void Entity::set_epoch(double p_seconds) {
	epoch = p_seconds;
}

Vector2 Entity::get_cartesian_pos() {
	double distance = get_distance_from_primary(true_anomaly);
	return distance * Vector2(Math::cos(true_anomaly), Math::sin(true_anomaly));
}

Vector2 Entity::get_cartesian_pos_at_angle(double p_radians) {
	double distance = get_distance_from_primary(p_radians);
	return distance * Vector2(Math::cos(p_radians), Math::sin(p_radians));
}

double Entity::get_distance_from_primary(double p_radians) {
	return semi_major_axis * (1 - eccentricity * eccentricity) / (1 + eccentricity * Math::cos(p_radians));
}

double Entity::get_angle_at_time(double p_seconds) {
	ERR_FAIL_COND_V(period <= 0, 0);

	int maxIterations = 15;
	double accuracy = 0.001;
	double M = 2.0 * Math_PI * p_seconds / period;
	double E = M;
	double e = eccentricity;
	double f;
	for (int i = 0; i < maxIterations; i++)
	{
		f = E - e * Math::sin(E) - M;
		if (f < accuracy)
		{
			break;
		}
		E = E - f / (1 - e * Math::cos(E));
	}
	// return 2.0 * Math::atan2(Math::sqrt(1 + eccentricity) * Math::sin(E / 2.0),
	// 	Math::sqrt(1 - eccentricity) * Math::cos(E / 2.0));
	double v = Math::atan2(Math::cos(E) - e, Math::sqrt(1 - e*e) * Math::sin(E));
	if (v < 0)
		v += 2.0 * Math_PI;
	return v;

}

double Entity::get_time_at_angle(double p_radians) {
	ERR_FAIL_COND_V(period <= 0, 0);


	double eccentric_anomaly = Math::atan2(eccentricity + Math::cos(p_radians), Math::sqrt(1 - eccentricity * eccentricity) * Math::sin(p_radians));
	return (period / (2.0 * Math_PI)) * (eccentric_anomaly - eccentricity * Math::sin(eccentric_anomaly));
}

void Entity::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_properties"),&Entity::get_properties);
	ClassDB::bind_method(D_METHOD("set_properties","dict"),&Entity::set_properties);
	ClassDB::bind_method(D_METHOD("get_entity_id"),&Entity::get_entity_id);
	ClassDB::bind_method(D_METHOD("set_entity_id","id"),&Entity::set_entity_id);
	ClassDB::bind_method(D_METHOD("get_entity_type_id"),&Entity::get_entity_type_id);
	ClassDB::bind_method(D_METHOD("set_entity_type_id","id"),&Entity::set_entity_type_id);
	ClassDB::bind_method(D_METHOD("get_primary_id"),&Entity::get_primary_id);
	ClassDB::bind_method(D_METHOD("set_primary_id","id"),&Entity::set_primary_id);
	// ClassDB::bind_method(D_METHOD("get_primary"),&Entity::get_primary);
	// ClassDB::bind_method(D_METHOD("set_primary","primary"),&Entity::set_primary);
	// ClassDB::bind_method(D_METHOD("get_satellites"),&Entity::get_satellites);
	// ClassDB::bind_method(D_METHOD("set_satellites","satellites"),&Entity::set_satellites);

	ADD_PROPERTYNZ(PropertyInfo(Variant::DICTIONARY,"properties"),"set_properties","get_properties");
	ADD_PROPERTYNZ(PropertyInfo(Variant::INT,"entity_id"),"set_entity_id","get_entity_id");
	ADD_PROPERTYNZ(PropertyInfo(Variant::INT,"entity_type_id"),"set_entity_type_id","get_entity_type_id");
	ADD_PROPERTYNZ(PropertyInfo(Variant::INT,"primary_id"),"set_primary_id","get_primary_id");

	ClassDB::bind_method(D_METHOD("get_semi_major_axis"),&Entity::get_semi_major_axis);
	ClassDB::bind_method(D_METHOD("get_eccentricity"),&Entity::get_eccentricity);
	ClassDB::bind_method(D_METHOD("get_longitude_of_periapsis"),&Entity::get_longitude_of_periapsis);
	ClassDB::bind_method(D_METHOD("get_true_anomaly"),&Entity::get_true_anomaly);
	ClassDB::bind_method(D_METHOD("get_period"),&Entity::get_period);
	ClassDB::bind_method(D_METHOD("get_epoch"),&Entity::get_epoch);

	ClassDB::bind_method(D_METHOD("set_semi_major_axis","semi_major_axis"),&Entity::set_semi_major_axis);
	ClassDB::bind_method(D_METHOD("set_eccentricity","eccentricity"),&Entity::set_eccentricity);
	ClassDB::bind_method(D_METHOD("set_longitude_of_periapsis","longitude_of_periapsis"),&Entity::set_longitude_of_periapsis);
	ClassDB::bind_method(D_METHOD("set_true_anomaly","true_anomaly"),&Entity::set_true_anomaly);
	ClassDB::bind_method(D_METHOD("set_period","period"),&Entity::set_period);
	ClassDB::bind_method(D_METHOD("set_epoch","epoch"),&Entity::set_epoch);

	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"semi_major_axis"),"set_semi_major_axis","get_semi_major_axis");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"eccentricity"),"set_eccentricity","get_eccentricity");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"longitude_of_periapsis"),"set_longitude_of_periapsis","get_longitude_of_periapsis");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"true_anomaly"),"set_true_anomaly","get_true_anomaly");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"period"),"set_period","get_period");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"epoch"),"set_epoch","get_epoch");

	ClassDB::bind_method(D_METHOD("get_cartesian_pos"),&Entity::get_cartesian_pos);
	ClassDB::bind_method(D_METHOD("get_cartesian_pos_at_angle","radians"),&Entity::get_cartesian_pos_at_angle);
	ClassDB::bind_method(D_METHOD("get_distance_from_primary"),&Entity::get_distance_from_primary);
	ClassDB::bind_method(D_METHOD("get_angle_at_time", "seconds"),&Entity::get_angle_at_time);
	ClassDB::bind_method(D_METHOD("get_time_at_angle", "p_radians"),&Entity::get_time_at_angle);

}

Entity::Entity() {
	entity_id = 0;
	entity_type_id = 0;
	primary_id = 0;
	semi_major_axis = 0;
	eccentricity = 0;
	longitude_of_periapsis = 0;
	true_anomaly = 0;
	period = 0;
	epoch = 0;
}


