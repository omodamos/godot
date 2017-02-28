/* orbit.h */

#ifndef ORBIT_H
#define ORBIT_H

#include "scene/2d/node_2d.h"

class Orbit : public Node2D {

	GDCLASS( Orbit, Node2D );

	Ref<Texture> texture;

	int entity_id;
	int parent_id;
	double semi_major_axis;
	double eccentricity;
	double longitude_of_periapsis;
	double true_anomaly;

public:
	void set_properties(const Dictionary& p_dict);
	int get_entity_id();
	void set_entity_id(int p_id);
	int get_parent_id();
	void set_parent_id(int p_id);

	Vector2 get_cartesian_pos();
	double get_distance_from_primary();

	double get_semi_major_axis();
	double get_eccentricity();
	double get_longitude_of_periapsis();
	double get_true_anomaly();
	void set_semi_major_axis(double p_au);
	void set_eccentricity(double p_val);
	void set_longitude_of_periapsis(double p_radians);
	void set_longitude_of_periapsis_in_degrees(double p_degrees);
	void set_true_anomaly(double p_radians);
	void set_true_anomaly_in_degrees(double p_degrees);

	void set_texture(const Ref<Texture>& p_texture);
	Ref<Texture> get_texture() const;

	Orbit();

private:
	

protected:
	void _notification(int p_what);
	static void _bind_methods();
};

#endif