/* orbit.cpp */

#include "orbit.h"

void Orbit::set_properties(const Dictionary& p_dict) {
	ERR_FAIL_COND(!p_dict.has("entity_id"));
	ERR_FAIL_COND(!p_dict.has("semi_major_axis"));
	ERR_FAIL_COND(!p_dict.has("eccentricity"));
	ERR_FAIL_COND(!p_dict.has("longitude_of_periapsis"));
	ERR_FAIL_COND(!p_dict.has("true_anomaly"));

	entity_id = p_dict["entity_id"];
	if (p_dict.has("parent_id")) {
		parent_id = p_dict["parent_id"];
	}

	set_semi_major_axis(p_dict["semi_major_axis"]);
	set_eccentricity(p_dict["eccentricity"]);
	set_longitude_of_periapsis_in_degrees(p_dict["longitude_of_periapsis"]);
	set_true_anomaly_in_degrees(p_dict["true_anomaly"]);
}

int Orbit::get_entity_id() {
	return entity_id;
}

void Orbit::set_entity_id(int p_id) {
	// somehow check for conflicts?
	entity_id = p_id;
}

int Orbit::get_parent_id() {
	return parent_id;
}

void Orbit::set_parent_id(int p_id) {
	parent_id = p_id;
}

void Orbit::_notification(int p_what) {

	switch(p_what) {
		case NOTIFICATION_DRAW: {
			// if (semi_major_axis <= 0 or eccentricity < 0)
			// 	return;
			// Vector<Vector2> points;
			// Vector<Vector2> uvs;
			// VS::get_singleton()->canvas_item_add_circle(get_canvas_item(), get_rect(), )
		}
	}
}

Vector2 Orbit::get_cartesian_pos() {
	double distance = get_distance_from_primary();
	return distance * Vector2(Math::cos(true_anomaly), Math::sin(true_anomaly));
}

double Orbit::get_distance_from_primary() {
	return semi_major_axis * (1 - eccentricity * eccentricity) / (1 + eccentricity * Math::cos(true_anomaly));
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

void Orbit::set_semi_major_axis(double p_au) {
	// TODO: set limits
	semi_major_axis = p_au;
}

void Orbit::set_eccentricity(double p_val) {
	eccentricity = p_val;
}

void Orbit::set_longitude_of_periapsis(double p_radians) {
	longitude_of_periapsis = p_radians;
}

void Orbit::set_longitude_of_periapsis_in_degrees(double p_degrees) {
	set_longitude_of_periapsis(Math::deg2rad(p_degrees));
}

void Orbit::set_true_anomaly(double p_radians) {
	true_anomaly = p_radians;
}

void Orbit::set_true_anomaly_in_degrees(double p_degrees) {
	set_true_anomaly(Math::deg2rad(p_degrees));
}

void Orbit::set_texture(const Ref<Texture>& p_texture){
	texture=p_texture;
	update();
}
Ref<Texture> Orbit::get_texture() const{
	return texture;
}

void Orbit::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_properties","dict"),&Orbit::set_properties);
	ClassDB::bind_method(D_METHOD("get_entity_id"),&Orbit::get_entity_id);
	ClassDB::bind_method(D_METHOD("set_entity_id","id"),&Orbit::set_entity_id);
	ClassDB::bind_method(D_METHOD("get_parent_id"),&Orbit::get_parent_id);
	ClassDB::bind_method(D_METHOD("set_parent_id","id"),&Orbit::set_parent_id);
	ClassDB::bind_method(D_METHOD("get_cartesian_pos"),&Orbit::get_cartesian_pos);
	ClassDB::bind_method(D_METHOD("get_distance_from_primary"),&Orbit::get_distance_from_primary);
	ClassDB::bind_method(D_METHOD("get_semi_major_axis"),&Orbit::get_semi_major_axis);
	ClassDB::bind_method(D_METHOD("get_eccentricity"),&Orbit::get_eccentricity);
	ClassDB::bind_method(D_METHOD("get_longitude_of_periapsis"),&Orbit::get_longitude_of_periapsis);
	ClassDB::bind_method(D_METHOD("get_true_anomaly"),&Orbit::get_true_anomaly);
	ClassDB::bind_method(D_METHOD("set_semi_major_axis","semi_major_axis"),&Orbit::set_semi_major_axis);
	ClassDB::bind_method(D_METHOD("set_eccentricity","eccentricity"),&Orbit::set_eccentricity);
	ClassDB::bind_method(D_METHOD("set_longitude_of_periapsis","longitude_of_periapsis"),&Orbit::set_longitude_of_periapsis);
	ClassDB::bind_method(D_METHOD("set_longitude_of_periapsis_in_degrees","longitude_of_periapsis"),&Orbit::set_longitude_of_periapsis_in_degrees);
	ClassDB::bind_method(D_METHOD("set_true_anomaly","true_anomaly"),&Orbit::set_true_anomaly);
	ClassDB::bind_method(D_METHOD("set_true_anomaly_in_degrees","true_anomaly"),&Orbit::set_true_anomaly_in_degrees);

	ADD_PROPERTYNZ(PropertyInfo(Variant::INT,"entity_id"),"set_entity_id","get_entity_id");
	ADD_PROPERTYNZ(PropertyInfo(Variant::INT,"parent_id"),"set_parent_id","get_parent_id");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"semi_major_axis"),"set_semi_major_axis","get_semi_major_axis");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"eccentricity"),"set_eccentricity","get_eccentricity");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"longitude_of_periapsis"),"set_longitude_of_periapsis","get_longitude_of_periapsis");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"true_anomaly"),"set_true_anomaly","get_true_anomaly");

	ADD_GROUP("Texture","");
	ADD_PROPERTY( PropertyInfo(Variant::OBJECT,"texture",PROPERTY_HINT_RESOURCE_TYPE,"Texture"),"set_texture","get_texture");
}

Orbit::Orbit() {
	entity_id = 0;
	parent_id = 0;
	semi_major_axis = 1;
	eccentricity = 0;
	longitude_of_periapsis = 0;
	true_anomaly = 0;
}


