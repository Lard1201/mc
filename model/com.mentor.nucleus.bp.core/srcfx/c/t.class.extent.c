T_b("/*");
T_b("\n");
T_b(" ");
T_b("* Statically allocate space for the instance population for this class.");
T_b("\n");
T_b(" ");
T_b("* Allocate space for the class instance and its attribute values.");
T_b("\n");
T_b(" ");
T_b("* Depending upon the collection scheme, allocate containoids (collection");
T_b("\n");
T_b(" ");
T_b("* nodes) for gathering instances into free and active extents.");
T_b("\n");
T_b(" ");
T_b("*/");
T_b("\n");
if (objExtent->result == true) {
T_b(objExtent->include_file);
if ( 0!=strcmp("$r{objExtent->include_file}","")) {
T_b("#include \"");
T_b(objExtent->include_file);
T_b("\"	/* ");
T_b(max_size_value);
T_b(" is defined in this file */");
T_b("\n");
}
T_b("#define ");
T_b(te_class->GeneratedName);
T_b("_MAX_EXTENT_SIZE ");
T_b(max_size_value);
T_b("\n");
} else {
T_b("#define ");
T_b(te_class->GeneratedName);
T_b("_MAX_EXTENT_SIZE ");
T_b(te_class->MaxExtentSize);
T_b("\n");
}
T_b(te_set->scope);
T_b(te_extent->type);
T_b(" ");
T_b(classExtent->result);
T_b(";");
T_b("\n");
T_b("static ");
T_b(te_set->scope);
T_b(te_set->element_type);
T_b(" * ");
T_b(te_class->GeneratedName);
T_b("_container;");
T_b("\n");
T_b("static ");
T_b(te_class->GeneratedName);
T_b(" * ");
T_b(te_class->GeneratedName);
T_b("_instance;");
T_b("\n");
T_b("int g_");
T_b(te_class->GeneratedName);
T_b("_instanceMax = 0;");
T_b("\n");
T_b("int g_");
T_b(te_class->GeneratedName);
T_b("_instanceNum = 0;");
T_b("\n");
T_b("/******************************************************************************");
T_b("\n");
T_b(" ");
T_b("* Initialize object factory services.");
T_b("\n");
T_b(" ");
T_b("*****************************************************************************/");
T_b("\n");
T_b("#include \"sys_mechs.h\"");
T_b("\n");
T_b("void ");
T_b(te_class->GeneratedName);
T_b("_FactoryInit()");
T_b("\n");
T_b("{");
T_b("\n");
T_b("    ");
T_b(te_class->GeneratedName);
T_b("_container = (");
T_b(te_set->scope);
T_b(te_set->element_type);
T_b(" *)malloc(sizeof(");
T_b(te_set->scope);
T_b(te_set->element_type);
T_b(")*");
T_b(te_class->GeneratedName);
T_b("_MAX_EXTENT_SIZE);");
T_b("\n");
T_b("    ");
T_b(te_class->GeneratedName);
T_b("_instance = (");
T_b(te_class->GeneratedName);
T_b(" *)malloc(sizeof(");
T_b(te_class->GeneratedName);
T_b(")*");
T_b(te_class->GeneratedName);
T_b("_MAX_EXTENT_SIZE);");
T_b("\n");
T_b("    ");
T_b(classExtent->result);
T_b(".active.head = NULL;");
T_b("\n");
T_b("    ");
T_b(classExtent->result);
T_b(".inactive.head = NULL;");
T_b("\n");
T_b("    ");
T_b(classExtent->result);
T_b(".container = ");
T_b(te_class->GeneratedName);
T_b("_container;");
T_b("\n");
T_b("    ");
T_b(classExtent->result);
T_b(".pool = (");
T_b(te_instance->handle);
T_b(")");
T_b(te_class->GeneratedName);
T_b("_instance;");
T_b("\n");
T_b("    ");
T_b(classExtent->result);
T_b(".size = sizeof(");
T_b(te_class->GeneratedName);
T_b(");");
T_b("\n");
T_b("    ");
T_b(classExtent->result);
T_b(".initial_state = 1;");
T_b("\n");
T_b("    ");
T_b(classExtent->result);
T_b(".population = ");
T_b(te_class->GeneratedName);
T_b("_MAX_EXTENT_SIZE;");
T_b("\n");
T_b("    ");
T_b(base_arch_prefix->result);
T_b("_ClassFactoryInit(&");
T_b(classExtent->result);
T_b(");");
T_b("\n");
T_b("}");
T_b("\n");
T_b("/******************************************************************************");
T_b("\n");
T_b(" ");
T_b("* Object Creation Accessor");
T_b("\n");
T_b(" ");
T_b("*****************************************************************************/");
T_b("\n");
T_b(te_instance->handle);
T_b(" ");
T_b(te_class->GeneratedName);
T_b("_Create()");
T_b("\n");
T_b("{");
T_b("\n");
T_b("    ");
T_b(te_class->GeneratedName);
T_b(" * ");
T_b(te_relstore->self_name);
T_b(";");
T_b("\n");
T_b("    ");
T_b(te_set->element_type);
T_b(" * node;");
T_b("\n");
T_b("    ");
T_b(te_instance->handle);
T_b(" instance;");
T_b("\n");
T_b("    ");
T_b(te_set->scope);
T_b(te_extent->type);
T_b(" * dci = &");
T_b(classExtent->result);
T_b(";");
T_b("\n");
T_b("    ");
T_b("node = dci->");
T_b(te_extent->inactive);
T_b(".head;");
T_b("\n");
T_b("    ");
T_b("/* Check if object pool is empty-> */");
T_b("\n");
T_b("    ");
T_b("if (node == 0) {");
T_b("\n");
T_b("        ");
T_b(base_arch_prefix->result);
T_b("_UserObjectPoolEmptyCallout(\"");
T_b(te_c->Name);
T_b("\", \"");
T_b(te_class->Name);
T_b("\");");
T_b("\n");
T_b("        ");
T_b("return (");
T_b(te_instance->handle);
T_b(")0;");
T_b("\n");
T_b("    ");
T_b("}");
T_b("\n");
T_b("    ");
T_b("dci->");
T_b(te_extent->inactive);
T_b(".head = dci->");
T_b(te_extent->inactive);
T_b(".head->next;");
T_b("\n");
T_b("    ");
T_b("instance = (");
T_b(te_instance->handle);
T_b(") node->object;");
T_b("\n");
T_b("    ");
T_b("if ( 0 != dci->");
T_b(te_extent->istate_name);
T_b(" ) {");
T_b("\n");
T_b("        ");
T_b("instance->");
T_b(te_instance->current_state);
T_b(" = dci->");
T_b(te_extent->istate_name);
T_b(";");
T_b("\n");
T_b("    ");
T_b("}");
T_b("\n");
T_b("    ");
T_b(te_set->insert_instance);
T_b("( &dci->");
T_b(te_extent->active);
T_b(", node );");
T_b("\n");
T_b("    ");
T_b(te_relstore->self_name);
T_b(" = (");
T_b(te_class->GeneratedName);
T_b(" *)instance;");
T_b("\n");
T_b("    ");
T_b("/* Initialize appication analysis object attributes. */");
T_b("\n");
if (code_needed->result) {
if (te_dt->Core_Typ != 6) {
if (te_dt->Core_Typ == 5) {
if (not_empty oida) {
T_b("    ");
T_b(te_relstore->self_name);
T_b("->");
T_b(te_attr->GeneratedName);
T_b(" = (");
T_b(te_dt->ExtName);
T_b(") self;");
T_b("\n");
} else {
T_b("    ");
T_b(te_relstore->self_name);
T_b("->");
T_b(te_attr->GeneratedName);
T_b(" = ");
T_b(initial_value);
T_b(";");
T_b("\n");
}
} else {
if (initial_value != "") {
if (initial_value != "CTOR") {
T_b("    ");
T_b(te_relstore->self_name);
T_b("->");
T_b(te_attr->GeneratedName);
T_b(" = ");
T_b(initial_value);
T_b(";");
T_b("\n");
} else {
T_b("    ");
T_b("memset(self->");
T_b(te_attr->GeneratedName);
T_b(", 0, sizeof(self->");
T_b(te_attr->GeneratedName);
T_b("));");
T_b("\n");
}
}
}
}
}
if (auto_inc->result) {
T_b(auto_inc->body);
T_b("\n");
}
if ( not_empty ism ) {
T_b("    ");
T_b(te_relstore->self_name);
T_b("->");
T_b(te_instance->current_state);
T_b(" = ");
T_b(current_state->result);
T_b(";");
T_b("\n");
}
if (te_relstore->data_init != "") {
T_b("    ");
T_b("/* Initialize relationship storage */");
T_b("\n");
T_b("  ");
T_b(te_relstore->data_init);
T_b("\n");
}
T_b("#ifdef MC3020_MAX_NUM_MEASURE");
T_b("\n");
T_b("    ");
T_b("g_");
T_b(te_class->GeneratedName);
T_b("_instanceNum++;");
T_b("\n");
T_b("    ");
T_b("g_");
T_b(te_class->GeneratedName);
T_b("_instanceMax = ((g_");
T_b(te_class->GeneratedName);
T_b("_instanceMax < g_");
T_b(te_class->GeneratedName);
T_b("_instanceNum) ? g_");
T_b(te_class->GeneratedName);
T_b("_instanceNum : g_");
T_b(te_class->GeneratedName);
T_b("_instanceMax);");
T_b("\n");
T_b("#endif");
T_b("\n");
T_b("    ");
T_b("return instance;");
T_b("\n");
T_b("}");
T_b("\n");
T_b(" ");
T_b("\n");
T_b("/******************************************************************************");
T_b("\n");
T_b(" ");
T_b("* Object Deletion Accessor");
T_b("\n");
T_b(" ");
T_b("*****************************************************************************/");
T_b("\n");
T_b("void ");
T_b(te_class->GeneratedName);
T_b("_Delete(");
T_b(te_instance->handle);
T_b(" instance)");
T_b("\n");
T_b("{");
T_b("\n");
T_b("    ");
T_b(te_class->GeneratedName);
T_b(" * ");
T_b(te_relstore->self_name);
T_b(";");
T_b("\n");
T_b("    ");
T_b(te_set->element_type);
T_b(" * node;");
T_b("\n");
T_b("    ");
T_b(te_set->scope);
T_b(te_extent->type);
T_b(" * dci = &");
T_b(classExtent->result);
T_b(";");
T_b("\n");
T_b("    ");
T_b(te_relstore->self_name);
T_b(" = (");
T_b(te_class->GeneratedName);
T_b(" *)instance;");
T_b("\n");
T_b("    ");
T_b("if ( !");
T_b(te_relstore->self_name);
T_b(" ) {");
T_b("\n");
T_b("        ");
T_b("return;");
T_b("\n");
T_b("    ");
T_b("}");
T_b("\n");
if (te_relstore->data_fini != "") {
T_b("    ");
T_b("/* Release relationship storage */");
T_b("\n");
T_b(te_relstore->data_fini);
T_b("\n");
}
T_b("    ");
T_b("node = ");
T_b(default_prefix->result);
T_b("_SetRemoveNode(&(dci->");
T_b(te_extent->active);
T_b("), instance);");
T_b("\n");
T_b("    ");
T_b("node->next = dci->");
T_b(te_extent->inactive);
T_b(".head;");
T_b("\n");
T_b("    ");
T_b("dci->");
T_b(te_extent->inactive);
T_b(".head = node;");
T_b("\n");
if ( not_empty ism ) {
T_b("    ");
T_b(te_relstore->self_name);
T_b("->");
T_b(te_instance->current_state);
T_b(" = ");
T_b(te_eq->cant_happen);
T_b(";");
T_b("\n");
}
T_b("    ");
T_b("/* Initialize storage to zero. */");
T_b("\n");
T_b("    ");
T_b(default_prefix->result);
T_b("_memset( instance, 0, dci->size );");
T_b("\n");
T_b("#ifdef MC3020_MAX_NUM_MEASURE");
T_b("\n");
T_b("    ");
T_b("g_");
T_b(te_class->GeneratedName);
T_b("_instanceNum--;");
T_b("\n");
T_b("#endif");
T_b("\n");
T_b("}");
T_b("\n");
