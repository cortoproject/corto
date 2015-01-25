/* Fast__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "Fast__meta.h"
#include "Fast__api.h"

Fast_BinaryExpr Fast_BinaryExpr__new(void) {
    return cx_new(cx_type(Fast_BinaryExpr_o));
}

Fast_BinaryExpr Fast_BinaryExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_BinaryExpr_o));
}

int Fast_BinaryExpr__define(Fast_BinaryExpr _this, Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator) {
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d99c0>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? cx_keep_ext(_this, rvalue, "element <0x95d99c0>.rvalue") : 0; _this->rvalue = rvalue;
    _this->operator = operator;
    return cx_define(_this);
}

Fast_BinaryExpr Fast_BinaryExpr__create(Fast_Expression lvalue, Fast_Expression rvalue, cx_operatorKind operator) {
    Fast_BinaryExpr _this;
    _this = cx_new(cx_type(Fast_BinaryExpr_o));
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d99c0>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? cx_keep_ext(_this, rvalue, "element <0x95d99c0>.rvalue") : 0; _this->rvalue = rvalue;
    _this->operator = operator;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_Binding__init(Fast_Binding *_this, cx_function function, Fast_Block impl) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_Binding_o), _this);
    cx_initValue(&v);
    function ? cx_keep_ext(_this, function, "element <0x95d80f8>.function") : 0; _this->function = function;
    impl ? cx_keep_ext(_this, impl, "element <0x95d80f8>.impl") : 0; _this->impl = impl;
}

void Fast_Binding__deinit(Fast_Binding *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_Binding_o), _this);
    cx_deinitValue(&v);
}

Fast_Block Fast_Block__new(void) {
    return cx_new(cx_type(Fast_Block_o));
}

Fast_Block Fast_Block__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Block_o));
}

int Fast_Block__define(Fast_Block _this, Fast_Block parent) {
    parent ? cx_keep_ext(_this, parent, "element <0x95d99c0>.parent") : 0; _this->parent = parent;
    return cx_define(_this);
}

Fast_Block Fast_Block__create(Fast_Block parent) {
    Fast_Block _this;
    _this = cx_new(cx_type(Fast_Block_o));
    parent ? cx_keep_ext(_this, parent, "element <0x95d99c0>.parent") : 0; _this->parent = parent;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Boolean Fast_Boolean__new(void) {
    return cx_new(cx_type(Fast_Boolean_o));
}

Fast_Boolean Fast_Boolean__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Boolean_o));
}

int Fast_Boolean__define(Fast_Boolean _this, cx_bool value) {
    _this->value = value;
    return cx_define(_this);
}

Fast_Boolean Fast_Boolean__create(cx_bool value) {
    Fast_Boolean _this;
    _this = cx_new(cx_type(Fast_Boolean_o));
    _this->value = value;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Call Fast_Call__new(void) {
    return cx_new(cx_type(Fast_Call_o));
}

Fast_Call Fast_Call__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Call_o));
}

int Fast_Call__define(Fast_Call _this, Fast_Expression instanceExpr, Fast_Expression arguments) {
    instanceExpr ? cx_keep_ext(_this, instanceExpr, "element <0x959c288>.instanceExpr") : 0; _this->instanceExpr = instanceExpr;
    arguments ? cx_keep_ext(_this, arguments, "element <0x959c288>.arguments") : 0; _this->arguments = arguments;
    return cx_define(_this);
}

Fast_Call Fast_Call__create(Fast_Expression instanceExpr, Fast_Expression arguments) {
    Fast_Call _this;
    _this = cx_new(cx_type(Fast_Call_o));
    instanceExpr ? cx_keep_ext(_this, instanceExpr, "element <0x95de988>.instanceExpr") : 0; _this->instanceExpr = instanceExpr;
    arguments ? cx_keep_ext(_this, arguments, "element <0x95de988>.arguments") : 0; _this->arguments = arguments;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_CallBuilder__init(Fast_CallBuilder *_this, cx_string name, Fast_Expression arguments, Fast_Expression instance, cx_object scope, Fast_Block block) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_CallBuilder_o), _this);
    cx_initValue(&v);
    _this->name = (name ? cx_strdup(name) : NULL);
    arguments ? cx_keep_ext(_this, arguments, "element <0x95d9770>.arguments") : 0; _this->arguments = arguments;
    instance ? cx_keep_ext(_this, instance, "element <0x95d9770>.instance") : 0; _this->instance = instance;
    scope ? cx_keep_ext(_this, scope, "element <0x95d9770>.scope") : 0; _this->scope = scope;
    block ? cx_keep_ext(_this, block, "element <0x95d9770>.block") : 0; _this->block = block;
}

void Fast_CallBuilder__deinit(Fast_CallBuilder *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_CallBuilder_o), _this);
    cx_deinitValue(&v);
}

Fast_CastExpr Fast_CastExpr__new(void) {
    return cx_new(cx_type(Fast_CastExpr_o));
}

Fast_CastExpr Fast_CastExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_CastExpr_o));
}

int Fast_CastExpr__define(Fast_CastExpr _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d9770>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? cx_keep_ext(_this, rvalue, "element <0x95d9770>.rvalue") : 0; _this->rvalue = rvalue;
    return cx_define(_this);
}

Fast_CastExpr Fast_CastExpr__create(Fast_Expression lvalue, Fast_Expression rvalue) {
    Fast_CastExpr _this;
    _this = cx_new(cx_type(Fast_CastExpr_o));
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d9770>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? cx_keep_ext(_this, rvalue, "element <0x95d9770>.rvalue") : 0; _this->rvalue = rvalue;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Character Fast_Character__new(void) {
    return cx_new(cx_type(Fast_Character_o));
}

Fast_Character Fast_Character__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Character_o));
}

int Fast_Character__define(Fast_Character _this, cx_char value) {
    _this->value = value;
    return cx_define(_this);
}

Fast_Character Fast_Character__create(cx_char value) {
    Fast_Character _this;
    _this = cx_new(cx_type(Fast_Character_o));
    _this->value = value;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_CommaExpr Fast_CommaExpr__new(void) {
    return cx_new(cx_type(Fast_CommaExpr_o));
}

Fast_CommaExpr Fast_CommaExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_CommaExpr_o));
}

int Fast_CommaExpr__define(Fast_CommaExpr _this) {
    return cx_define(_this);
}

Fast_CommaExpr Fast_CommaExpr__create(void) {
    Fast_CommaExpr _this;
    _this = cx_new(cx_type(Fast_CommaExpr_o));
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Define Fast_Define__new(void) {
    return cx_new(cx_type(Fast_Define_o));
}

Fast_Define Fast_Define__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Define_o));
}

int Fast_Define__define(Fast_Define _this, Fast_Expression object) {
    object ? cx_keep_ext(_this, object, "element <0x95d9cb8>.object") : 0; _this->object = object;
    return cx_define(_this);
}

Fast_Define Fast_Define__create(Fast_Expression object) {
    Fast_Define _this;
    _this = cx_new(cx_type(Fast_Define_o));
    object ? cx_keep_ext(_this, object, "element <0x95d9cb8>.object") : 0; _this->object = object;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_DelegateCall Fast_DelegateCall__new(void) {
    return cx_new(cx_type(Fast_DelegateCall_o));
}

Fast_DelegateCall Fast_DelegateCall__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_DelegateCall_o));
}

int Fast_DelegateCall__define(Fast_DelegateCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, Fast_Expression expr) {
    instanceExpr ? cx_keep_ext(_this, instanceExpr, "element <0x95952e0>.instanceExpr") : 0; Fast_Call(_this)->instanceExpr = instanceExpr;
    arguments ? cx_keep_ext(_this, arguments, "element <0x95952e0>.arguments") : 0; Fast_Call(_this)->arguments = arguments;
    expr ? cx_keep_ext(_this, expr, "element <0x95952e0>.expr") : 0; _this->expr = expr;
    return cx_define(_this);
}

Fast_DelegateCall Fast_DelegateCall__create(Fast_Expression instanceExpr, Fast_Expression arguments, Fast_Expression expr) {
    Fast_DelegateCall _this;
    _this = cx_new(cx_type(Fast_DelegateCall_o));
    instanceExpr ? cx_keep_ext(_this, instanceExpr, "element <0x95de988>.instanceExpr") : 0; Fast_Call(_this)->instanceExpr = instanceExpr;
    arguments ? cx_keep_ext(_this, arguments, "element <0x95de988>.arguments") : 0; Fast_Call(_this)->arguments = arguments;
    expr ? cx_keep_ext(_this, expr, "element <0x95de988>.expr") : 0; _this->expr = expr;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_DynamicInitializer Fast_DynamicInitializer__new(void) {
    return cx_new(cx_type(Fast_DynamicInitializer_o));
}

Fast_DynamicInitializer Fast_DynamicInitializer__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_DynamicInitializer_o));
}

int Fast_DynamicInitializer__define(Fast_DynamicInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue) {
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    _this->assignValue = assignValue;
    return cx_define(_this);
}

Fast_DynamicInitializer Fast_DynamicInitializer__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue) {
    Fast_DynamicInitializer _this;
    _this = cx_new(cx_type(Fast_DynamicInitializer_o));
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    _this->assignValue = assignValue;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_DynamicInitializerFrame__init(Fast_DynamicInitializerFrame *_this, Fast_Expression_array64 expr, Fast_Expression_array64 keyExpr, Fast_Integer sequenceSize) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_DynamicInitializerFrame_o), _this);
    cx_initValue(&v);
    memcpy(_this->expr, expr, sizeof(Fast_Expression_array64));
    memcpy(_this->keyExpr, keyExpr, sizeof(Fast_Expression_array64));
    sequenceSize ? cx_keep_ext(_this, sequenceSize, "element <0x95da828>.sequenceSize") : 0; _this->sequenceSize = sequenceSize;
}

void Fast_DynamicInitializerFrame__deinit(Fast_DynamicInitializerFrame *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_DynamicInitializerFrame_o), _this);
    cx_deinitValue(&v);
}

Fast_ElementExpr Fast_ElementExpr__new(void) {
    return cx_new(cx_type(Fast_ElementExpr_o));
}

Fast_ElementExpr Fast_ElementExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_ElementExpr_o));
}

int Fast_ElementExpr__define(Fast_ElementExpr _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d80f8>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? cx_keep_ext(_this, rvalue, "element <0x95d80f8>.rvalue") : 0; _this->rvalue = rvalue;
    return cx_define(_this);
}

Fast_ElementExpr Fast_ElementExpr__create(Fast_Expression lvalue, Fast_Expression rvalue) {
    Fast_ElementExpr _this;
    _this = cx_new(cx_type(Fast_ElementExpr_o));
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d80f8>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? cx_keep_ext(_this, rvalue, "element <0x95d80f8>.rvalue") : 0; _this->rvalue = rvalue;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Expression Fast_Expression__new(void) {
    return cx_new(cx_type(Fast_Expression_o));
}

Fast_Expression Fast_Expression__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Expression_o));
}

int Fast_Expression__define(Fast_Expression _this, Fast_nodeKind kind) {
    Fast_Node(_this)->kind = kind;
    return cx_define(_this);
}

Fast_Expression Fast_Expression__create(Fast_nodeKind kind) {
    Fast_Expression _this;
    _this = cx_new(cx_type(Fast_Expression_o));
    Fast_Node(_this)->kind = kind;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_FloatingPoint Fast_FloatingPoint__new(void) {
    return cx_new(cx_type(Fast_FloatingPoint_o));
}

Fast_FloatingPoint Fast_FloatingPoint__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_FloatingPoint_o));
}

int Fast_FloatingPoint__define(Fast_FloatingPoint _this, cx_float64 value) {
    _this->value = value;
    return cx_define(_this);
}

Fast_FloatingPoint Fast_FloatingPoint__create(cx_float64 value) {
    Fast_FloatingPoint _this;
    _this = cx_new(cx_type(Fast_FloatingPoint_o));
    _this->value = value;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_If Fast_If__new(void) {
    return cx_new(cx_type(Fast_If_o));
}

Fast_If Fast_If__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_If_o));
}

int Fast_If__define(Fast_If _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch) {
    condition ? cx_keep_ext(_this, condition, "element <0x95d80f8>.condition") : 0; _this->condition = condition;
    trueBranch ? cx_keep_ext(_this, trueBranch, "element <0x95d80f8>.trueBranch") : 0; _this->trueBranch = trueBranch;
    falseBranch ? cx_keep_ext(_this, falseBranch, "element <0x95d80f8>.falseBranch") : 0; _this->falseBranch = falseBranch;
    return cx_define(_this);
}

Fast_If Fast_If__create(Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch) {
    Fast_If _this;
    _this = cx_new(cx_type(Fast_If_o));
    condition ? cx_keep_ext(_this, condition, "element <0x95d80f8>.condition") : 0; _this->condition = condition;
    trueBranch ? cx_keep_ext(_this, trueBranch, "element <0x95d80f8>.trueBranch") : 0; _this->trueBranch = trueBranch;
    falseBranch ? cx_keep_ext(_this, falseBranch, "element <0x95d80f8>.falseBranch") : 0; _this->falseBranch = falseBranch;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Initializer Fast_Initializer__new(void) {
    return cx_new(cx_type(Fast_Initializer_o));
}

Fast_Initializer Fast_Initializer__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Initializer_o));
}

int Fast_Initializer__define(Fast_Initializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount) {
    memcpy(_this->variables, variables, sizeof(Fast_InitializerVariable_array64));
    _this->variableCount = variableCount;
    return cx_define(_this);
}

Fast_Initializer Fast_Initializer__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount) {
    Fast_Initializer _this;
    _this = cx_new(cx_type(Fast_Initializer_o));
    memcpy(_this->variables, variables, sizeof(Fast_InitializerVariable_array64));
    _this->variableCount = variableCount;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_InitializerExpr Fast_InitializerExpr__new(void) {
    return cx_new(cx_type(Fast_InitializerExpr_o));
}

Fast_InitializerExpr Fast_InitializerExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_InitializerExpr_o));
}

int Fast_InitializerExpr__define(Fast_InitializerExpr _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue) {
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    _this->assignValue = assignValue;
    return cx_define(_this);
}

Fast_InitializerExpr Fast_InitializerExpr__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount, cx_bool assignValue) {
    Fast_InitializerExpr _this;
    _this = cx_new(cx_type(Fast_InitializerExpr_o));
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    _this->assignValue = assignValue;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_InitializerFrame__init(Fast_InitializerFrame *_this, cx_uint32 location, cx_type type, cx_bool isKey, cx_member member) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_InitializerFrame_o), _this);
    cx_initValue(&v);
    _this->location = location;
    type ? cx_keep_ext(_this, type, "element <0x95e5e78>.type") : 0; _this->type = type;
    _this->isKey = isKey;
    member ? cx_keep_ext(_this, member, "element <0x95e5e78>.member") : 0; _this->member = member;
}

void Fast_InitializerFrame__deinit(Fast_InitializerFrame *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_InitializerFrame_o), _this);
    cx_deinitValue(&v);
}

void Fast_InitializerVariable__init(Fast_InitializerVariable *_this, cx_word offset, Fast_Expression object, cx_word key) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_InitializerVariable_o), _this);
    cx_initValue(&v);
    _this->offset = offset;
    object ? cx_keep_ext(_this, object, "element <0x95d6ca0>.object") : 0; _this->object = object;
    _this->key = key;
}

void Fast_InitializerVariable__deinit(Fast_InitializerVariable *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_InitializerVariable_o), _this);
    cx_deinitValue(&v);
}

void Fast_InitOper__init(Fast_InitOper *_this, Fast_InitOperKind kind, Fast_Expression expr, cx_string name) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_InitOper_o), _this);
    cx_initValue(&v);
    _this->kind = kind;
    expr ? cx_keep_ext(_this, expr, "element <0x95d6ca0>.expr") : 0; _this->expr = expr;
    _this->name = (name ? cx_strdup(name) : NULL);
}

void Fast_InitOper__deinit(Fast_InitOper *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_InitOper_o), _this);
    cx_deinitValue(&v);
}

Fast_Integer Fast_Integer__new(void) {
    return cx_new(cx_type(Fast_Integer_o));
}

Fast_Integer Fast_Integer__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Integer_o));
}

int Fast_Integer__define(Fast_Integer _this, cx_uint64 value) {
    _this->value = value;
    return cx_define(_this);
}

Fast_Integer Fast_Integer__create(cx_uint64 value) {
    Fast_Integer _this;
    _this = cx_new(cx_type(Fast_Integer_o));
    _this->value = value;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Literal Fast_Literal__new(void) {
    return cx_new(cx_type(Fast_Literal_o));
}

Fast_Literal Fast_Literal__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Literal_o));
}

int Fast_Literal__define(Fast_Literal _this, Fast_valueKind kind_1) {
    _this->kind = kind_1;
    return cx_define(_this);
}

Fast_Literal Fast_Literal__create(Fast_valueKind kind_1) {
    Fast_Literal _this;
    _this = cx_new(cx_type(Fast_Literal_o));
    _this->kind = kind_1;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Local Fast_Local__new(void) {
    return cx_new(cx_type(Fast_Local_o));
}

Fast_Local Fast_Local__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Local_o));
}

int Fast_Local__define(Fast_Local _this, cx_string name, Fast_Variable type_1, Fast_LocalKind kind_2, cx_bool isReference_1) {
    _this->name = (name ? cx_strdup(name) : NULL);
    type_1 ? cx_keep_ext(_this, type_1, "element <0x95d9ca0>.type") : 0; _this->type = type_1;
    _this->kind = kind_2;
    _this->isReference = isReference_1;
    return cx_define(_this);
}

Fast_Local Fast_Local__create(cx_string name, Fast_Variable type_1, Fast_LocalKind kind_2, cx_bool isReference_1) {
    Fast_Local _this;
    _this = cx_new(cx_type(Fast_Local_o));
    _this->name = (name ? cx_strdup(name) : NULL);
    type_1 ? cx_keep_ext(_this, type_1, "element <0x95d9ca0>.type") : 0; _this->type = type_1;
    _this->kind = kind_2;
    _this->isReference = isReference_1;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_Lvalue__init(Fast_Lvalue *_this, Fast_Expression expr, cx_bool isAssignment) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_Lvalue_o), _this);
    cx_initValue(&v);
    expr ? cx_keep_ext(_this, expr, "element <0x95d6ca0>.expr") : 0; _this->expr = expr;
    _this->isAssignment = isAssignment;
}

void Fast_Lvalue__deinit(Fast_Lvalue *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_Lvalue_o), _this);
    cx_deinitValue(&v);
}

Fast_MemberExpr Fast_MemberExpr__new(void) {
    return cx_new(cx_type(Fast_MemberExpr_o));
}

Fast_MemberExpr Fast_MemberExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_MemberExpr_o));
}

int Fast_MemberExpr__define(Fast_MemberExpr _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d99c0>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? cx_keep_ext(_this, rvalue, "element <0x95d99c0>.rvalue") : 0; _this->rvalue = rvalue;
    return cx_define(_this);
}

Fast_MemberExpr Fast_MemberExpr__create(Fast_Expression lvalue, Fast_Expression rvalue) {
    Fast_MemberExpr _this;
    _this = cx_new(cx_type(Fast_MemberExpr_o));
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d99c0>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? cx_keep_ext(_this, rvalue, "element <0x95d99c0>.rvalue") : 0; _this->rvalue = rvalue;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_NewExpr Fast_NewExpr__new(void) {
    return cx_new(cx_type(Fast_NewExpr_o));
}

Fast_NewExpr Fast_NewExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_NewExpr_o));
}

int Fast_NewExpr__define(Fast_NewExpr _this, Fast_Expression type_1, Fast_Expression attributes) {
    type_1 ? cx_keep_ext(_this, type_1, "element <0x95d80f8>.type") : 0; _this->type = type_1;
    attributes ? cx_keep_ext(_this, attributes, "element <0x95d80f8>.attributes") : 0; _this->attributes = attributes;
    return cx_define(_this);
}

Fast_NewExpr Fast_NewExpr__create(Fast_Expression type_1, Fast_Expression attributes) {
    Fast_NewExpr _this;
    _this = cx_new(cx_type(Fast_NewExpr_o));
    type_1 ? cx_keep_ext(_this, type_1, "element <0x95d80f8>.type") : 0; _this->type = type_1;
    attributes ? cx_keep_ext(_this, attributes, "element <0x95d80f8>.attributes") : 0; _this->attributes = attributes;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Node Fast_Node__new(void) {
    return cx_new(cx_type(Fast_Node_o));
}

Fast_Node Fast_Node__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Node_o));
}

int Fast_Node__define(Fast_Node _this, Fast_nodeKind kind) {
    _this->kind = kind;
    return cx_define(_this);
}

Fast_Node Fast_Node__create(Fast_nodeKind kind) {
    Fast_Node _this;
    _this = cx_new(cx_type(Fast_Node_o));
    _this->kind = kind;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Null Fast_Null__new(void) {
    return cx_new(cx_type(Fast_Null_o));
}

Fast_Null Fast_Null__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Null_o));
}

int Fast_Null__define(Fast_Null _this) {
    return cx_define(_this);
}

Fast_Null Fast_Null__create(void) {
    Fast_Null _this;
    _this = cx_new(cx_type(Fast_Null_o));
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Object Fast_Object__new(void) {
    return cx_new(cx_type(Fast_Object_o));
}

Fast_Object Fast_Object__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Object_o));
}

int Fast_Object__define(Fast_Object _this, cx_object value) {
    value ? cx_keep_ext(_this, value, "element <0x95d80f8>.value") : 0; Fast_ObjectBase(_this)->value = value;
    return cx_define(_this);
}

Fast_Object Fast_Object__create(cx_object value) {
    Fast_Object _this;
    _this = cx_new(cx_type(Fast_Object_o));
    value ? cx_keep_ext(_this, value, "element <0x95d80f8>.value") : 0; Fast_ObjectBase(_this)->value = value;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_ObjectBase Fast_ObjectBase__new(void) {
    return cx_new(cx_type(Fast_ObjectBase_o));
}

Fast_ObjectBase Fast_ObjectBase__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_ObjectBase_o));
}

int Fast_ObjectBase__define(Fast_ObjectBase _this, cx_object value) {
    value ? cx_keep_ext(_this, value, "element <0x95d80f8>.value") : 0; _this->value = value;
    return cx_define(_this);
}

Fast_ObjectBase Fast_ObjectBase__create(cx_object value) {
    Fast_ObjectBase _this;
    _this = cx_new(cx_type(Fast_ObjectBase_o));
    value ? cx_keep_ext(_this, value, "element <0x95d80f8>.value") : 0; _this->value = value;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Parser Fast_Parser__new(void) {
    return cx_new(cx_type(Fast_Parser_o));
}

Fast_Parser Fast_Parser__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Parser_o));
}

int Fast_Parser__define(Fast_Parser _this, cx_string source, cx_string filename) {
    _this->source = (source ? cx_strdup(source) : NULL);
    _this->filename = (filename ? cx_strdup(filename) : NULL);
    return cx_define(_this);
}

Fast_Parser Fast_Parser__create(cx_string source, cx_string filename) {
    Fast_Parser _this;
    _this = cx_new(cx_type(Fast_Parser_o));
    _this->source = (source ? cx_strdup(source) : NULL);
    _this->filename = (filename ? cx_strdup(filename) : NULL);
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_Parser_stagedId__init(Fast_Parser_stagedId *_this, cx_string name, cx_bool found, cx_uint32 line, cx_uint32 column) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_Parser_stagedId_o), _this);
    cx_initValue(&v);
    _this->name = (name ? cx_strdup(name) : NULL);
    _this->found = found;
    _this->line = line;
    _this->column = column;
}

void Fast_Parser_stagedId__deinit(Fast_Parser_stagedId *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_Parser_stagedId_o), _this);
    cx_deinitValue(&v);
}

void Fast_ParserDeclaration__init(Fast_ParserDeclaration *_this, cx_string name, Fast_Variable variable) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_ParserDeclaration_o), _this);
    cx_initValue(&v);
    _this->name = (name ? cx_strdup(name) : NULL);
    variable ? cx_keep_ext(_this, variable, "element <0x95d8970>.variable") : 0; _this->variable = variable;
}

void Fast_ParserDeclaration__deinit(Fast_ParserDeclaration *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_ParserDeclaration_o), _this);
    cx_deinitValue(&v);
}

void Fast_ParserNew__init(Fast_ParserNew *_this, Fast_nodeKind kind, Fast_Expression parent, Fast_Expression name, Fast_Expression attr) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_ParserNew_o), _this);
    cx_initValue(&v);
    _this->kind = kind;
    parent ? cx_keep_ext(_this, parent, "element <0x95e5e78>.parent") : 0; _this->parent = parent;
    name ? cx_keep_ext(_this, name, "element <0x95e5e78>.name") : 0; _this->name = name;
    attr ? cx_keep_ext(_this, attr, "element <0x95e5e78>.attr") : 0; _this->attr = attr;
}

void Fast_ParserNew__deinit(Fast_ParserNew *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_ParserNew_o), _this);
    cx_deinitValue(&v);
}

Fast_PostfixExpr Fast_PostfixExpr__new(void) {
    return cx_new(cx_type(Fast_PostfixExpr_o));
}

Fast_PostfixExpr Fast_PostfixExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_PostfixExpr_o));
}

int Fast_PostfixExpr__define(Fast_PostfixExpr _this, Fast_Expression lvalue, cx_operatorKind operator) {
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d80f8>.lvalue") : 0; _this->lvalue = lvalue;
    _this->operator = operator;
    return cx_define(_this);
}

Fast_PostfixExpr Fast_PostfixExpr__create(Fast_Expression lvalue, cx_operatorKind operator) {
    Fast_PostfixExpr _this;
    _this = cx_new(cx_type(Fast_PostfixExpr_o));
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d80f8>.lvalue") : 0; _this->lvalue = lvalue;
    _this->operator = operator;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_SignedInteger Fast_SignedInteger__new(void) {
    return cx_new(cx_type(Fast_SignedInteger_o));
}

Fast_SignedInteger Fast_SignedInteger__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_SignedInteger_o));
}

int Fast_SignedInteger__define(Fast_SignedInteger _this, cx_int64 value) {
    _this->value = value;
    return cx_define(_this);
}

Fast_SignedInteger Fast_SignedInteger__create(cx_int64 value) {
    Fast_SignedInteger _this;
    _this = cx_new(cx_type(Fast_SignedInteger_o));
    _this->value = value;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_StaticCall Fast_StaticCall__new(void) {
    return cx_new(cx_type(Fast_StaticCall_o));
}

Fast_StaticCall Fast_StaticCall__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_StaticCall_o));
}

int Fast_StaticCall__define(Fast_StaticCall _this, Fast_Expression instanceExpr, Fast_Expression arguments, cx_function function) {
    instanceExpr ? cx_keep_ext(_this, instanceExpr, "element <0x95de988>.instanceExpr") : 0; Fast_Call(_this)->instanceExpr = instanceExpr;
    arguments ? cx_keep_ext(_this, arguments, "element <0x95de988>.arguments") : 0; Fast_Call(_this)->arguments = arguments;
    function ? cx_keep_ext(_this, function, "element <0x95de988>.function") : 0; _this->function = function;
    return cx_define(_this);
}

Fast_StaticCall Fast_StaticCall__create(Fast_Expression instanceExpr, Fast_Expression arguments, cx_function function) {
    Fast_StaticCall _this;
    _this = cx_new(cx_type(Fast_StaticCall_o));
    instanceExpr ? cx_keep_ext(_this, instanceExpr, "element <0x95952e0>.instanceExpr") : 0; Fast_Call(_this)->instanceExpr = instanceExpr;
    arguments ? cx_keep_ext(_this, arguments, "element <0x95952e0>.arguments") : 0; Fast_Call(_this)->arguments = arguments;
    function ? cx_keep_ext(_this, function, "element <0x95952e0>.function") : 0; _this->function = function;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_StaticInitializer Fast_StaticInitializer__new(void) {
    return cx_new(cx_type(Fast_StaticInitializer_o));
}

Fast_StaticInitializer Fast_StaticInitializer__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_StaticInitializer_o));
}

int Fast_StaticInitializer__define(Fast_StaticInitializer _this, Fast_InitializerVariable_array64 variables, cx_uint8 variableCount) {
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    return cx_define(_this);
}

Fast_StaticInitializer Fast_StaticInitializer__create(Fast_InitializerVariable_array64 variables, cx_uint8 variableCount) {
    Fast_StaticInitializer _this;
    _this = cx_new(cx_type(Fast_StaticInitializer_o));
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_StaticInitializerFrame__init(Fast_StaticInitializerFrame *_this, cx_word_array64 ptr, cx_word_array64 keyPtr) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(Fast_StaticInitializerFrame_o), _this);
    cx_initValue(&v);
    memcpy(_this->ptr, ptr, sizeof(cx_word_array64));
    memcpy(_this->keyPtr, keyPtr, sizeof(cx_word_array64));
}

void Fast_StaticInitializerFrame__deinit(Fast_StaticInitializerFrame *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(Fast_StaticInitializerFrame_o), _this);
    cx_deinitValue(&v);
}

Fast_String Fast_String__new(void) {
    return cx_new(cx_type(Fast_String_o));
}

Fast_String Fast_String__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_String_o));
}

int Fast_String__define(Fast_String _this, cx_string value) {
    _this->value = (value ? cx_strdup(value) : NULL);
    return cx_define(_this);
}

Fast_String Fast_String__create(cx_string value) {
    Fast_String _this;
    _this = cx_new(cx_type(Fast_String_o));
    _this->value = (value ? cx_strdup(value) : NULL);
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Template Fast_Template__new(void) {
    return cx_new(cx_type(Fast_Template_o));
}

Fast_Template Fast_Template__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Template_o));
}

int Fast_Template__define(Fast_Template _this, cx_string name, Fast_Variable type_1, Fast_LocalKind kind_2, cx_bool isReference_1) {
    Fast_Local(_this)->name = (name ? cx_strdup(name) : NULL);
    type_1 ? cx_keep_ext(_this, type_1, "element <0x95d9ca0>.type") : 0; Fast_Local(_this)->type = type_1;
    Fast_Local(_this)->kind = kind_2;
    Fast_Local(_this)->isReference = isReference_1;
    return cx_define(_this);
}

Fast_Template Fast_Template__create(cx_string name, Fast_Variable type_1, Fast_LocalKind kind_2, cx_bool isReference_1) {
    Fast_Template _this;
    _this = cx_new(cx_type(Fast_Template_o));
    Fast_Local(_this)->name = (name ? cx_strdup(name) : NULL);
    type_1 ? cx_keep_ext(_this, type_1, "element <0x95d9ca0>.type") : 0; Fast_Local(_this)->type = type_1;
    Fast_Local(_this)->kind = kind_2;
    Fast_Local(_this)->isReference = isReference_1;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_TernaryExpr Fast_TernaryExpr__new(void) {
    return cx_new(cx_type(Fast_TernaryExpr_o));
}

Fast_TernaryExpr Fast_TernaryExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_TernaryExpr_o));
}

int Fast_TernaryExpr__define(Fast_TernaryExpr _this, Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result) {
    condition ? cx_keep_ext(_this, condition, "element <0x95d9770>.condition") : 0; _this->condition = condition;
    ifTrue ? cx_keep_ext(_this, ifTrue, "element <0x95d9770>.ifTrue") : 0; _this->ifTrue = ifTrue;
    ifFalse ? cx_keep_ext(_this, ifFalse, "element <0x95d9770>.ifFalse") : 0; _this->ifFalse = ifFalse;
    result ? cx_keep_ext(_this, result, "element <0x95d9770>.result") : 0; _this->result = result;
    return cx_define(_this);
}

Fast_TernaryExpr Fast_TernaryExpr__create(Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result) {
    Fast_TernaryExpr _this;
    _this = cx_new(cx_type(Fast_TernaryExpr_o));
    condition ? cx_keep_ext(_this, condition, "element <0x95d9770>.condition") : 0; _this->condition = condition;
    ifTrue ? cx_keep_ext(_this, ifTrue, "element <0x95d9770>.ifTrue") : 0; _this->ifTrue = ifTrue;
    ifFalse ? cx_keep_ext(_this, ifFalse, "element <0x95d9770>.ifFalse") : 0; _this->ifFalse = ifFalse;
    result ? cx_keep_ext(_this, result, "element <0x95d9770>.result") : 0; _this->result = result;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_UnaryExpr Fast_UnaryExpr__new(void) {
    return cx_new(cx_type(Fast_UnaryExpr_o));
}

Fast_UnaryExpr Fast_UnaryExpr__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_UnaryExpr_o));
}

int Fast_UnaryExpr__define(Fast_UnaryExpr _this, Fast_Expression lvalue, cx_operatorKind operator) {
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d80f8>.lvalue") : 0; _this->lvalue = lvalue;
    _this->operator = operator;
    return cx_define(_this);
}

Fast_UnaryExpr Fast_UnaryExpr__create(Fast_Expression lvalue, cx_operatorKind operator) {
    Fast_UnaryExpr _this;
    _this = cx_new(cx_type(Fast_UnaryExpr_o));
    lvalue ? cx_keep_ext(_this, lvalue, "element <0x95d80f8>.lvalue") : 0; _this->lvalue = lvalue;
    _this->operator = operator;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Update Fast_Update__new(void) {
    return cx_new(cx_type(Fast_Update_o));
}

Fast_Update Fast_Update__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Update_o));
}

int Fast_Update__define(Fast_Update _this, Fast_Expression_list exprList, Fast_Block block, Fast_Expression from) {
    _this->exprList = exprList;
    block ? cx_keep_ext(_this, block, "element <0x95d80f8>.block") : 0; _this->block = block;
    from ? cx_keep_ext(_this, from, "element <0x95d80f8>.from") : 0; _this->from = from;
    return cx_define(_this);
}

Fast_Update Fast_Update__create(Fast_Expression_list exprList, Fast_Block block, Fast_Expression from) {
    Fast_Update _this;
    _this = cx_new(cx_type(Fast_Update_o));
    _this->exprList = exprList;
    block ? cx_keep_ext(_this, block, "element <0x95d80f8>.block") : 0; _this->block = block;
    from ? cx_keep_ext(_this, from, "element <0x95d80f8>.from") : 0; _this->from = from;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Variable Fast_Variable__new(void) {
    return cx_new(cx_type(Fast_Variable_o));
}

Fast_Variable Fast_Variable__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Variable_o));
}

int Fast_Variable__define(Fast_Variable _this, Fast_variableKind kind_1) {
    _this->kind = kind_1;
    return cx_define(_this);
}

Fast_Variable Fast_Variable__create(Fast_variableKind kind_1) {
    Fast_Variable _this;
    _this = cx_new(cx_type(Fast_Variable_o));
    _this->kind = kind_1;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Wait Fast_Wait__new(void) {
    return cx_new(cx_type(Fast_Wait_o));
}

Fast_Wait Fast_Wait__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_Wait_o));
}

int Fast_Wait__define(Fast_Wait _this, Fast_Expression_list exprList, Fast_Expression timeout) {
    _this->exprList = exprList;
    timeout ? cx_keep_ext(_this, timeout, "element <0x95d80f8>.timeout") : 0; _this->timeout = timeout;
    return cx_define(_this);
}

Fast_Wait Fast_Wait__create(Fast_Expression_list exprList, Fast_Expression timeout) {
    Fast_Wait _this;
    _this = cx_new(cx_type(Fast_Wait_o));
    _this->exprList = exprList;
    timeout ? cx_keep_ext(_this, timeout, "element <0x95d80f8>.timeout") : 0; _this->timeout = timeout;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_While Fast_While__new(void) {
    return cx_new(cx_type(Fast_While_o));
}

Fast_While Fast_While__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(Fast_While_o));
}

int Fast_While__define(Fast_While _this, Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil) {
    condition ? cx_keep_ext(_this, condition, "element <0x95d80f8>.condition") : 0; _this->condition = condition;
    trueBranch ? cx_keep_ext(_this, trueBranch, "element <0x95d80f8>.trueBranch") : 0; _this->trueBranch = trueBranch;
    _this->isUntil = isUntil;
    return cx_define(_this);
}

Fast_While Fast_While__create(Fast_Expression condition, Fast_Block trueBranch, cx_bool isUntil) {
    Fast_While _this;
    _this = cx_new(cx_type(Fast_While_o));
    condition ? cx_keep_ext(_this, condition, "element <0x95d80f8>.condition") : 0; _this->condition = condition;
    trueBranch ? cx_keep_ext(_this, trueBranch, "element <0x95d80f8>.trueBranch") : 0; _this->trueBranch = trueBranch;
    _this->isUntil = isUntil;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Binding* Fast_Binding_list__insert(Fast_Binding_list list) {
    Fast_Binding* result;
    result = cx_calloc(cx_type_sizeof(cx_type(Fast_Binding_o)));
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(Fast_Binding_o), result);
        cx_initValue(&v);
    }
    cx_llInsert(list, result);
    return result;
}

Fast_Binding* Fast_Binding_list__append(Fast_Binding_list list) {
    Fast_Binding* result;
    result = cx_calloc(cx_type_sizeof(cx_type(Fast_Binding_o)));
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(Fast_Binding_o), result);
        cx_initValue(&v);
    }
    cx_llAppend(list, result);
    return result;
}

Fast_Binding* Fast_Binding_list__takeFirst(Fast_Binding_list list) {
    return (Fast_Binding*)cx_llTakeFirst(list);
}

Fast_Binding* Fast_Binding_list__last(Fast_Binding_list list) {
    return (Fast_Binding*)cx_llLast(list);
}

void Fast_Binding_list__clear(Fast_Binding_list list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
        {
            cx_value v;
            cx_valueValueInit(&v, NULL, cx_type(Fast_Binding_o), element);
            cx_deinitValue(&v);
        }
        cx_dealloc(element);
    }
}

Fast_Binding* Fast_Binding_list__get(Fast_Binding_list list, cx_uint32 index) {
    return (Fast_Binding*)cx_llGet(list, index);
}

cx_uint32 Fast_Binding_list__size(Fast_Binding_list list) {
    return cx_llSize(list);
}

void Fast_Expression_list__insert(Fast_Expression_list list, Fast_Expression element) {
    cx_llInsert(list, (void*)element);
}

void Fast_Expression_list__append(Fast_Expression_list list, Fast_Expression element) {
    cx_llAppend(list, (void*)element);
}

Fast_Expression Fast_Expression_list__takeFirst(Fast_Expression_list list) {
    return (Fast_Expression)cx_llTakeFirst(list);
}

Fast_Expression Fast_Expression_list__last(Fast_Expression_list list) {
    return (Fast_Expression)cx_llLast(list);
}

void Fast_Expression_list__clear(Fast_Expression_list list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
        cx_free(element);
    }
}

Fast_Expression Fast_Expression_list__get(Fast_Expression_list list, cx_uint32 index) {
    return (Fast_Expression)cx_llGet(list, index);
}

cx_uint32 Fast_Expression_list__size(Fast_Expression_list list) {
    return cx_llSize(list);
}

Fast_InitOper* Fast_InitOper_list__insert(Fast_InitOper_list list) {
    Fast_InitOper* result;
    result = cx_calloc(cx_type_sizeof(cx_type(Fast_InitOper_o)));
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(Fast_InitOper_o), result);
        cx_initValue(&v);
    }
    cx_llInsert(list, result);
    return result;
}

Fast_InitOper* Fast_InitOper_list__append(Fast_InitOper_list list) {
    Fast_InitOper* result;
    result = cx_calloc(cx_type_sizeof(cx_type(Fast_InitOper_o)));
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(Fast_InitOper_o), result);
        cx_initValue(&v);
    }
    cx_llAppend(list, result);
    return result;
}

Fast_InitOper* Fast_InitOper_list__takeFirst(Fast_InitOper_list list) {
    return (Fast_InitOper*)cx_llTakeFirst(list);
}

Fast_InitOper* Fast_InitOper_list__last(Fast_InitOper_list list) {
    return (Fast_InitOper*)cx_llLast(list);
}

void Fast_InitOper_list__clear(Fast_InitOper_list list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
        {
            cx_value v;
            cx_valueValueInit(&v, NULL, cx_type(Fast_InitOper_o), element);
            cx_deinitValue(&v);
        }
        cx_dealloc(element);
    }
}

Fast_InitOper* Fast_InitOper_list__get(Fast_InitOper_list list, cx_uint32 index) {
    return (Fast_InitOper*)cx_llGet(list, index);
}

cx_uint32 Fast_InitOper_list__size(Fast_InitOper_list list) {
    return cx_llSize(list);
}

void Fast_Local_list__insert(Fast_Local_list list, Fast_Local element) {
    cx_llInsert(list, (void*)element);
}

void Fast_Local_list__append(Fast_Local_list list, Fast_Local element) {
    cx_llAppend(list, (void*)element);
}

Fast_Local Fast_Local_list__takeFirst(Fast_Local_list list) {
    return (Fast_Local)cx_llTakeFirst(list);
}

Fast_Local Fast_Local_list__last(Fast_Local_list list) {
    return (Fast_Local)cx_llLast(list);
}

void Fast_Local_list__clear(Fast_Local_list list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
        cx_free(element);
    }
}

Fast_Local Fast_Local_list__get(Fast_Local_list list, cx_uint32 index) {
    return (Fast_Local)cx_llGet(list, index);
}

cx_uint32 Fast_Local_list__size(Fast_Local_list list) {
    return cx_llSize(list);
}

void Fast_Node_list__insert(Fast_Node_list list, Fast_Node element) {
    cx_llInsert(list, (void*)element);
}

void Fast_Node_list__append(Fast_Node_list list, Fast_Node element) {
    cx_llAppend(list, (void*)element);
}

Fast_Node Fast_Node_list__takeFirst(Fast_Node_list list) {
    return (Fast_Node)cx_llTakeFirst(list);
}

Fast_Node Fast_Node_list__last(Fast_Node_list list) {
    return (Fast_Node)cx_llLast(list);
}

void Fast_Node_list__clear(Fast_Node_list list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
        cx_free(element);
    }
}

Fast_Node Fast_Node_list__get(Fast_Node_list list, cx_uint32 index) {
    return (Fast_Node)cx_llGet(list, index);
}

cx_uint32 Fast_Node_list__size(Fast_Node_list list) {
    return cx_llSize(list);
}

Fast_ParserDeclaration* Fast_ParserDeclarationSeq__append(Fast_ParserDeclarationSeq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(Fast_ParserDeclaration_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(Fast_ParserDeclaration_o), &seq->buffer[seq->length-1]);
        cx_initValue(&v);
    }
    return &seq->buffer[seq->length-1];
}

void Fast_ParserDeclarationSeq__size(Fast_ParserDeclarationSeq *seq, cx_uint32 length) {
    cx_uint32 size;
    if (length < seq->length) {
        cx_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(Fast_ParserDeclaration_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(Fast_ParserDeclaration_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(Fast_ParserDeclaration_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void Fast_ParserDeclarationSeq__clear(Fast_ParserDeclarationSeq *seq) {
    Fast_ParserDeclarationSeq__size(seq, 0);
}

cx_parameter* cx_parameter_seq__append(cx_parameter_seq *seq) {
    cx_uint32 size;
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, seq->length * (size=cx_type_sizeof(cx_type(cx_parameter_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        cx_value v;
        cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &seq->buffer[seq->length-1]);
        cx_initValue(&v);
    }
    return &seq->buffer[seq->length-1];
}

void cx_parameter_seq__size(cx_parameter_seq *seq, cx_uint32 length) {
    cx_uint32 size;
    if (length < seq->length) {
        cx_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->buffer = cx_realloc(seq->buffer, length * (size=cx_type_sizeof(cx_type(cx_parameter_o))));
    if (length > seq->length) {
        cx_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                cx_value v;
                cx_valueValueInit(&v, NULL, cx_type(cx_parameter_o), &seq->buffer[i]);
                cx_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void cx_parameter_seq__clear(cx_parameter_seq *seq) {
    cx_parameter_seq__size(seq, 0);
}

void cx_object_list__insert(cx_object_list list, cx_object element) {
    cx_llInsert(list, (void*)element);
}

void cx_object_list__append(cx_object_list list, cx_object element) {
    cx_llAppend(list, (void*)element);
}

cx_object cx_object_list__takeFirst(cx_object_list list) {
    return (cx_object)cx_llTakeFirst(list);
}

cx_object cx_object_list__last(cx_object_list list) {
    return (cx_object)cx_llLast(list);
}

void cx_object_list__clear(cx_object_list list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
        cx_free(element);
    }
}

cx_object cx_object_list__get(cx_object_list list, cx_uint32 index) {
    return (cx_object)cx_llGet(list, index);
}

cx_uint32 cx_object_list__size(cx_object_list list) {
    return cx_llSize(list);
}

void cx_word_list__insert(cx_word_list list, cx_word element) {
    cx_llInsert(list, (void*)element);
}

void cx_word_list__append(cx_word_list list, cx_word element) {
    cx_llAppend(list, (void*)element);
}

cx_word cx_word_list__takeFirst(cx_word_list list) {
    return (cx_word)cx_llTakeFirst(list);
}

cx_word cx_word_list__last(cx_word_list list) {
    return (cx_word)cx_llLast(list);
}

void cx_word_list__clear(cx_word_list list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

cx_word cx_word_list__get(cx_word_list list, cx_uint32 index) {
    return (cx_word)cx_llGet(list, index);
}

cx_uint32 cx_word_list__size(cx_word_list list) {
    return cx_llSize(list);
}

