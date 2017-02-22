/* entity.h */

#ifndef ENTITY_H
#define ENTITY_H

#include "scene/2d/node_2d.h"

class Entity : public Node2D {

	GDCLASS( Entity, Node2D );

	int entity_id;
	Dictionary properties;

public:
	Dictionary get_properties();
	void set_properties(const Dictionary& p_dict);
	int get_entity_id();
	void set_entity_id(int p_id);
	Entity();

protected:
	void _notification(int p_what);
	static void _bind_methods();
};

#endif
