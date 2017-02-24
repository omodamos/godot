/* entity.cpp */

#include "entity.h"

Dictionary Entity::get_properties() {
	return properties;
}

void Entity::set_properties(const Dictionary& p_dict) {
	ERR_FAIL_COND(!p_dict.has("entity_id"));
	entity_id = p_dict["entity_id"];
	if (p_dict.has("parent_id")) {
		parent_id = p_dict["parent_id"];
	}
	if (p_dict.has("name")) {
		set_name(p_dict["name"]);
	}
	properties = p_dict;
}

int Entity::get_entity_id() {
	return entity_id;
}

void Entity::set_entity_id(int p_id) {
	// somehow check for conflicts?
	entity_id = p_id;
	// _change_notify("entity_id");
}

int Entity::get_parent_id() {
	return parent_id;
}

void Entity::set_parent_id(int p_id) {
	parent_id = p_id;
}

void Entity::_notification(int p_what) {

	switch(p_what) {

	}
}

void Entity::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_properties"),&Entity::get_properties);
	ClassDB::bind_method(D_METHOD("set_properties","dict"),&Entity::set_properties);
	ClassDB::bind_method(D_METHOD("get_entity_id"),&Entity::get_entity_id);
	ClassDB::bind_method(D_METHOD("set_entity_id","id"),&Entity::set_entity_id);
	ClassDB::bind_method(D_METHOD("get_parent_id"),&Entity::get_parent_id);
	ClassDB::bind_method(D_METHOD("set_parent_id","id"),&Entity::set_parent_id);

	ADD_PROPERTYNZ(PropertyInfo(Variant::DICTIONARY,"properties"),"set_properties","get_properties");
	ADD_PROPERTYNZ(PropertyInfo(Variant::INT,"entity_id"),"set_entity_id","get_entity_id");
	ADD_PROPERTYNZ(PropertyInfo(Variant::INT,"parent_id"),"set_parent_id","get_parent_id");
}

Entity::Entity() {
	entity_id = 0;
	parent_id = 0;
	properties = Dictionary();
}


