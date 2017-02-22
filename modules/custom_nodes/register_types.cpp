/* register_types.cpp */

#include "register_types.h"
#include "class_db.h"

#include "entity.h"
#include "orbit.h"

void register_custom_nodes_types() {

    ClassDB::register_class<Entity>();
    ClassDB::register_class<Orbit>();
}

void unregister_custom_nodes_types() {
   //nothing to do here
}
