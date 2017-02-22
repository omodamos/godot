/* orbit.h */

#ifndef ORBIT_H
#define ORBIT_H

#include "scene/2d/node_2d.h"

class Orbit : public Node2D {

	GDCLASS( Orbit, Node2D );

	int entity_id;
	double semi_major_axis;
	double eccentricity;
	double longitude_of_periapsis;
	double true_anomaly;

public:
	void set_properties(const Dictionary& p_dict);
	int get_entity_id();
	void set_entity_id(int p_id);
	Vector2 get_cartesian_position();
	double get_semi_major_axis();
	double get_eccentricity();
	double get_longitude_of_periapsis();
	double get_true_anomaly();
	void set_semi_major_axis(double p_sm_axis);
	void set_eccentricity(double p_eccentricity);
	void set_longitude_of_periapsis(double p_longitude);
	void set_true_anomaly(double p_anomaly);
	Orbit();

protected:
	void _notification(int p_what);
	static void _bind_methods();
};

#endif