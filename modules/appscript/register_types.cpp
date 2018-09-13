/* register_types.cpp */

#include "register_types.h"
#include "core/class_db.h"

#include "appscript.h"

void register_appscript_types() {

        ClassDB::register_class<AppScript>();
}

void unregister_appscript_types() {
   //nothing to do here
}
