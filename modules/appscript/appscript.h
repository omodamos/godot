/* appscript.h */
#ifndef APPSCRIPT_H
#define APPSCRIPT_H

#include "scene/main/node.h"

class AppScript : public Node {
	GDCLASS(AppScript, Node);

protected:
	static void _bind_methods();

public:
	// AppScript();
	// void _(const String &p_text);
	// void _(const String &p_actor, const String &p_text);
	// void write(const Dictionary &p_params);
	// void pause();
	// void choice(const Dictionary &p_params);

	Variant call(const StringName &p_method, const Variant **p_args, int p_argcount, Variant::CallError &r_error);
	
};

#endif
