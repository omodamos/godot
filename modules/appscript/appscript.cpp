/* appscript.cpp */

#include "appscript.h"
// #include "project_settings.h"
// #include "os/os.h"

// AppScript::AppScript() {
// }

// void AppScript::_(const String &p_text) {
// }

// void AppScript::_(const String &p_text, const String &p_text) {
// }

// void AppScript::write(const Dictionary &p_params) {
// }

// void AppScript::pause() {
// }

// void AppScript::choice(const Dictionary &p_params) {
// }

Variant AppScript::call(const StringName &p_method, const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	Array str_args;
	String str_method = p_method;
	for (int i = 0; i < p_argcount; i++) {
		str_args.push_back(Variant(*p_args[i]));
	}
	Variant ret = Object::call(p_method, p_args, p_argcount, r_error);
	emit_signal("call_method", get_name(), str_method, str_args);
	return ret;
}

void AppScript::_bind_methods() {
	ADD_SIGNAL(MethodInfo("call_method", PropertyInfo(Variant::STRING, "script"),
										 PropertyInfo(Variant::STRING, "method"),
										 PropertyInfo(Variant::ARRAY, "args") ) );
}

