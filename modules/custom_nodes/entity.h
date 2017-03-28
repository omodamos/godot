/* entity.h */

#ifndef ENTITY_H
#define ENTITY_H

#include "scene/2d/node_2d.h"

class Entity : public Node2D {

	GDCLASS( Entity, Node2D );

	int entity_id;
	int primary_id;
	int entity_type_id;
	Dictionary properties;

	// Node* primary;
	// Dictionary satellites;
	
	double semi_major_axis;
	double eccentricity;
	double longitude_of_periapsis;
	double true_anomaly;

public:
	// ID
	Dictionary get_properties();
	void set_properties(const Dictionary& p_dict);
	int get_entity_id();
	void set_entity_id(int p_id);
	int get_entity_type_id();
	void set_entity_type_id(int p_id);
	int get_primary_id();
	void set_primary_id(int p_id);

	// References
	// void set_primary(Node* p_primary);
	// Node* get_primary();
	// void set_satellites(const Array& p_satellites);
	// Array get_satellites();
	// void add_satellite()
	// void move_satellite

	// Orbit
	double get_semi_major_axis();
	double get_eccentricity();
	double get_longitude_of_periapsis();
	double get_true_anomaly();
	void set_semi_major_axis(double p_km);
	void set_eccentricity(double p_val);
	void set_longitude_of_periapsis(double p_radians);
	void set_true_anomaly(double p_radians);

	// Orbit Equations
	Vector2 get_cartesian_pos();
	Vector2 get_cartesian_pos_at_angle(double p_radians);
	double get_distance_from_primary(double p_radians);	
	
	Entity();

protected:
	void _notification(int p_what);
	static void _bind_methods();
};

#endif
