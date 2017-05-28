/* starfield.h */

#ifndef STARFIELD_H
#define STARFIELD_H

#include "scene/2d/node_2d.h"

class Starfield : public Node2D {

	GDCLASS( Starfield, Node2D );

	Array points;
	Array star_sizes;
	Ref<Texture> texture;
	double min_star_size;
	double max_star_size;
	Vector2 starfield_size;
	int star_count;

public:
	void generate_points();
	Array get_points();
	void set_texture(const Ref<Texture> &p_texture);
	Ref<Texture> get_texture() const;
	void set_min_star_size(double p_size);
	double get_min_star_size() const;
	void set_max_star_size(double p_size);
	double get_max_star_size() const;
	void set_starfield_size(Vector2 p_size);
	Vector2 get_starfield_size() const;
	void set_star_count(int p_count);
	int get_star_count() const;
	Starfield();

protected:
	void _notification(int p_what);
	static void _bind_methods();
};

#endif
