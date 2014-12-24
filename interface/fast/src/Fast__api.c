/* Fast__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "Fast__meta.h"
#include "Fast__api.h"

Fast_BinaryExpr Fast_BinaryExpr__new(void) {
    return db_new(db_typedef(Fast_BinaryExpr_o));
}

Fast_BinaryExpr Fast_BinaryExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_BinaryExpr_o));
}

int Fast_BinaryExpr__define(Fast_BinaryExpr _this, Fast_Expression lvalue, Fast_Expression rvalue, db_operatorKind operator) {
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c76390>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? db_keep_ext(_this, rvalue, "element <0x9c76390>.rvalue") : 0; _this->rvalue = rvalue;
    _this->operator = operator;
    return db_define(_this);
}

Fast_BinaryExpr Fast_BinaryExpr__create(Fast_Expression lvalue, Fast_Expression rvalue, db_operatorKind operator) {
    Fast_BinaryExpr _this;
    _this = db_new(db_typedef(Fast_BinaryExpr_o));
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c76390>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? db_keep_ext(_this, rvalue, "element <0x9c76390>.rvalue") : 0; _this->rvalue = rvalue;
    _this->operator = operator;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_Binding__init(Fast_Binding *_this, db_function function, Fast_Block impl) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_Binding_o), _this);
    db_initValue(&v);
    function ? db_keep_ext(_this, function, "element <0x9c7a608>.function") : 0; _this->function = function;
    impl ? db_keep_ext(_this, impl, "element <0x9c7a608>.impl") : 0; _this->impl = impl;
}

void Fast_Binding__deinit(Fast_Binding *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_Binding_o), _this);
    db_deinitValue(&v);
}

Fast_Block Fast_Block__new(void) {
    return db_new(db_typedef(Fast_Block_o));
}

Fast_Block Fast_Block__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Block_o));
}

int Fast_Block__define(Fast_Block _this, Fast_Block parent) {
    parent ? db_keep_ext(_this, parent, "element <0x9c76390>.parent") : 0; _this->parent = parent;
    return db_define(_this);
}

Fast_Block Fast_Block__create(Fast_Block parent) {
    Fast_Block _this;
    _this = db_new(db_typedef(Fast_Block_o));
    parent ? db_keep_ext(_this, parent, "element <0x9c76390>.parent") : 0; _this->parent = parent;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Boolean Fast_Boolean__new(void) {
    return db_new(db_typedef(Fast_Boolean_o));
}

Fast_Boolean Fast_Boolean__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Boolean_o));
}

int Fast_Boolean__define(Fast_Boolean _this, db_bool value) {
    _this->value = value;
    return db_define(_this);
}

Fast_Boolean Fast_Boolean__create(db_bool value) {
    Fast_Boolean _this;
    _this = db_new(db_typedef(Fast_Boolean_o));
    _this->value = value;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Call Fast_Call__new(void) {
    return db_new(db_typedef(Fast_Call_o));
}

Fast_Call Fast_Call__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Call_o));
}

int Fast_Call__define(Fast_Call _this, Fast_Expression function, Fast_Expression arguments) {
    function ? db_keep_ext(_this, function, "element <0x9c76390>.function") : 0; _this->function = function;
    arguments ? db_keep_ext(_this, arguments, "element <0x9c76390>.arguments") : 0; _this->arguments = arguments;
    return db_define(_this);
}

Fast_Call Fast_Call__create(Fast_Expression function, Fast_Expression arguments) {
    Fast_Call _this;
    _this = db_new(db_typedef(Fast_Call_o));
    function ? db_keep_ext(_this, function, "element <0x9c76390>.function") : 0; _this->function = function;
    arguments ? db_keep_ext(_this, arguments, "element <0x9c76390>.arguments") : 0; _this->arguments = arguments;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_CastExpr Fast_CastExpr__new(void) {
    return db_new(db_typedef(Fast_CastExpr_o));
}

Fast_CastExpr Fast_CastExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_CastExpr_o));
}

int Fast_CastExpr__define(Fast_CastExpr _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c75dd0>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? db_keep_ext(_this, rvalue, "element <0x9c75dd0>.rvalue") : 0; _this->rvalue = rvalue;
    return db_define(_this);
}

Fast_CastExpr Fast_CastExpr__create(Fast_Expression lvalue, Fast_Expression rvalue) {
    Fast_CastExpr _this;
    _this = db_new(db_typedef(Fast_CastExpr_o));
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c75dd0>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? db_keep_ext(_this, rvalue, "element <0x9c75dd0>.rvalue") : 0; _this->rvalue = rvalue;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Character Fast_Character__new(void) {
    return db_new(db_typedef(Fast_Character_o));
}

Fast_Character Fast_Character__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Character_o));
}

int Fast_Character__define(Fast_Character _this, db_char value) {
    _this->value = value;
    return db_define(_this);
}

Fast_Character Fast_Character__create(db_char value) {
    Fast_Character _this;
    _this = db_new(db_typedef(Fast_Character_o));
    _this->value = value;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_CommaExpr Fast_CommaExpr__new(void) {
    return db_new(db_typedef(Fast_CommaExpr_o));
}

Fast_CommaExpr Fast_CommaExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_CommaExpr_o));
}

int Fast_CommaExpr__define(Fast_CommaExpr _this) {
    return db_define(_this);
}

Fast_CommaExpr Fast_CommaExpr__create(void) {
    Fast_CommaExpr _this;
    _this = db_new(db_typedef(Fast_CommaExpr_o));
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Define Fast_Define__new(void) {
    return db_new(db_typedef(Fast_Define_o));
}

Fast_Define Fast_Define__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Define_o));
}

int Fast_Define__define(Fast_Define _this, Fast_Expression object) {
    object ? db_keep_ext(_this, object, "element <0x9c5ff38>.object") : 0; _this->object = object;
    return db_define(_this);
}

Fast_Define Fast_Define__create(Fast_Expression object) {
    Fast_Define _this;
    _this = db_new(db_typedef(Fast_Define_o));
    object ? db_keep_ext(_this, object, "element <0x9c5ff38>.object") : 0; _this->object = object;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_DynamicInitializer Fast_DynamicInitializer__new(void) {
    return db_new(db_typedef(Fast_DynamicInitializer_o));
}

Fast_DynamicInitializer Fast_DynamicInitializer__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_DynamicInitializer_o));
}

int Fast_DynamicInitializer__define(Fast_DynamicInitializer _this, Fast_InitializerVariable_array64 variables, db_uint8 variableCount, db_bool assignValue) {
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    _this->assignValue = assignValue;
    return db_define(_this);
}

Fast_DynamicInitializer Fast_DynamicInitializer__create(Fast_InitializerVariable_array64 variables, db_uint8 variableCount, db_bool assignValue) {
    Fast_DynamicInitializer _this;
    _this = db_new(db_typedef(Fast_DynamicInitializer_o));
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    _this->assignValue = assignValue;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_DynamicInitializerFrame__init(Fast_DynamicInitializerFrame *_this, Fast_Expression_array64 expr, Fast_Expression_array64 keyExpr, Fast_Integer sequenceSize) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_DynamicInitializerFrame_o), _this);
    db_initValue(&v);
    memcpy(_this->expr, expr, sizeof(Fast_Expression_array64));
    memcpy(_this->keyExpr, keyExpr, sizeof(Fast_Expression_array64));
    sequenceSize ? db_keep_ext(_this, sequenceSize, "element <0x9c5d800>.sequenceSize") : 0; _this->sequenceSize = sequenceSize;
}

void Fast_DynamicInitializerFrame__deinit(Fast_DynamicInitializerFrame *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_DynamicInitializerFrame_o), _this);
    db_deinitValue(&v);
}

Fast_ElementExpr Fast_ElementExpr__new(void) {
    return db_new(db_typedef(Fast_ElementExpr_o));
}

Fast_ElementExpr Fast_ElementExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_ElementExpr_o));
}

int Fast_ElementExpr__define(Fast_ElementExpr _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c60120>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? db_keep_ext(_this, rvalue, "element <0x9c60120>.rvalue") : 0; _this->rvalue = rvalue;
    return db_define(_this);
}

Fast_ElementExpr Fast_ElementExpr__create(Fast_Expression lvalue, Fast_Expression rvalue) {
    Fast_ElementExpr _this;
    _this = db_new(db_typedef(Fast_ElementExpr_o));
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c60120>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? db_keep_ext(_this, rvalue, "element <0x9c60120>.rvalue") : 0; _this->rvalue = rvalue;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Expression Fast_Expression__new(void) {
    return db_new(db_typedef(Fast_Expression_o));
}

Fast_Expression Fast_Expression__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Expression_o));
}

int Fast_Expression__define(Fast_Expression _this, Fast_nodeKind kind) {
    Fast_Node(_this)->kind = kind;
    return db_define(_this);
}

Fast_Expression Fast_Expression__create(Fast_nodeKind kind) {
    Fast_Expression _this;
    _this = db_new(db_typedef(Fast_Expression_o));
    Fast_Node(_this)->kind = kind;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_FloatingPoint Fast_FloatingPoint__new(void) {
    return db_new(db_typedef(Fast_FloatingPoint_o));
}

Fast_FloatingPoint Fast_FloatingPoint__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_FloatingPoint_o));
}

int Fast_FloatingPoint__define(Fast_FloatingPoint _this, db_float64 value) {
    _this->value = value;
    return db_define(_this);
}

Fast_FloatingPoint Fast_FloatingPoint__create(db_float64 value) {
    Fast_FloatingPoint _this;
    _this = db_new(db_typedef(Fast_FloatingPoint_o));
    _this->value = value;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_If Fast_If__new(void) {
    return db_new(db_typedef(Fast_If_o));
}

Fast_If Fast_If__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_If_o));
}

int Fast_If__define(Fast_If _this, Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch) {
    condition ? db_keep_ext(_this, condition, "element <0x9c60120>.condition") : 0; _this->condition = condition;
    trueBranch ? db_keep_ext(_this, trueBranch, "element <0x9c60120>.trueBranch") : 0; _this->trueBranch = trueBranch;
    falseBranch ? db_keep_ext(_this, falseBranch, "element <0x9c60120>.falseBranch") : 0; _this->falseBranch = falseBranch;
    return db_define(_this);
}

Fast_If Fast_If__create(Fast_Expression condition, Fast_Block trueBranch, Fast_If falseBranch) {
    Fast_If _this;
    _this = db_new(db_typedef(Fast_If_o));
    condition ? db_keep_ext(_this, condition, "element <0x9c60120>.condition") : 0; _this->condition = condition;
    trueBranch ? db_keep_ext(_this, trueBranch, "element <0x9c60120>.trueBranch") : 0; _this->trueBranch = trueBranch;
    falseBranch ? db_keep_ext(_this, falseBranch, "element <0x9c60120>.falseBranch") : 0; _this->falseBranch = falseBranch;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Initializer Fast_Initializer__new(void) {
    return db_new(db_typedef(Fast_Initializer_o));
}

Fast_Initializer Fast_Initializer__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Initializer_o));
}

int Fast_Initializer__define(Fast_Initializer _this, Fast_InitializerVariable_array64 variables, db_uint8 variableCount) {
    memcpy(_this->variables, variables, sizeof(Fast_InitializerVariable_array64));
    _this->variableCount = variableCount;
    return db_define(_this);
}

Fast_Initializer Fast_Initializer__create(Fast_InitializerVariable_array64 variables, db_uint8 variableCount) {
    Fast_Initializer _this;
    _this = db_new(db_typedef(Fast_Initializer_o));
    memcpy(_this->variables, variables, sizeof(Fast_InitializerVariable_array64));
    _this->variableCount = variableCount;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_InitializerExpr Fast_InitializerExpr__new(void) {
    return db_new(db_typedef(Fast_InitializerExpr_o));
}

Fast_InitializerExpr Fast_InitializerExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_InitializerExpr_o));
}

int Fast_InitializerExpr__define(Fast_InitializerExpr _this, Fast_InitializerVariable_array64 variables, db_uint8 variableCount, db_bool assignValue) {
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    _this->assignValue = assignValue;
    return db_define(_this);
}

Fast_InitializerExpr Fast_InitializerExpr__create(Fast_InitializerVariable_array64 variables, db_uint8 variableCount, db_bool assignValue) {
    Fast_InitializerExpr _this;
    _this = db_new(db_typedef(Fast_InitializerExpr_o));
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    _this->assignValue = assignValue;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_InitializerFrame__init(Fast_InitializerFrame *_this, db_uint32 location, db_type type, db_bool isKey, db_member member) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_InitializerFrame_o), _this);
    db_initValue(&v);
    _this->location = location;
    type ? db_keep_ext(_this, type, "element <0x9c77728>.type") : 0; _this->type = type;
    _this->isKey = isKey;
    member ? db_keep_ext(_this, member, "element <0x9c77728>.member") : 0; _this->member = member;
}

void Fast_InitializerFrame__deinit(Fast_InitializerFrame *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_InitializerFrame_o), _this);
    db_deinitValue(&v);
}

void Fast_InitializerVariable__init(Fast_InitializerVariable *_this, db_word offset, Fast_Expression object, db_word key) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_InitializerVariable_o), _this);
    db_initValue(&v);
    _this->offset = offset;
    object ? db_keep_ext(_this, object, "element <0x9c75a98>.object") : 0; _this->object = object;
    _this->key = key;
}

void Fast_InitializerVariable__deinit(Fast_InitializerVariable *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_InitializerVariable_o), _this);
    db_deinitValue(&v);
}

void Fast_InitOper__init(Fast_InitOper *_this, Fast_InitOperKind kind, Fast_Expression expr, db_string name) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_InitOper_o), _this);
    db_initValue(&v);
    _this->kind = kind;
    expr ? db_keep_ext(_this, expr, "element <0x9c75a98>.expr") : 0; _this->expr = expr;
    _this->name = (name ? db_strdup(name) : NULL);
}

void Fast_InitOper__deinit(Fast_InitOper *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_InitOper_o), _this);
    db_deinitValue(&v);
}

Fast_Integer Fast_Integer__new(void) {
    return db_new(db_typedef(Fast_Integer_o));
}

Fast_Integer Fast_Integer__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Integer_o));
}

int Fast_Integer__define(Fast_Integer _this, db_uint64 value) {
    _this->value = value;
    return db_define(_this);
}

Fast_Integer Fast_Integer__create(db_uint64 value) {
    Fast_Integer _this;
    _this = db_new(db_typedef(Fast_Integer_o));
    _this->value = value;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Literal Fast_Literal__new(void) {
    return db_new(db_typedef(Fast_Literal_o));
}

Fast_Literal Fast_Literal__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Literal_o));
}

int Fast_Literal__define(Fast_Literal _this, Fast_valueKind kind_1) {
    _this->kind = kind_1;
    return db_define(_this);
}

Fast_Literal Fast_Literal__create(Fast_valueKind kind_1) {
    Fast_Literal _this;
    _this = db_new(db_typedef(Fast_Literal_o));
    _this->kind = kind_1;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Local Fast_Local__new(void) {
    return db_new(db_typedef(Fast_Local_o));
}

Fast_Local Fast_Local__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Local_o));
}

int Fast_Local__define(Fast_Local _this, db_string name, Fast_Variable type_1, Fast_LocalKind kind_2, db_bool isReference_1) {
    _this->name = (name ? db_strdup(name) : NULL);
    type_1 ? db_keep_ext(_this, type_1, "element <0x9c77438>.type") : 0; _this->type = type_1;
    _this->kind = kind_2;
    _this->isReference = isReference_1;
    return db_define(_this);
}

Fast_Local Fast_Local__create(db_string name, Fast_Variable type_1, Fast_LocalKind kind_2, db_bool isReference_1) {
    Fast_Local _this;
    _this = db_new(db_typedef(Fast_Local_o));
    _this->name = (name ? db_strdup(name) : NULL);
    type_1 ? db_keep_ext(_this, type_1, "element <0x9c77438>.type") : 0; _this->type = type_1;
    _this->kind = kind_2;
    _this->isReference = isReference_1;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_Lvalue__init(Fast_Lvalue *_this, Fast_Expression expr, db_bool isAssignment) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_Lvalue_o), _this);
    db_initValue(&v);
    expr ? db_keep_ext(_this, expr, "element <0x9c75a98>.expr") : 0; _this->expr = expr;
    _this->isAssignment = isAssignment;
}

void Fast_Lvalue__deinit(Fast_Lvalue *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_Lvalue_o), _this);
    db_deinitValue(&v);
}

Fast_MemberExpr Fast_MemberExpr__new(void) {
    return db_new(db_typedef(Fast_MemberExpr_o));
}

Fast_MemberExpr Fast_MemberExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_MemberExpr_o));
}

int Fast_MemberExpr__define(Fast_MemberExpr _this, Fast_Expression lvalue, Fast_Expression rvalue) {
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c5ff28>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? db_keep_ext(_this, rvalue, "element <0x9c5ff28>.rvalue") : 0; _this->rvalue = rvalue;
    return db_define(_this);
}

Fast_MemberExpr Fast_MemberExpr__create(Fast_Expression lvalue, Fast_Expression rvalue) {
    Fast_MemberExpr _this;
    _this = db_new(db_typedef(Fast_MemberExpr_o));
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c5ff28>.lvalue") : 0; _this->lvalue = lvalue;
    rvalue ? db_keep_ext(_this, rvalue, "element <0x9c5ff28>.rvalue") : 0; _this->rvalue = rvalue;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_NewExpr Fast_NewExpr__new(void) {
    return db_new(db_typedef(Fast_NewExpr_o));
}

Fast_NewExpr Fast_NewExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_NewExpr_o));
}

int Fast_NewExpr__define(Fast_NewExpr _this, Fast_Expression type_1, Fast_Expression attributes) {
    type_1 ? db_keep_ext(_this, type_1, "element <0x9c76b20>.type") : 0; _this->type = type_1;
    attributes ? db_keep_ext(_this, attributes, "element <0x9c76b20>.attributes") : 0; _this->attributes = attributes;
    return db_define(_this);
}

Fast_NewExpr Fast_NewExpr__create(Fast_Expression type_1, Fast_Expression attributes) {
    Fast_NewExpr _this;
    _this = db_new(db_typedef(Fast_NewExpr_o));
    type_1 ? db_keep_ext(_this, type_1, "element <0x9c76b20>.type") : 0; _this->type = type_1;
    attributes ? db_keep_ext(_this, attributes, "element <0x9c76b20>.attributes") : 0; _this->attributes = attributes;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Node Fast_Node__new(void) {
    return db_new(db_typedef(Fast_Node_o));
}

Fast_Node Fast_Node__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Node_o));
}

int Fast_Node__define(Fast_Node _this, Fast_nodeKind kind) {
    _this->kind = kind;
    return db_define(_this);
}

Fast_Node Fast_Node__create(Fast_nodeKind kind) {
    Fast_Node _this;
    _this = db_new(db_typedef(Fast_Node_o));
    _this->kind = kind;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Null Fast_Null__new(void) {
    return db_new(db_typedef(Fast_Null_o));
}

Fast_Null Fast_Null__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Null_o));
}

int Fast_Null__define(Fast_Null _this) {
    return db_define(_this);
}

Fast_Null Fast_Null__create(void) {
    Fast_Null _this;
    _this = db_new(db_typedef(Fast_Null_o));
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Object Fast_Object__new(void) {
    return db_new(db_typedef(Fast_Object_o));
}

Fast_Object Fast_Object__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Object_o));
}

int Fast_Object__define(Fast_Object _this, db_object value) {
    value ? db_keep_ext(_this, value, "element <0x9c76b20>.value") : 0; Fast_ObjectBase(_this)->value = value;
    return db_define(_this);
}

Fast_Object Fast_Object__create(db_object value) {
    Fast_Object _this;
    _this = db_new(db_typedef(Fast_Object_o));
    value ? db_keep_ext(_this, value, "element <0x9c76b20>.value") : 0; Fast_ObjectBase(_this)->value = value;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_ObjectBase Fast_ObjectBase__new(void) {
    return db_new(db_typedef(Fast_ObjectBase_o));
}

Fast_ObjectBase Fast_ObjectBase__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_ObjectBase_o));
}

int Fast_ObjectBase__define(Fast_ObjectBase _this, db_object value) {
    value ? db_keep_ext(_this, value, "element <0x9c76b20>.value") : 0; _this->value = value;
    return db_define(_this);
}

Fast_ObjectBase Fast_ObjectBase__create(db_object value) {
    Fast_ObjectBase _this;
    _this = db_new(db_typedef(Fast_ObjectBase_o));
    value ? db_keep_ext(_this, value, "element <0x9c76b20>.value") : 0; _this->value = value;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Parser Fast_Parser__new(void) {
    return db_new(db_typedef(Fast_Parser_o));
}

Fast_Parser Fast_Parser__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Parser_o));
}

int Fast_Parser__define(Fast_Parser _this, db_string source, db_string filename) {
    _this->source = (source ? db_strdup(source) : NULL);
    _this->filename = (filename ? db_strdup(filename) : NULL);
    return db_define(_this);
}

Fast_Parser Fast_Parser__create(db_string source, db_string filename) {
    Fast_Parser _this;
    _this = db_new(db_typedef(Fast_Parser_o));
    _this->source = (source ? db_strdup(source) : NULL);
    _this->filename = (filename ? db_strdup(filename) : NULL);
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_Parser_stagedId__init(Fast_Parser_stagedId *_this, db_string name, db_bool found, db_uint32 line, db_uint32 column) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_Parser_stagedId_o), _this);
    db_initValue(&v);
    _this->name = (name ? db_strdup(name) : NULL);
    _this->found = found;
    _this->line = line;
    _this->column = column;
}

void Fast_Parser_stagedId__deinit(Fast_Parser_stagedId *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_Parser_stagedId_o), _this);
    db_deinitValue(&v);
}

void Fast_ParserDeclaration__init(Fast_ParserDeclaration *_this, db_string name, Fast_Variable variable) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_ParserDeclaration_o), _this);
    db_initValue(&v);
    _this->name = (name ? db_strdup(name) : NULL);
    variable ? db_keep_ext(_this, variable, "element <0x9c5ff28>.variable") : 0; _this->variable = variable;
}

void Fast_ParserDeclaration__deinit(Fast_ParserDeclaration *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_ParserDeclaration_o), _this);
    db_deinitValue(&v);
}

void Fast_ParserNew__init(Fast_ParserNew *_this, Fast_nodeKind kind, Fast_Expression parent, Fast_Expression name, Fast_Expression attr) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_ParserNew_o), _this);
    db_initValue(&v);
    _this->kind = kind;
    parent ? db_keep_ext(_this, parent, "element <0x9c76390>.parent") : 0; _this->parent = parent;
    name ? db_keep_ext(_this, name, "element <0x9c76390>.name") : 0; _this->name = name;
    attr ? db_keep_ext(_this, attr, "element <0x9c76390>.attr") : 0; _this->attr = attr;
}

void Fast_ParserNew__deinit(Fast_ParserNew *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_ParserNew_o), _this);
    db_deinitValue(&v);
}

Fast_PostfixExpr Fast_PostfixExpr__new(void) {
    return db_new(db_typedef(Fast_PostfixExpr_o));
}

Fast_PostfixExpr Fast_PostfixExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_PostfixExpr_o));
}

int Fast_PostfixExpr__define(Fast_PostfixExpr _this, Fast_Expression lvalue, db_operatorKind operator) {
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c5ff48>.lvalue") : 0; _this->lvalue = lvalue;
    _this->operator = operator;
    return db_define(_this);
}

Fast_PostfixExpr Fast_PostfixExpr__create(Fast_Expression lvalue, db_operatorKind operator) {
    Fast_PostfixExpr _this;
    _this = db_new(db_typedef(Fast_PostfixExpr_o));
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c5ff48>.lvalue") : 0; _this->lvalue = lvalue;
    _this->operator = operator;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_SignedInteger Fast_SignedInteger__new(void) {
    return db_new(db_typedef(Fast_SignedInteger_o));
}

Fast_SignedInteger Fast_SignedInteger__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_SignedInteger_o));
}

int Fast_SignedInteger__define(Fast_SignedInteger _this, db_int64 value) {
    _this->value = value;
    return db_define(_this);
}

Fast_SignedInteger Fast_SignedInteger__create(db_int64 value) {
    Fast_SignedInteger _this;
    _this = db_new(db_typedef(Fast_SignedInteger_o));
    _this->value = value;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_StaticInitializer Fast_StaticInitializer__new(void) {
    return db_new(db_typedef(Fast_StaticInitializer_o));
}

Fast_StaticInitializer Fast_StaticInitializer__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_StaticInitializer_o));
}

int Fast_StaticInitializer__define(Fast_StaticInitializer _this, Fast_InitializerVariable_array64 variables, db_uint8 variableCount) {
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    return db_define(_this);
}

Fast_StaticInitializer Fast_StaticInitializer__create(Fast_InitializerVariable_array64 variables, db_uint8 variableCount) {
    Fast_StaticInitializer _this;
    _this = db_new(db_typedef(Fast_StaticInitializer_o));
    memcpy(Fast_Initializer(_this)->variables, variables, sizeof(Fast_InitializerVariable_array64));
    Fast_Initializer(_this)->variableCount = variableCount;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

void Fast_StaticInitializerFrame__init(Fast_StaticInitializerFrame *_this, db_word_array64 ptr, db_word_array64 keyPtr) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_StaticInitializerFrame_o), _this);
    db_initValue(&v);
    memcpy(_this->ptr, ptr, sizeof(db_word_array64));
    memcpy(_this->keyPtr, keyPtr, sizeof(db_word_array64));
}

void Fast_StaticInitializerFrame__deinit(Fast_StaticInitializerFrame *_this) {
    db_value v;
    db_valueValueInit(&v, NULL, db_typedef(Fast_StaticInitializerFrame_o), _this);
    db_deinitValue(&v);
}

Fast_String Fast_String__new(void) {
    return db_new(db_typedef(Fast_String_o));
}

Fast_String Fast_String__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_String_o));
}

int Fast_String__define(Fast_String _this, db_string value) {
    _this->value = (value ? db_strdup(value) : NULL);
    return db_define(_this);
}

Fast_String Fast_String__create(db_string value) {
    Fast_String _this;
    _this = db_new(db_typedef(Fast_String_o));
    _this->value = (value ? db_strdup(value) : NULL);
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Template Fast_Template__new(void) {
    return db_new(db_typedef(Fast_Template_o));
}

Fast_Template Fast_Template__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Template_o));
}

int Fast_Template__define(Fast_Template _this, db_string name, Fast_Variable type_1, Fast_LocalKind kind_2, db_bool isReference_1) {
    Fast_Local(_this)->name = (name ? db_strdup(name) : NULL);
    type_1 ? db_keep_ext(_this, type_1, "element <0x9c77728>.type") : 0; Fast_Local(_this)->type = type_1;
    Fast_Local(_this)->kind = kind_2;
    Fast_Local(_this)->isReference = isReference_1;
    return db_define(_this);
}

Fast_Template Fast_Template__create(db_string name, Fast_Variable type_1, Fast_LocalKind kind_2, db_bool isReference_1) {
    Fast_Template _this;
    _this = db_new(db_typedef(Fast_Template_o));
    Fast_Local(_this)->name = (name ? db_strdup(name) : NULL);
    type_1 ? db_keep_ext(_this, type_1, "element <0x9c77728>.type") : 0; Fast_Local(_this)->type = type_1;
    Fast_Local(_this)->kind = kind_2;
    Fast_Local(_this)->isReference = isReference_1;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_TernaryExpr Fast_TernaryExpr__new(void) {
    return db_new(db_typedef(Fast_TernaryExpr_o));
}

Fast_TernaryExpr Fast_TernaryExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_TernaryExpr_o));
}

int Fast_TernaryExpr__define(Fast_TernaryExpr _this, Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result) {
    condition ? db_keep_ext(_this, condition, "element <0x9c78938>.condition") : 0; _this->condition = condition;
    ifTrue ? db_keep_ext(_this, ifTrue, "element <0x9c78938>.ifTrue") : 0; _this->ifTrue = ifTrue;
    ifFalse ? db_keep_ext(_this, ifFalse, "element <0x9c78938>.ifFalse") : 0; _this->ifFalse = ifFalse;
    result ? db_keep_ext(_this, result, "element <0x9c78938>.result") : 0; _this->result = result;
    return db_define(_this);
}

Fast_TernaryExpr Fast_TernaryExpr__create(Fast_Expression condition, Fast_Expression ifTrue, Fast_Expression ifFalse, Fast_Expression result) {
    Fast_TernaryExpr _this;
    _this = db_new(db_typedef(Fast_TernaryExpr_o));
    condition ? db_keep_ext(_this, condition, "element <0x9c78938>.condition") : 0; _this->condition = condition;
    ifTrue ? db_keep_ext(_this, ifTrue, "element <0x9c78938>.ifTrue") : 0; _this->ifTrue = ifTrue;
    ifFalse ? db_keep_ext(_this, ifFalse, "element <0x9c78938>.ifFalse") : 0; _this->ifFalse = ifFalse;
    result ? db_keep_ext(_this, result, "element <0x9c78938>.result") : 0; _this->result = result;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_UnaryExpr Fast_UnaryExpr__new(void) {
    return db_new(db_typedef(Fast_UnaryExpr_o));
}

Fast_UnaryExpr Fast_UnaryExpr__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_UnaryExpr_o));
}

int Fast_UnaryExpr__define(Fast_UnaryExpr _this, Fast_Expression lvalue, db_operatorKind operator) {
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c75dd0>.lvalue") : 0; _this->lvalue = lvalue;
    _this->operator = operator;
    return db_define(_this);
}

Fast_UnaryExpr Fast_UnaryExpr__create(Fast_Expression lvalue, db_operatorKind operator) {
    Fast_UnaryExpr _this;
    _this = db_new(db_typedef(Fast_UnaryExpr_o));
    lvalue ? db_keep_ext(_this, lvalue, "element <0x9c75dd0>.lvalue") : 0; _this->lvalue = lvalue;
    _this->operator = operator;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Update Fast_Update__new(void) {
    return db_new(db_typedef(Fast_Update_o));
}

Fast_Update Fast_Update__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Update_o));
}

int Fast_Update__define(Fast_Update _this, Fast_Expression_list exprList, Fast_Block block, Fast_Expression from) {
    _this->exprList = exprList;
    block ? db_keep_ext(_this, block, "element <0x9c75dd0>.block") : 0; _this->block = block;
    from ? db_keep_ext(_this, from, "element <0x9c75dd0>.from") : 0; _this->from = from;
    return db_define(_this);
}

Fast_Update Fast_Update__create(Fast_Expression_list exprList, Fast_Block block, Fast_Expression from) {
    Fast_Update _this;
    _this = db_new(db_typedef(Fast_Update_o));
    _this->exprList = exprList;
    block ? db_keep_ext(_this, block, "element <0x9c75dd0>.block") : 0; _this->block = block;
    from ? db_keep_ext(_this, from, "element <0x9c75dd0>.from") : 0; _this->from = from;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Variable Fast_Variable__new(void) {
    return db_new(db_typedef(Fast_Variable_o));
}

Fast_Variable Fast_Variable__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Variable_o));
}

int Fast_Variable__define(Fast_Variable _this, Fast_variableKind kind_1) {
    _this->kind = kind_1;
    return db_define(_this);
}

Fast_Variable Fast_Variable__create(Fast_variableKind kind_1) {
    Fast_Variable _this;
    _this = db_new(db_typedef(Fast_Variable_o));
    _this->kind = kind_1;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Wait Fast_Wait__new(void) {
    return db_new(db_typedef(Fast_Wait_o));
}

Fast_Wait Fast_Wait__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_Wait_o));
}

int Fast_Wait__define(Fast_Wait _this, Fast_Expression_list exprList, Fast_Expression timeout) {
    _this->exprList = exprList;
    timeout ? db_keep_ext(_this, timeout, "element <0x9c75dd0>.timeout") : 0; _this->timeout = timeout;
    return db_define(_this);
}

Fast_Wait Fast_Wait__create(Fast_Expression_list exprList, Fast_Expression timeout) {
    Fast_Wait _this;
    _this = db_new(db_typedef(Fast_Wait_o));
    _this->exprList = exprList;
    timeout ? db_keep_ext(_this, timeout, "element <0x9c75dd0>.timeout") : 0; _this->timeout = timeout;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_While Fast_While__new(void) {
    return db_new(db_typedef(Fast_While_o));
}

Fast_While Fast_While__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Fast_While_o));
}

int Fast_While__define(Fast_While _this, Fast_Expression condition, Fast_Block trueBranch, db_bool isUntil) {
    condition ? db_keep_ext(_this, condition, "element <0x9c75dd0>.condition") : 0; _this->condition = condition;
    trueBranch ? db_keep_ext(_this, trueBranch, "element <0x9c75dd0>.trueBranch") : 0; _this->trueBranch = trueBranch;
    _this->isUntil = isUntil;
    return db_define(_this);
}

Fast_While Fast_While__create(Fast_Expression condition, Fast_Block trueBranch, db_bool isUntil) {
    Fast_While _this;
    _this = db_new(db_typedef(Fast_While_o));
    condition ? db_keep_ext(_this, condition, "element <0x9c75dd0>.condition") : 0; _this->condition = condition;
    trueBranch ? db_keep_ext(_this, trueBranch, "element <0x9c75dd0>.trueBranch") : 0; _this->trueBranch = trueBranch;
    _this->isUntil = isUntil;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

Fast_Binding* Fast_Binding_list__insert(Fast_Binding_list list) {
    Fast_Binding* result;
    result = db_calloc(db_type_sizeof(db_type(Fast_Binding_o)));
    {
        db_value v;
        db_valueValueInit(&v, NULL, db_typedef(Fast_Binding_o), result);
        db_initValue(&v);
    }
    db_llInsert(list, result);
    return result;
}

Fast_Binding* Fast_Binding_list__append(Fast_Binding_list list) {
    Fast_Binding* result;
    result = db_calloc(db_type_sizeof(db_type(Fast_Binding_o)));
    {
        db_value v;
        db_valueValueInit(&v, NULL, db_typedef(Fast_Binding_o), result);
        db_initValue(&v);
    }
    db_llAppend(list, result);
    return result;
}

Fast_Binding* Fast_Binding_list__takeFirst(Fast_Binding_list list) {
    return (Fast_Binding*)db_llTakeFirst(list);
}

Fast_Binding* Fast_Binding_list__last(Fast_Binding_list list) {
    return (Fast_Binding*)db_llLast(list);
}

void Fast_Binding_list__clear(Fast_Binding_list list) {
    void *element;

    while((element = db_llTakeFirst(list))) {
        {
            db_value v;
            db_valueValueInit(&v, NULL, db_typedef(Fast_Binding_o), element);
            db_deinitValue(&v);
        }
        db_dealloc(element);
    }
}

Fast_Binding* Fast_Binding_list__get(Fast_Binding_list list, db_uint32 index) {
    return (Fast_Binding*)db_llGet(list, index);
}

db_uint32 Fast_Binding_list__size(Fast_Binding_list list) {
    return db_llSize(list);
}

void Fast_Expression_list__insert(Fast_Expression_list list, Fast_Expression element) {
    db_llInsert(list, (void*)element);
}

void Fast_Expression_list__append(Fast_Expression_list list, Fast_Expression element) {
    db_llAppend(list, (void*)element);
}

Fast_Expression Fast_Expression_list__takeFirst(Fast_Expression_list list) {
    return (Fast_Expression)db_llTakeFirst(list);
}

Fast_Expression Fast_Expression_list__last(Fast_Expression_list list) {
    return (Fast_Expression)db_llLast(list);
}

void Fast_Expression_list__clear(Fast_Expression_list list) {
    void *element;

    while((element = db_llTakeFirst(list))) {
        db_free(element);
    }
}

Fast_Expression Fast_Expression_list__get(Fast_Expression_list list, db_uint32 index) {
    return (Fast_Expression)db_llGet(list, index);
}

db_uint32 Fast_Expression_list__size(Fast_Expression_list list) {
    return db_llSize(list);
}

Fast_InitOper* Fast_InitOper_list__insert(Fast_InitOper_list list) {
    Fast_InitOper* result;
    result = db_calloc(db_type_sizeof(db_type(Fast_InitOper_o)));
    {
        db_value v;
        db_valueValueInit(&v, NULL, db_typedef(Fast_InitOper_o), result);
        db_initValue(&v);
    }
    db_llInsert(list, result);
    return result;
}

Fast_InitOper* Fast_InitOper_list__append(Fast_InitOper_list list) {
    Fast_InitOper* result;
    result = db_calloc(db_type_sizeof(db_type(Fast_InitOper_o)));
    {
        db_value v;
        db_valueValueInit(&v, NULL, db_typedef(Fast_InitOper_o), result);
        db_initValue(&v);
    }
    db_llAppend(list, result);
    return result;
}

Fast_InitOper* Fast_InitOper_list__takeFirst(Fast_InitOper_list list) {
    return (Fast_InitOper*)db_llTakeFirst(list);
}

Fast_InitOper* Fast_InitOper_list__last(Fast_InitOper_list list) {
    return (Fast_InitOper*)db_llLast(list);
}

void Fast_InitOper_list__clear(Fast_InitOper_list list) {
    void *element;

    while((element = db_llTakeFirst(list))) {
        {
            db_value v;
            db_valueValueInit(&v, NULL, db_typedef(Fast_InitOper_o), element);
            db_deinitValue(&v);
        }
        db_dealloc(element);
    }
}

Fast_InitOper* Fast_InitOper_list__get(Fast_InitOper_list list, db_uint32 index) {
    return (Fast_InitOper*)db_llGet(list, index);
}

db_uint32 Fast_InitOper_list__size(Fast_InitOper_list list) {
    return db_llSize(list);
}

void Fast_Local_list__insert(Fast_Local_list list, Fast_Local element) {
    db_llInsert(list, (void*)element);
}

void Fast_Local_list__append(Fast_Local_list list, Fast_Local element) {
    db_llAppend(list, (void*)element);
}

Fast_Local Fast_Local_list__takeFirst(Fast_Local_list list) {
    return (Fast_Local)db_llTakeFirst(list);
}

Fast_Local Fast_Local_list__last(Fast_Local_list list) {
    return (Fast_Local)db_llLast(list);
}

void Fast_Local_list__clear(Fast_Local_list list) {
    void *element;

    while((element = db_llTakeFirst(list))) {
        db_free(element);
    }
}

Fast_Local Fast_Local_list__get(Fast_Local_list list, db_uint32 index) {
    return (Fast_Local)db_llGet(list, index);
}

db_uint32 Fast_Local_list__size(Fast_Local_list list) {
    return db_llSize(list);
}

void Fast_Node_list__insert(Fast_Node_list list, Fast_Node element) {
    db_llInsert(list, (void*)element);
}

void Fast_Node_list__append(Fast_Node_list list, Fast_Node element) {
    db_llAppend(list, (void*)element);
}

Fast_Node Fast_Node_list__takeFirst(Fast_Node_list list) {
    return (Fast_Node)db_llTakeFirst(list);
}

Fast_Node Fast_Node_list__last(Fast_Node_list list) {
    return (Fast_Node)db_llLast(list);
}

void Fast_Node_list__clear(Fast_Node_list list) {
    void *element;

    while((element = db_llTakeFirst(list))) {
        db_free(element);
    }
}

Fast_Node Fast_Node_list__get(Fast_Node_list list, db_uint32 index) {
    return (Fast_Node)db_llGet(list, index);
}

db_uint32 Fast_Node_list__size(Fast_Node_list list) {
    return db_llSize(list);
}

void Fast_Object_list__insert(Fast_Object_list list, Fast_Object element) {
    db_llInsert(list, (void*)element);
}

void Fast_Object_list__append(Fast_Object_list list, Fast_Object element) {
    db_llAppend(list, (void*)element);
}

Fast_Object Fast_Object_list__takeFirst(Fast_Object_list list) {
    return (Fast_Object)db_llTakeFirst(list);
}

Fast_Object Fast_Object_list__last(Fast_Object_list list) {
    return (Fast_Object)db_llLast(list);
}

void Fast_Object_list__clear(Fast_Object_list list) {
    void *element;

    while((element = db_llTakeFirst(list))) {
        db_free(element);
    }
}

Fast_Object Fast_Object_list__get(Fast_Object_list list, db_uint32 index) {
    return (Fast_Object)db_llGet(list, index);
}

db_uint32 Fast_Object_list__size(Fast_Object_list list) {
    return db_llSize(list);
}

Fast_ParserDeclaration* Fast_ParserDeclaration_seq256__append(Fast_ParserDeclaration_seq256 *seq) {
    db_uint32 size;
    seq->length++;
    seq->buffer = db_realloc(seq->buffer, seq->length * (size=db_type_sizeof(db_type(Fast_ParserDeclaration_o))));
    memset(&seq->buffer[seq->length-1], 0, size);
    {
        db_value v;
        db_valueValueInit(&v, NULL, db_typedef(Fast_ParserDeclaration_o), &seq->buffer[seq->length-1]);
        db_initValue(&v);
    }
    return &seq->buffer[seq->length-1];
}

void Fast_ParserDeclaration_seq256__size(Fast_ParserDeclaration_seq256 *seq, db_uint32 length) {
    db_uint32 size;
    if (length < seq->length) {
        db_uint32 i;
        for(i=length; i<seq->length; i++) {
            {
                db_value v;
                db_valueValueInit(&v, NULL, db_typedef(Fast_ParserDeclaration_o), &seq->buffer[i]);
                db_deinitValue(&v);
            }
        }
    }
    seq->buffer = db_realloc(seq->buffer, length * (size=db_type_sizeof(db_type(Fast_ParserDeclaration_o))));
    if (length > seq->length) {
        db_uint32 i;
        memset(&seq->buffer[seq->length], 0, size * (length - seq->length));
        for(i=seq->length; i<length; i++) {
            {
                db_value v;
                db_valueValueInit(&v, NULL, db_typedef(Fast_ParserDeclaration_o), &seq->buffer[i]);
                db_deinitValue(&v);
            }
        }
    }
    seq->length = length;
}

void Fast_ParserDeclaration_seq256__clear(Fast_ParserDeclaration_seq256 *seq) {
    Fast_ParserDeclaration_seq256__size(seq, 0);
}

void db_word_list__insert(db_word_list list, db_word element) {
    db_llInsert(list, (void*)element);
}

void db_word_list__append(db_word_list list, db_word element) {
    db_llAppend(list, (void*)element);
}

db_word db_word_list__takeFirst(db_word_list list) {
    return (db_word)db_llTakeFirst(list);
}

db_word db_word_list__last(db_word_list list) {
    return (db_word)db_llLast(list);
}

void db_word_list__clear(db_word_list list) {
    void *element;

    while((element = db_llTakeFirst(list))) {
    }
}

db_word db_word_list__get(db_word_list list, db_uint32 index) {
    return (db_word)db_llGet(list, index);
}

db_uint32 db_word_list__size(db_word_list list) {
    return db_llSize(list);
}

