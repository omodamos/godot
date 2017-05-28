/* starfield.cpp */

#include "starfield.h"

// _FORCE_INLINE_ static double _rand_from_seed(double from, double to, uint64_t *seed) {

// 	uint32_t r = Math::rand();
// 	return ((double)r / (double)Math::RANDOM_MAX) * (to - from) + from;
// }

void Starfield::generate_points() {
	points = Array();
	star_sizes = Array();
	// uint64_t array_seed = Math::rand() % 12345678;
	for (int i = 0; i < star_count; i++) {
		double x = (double)starfield_size.x * (2.0 * (double)Math::rand() / (double)4294967295 - 1.0);
		double y = (double)starfield_size.y * (2.0 * (double)Math::rand() / (double)4294967295 - 1.0);
		points.append(Vector2(x,y));

		double size = ((double)Math::rand() / (double)4294967295) * (max_star_size - min_star_size) + min_star_size;
		star_sizes.append(Vector2(size,size));
		// uint64_t rand_seed = array_seed * (i + 1);
		// points.append(Vector2(_rand_from_seed(0.0, (double)starfield_size.x, &rand_seed),
		// 	_rand_from_seed(0.0, (double)starfield_size.y, &rand_seed)));
		// points.append(Vector2(Math::random((double)0.0, (double)starfield_size.x), 
		// 	Math::random((double)0.0, (double)starfield_size.y)));
	}
	update();
}

Array Starfield::get_points() {
	return points;
}

void Starfield::set_texture(const Ref<Texture> &p_texture) {
	if (p_texture == texture)
		return;
	texture = p_texture;
	update();
}

Ref<Texture> Starfield::get_texture() const{
	return texture;
}

void Starfield::set_min_star_size(double p_size) {
	min_star_size = p_size;
	generate_points();
}

double Starfield::get_min_star_size() const {
	return min_star_size;
}

void Starfield::set_max_star_size(double p_size) {
	max_star_size = p_size;
	generate_points();
}

double Starfield::get_max_star_size() const {
	return max_star_size;
}

void Starfield::set_starfield_size(Vector2 p_size) {
	starfield_size = p_size;
	generate_points();
}

Vector2 Starfield::get_starfield_size() const {
	return starfield_size;
}

void Starfield::set_star_count(int p_count) {
	star_count = p_count;
	generate_points();
}
int Starfield::get_star_count() const {
	return star_count;
}

void Starfield::_notification(int p_what) {

	switch (p_what) {
		case NOTIFICATION_DRAW: {
			RID ci = get_canvas_item();
			RID texrid;
			Size2 texsize(1,1);
			if (texture.is_valid()) {
				texrid = texture->get_rid();
				texsize = texture->get_size();
			}

			for (int i = 0; i < points.size(); i++) {
				if (texrid.is_valid()) {
					Rect2 src_rect;
					src_rect.size = texsize;
					texture->draw_rect_region(ci, Rect2(points[i], star_sizes[i]), src_rect, get_modulate());
				} else {
					VisualServer::get_singleton()->canvas_item_add_rect(ci, Rect2(points[i], star_sizes[i]), get_modulate());
				}
			}
		}
	}
}

void Starfield::_bind_methods() {
	ClassDB::bind_method(D_METHOD("generate_points"),&Starfield::generate_points);
	ClassDB::bind_method(D_METHOD("get_points"),&Starfield::get_points);
	ClassDB::bind_method(D_METHOD("get_texture"),&Starfield::get_texture);
	ClassDB::bind_method(D_METHOD("set_texture","texture:Texture"),&Starfield::set_texture);
	ClassDB::bind_method(D_METHOD("get_min_star_size"),&Starfield::get_min_star_size);
	ClassDB::bind_method(D_METHOD("set_min_star_size","size"),&Starfield::set_min_star_size);
	ClassDB::bind_method(D_METHOD("get_max_star_size"),&Starfield::get_max_star_size);
	ClassDB::bind_method(D_METHOD("set_max_star_size","size"),&Starfield::set_max_star_size);
	ClassDB::bind_method(D_METHOD("get_starfield_size"),&Starfield::get_starfield_size);
	ClassDB::bind_method(D_METHOD("set_starfield_size","size"),&Starfield::set_starfield_size);
	ClassDB::bind_method(D_METHOD("get_star_count"),&Starfield::get_star_count);
	ClassDB::bind_method(D_METHOD("set_star_count","count"),&Starfield::set_star_count);
	ADD_PROPERTYNZ(PropertyInfo(Variant::OBJECT,"texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture"),"set_texture","get_texture");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"min_star_size"),"set_min_star_size","get_min_star_size");
	ADD_PROPERTYNZ(PropertyInfo(Variant::REAL,"max_star_size"),"set_max_star_size","get_max_star_size");
	ADD_PROPERTYNZ(PropertyInfo(Variant::VECTOR2,"starfield_size"),"set_starfield_size","get_starfield_size");
	ADD_PROPERTYNZ(PropertyInfo(Variant::INT,"star_count"),"set_star_count","get_star_count");
}

Starfield::Starfield() {
	min_star_size = 0.5;
	max_star_size = 1.0;
	starfield_size = Vector2(100, 100);
	star_count = 100;
}


