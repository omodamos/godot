/* register_types.cpp */

#include "register_types.h"
#include "object_type_db.h"

#include "gdgraph.h"

void register_graph_types() {

        ObjectTypeDB::register_type<Graph>();
}

void unregister_graph_types() {
   //nothing to do here
}
