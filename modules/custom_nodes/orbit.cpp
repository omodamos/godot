/* orbit.cpp */

#include "orbit.h"

void Orbit::set_properties(const Dictionary& p_dict) {
	if (p_dict.has("semi_major_axis")) {
		set_semi_major_axis(p_dict["semi_major_axis"]);
	}
	if (p_dict.has("eccentricity")) {
		set_eccentricity(p_dict["eccentricity"]);
	}
	if (p_dict.has("longitude_of_periapsis")) {
		set_longitude_of_periapsis(p_dict["longitude_of_periapsis"]);
	}
	if (p_dict.has("true_anomaly")) {
		set_true_anomaly(p_dict["true_anomaly"]);
	}
}

int Orbit::get_entity_id() {
	return entity_id;
}

void Orbit::set_entity_id(int p_id) {
	// somehow check for conflicts?
	entity_id = p_id;
}

void Orbit::_notification(int p_what) {

	switch(p_what) {

	}
}

Vector2 Orbit::get_cartesian_position() {
	return Vector2(0,0);
}

double Orbit::get_semi_major_axis() {
	return semi_major_axis;
}

double Orbit::get_eccentricity() {
	return eccentricity;
}

double Orbit::get_longitude_of_periapsis() {
	return longitude_of_periapsis;
}

double Orbit::get_true_anomaly() {
	return true_anomaly;
}

void Orbit::set_semi_major_axis(double p_sm_axis) {
	// TODO: set limits
	semi_major_axis = p_sm_axis;
}

void Orbit::set_eccentricity(double p_eccentricity) {
	eccentricity = p_eccentricity;
}

void Orbit::set_longitude_of_periapsis(double p_longitude) {
	longitude_of_periapsis = p_longitude;
}

void Orbit::set_true_anomaly(double p_anomaly) {
	true_anomaly = p_anomaly;
}

void Orbit::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_properties","dict"),&Orbit::set_properties);
	ClassDB::bind_method(D_METHOD("get_entity_id"),&Orbit::get_entity_id);
	ClassDB::bind_method(D_METHOD("set_entity_id","id"),&Orbit::set_entity_id);
	ClassDB::bind_method(D_METHOD("get_cartesian_position"),&Orbit::get_cartesian_position);
	ClassDB::bind_method(D_METHOD("get_semi_major_axis"),&Orbit::get_semi_major_axis);
	ClassDB::bind_method(D_METHOD("get_eccentricity"),&Orbit::get_eccentricity);
	ClassDB::bind_method(D_METHOD("get_longitude_of_periapsis"),&Orbit::get_longitude_of_periapsis);
	ClassDB::bind_method(D_METHOD("get_true_anomaly"),&Orbit::get_true_anomaly);
	ClassDB::bind_method(D_METHOD("set_semi_major_axis","semi_major_axis"),&Orbit::set_semi_major_axis);
	ClassDB::bind_method(D_METHOD("set_eccentricity","eccentricity"),&Orbit::set_eccentricity);
	ClassDB::bind_method(D_METHOD("set_longitude_of_periapsis","longitude_of_periapsis"),&Orbit::set_longitude_of_periapsis);
	ClassDB::bind_method(D_METHOD("set_true_anomaly","true_anomaly"),&Orbit::set_true_anomaly);

	ADD_PROPERTYNZ(PropertyInfo(Variant::INT,"entity_id"),"set_entity_id","get_entity_id");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"semi_major_axis"),"set_semi_major_axis","get_semi_major_axis");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"eccentricity"),"set_eccentricity","get_eccentricity");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"longitude_of_periapsis"),"set_longitude_of_periapsis","get_longitude_of_periapsis");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"true_anomaly"),"set_true_anomaly","get_true_anomaly");
}

Orbit::Orbit() {
}


