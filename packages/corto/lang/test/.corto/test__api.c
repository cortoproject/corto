/* test__api.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include "test.h"

test_Animal _test_AnimalCreate(corto_bool a) {
    test_Animal this;
    this = corto_declare(test_Animal_o);
    if (!this) {
        return NULL;
    }
    this->a = a;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Animal _test_AnimalCreateChild(corto_object _parent, corto_string _name, corto_bool a) {
    test_Animal this;
    this = corto_declareChild(_parent, _name, test_Animal_o);
    if (!this) {
        return NULL;
    }
    this->a = a;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_AnimalUpdate(test_Animal this, corto_bool a) {
    if (!corto_updateBegin(this)) {
        this->a = a;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Animal _test_AnimalDeclare(void) {
    test_Animal this;
    this = corto_declare(test_Animal_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Animal _test_AnimalDeclareChild(corto_object _parent, corto_string _name) {
    test_Animal this;
    this = corto_declareChild(_parent, _name, test_Animal_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_AnimalDefine(test_Animal this, corto_bool a) {
    this->a = a;
    return corto_define(this);
}

void _test_AnimalSet(test_Animal this, corto_bool a) {
    this->a = a;
}

corto_string _test_AnimalStr(test_Animal value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Animal_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Animal test_AnimalFromStr(test_Animal value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Animal_o), str);
    return value;
}

corto_int16 _test_AnimalCopy(test_Animal *dst, test_Animal src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_AnimalCompare(test_Animal dst, test_Animal src) {
    return corto_compare(dst, src);
}

test_AnonymousTest _test_AnonymousTestCreate(corto_objectList objects) {
    test_AnonymousTest this;
    this = corto_declare(test_AnonymousTest_o);
    if (!this) {
        return NULL;
    }
    this->objects = objects;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_AnonymousTest _test_AnonymousTestCreateChild(corto_object _parent, corto_string _name, corto_objectList objects) {
    test_AnonymousTest this;
    this = corto_declareChild(_parent, _name, test_AnonymousTest_o);
    if (!this) {
        return NULL;
    }
    this->objects = objects;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_AnonymousTestUpdate(test_AnonymousTest this, corto_objectList objects) {
    if (!corto_updateBegin(this)) {
        this->objects = objects;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_AnonymousTest _test_AnonymousTestDeclare(void) {
    test_AnonymousTest this;
    this = corto_declare(test_AnonymousTest_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_AnonymousTest _test_AnonymousTestDeclareChild(corto_object _parent, corto_string _name) {
    test_AnonymousTest this;
    this = corto_declareChild(_parent, _name, test_AnonymousTest_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_AnonymousTestDefine(test_AnonymousTest this, corto_objectList objects) {
    this->objects = objects;
    return corto_define(this);
}

void _test_AnonymousTestSet(test_AnonymousTest this, corto_objectList objects) {
    this->objects = objects;
}

corto_string _test_AnonymousTestStr(test_AnonymousTest value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_AnonymousTest_o));
    result = corto_strv(&v, 0);
    return result;
}

test_AnonymousTest test_AnonymousTestFromStr(test_AnonymousTest value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_AnonymousTest_o), str);
    return value;
}

corto_int16 _test_AnonymousTestCopy(test_AnonymousTest *dst, test_AnonymousTest src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_AnonymousTestCompare(test_AnonymousTest dst, test_AnonymousTest src) {
    return corto_compare(dst, src);
}

test_Args _test_ArgsCreate(test_Case test, corto_uint32 assertCount) {
    test_Args this;
    this = corto_declare(test_Args_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Args _test_ArgsCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_Args this;
    this = corto_declareChild(_parent, _name, test_Args_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_ArgsUpdate(test_Args this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Args _test_ArgsDeclare(void) {
    test_Args this;
    this = corto_declare(test_Args_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Args _test_ArgsDeclareChild(corto_object _parent, corto_string _name) {
    test_Args this;
    this = corto_declareChild(_parent, _name, test_Args_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_ArgsDefine(test_Args this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_ArgsSet(test_Args this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_ArgsStr(test_Args value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Args_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Args test_ArgsFromStr(test_Args value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Args_o), str);
    return value;
}

corto_int16 _test_ArgsCopy(test_Args *dst, test_Args src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_ArgsCompare(test_Args dst, test_Args src) {
    return corto_compare(dst, src);
}

test_Bar _test_BarCreate(void) {
    test_Bar this;
    this = corto_declare(test_Bar_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Bar _test_BarCreateChild(corto_object _parent, corto_string _name) {
    test_Bar this;
    this = corto_declareChild(_parent, _name, test_Bar_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_BarUpdate(test_Bar this) {
    if (!corto_updateBegin(this)) {
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Bar _test_BarDeclare(void) {
    test_Bar this;
    this = corto_declare(test_Bar_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Bar _test_BarDeclareChild(corto_object _parent, corto_string _name) {
    test_Bar this;
    this = corto_declareChild(_parent, _name, test_Bar_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_BarDefine(test_Bar this) {
    return corto_define(this);
}

void _test_BarSet(test_Bar this) {
    CORTO_UNUSED(this);
}

corto_string _test_BarStr(test_Bar value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Bar_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Bar test_BarFromStr(test_Bar value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Bar_o), str);
    return value;
}

corto_int16 _test_BarCopy(test_Bar *dst, test_Bar src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_BarCompare(test_Bar dst, test_Bar src) {
    return corto_compare(dst, src);
}

test_Cat _test_CatCreate(corto_bool a, corto_bool b) {
    test_Cat this;
    this = corto_declare(test_Cat_o);
    if (!this) {
        return NULL;
    }
    test_Animal(this)->a = a;
    this->b = b;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Cat _test_CatCreateChild(corto_object _parent, corto_string _name, corto_bool a, corto_bool b) {
    test_Cat this;
    this = corto_declareChild(_parent, _name, test_Cat_o);
    if (!this) {
        return NULL;
    }
    test_Animal(this)->a = a;
    this->b = b;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_CatUpdate(test_Cat this, corto_bool a, corto_bool b) {
    if (!corto_updateBegin(this)) {
        test_Animal(this)->a = a;
        this->b = b;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Cat _test_CatDeclare(void) {
    test_Cat this;
    this = corto_declare(test_Cat_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Cat _test_CatDeclareChild(corto_object _parent, corto_string _name) {
    test_Cat this;
    this = corto_declareChild(_parent, _name, test_Cat_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_CatDefine(test_Cat this, corto_bool a, corto_bool b) {
    test_Animal(this)->a = a;
    this->b = b;
    return corto_define(this);
}

void _test_CatSet(test_Cat this, corto_bool a, corto_bool b) {
    test_Animal(this)->a = a;
    this->b = b;
}

corto_string _test_CatStr(test_Cat value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Cat_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Cat test_CatFromStr(test_Cat value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Cat_o), str);
    return value;
}

corto_int16 _test_CatCopy(test_Cat *dst, test_Cat src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_CatCompare(test_Cat dst, test_Cat src) {
    return corto_compare(dst, src);
}

test_Color* _test_ColorCreate(test_Color value) {
    test_Color* this;
    this = corto_declare(test_Color_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Color* _test_ColorCreateChild(corto_object _parent, corto_string _name, test_Color value) {
    test_Color* this;
    this = corto_declareChild(_parent, _name, test_Color_o);
    if (!this) {
        return NULL;
    }
    *this = value;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_ColorUpdate(test_Color* this, test_Color value) {
    if (!corto_updateBegin(this)) {
        *this = value;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Color* _test_ColorDeclare(void) {
    test_Color* this;
    this = corto_declare(test_Color_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Color* _test_ColorDeclareChild(corto_object _parent, corto_string _name) {
    test_Color* this;
    this = corto_declareChild(_parent, _name, test_Color_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_ColorDefine(test_Color* this, test_Color value) {
    *this = value;
    return corto_define(this);
}

void _test_ColorSet(test_Color* this, test_Color value) {
    *this = value;
}

corto_string _test_ColorStr(test_Color value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Color_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_Color* test_ColorFromStr(test_Color* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Color_o), str);
    return value;
}

corto_int16 _test_ColorCopy(test_Color* *dst, test_Color* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_Color_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_Color_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_ColorCompare(test_Color* dst, test_Color* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_Color_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_Color_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_ColorInit(test_Color* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_Color_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Color_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_ColorDeinit(test_Color* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Color_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_CompositeCollection* _test_CompositeCollectionCreate(test_PointList points) {
    test_CompositeCollection* this;
    this = corto_declare(test_CompositeCollection_o);
    if (!this) {
        return NULL;
    }
    this->points = points;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_CompositeCollection* _test_CompositeCollectionCreateChild(corto_object _parent, corto_string _name, test_PointList points) {
    test_CompositeCollection* this;
    this = corto_declareChild(_parent, _name, test_CompositeCollection_o);
    if (!this) {
        return NULL;
    }
    this->points = points;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_CompositeCollectionUpdate(test_CompositeCollection* this, test_PointList points) {
    if (!corto_updateBegin(this)) {
        this->points = points;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_CompositeCollection* _test_CompositeCollectionDeclare(void) {
    test_CompositeCollection* this;
    this = corto_declare(test_CompositeCollection_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_CompositeCollection* _test_CompositeCollectionDeclareChild(corto_object _parent, corto_string _name) {
    test_CompositeCollection* this;
    this = corto_declareChild(_parent, _name, test_CompositeCollection_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_CompositeCollectionDefine(test_CompositeCollection* this, test_PointList points) {
    this->points = points;
    return corto_define(this);
}

void _test_CompositeCollectionSet(test_CompositeCollection* this, test_PointList points) {
    this->points = points;
}

corto_string _test_CompositeCollectionStr(test_CompositeCollection* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_CompositeCollection_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_CompositeCollection* test_CompositeCollectionFromStr(test_CompositeCollection* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_CompositeCollection_o), str);
    return value;
}

corto_int16 _test_CompositeCollectionCopy(test_CompositeCollection* *dst, test_CompositeCollection* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_CompositeCollection_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_CompositeCollection_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_CompositeCollectionCompare(test_CompositeCollection* dst, test_CompositeCollection* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_CompositeCollection_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_CompositeCollection_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_CompositeCollectionInit(test_CompositeCollection* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_CompositeCollection_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_CompositeCollection_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_CompositeCollectionDeinit(test_CompositeCollection* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_CompositeCollection_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_DeclaredParent* _test_DeclaredParentCreate(corto_int32 Foo) {
    test_DeclaredParent* this;
    this = corto_declare(test_DeclaredParent_o);
    if (!this) {
        return NULL;
    }
    this->Foo = Foo;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_DeclaredParent* _test_DeclaredParentCreateChild(corto_object _parent, corto_string _name, corto_int32 Foo) {
    test_DeclaredParent* this;
    this = corto_declareChild(_parent, _name, test_DeclaredParent_o);
    if (!this) {
        return NULL;
    }
    this->Foo = Foo;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_DeclaredParentUpdate(test_DeclaredParent* this, corto_int32 Foo) {
    if (!corto_updateBegin(this)) {
        this->Foo = Foo;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_DeclaredParent* _test_DeclaredParentDeclare(void) {
    test_DeclaredParent* this;
    this = corto_declare(test_DeclaredParent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_DeclaredParent* _test_DeclaredParentDeclareChild(corto_object _parent, corto_string _name) {
    test_DeclaredParent* this;
    this = corto_declareChild(_parent, _name, test_DeclaredParent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_DeclaredParentDefine(test_DeclaredParent* this, corto_int32 Foo) {
    this->Foo = Foo;
    return corto_define(this);
}

void _test_DeclaredParentSet(test_DeclaredParent* this, corto_int32 Foo) {
    this->Foo = Foo;
}

corto_string _test_DeclaredParentStr(test_DeclaredParent* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_DeclaredParent_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_DeclaredParent* test_DeclaredParentFromStr(test_DeclaredParent* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_DeclaredParent_o), str);
    return value;
}

corto_int16 _test_DeclaredParentCopy(test_DeclaredParent* *dst, test_DeclaredParent* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_DeclaredParent_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_DeclaredParent_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_DeclaredParentCompare(test_DeclaredParent* dst, test_DeclaredParent* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_DeclaredParent_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_DeclaredParent_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_DeclaredParentInit(test_DeclaredParent* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_DeclaredParent_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_DeclaredParent_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_DeclaredParentDeinit(test_DeclaredParent* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_DeclaredParent_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_DefinedParent* _test_DefinedParentCreate(corto_int32 Foo) {
    test_DefinedParent* this;
    this = corto_declare(test_DefinedParent_o);
    if (!this) {
        return NULL;
    }
    this->Foo = Foo;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_DefinedParent* _test_DefinedParentCreateChild(corto_object _parent, corto_string _name, corto_int32 Foo) {
    test_DefinedParent* this;
    this = corto_declareChild(_parent, _name, test_DefinedParent_o);
    if (!this) {
        return NULL;
    }
    this->Foo = Foo;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_DefinedParentUpdate(test_DefinedParent* this, corto_int32 Foo) {
    if (!corto_updateBegin(this)) {
        this->Foo = Foo;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_DefinedParent* _test_DefinedParentDeclare(void) {
    test_DefinedParent* this;
    this = corto_declare(test_DefinedParent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_DefinedParent* _test_DefinedParentDeclareChild(corto_object _parent, corto_string _name) {
    test_DefinedParent* this;
    this = corto_declareChild(_parent, _name, test_DefinedParent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_DefinedParentDefine(test_DefinedParent* this, corto_int32 Foo) {
    this->Foo = Foo;
    return corto_define(this);
}

void _test_DefinedParentSet(test_DefinedParent* this, corto_int32 Foo) {
    this->Foo = Foo;
}

corto_string _test_DefinedParentStr(test_DefinedParent* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_DefinedParent_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_DefinedParent* test_DefinedParentFromStr(test_DefinedParent* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_DefinedParent_o), str);
    return value;
}

corto_int16 _test_DefinedParentCopy(test_DefinedParent* *dst, test_DefinedParent* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_DefinedParent_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_DefinedParent_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_DefinedParentCompare(test_DefinedParent* dst, test_DefinedParent* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_DefinedParent_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_DefinedParent_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_DefinedParentInit(test_DefinedParent* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_DefinedParent_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_DefinedParent_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_DefinedParentDeinit(test_DefinedParent* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_DefinedParent_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Dog _test_DogCreate(corto_bool a, corto_bool b) {
    test_Dog this;
    this = corto_declare(test_Dog_o);
    if (!this) {
        return NULL;
    }
    test_Animal(this)->a = a;
    this->b = b;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Dog _test_DogCreateChild(corto_object _parent, corto_string _name, corto_bool a, corto_bool b) {
    test_Dog this;
    this = corto_declareChild(_parent, _name, test_Dog_o);
    if (!this) {
        return NULL;
    }
    test_Animal(this)->a = a;
    this->b = b;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_DogUpdate(test_Dog this, corto_bool a, corto_bool b) {
    if (!corto_updateBegin(this)) {
        test_Animal(this)->a = a;
        this->b = b;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Dog _test_DogDeclare(void) {
    test_Dog this;
    this = corto_declare(test_Dog_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Dog _test_DogDeclareChild(corto_object _parent, corto_string _name) {
    test_Dog this;
    this = corto_declareChild(_parent, _name, test_Dog_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_DogDefine(test_Dog this, corto_bool a, corto_bool b) {
    test_Animal(this)->a = a;
    this->b = b;
    return corto_define(this);
}

void _test_DogSet(test_Dog this, corto_bool a, corto_bool b) {
    test_Animal(this)->a = a;
    this->b = b;
}

corto_string _test_DogStr(test_Dog value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Dog_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Dog test_DogFromStr(test_Dog value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Dog_o), str);
    return value;
}

corto_int16 _test_DogCopy(test_Dog *dst, test_Dog src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_DogCompare(test_Dog dst, test_Dog src) {
    return corto_compare(dst, src);
}

test_Env _test_EnvCreate(test_Case test, corto_uint32 assertCount) {
    test_Env this;
    this = corto_declare(test_Env_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Env _test_EnvCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_Env this;
    this = corto_declareChild(_parent, _name, test_Env_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_EnvUpdate(test_Env this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Env _test_EnvDeclare(void) {
    test_Env this;
    this = corto_declare(test_Env_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Env _test_EnvDeclareChild(corto_object _parent, corto_string _name) {
    test_Env this;
    this = corto_declareChild(_parent, _name, test_Env_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_EnvDefine(test_Env this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_EnvSet(test_Env this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_EnvStr(test_Env value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Env_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Env test_EnvFromStr(test_Env value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Env_o), str);
    return value;
}

corto_int16 _test_EnvCopy(test_Env *dst, test_Env src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_EnvCompare(test_Env dst, test_Env src) {
    return corto_compare(dst, src);
}

test_Event _test_EventCreate(test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr) {
    test_Event this;
    this = corto_declare(test_Event_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    corto_setref(&this->et, test_EventTest(et));
    this->prevAttr = prevAttr;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Event _test_EventCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr) {
    test_Event this;
    this = corto_declareChild(_parent, _name, test_Event_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    corto_setref(&this->et, test_EventTest(et));
    this->prevAttr = prevAttr;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_EventUpdate(test_Event this, test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_setref(&this->et, test_EventTest(et));
        this->prevAttr = prevAttr;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Event _test_EventDeclare(void) {
    test_Event this;
    this = corto_declare(test_Event_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Event _test_EventDeclareChild(corto_object _parent, corto_string _name) {
    test_Event this;
    this = corto_declareChild(_parent, _name, test_Event_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_EventDefine(test_Event this, test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    corto_setref(&this->et, test_EventTest(et));
    this->prevAttr = prevAttr;
    return corto_define(this);
}

void _test_EventSet(test_Event this, test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    corto_setref(&this->et, test_EventTest(et));
    this->prevAttr = prevAttr;
}

corto_string _test_EventStr(test_Event value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Event_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Event test_EventFromStr(test_Event value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Event_o), str);
    return value;
}

corto_int16 _test_EventCopy(test_Event *dst, test_Event src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_EventCompare(test_Event dst, test_Event src) {
    return corto_compare(dst, src);
}

test_EventTest _test_EventTestCreate(corto_object scope) {
    test_EventTest this;
    this = corto_declare(test_EventTest_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->scope, scope);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_EventTest _test_EventTestCreateChild(corto_object _parent, corto_string _name, corto_object scope) {
    test_EventTest this;
    this = corto_declareChild(_parent, _name, test_EventTest_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&this->scope, scope);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_EventTestUpdate(test_EventTest this, corto_object scope) {
    if (!corto_updateBegin(this)) {
        corto_setref(&this->scope, scope);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_EventTest _test_EventTestDeclare(void) {
    test_EventTest this;
    this = corto_declare(test_EventTest_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_EventTest _test_EventTestDeclareChild(corto_object _parent, corto_string _name) {
    test_EventTest this;
    this = corto_declareChild(_parent, _name, test_EventTest_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_EventTestDefine(test_EventTest this, corto_object scope) {
    corto_setref(&this->scope, scope);
    return corto_define(this);
}

void _test_EventTestSet(test_EventTest this, corto_object scope) {
    corto_setref(&this->scope, scope);
}

corto_string _test_EventTestStr(test_EventTest value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_EventTest_o));
    result = corto_strv(&v, 0);
    return result;
}

test_EventTest test_EventTestFromStr(test_EventTest value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_EventTest_o), str);
    return value;
}

corto_int16 _test_EventTestCopy(test_EventTest *dst, test_EventTest src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_EventTestCompare(test_EventTest dst, test_EventTest src) {
    return corto_compare(dst, src);
}

test_Foo _test_FooCreate(corto_int32 x, corto_int32 y) {
    test_Foo this;
    this = corto_declare(test_Foo_o);
    if (!this) {
        return NULL;
    }
    this->x = x;
    this->y = y;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Foo _test_FooCreateChild(corto_object _parent, corto_string _name, corto_int32 x, corto_int32 y) {
    test_Foo this;
    this = corto_declareChild(_parent, _name, test_Foo_o);
    if (!this) {
        return NULL;
    }
    this->x = x;
    this->y = y;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_FooUpdate(test_Foo this, corto_int32 x, corto_int32 y) {
    if (!corto_updateBegin(this)) {
        this->x = x;
        this->y = y;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Foo _test_FooDeclare(void) {
    test_Foo this;
    this = corto_declare(test_Foo_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Foo _test_FooDeclareChild(corto_object _parent, corto_string _name) {
    test_Foo this;
    this = corto_declareChild(_parent, _name, test_Foo_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_FooDefine(test_Foo this, corto_int32 x, corto_int32 y) {
    this->x = x;
    this->y = y;
    return corto_define(this);
}

void _test_FooSet(test_Foo this, corto_int32 x, corto_int32 y) {
    this->x = x;
    this->y = y;
}

corto_string _test_FooStr(test_Foo value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Foo_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Foo test_FooFromStr(test_Foo value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Foo_o), str);
    return value;
}

corto_int16 _test_FooCopy(test_Foo *dst, test_Foo src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_FooCompare(test_Foo dst, test_Foo src) {
    return corto_compare(dst, src);
}

test_Fullname _test_FullnameCreate(test_Case test, corto_uint32 assertCount) {
    test_Fullname this;
    this = corto_declare(test_Fullname_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Fullname _test_FullnameCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_Fullname this;
    this = corto_declareChild(_parent, _name, test_Fullname_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_FullnameUpdate(test_Fullname this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Fullname _test_FullnameDeclare(void) {
    test_Fullname this;
    this = corto_declare(test_Fullname_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Fullname _test_FullnameDeclareChild(corto_object _parent, corto_string _name) {
    test_Fullname this;
    this = corto_declareChild(_parent, _name, test_Fullname_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_FullnameDefine(test_Fullname this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_FullnameSet(test_Fullname this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_FullnameStr(test_Fullname value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Fullname_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Fullname test_FullnameFromStr(test_Fullname value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Fullname_o), str);
    return value;
}

corto_int16 _test_FullnameCopy(test_Fullname *dst, test_Fullname src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_FullnameCompare(test_Fullname dst, test_Fullname src) {
    return corto_compare(dst, src);
}

test_GoldenRetriever _test_GoldenRetrieverCreate(corto_bool a, corto_bool b, corto_bool c) {
    test_GoldenRetriever this;
    this = corto_declare(test_GoldenRetriever_o);
    if (!this) {
        return NULL;
    }
    test_Animal(this)->a = a;
    test_Dog(this)->b = b;
    this->c = c;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_GoldenRetriever _test_GoldenRetrieverCreateChild(corto_object _parent, corto_string _name, corto_bool a, corto_bool b, corto_bool c) {
    test_GoldenRetriever this;
    this = corto_declareChild(_parent, _name, test_GoldenRetriever_o);
    if (!this) {
        return NULL;
    }
    test_Animal(this)->a = a;
    test_Dog(this)->b = b;
    this->c = c;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_GoldenRetrieverUpdate(test_GoldenRetriever this, corto_bool a, corto_bool b, corto_bool c) {
    if (!corto_updateBegin(this)) {
        test_Animal(this)->a = a;
        test_Dog(this)->b = b;
        this->c = c;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_GoldenRetriever _test_GoldenRetrieverDeclare(void) {
    test_GoldenRetriever this;
    this = corto_declare(test_GoldenRetriever_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_GoldenRetriever _test_GoldenRetrieverDeclareChild(corto_object _parent, corto_string _name) {
    test_GoldenRetriever this;
    this = corto_declareChild(_parent, _name, test_GoldenRetriever_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_GoldenRetrieverDefine(test_GoldenRetriever this, corto_bool a, corto_bool b, corto_bool c) {
    test_Animal(this)->a = a;
    test_Dog(this)->b = b;
    this->c = c;
    return corto_define(this);
}

void _test_GoldenRetrieverSet(test_GoldenRetriever this, corto_bool a, corto_bool b, corto_bool c) {
    test_Animal(this)->a = a;
    test_Dog(this)->b = b;
    this->c = c;
}

corto_string _test_GoldenRetrieverStr(test_GoldenRetriever value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_GoldenRetriever_o));
    result = corto_strv(&v, 0);
    return result;
}

test_GoldenRetriever test_GoldenRetrieverFromStr(test_GoldenRetriever value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_GoldenRetriever_o), str);
    return value;
}

corto_int16 _test_GoldenRetrieverCopy(test_GoldenRetriever *dst, test_GoldenRetriever src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_GoldenRetrieverCompare(test_GoldenRetriever dst, test_GoldenRetriever src) {
    return corto_compare(dst, src);
}

test_Line* _test_LineCreate(test_Point start, test_Point stop) {
    test_Line* this;
    this = corto_declare(test_Line_o);
    if (!this) {
        return NULL;
    }
    this->start = start;
    this->stop = stop;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Line* _test_LineCreateChild(corto_object _parent, corto_string _name, test_Point start, test_Point stop) {
    test_Line* this;
    this = corto_declareChild(_parent, _name, test_Line_o);
    if (!this) {
        return NULL;
    }
    this->start = start;
    this->stop = stop;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_LineUpdate(test_Line* this, test_Point start, test_Point stop) {
    if (!corto_updateBegin(this)) {
        this->start = start;
        this->stop = stop;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Line* _test_LineDeclare(void) {
    test_Line* this;
    this = corto_declare(test_Line_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Line* _test_LineDeclareChild(corto_object _parent, corto_string _name) {
    test_Line* this;
    this = corto_declareChild(_parent, _name, test_Line_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_LineDefine(test_Line* this, test_Point start, test_Point stop) {
    this->start = start;
    this->stop = stop;
    return corto_define(this);
}

void _test_LineSet(test_Line* this, test_Point start, test_Point stop) {
    this->start = start;
    this->stop = stop;
}

corto_string _test_LineStr(test_Line* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Line_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_Line* test_LineFromStr(test_Line* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Line_o), str);
    return value;
}

corto_int16 _test_LineCopy(test_Line* *dst, test_Line* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_Line_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_Line_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_LineCompare(test_Line* dst, test_Line* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_Line_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_Line_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_LineInit(test_Line* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_Line_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Line_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_LineDeinit(test_Line* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Line_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_MethodResolver _test_MethodResolverCreate(test_Case test, corto_uint32 assertCount) {
    test_MethodResolver this;
    this = corto_declare(test_MethodResolver_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_MethodResolver _test_MethodResolverCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_MethodResolver this;
    this = corto_declareChild(_parent, _name, test_MethodResolver_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_MethodResolverUpdate(test_MethodResolver this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_MethodResolver _test_MethodResolverDeclare(void) {
    test_MethodResolver this;
    this = corto_declare(test_MethodResolver_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_MethodResolver _test_MethodResolverDeclareChild(corto_object _parent, corto_string _name) {
    test_MethodResolver this;
    this = corto_declareChild(_parent, _name, test_MethodResolver_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_MethodResolverDefine(test_MethodResolver this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_MethodResolverSet(test_MethodResolver this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_MethodResolverStr(test_MethodResolver value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_MethodResolver_o));
    result = corto_strv(&v, 0);
    return result;
}

test_MethodResolver test_MethodResolverFromStr(test_MethodResolver value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_MethodResolver_o), str);
    return value;
}

corto_int16 _test_MethodResolverCopy(test_MethodResolver *dst, test_MethodResolver src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_MethodResolverCompare(test_MethodResolver dst, test_MethodResolver src) {
    return corto_compare(dst, src);
}

test_MethodTester _test_MethodTesterCreate(void) {
    test_MethodTester this;
    this = corto_declare(test_MethodTester_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_MethodTester _test_MethodTesterCreateChild(corto_object _parent, corto_string _name) {
    test_MethodTester this;
    this = corto_declareChild(_parent, _name, test_MethodTester_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_MethodTesterUpdate(test_MethodTester this) {
    if (!corto_updateBegin(this)) {
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_MethodTester _test_MethodTesterDeclare(void) {
    test_MethodTester this;
    this = corto_declare(test_MethodTester_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_MethodTester _test_MethodTesterDeclareChild(corto_object _parent, corto_string _name) {
    test_MethodTester this;
    this = corto_declareChild(_parent, _name, test_MethodTester_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_MethodTesterDefine(test_MethodTester this) {
    return corto_define(this);
}

void _test_MethodTesterSet(test_MethodTester this) {
    CORTO_UNUSED(this);
}

corto_string _test_MethodTesterStr(test_MethodTester value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_MethodTester_o));
    result = corto_strv(&v, 0);
    return result;
}

test_MethodTester test_MethodTesterFromStr(test_MethodTester value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_MethodTester_o), str);
    return value;
}

corto_int16 _test_MethodTesterCopy(test_MethodTester *dst, test_MethodTester src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_MethodTesterCompare(test_MethodTester dst, test_MethodTester src) {
    return corto_compare(dst, src);
}

test_MethodTesterInherit _test_MethodTesterInheritCreate(void) {
    test_MethodTesterInherit this;
    this = corto_declare(test_MethodTesterInherit_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_MethodTesterInherit _test_MethodTesterInheritCreateChild(corto_object _parent, corto_string _name) {
    test_MethodTesterInherit this;
    this = corto_declareChild(_parent, _name, test_MethodTesterInherit_o);
    if (!this) {
        return NULL;
    }
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_MethodTesterInheritUpdate(test_MethodTesterInherit this) {
    if (!corto_updateBegin(this)) {
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_MethodTesterInherit _test_MethodTesterInheritDeclare(void) {
    test_MethodTesterInherit this;
    this = corto_declare(test_MethodTesterInherit_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_MethodTesterInherit _test_MethodTesterInheritDeclareChild(corto_object _parent, corto_string _name) {
    test_MethodTesterInherit this;
    this = corto_declareChild(_parent, _name, test_MethodTesterInherit_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_MethodTesterInheritDefine(test_MethodTesterInherit this) {
    return corto_define(this);
}

void _test_MethodTesterInheritSet(test_MethodTesterInherit this) {
    CORTO_UNUSED(this);
}

corto_string _test_MethodTesterInheritStr(test_MethodTesterInherit value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_MethodTesterInherit_o));
    result = corto_strv(&v, 0);
    return result;
}

test_MethodTesterInherit test_MethodTesterInheritFromStr(test_MethodTesterInherit value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_MethodTesterInherit_o), str);
    return value;
}

corto_int16 _test_MethodTesterInheritCopy(test_MethodTesterInherit *dst, test_MethodTesterInherit src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_MethodTesterInheritCompare(test_MethodTesterInherit dst, test_MethodTesterInherit src) {
    return corto_compare(dst, src);
}

test_ObjectMgmt _test_ObjectMgmtCreate(test_Case test, corto_uint32 assertCount) {
    test_ObjectMgmt this;
    this = corto_declare(test_ObjectMgmt_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_ObjectMgmt _test_ObjectMgmtCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_ObjectMgmt this;
    this = corto_declareChild(_parent, _name, test_ObjectMgmt_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_ObjectMgmtUpdate(test_ObjectMgmt this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_ObjectMgmt _test_ObjectMgmtDeclare(void) {
    test_ObjectMgmt this;
    this = corto_declare(test_ObjectMgmt_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_ObjectMgmt _test_ObjectMgmtDeclareChild(corto_object _parent, corto_string _name) {
    test_ObjectMgmt this;
    this = corto_declareChild(_parent, _name, test_ObjectMgmt_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_ObjectMgmtDefine(test_ObjectMgmt this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_ObjectMgmtSet(test_ObjectMgmt this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_ObjectMgmtStr(test_ObjectMgmt value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_ObjectMgmt_o));
    result = corto_strv(&v, 0);
    return result;
}

test_ObjectMgmt test_ObjectMgmtFromStr(test_ObjectMgmt value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_ObjectMgmt_o), str);
    return value;
}

corto_int16 _test_ObjectMgmtCopy(test_ObjectMgmt *dst, test_ObjectMgmt src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_ObjectMgmtCompare(test_ObjectMgmt dst, test_ObjectMgmt src) {
    return corto_compare(dst, src);
}

test_Overload _test_OverloadCreate(test_Case test, corto_uint32 assertCount) {
    test_Overload this;
    this = corto_declare(test_Overload_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Overload _test_OverloadCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_Overload this;
    this = corto_declareChild(_parent, _name, test_Overload_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_OverloadUpdate(test_Overload this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Overload _test_OverloadDeclare(void) {
    test_Overload this;
    this = corto_declare(test_Overload_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Overload _test_OverloadDeclareChild(corto_object _parent, corto_string _name) {
    test_Overload this;
    this = corto_declareChild(_parent, _name, test_Overload_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_OverloadDefine(test_Overload this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_OverloadSet(test_Overload this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_OverloadStr(test_Overload value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Overload_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Overload test_OverloadFromStr(test_Overload value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Overload_o), str);
    return value;
}

corto_int16 _test_OverloadCopy(test_Overload *dst, test_Overload src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_OverloadCompare(test_Overload dst, test_Overload src) {
    return corto_compare(dst, src);
}

test_Point* _test_PointCreate(corto_int32 x, corto_int32 y) {
    test_Point* this;
    this = corto_declare(test_Point_o);
    if (!this) {
        return NULL;
    }
    this->x = x;
    this->y = y;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Point* _test_PointCreateChild(corto_object _parent, corto_string _name, corto_int32 x, corto_int32 y) {
    test_Point* this;
    this = corto_declareChild(_parent, _name, test_Point_o);
    if (!this) {
        return NULL;
    }
    this->x = x;
    this->y = y;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_PointUpdate(test_Point* this, corto_int32 x, corto_int32 y) {
    if (!corto_updateBegin(this)) {
        this->x = x;
        this->y = y;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Point* _test_PointDeclare(void) {
    test_Point* this;
    this = corto_declare(test_Point_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Point* _test_PointDeclareChild(corto_object _parent, corto_string _name) {
    test_Point* this;
    this = corto_declareChild(_parent, _name, test_Point_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_PointDefine(test_Point* this, corto_int32 x, corto_int32 y) {
    this->x = x;
    this->y = y;
    return corto_define(this);
}

void _test_PointSet(test_Point* this, corto_int32 x, corto_int32 y) {
    this->x = x;
    this->y = y;
}

corto_string _test_PointStr(test_Point* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Point_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_Point* test_PointFromStr(test_Point* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Point_o), str);
    return value;
}

corto_int16 _test_PointCopy(test_Point* *dst, test_Point* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_Point_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_Point_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_PointCompare(test_Point* dst, test_Point* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_Point_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_Point_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_PointInit(test_Point* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_Point_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Point_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_PointDeinit(test_Point* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Point_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Point3D* _test_Point3DCreate(corto_int32 x, corto_int32 y, corto_int32 z) {
    test_Point3D* this;
    this = corto_declare(test_Point3D_o);
    if (!this) {
        return NULL;
    }
    ((test_Point*)this)->x = x;
    ((test_Point*)this)->y = y;
    this->z = z;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Point3D* _test_Point3DCreateChild(corto_object _parent, corto_string _name, corto_int32 x, corto_int32 y, corto_int32 z) {
    test_Point3D* this;
    this = corto_declareChild(_parent, _name, test_Point3D_o);
    if (!this) {
        return NULL;
    }
    ((test_Point*)this)->x = x;
    ((test_Point*)this)->y = y;
    this->z = z;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_Point3DUpdate(test_Point3D* this, corto_int32 x, corto_int32 y, corto_int32 z) {
    if (!corto_updateBegin(this)) {
        ((test_Point*)this)->x = x;
        ((test_Point*)this)->y = y;
        this->z = z;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Point3D* _test_Point3DDeclare(void) {
    test_Point3D* this;
    this = corto_declare(test_Point3D_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Point3D* _test_Point3DDeclareChild(corto_object _parent, corto_string _name) {
    test_Point3D* this;
    this = corto_declareChild(_parent, _name, test_Point3D_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_Point3DDefine(test_Point3D* this, corto_int32 x, corto_int32 y, corto_int32 z) {
    ((test_Point*)this)->x = x;
    ((test_Point*)this)->y = y;
    this->z = z;
    return corto_define(this);
}

void _test_Point3DSet(test_Point3D* this, corto_int32 x, corto_int32 y, corto_int32 z) {
    ((test_Point*)this)->x = x;
    ((test_Point*)this)->y = y;
    this->z = z;
}

corto_string _test_Point3DStr(test_Point3D* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Point3D_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_Point3D* test_Point3DFromStr(test_Point3D* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Point3D_o), str);
    return value;
}

corto_int16 _test_Point3DCopy(test_Point3D* *dst, test_Point3D* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_Point3D_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_Point3D_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_Point3DCompare(test_Point3D* dst, test_Point3D* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_Point3D_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_Point3D_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_Point3DInit(test_Point3D* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_Point3D_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Point3D_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_Point3DDeinit(test_Point3D* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_Point3D_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_PrimitiveCollection* _test_PrimitiveCollectionCreate(corto_int32List ints) {
    test_PrimitiveCollection* this;
    this = corto_declare(test_PrimitiveCollection_o);
    if (!this) {
        return NULL;
    }
    this->ints = ints;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_PrimitiveCollection* _test_PrimitiveCollectionCreateChild(corto_object _parent, corto_string _name, corto_int32List ints) {
    test_PrimitiveCollection* this;
    this = corto_declareChild(_parent, _name, test_PrimitiveCollection_o);
    if (!this) {
        return NULL;
    }
    this->ints = ints;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_PrimitiveCollectionUpdate(test_PrimitiveCollection* this, corto_int32List ints) {
    if (!corto_updateBegin(this)) {
        this->ints = ints;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_PrimitiveCollection* _test_PrimitiveCollectionDeclare(void) {
    test_PrimitiveCollection* this;
    this = corto_declare(test_PrimitiveCollection_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_PrimitiveCollection* _test_PrimitiveCollectionDeclareChild(corto_object _parent, corto_string _name) {
    test_PrimitiveCollection* this;
    this = corto_declareChild(_parent, _name, test_PrimitiveCollection_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_PrimitiveCollectionDefine(test_PrimitiveCollection* this, corto_int32List ints) {
    this->ints = ints;
    return corto_define(this);
}

void _test_PrimitiveCollectionSet(test_PrimitiveCollection* this, corto_int32List ints) {
    this->ints = ints;
}

corto_string _test_PrimitiveCollectionStr(test_PrimitiveCollection* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_PrimitiveCollection_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_PrimitiveCollection* test_PrimitiveCollectionFromStr(test_PrimitiveCollection* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_PrimitiveCollection_o), str);
    return value;
}

corto_int16 _test_PrimitiveCollectionCopy(test_PrimitiveCollection* *dst, test_PrimitiveCollection* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_PrimitiveCollection_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_PrimitiveCollection_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_PrimitiveCollectionCompare(test_PrimitiveCollection* dst, test_PrimitiveCollection* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_PrimitiveCollection_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_PrimitiveCollection_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_PrimitiveCollectionInit(test_PrimitiveCollection* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_PrimitiveCollection_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_PrimitiveCollection_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_PrimitiveCollectionDeinit(test_PrimitiveCollection* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_PrimitiveCollection_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Project _test_ProjectCreate(test_Case test, corto_uint32 assertCount) {
    test_Project this;
    this = corto_declare(test_Project_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Project _test_ProjectCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_Project this;
    this = corto_declareChild(_parent, _name, test_Project_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_ProjectUpdate(test_Project this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Project _test_ProjectDeclare(void) {
    test_Project this;
    this = corto_declare(test_Project_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Project _test_ProjectDeclareChild(corto_object _parent, corto_string _name) {
    test_Project this;
    this = corto_declareChild(_parent, _name, test_Project_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_ProjectDefine(test_Project this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_ProjectSet(test_Project this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_ProjectStr(test_Project value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Project_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Project test_ProjectFromStr(test_Project value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Project_o), str);
    return value;
}

corto_int16 _test_ProjectCopy(test_Project *dst, test_Project src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_ProjectCompare(test_Project dst, test_Project src) {
    return corto_compare(dst, src);
}

test_RelativeName _test_RelativeNameCreate(test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    test_RelativeName this;
    this = corto_declare(test_RelativeName_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    corto_setref(&this->tier1, tier1);
    corto_setref(&this->tier2, tier2);
    corto_setref(&this->tier3, tier3);
    corto_setref(&this->obj, obj);
    corto_setref(&this->disjunct, disjunct);
    corto_setref(&this->child, child);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_RelativeName _test_RelativeNameCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    test_RelativeName this;
    this = corto_declareChild(_parent, _name, test_RelativeName_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    corto_setref(&this->tier1, tier1);
    corto_setref(&this->tier2, tier2);
    corto_setref(&this->tier3, tier3);
    corto_setref(&this->obj, obj);
    corto_setref(&this->disjunct, disjunct);
    corto_setref(&this->child, child);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_RelativeNameUpdate(test_RelativeName this, test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_setref(&this->tier1, tier1);
        corto_setref(&this->tier2, tier2);
        corto_setref(&this->tier3, tier3);
        corto_setref(&this->obj, obj);
        corto_setref(&this->disjunct, disjunct);
        corto_setref(&this->child, child);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_RelativeName _test_RelativeNameDeclare(void) {
    test_RelativeName this;
    this = corto_declare(test_RelativeName_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_RelativeName _test_RelativeNameDeclareChild(corto_object _parent, corto_string _name) {
    test_RelativeName this;
    this = corto_declareChild(_parent, _name, test_RelativeName_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_RelativeNameDefine(test_RelativeName this, test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    corto_setref(&this->tier1, tier1);
    corto_setref(&this->tier2, tier2);
    corto_setref(&this->tier3, tier3);
    corto_setref(&this->obj, obj);
    corto_setref(&this->disjunct, disjunct);
    corto_setref(&this->child, child);
    return corto_define(this);
}

void _test_RelativeNameSet(test_RelativeName this, test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    corto_setref(&this->tier1, tier1);
    corto_setref(&this->tier2, tier2);
    corto_setref(&this->tier3, tier3);
    corto_setref(&this->obj, obj);
    corto_setref(&this->disjunct, disjunct);
    corto_setref(&this->child, child);
}

corto_string _test_RelativeNameStr(test_RelativeName value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_RelativeName_o));
    result = corto_strv(&v, 0);
    return result;
}

test_RelativeName test_RelativeNameFromStr(test_RelativeName value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_RelativeName_o), str);
    return value;
}

corto_int16 _test_RelativeNameCopy(test_RelativeName *dst, test_RelativeName src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_RelativeNameCompare(test_RelativeName dst, test_RelativeName src) {
    return corto_compare(dst, src);
}

test_Resolver _test_ResolverCreate(test_Case test, corto_uint32 assertCount) {
    test_Resolver this;
    this = corto_declare(test_Resolver_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Resolver _test_ResolverCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_Resolver this;
    this = corto_declareChild(_parent, _name, test_Resolver_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_ResolverUpdate(test_Resolver this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Resolver _test_ResolverDeclare(void) {
    test_Resolver this;
    this = corto_declare(test_Resolver_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Resolver _test_ResolverDeclareChild(corto_object _parent, corto_string _name) {
    test_Resolver this;
    this = corto_declareChild(_parent, _name, test_Resolver_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_ResolverDefine(test_Resolver this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_ResolverSet(test_Resolver this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_ResolverStr(test_Resolver value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Resolver_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Resolver test_ResolverFromStr(test_Resolver value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Resolver_o), str);
    return value;
}

corto_int16 _test_ResolverCopy(test_Resolver *dst, test_Resolver src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_ResolverCompare(test_Resolver dst, test_Resolver src) {
    return corto_compare(dst, src);
}

test_Select _test_SelectCreate(test_Case test, corto_uint32 assertCount) {
    test_Select this;
    this = corto_declare(test_Select_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_Select _test_SelectCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_Select this;
    this = corto_declareChild(_parent, _name, test_Select_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_SelectUpdate(test_Select this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_Select _test_SelectDeclare(void) {
    test_Select this;
    this = corto_declare(test_Select_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_Select _test_SelectDeclareChild(corto_object _parent, corto_string _name) {
    test_Select this;
    this = corto_declareChild(_parent, _name, test_Select_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_SelectDefine(test_Select this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_SelectSet(test_Select this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_SelectStr(test_Select value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_Select_o));
    result = corto_strv(&v, 0);
    return result;
}

test_Select test_SelectFromStr(test_Select value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_Select_o), str);
    return value;
}

corto_int16 _test_SelectCopy(test_Select *dst, test_Select src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_SelectCompare(test_Select dst, test_Select src) {
    return corto_compare(dst, src);
}

test_selectItem* _test_selectItemCreate(corto_string parent, corto_string name, corto_string type) {
    test_selectItem* this;
    this = corto_declare(test_selectItem_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&this->parent, parent);
    corto_setstr(&this->name, name);
    corto_setstr(&this->type, type);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_selectItem* _test_selectItemCreateChild(corto_object _parent, corto_string _name, corto_string parent, corto_string name, corto_string type) {
    test_selectItem* this;
    this = corto_declareChild(_parent, _name, test_selectItem_o);
    if (!this) {
        return NULL;
    }
    corto_setstr(&this->parent, parent);
    corto_setstr(&this->name, name);
    corto_setstr(&this->type, type);
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_selectItemUpdate(test_selectItem* this, corto_string parent, corto_string name, corto_string type) {
    if (!corto_updateBegin(this)) {
        corto_setstr(&this->parent, parent);
        corto_setstr(&this->name, name);
        corto_setstr(&this->type, type);
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_selectItem* _test_selectItemDeclare(void) {
    test_selectItem* this;
    this = corto_declare(test_selectItem_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_selectItem* _test_selectItemDeclareChild(corto_object _parent, corto_string _name) {
    test_selectItem* this;
    this = corto_declareChild(_parent, _name, test_selectItem_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_selectItemDefine(test_selectItem* this, corto_string parent, corto_string name, corto_string type) {
    corto_setstr(&this->parent, parent);
    corto_setstr(&this->name, name);
    corto_setstr(&this->type, type);
    return corto_define(this);
}

void _test_selectItemSet(test_selectItem* this, corto_string parent, corto_string name, corto_string type) {
    corto_setstr(&this->parent, parent);
    corto_setstr(&this->name, name);
    corto_setstr(&this->type, type);
}

corto_string _test_selectItemStr(test_selectItem* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_selectItem_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_selectItem* test_selectItemFromStr(test_selectItem* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_selectItem_o), str);
    return value;
}

corto_int16 _test_selectItemCopy(test_selectItem* *dst, test_selectItem* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_selectItem_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_selectItem_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_selectItemCompare(test_selectItem* dst, test_selectItem* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_selectItem_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_selectItem_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_selectItemInit(test_selectItem* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_selectItem_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_selectItem_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_selectItemDeinit(test_selectItem* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_selectItem_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_StringDeserializer _test_StringDeserializerCreate(test_Case test, corto_uint32 assertCount) {
    test_StringDeserializer this;
    this = corto_declare(test_StringDeserializer_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_StringDeserializer _test_StringDeserializerCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount) {
    test_StringDeserializer this;
    this = corto_declareChild(_parent, _name, test_StringDeserializer_o);
    if (!this) {
        return NULL;
    }
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_StringDeserializerUpdate(test_StringDeserializer this, test_Case test, corto_uint32 assertCount) {
    if (!corto_updateBegin(this)) {
        corto_setref(&test_SuiteData(this)->test, test_Case(test));
        test_SuiteData(this)->assertCount = assertCount;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_StringDeserializer _test_StringDeserializerDeclare(void) {
    test_StringDeserializer this;
    this = corto_declare(test_StringDeserializer_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_StringDeserializer _test_StringDeserializerDeclareChild(corto_object _parent, corto_string _name) {
    test_StringDeserializer this;
    this = corto_declareChild(_parent, _name, test_StringDeserializer_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_StringDeserializerDefine(test_StringDeserializer this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
    return corto_define(this);
}

void _test_StringDeserializerSet(test_StringDeserializer this, test_Case test, corto_uint32 assertCount) {
    corto_setref(&test_SuiteData(this)->test, test_Case(test));
    test_SuiteData(this)->assertCount = assertCount;
}

corto_string _test_StringDeserializerStr(test_StringDeserializer value) {
    corto_string result;
    corto_value v;
    corto_valueObjectInit(&v, value, corto_type(test_StringDeserializer_o));
    result = corto_strv(&v, 0);
    return result;
}

test_StringDeserializer test_StringDeserializerFromStr(test_StringDeserializer value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_StringDeserializer_o), str);
    return value;
}

corto_int16 _test_StringDeserializerCopy(test_StringDeserializer *dst, test_StringDeserializer src) {
    return corto_copy((corto_object*)dst, src);
}

corto_int16 _test_StringDeserializerCompare(test_StringDeserializer dst, test_StringDeserializer src) {
    return corto_compare(dst, src);
}

test_VoidParent* _test_VoidParentCreate(corto_int32 Foo) {
    test_VoidParent* this;
    this = corto_declare(test_VoidParent_o);
    if (!this) {
        return NULL;
    }
    this->Foo = Foo;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

test_VoidParent* _test_VoidParentCreateChild(corto_object _parent, corto_string _name, corto_int32 Foo) {
    test_VoidParent* this;
    this = corto_declareChild(_parent, _name, test_VoidParent_o);
    if (!this) {
        return NULL;
    }
    this->Foo = Foo;
    if (this && corto_define(this)) {
        corto_release(this);
        this = NULL;
    }
    return this;
}

corto_int16 _test_VoidParentUpdate(test_VoidParent* this, corto_int32 Foo) {
    if (!corto_updateBegin(this)) {
        this->Foo = Foo;
        corto_updateEnd(this);
    } else {
        return -1;
    }
    return 0;
}

test_VoidParent* _test_VoidParentDeclare(void) {
    test_VoidParent* this;
    this = corto_declare(test_VoidParent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

test_VoidParent* _test_VoidParentDeclareChild(corto_object _parent, corto_string _name) {
    test_VoidParent* this;
    this = corto_declareChild(_parent, _name, test_VoidParent_o);
    if (!this) {
        return NULL;
    }
    return this;
}

corto_int16 _test_VoidParentDefine(test_VoidParent* this, corto_int32 Foo) {
    this->Foo = Foo;
    return corto_define(this);
}

void _test_VoidParentSet(test_VoidParent* this, corto_int32 Foo) {
    this->Foo = Foo;
}

corto_string _test_VoidParentStr(test_VoidParent* value) {
    corto_string result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_VoidParent_o), &value);
    result = corto_strv(&v, 0);
    return result;
}

test_VoidParent* test_VoidParentFromStr(test_VoidParent* value, corto_string str) {
    corto_fromStrp(&value, corto_type(test_VoidParent_o), str);
    return value;
}

corto_int16 _test_VoidParentCopy(test_VoidParent* *dst, test_VoidParent* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_VoidParent_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_VoidParent_o), src);
    return corto_copyv(&v1, &v2);
}

corto_int16 _test_VoidParentCompare(test_VoidParent* dst, test_VoidParent* src) {
    corto_value v1, v2;
    corto_valueValueInit(&v1, NULL, corto_type(test_VoidParent_o), dst);
    corto_valueValueInit(&v2, NULL, corto_type(test_VoidParent_o), src);
    return corto_comparev(&v1, &v2);
}

corto_int16 _test_VoidParentInit(test_VoidParent* value) {
    corto_int16 result;
    memset(value, 0, corto_type(test_VoidParent_o)->size);
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_VoidParent_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _test_VoidParentDeinit(test_VoidParent* value) {
    corto_int16 result;
    corto_value v;
    corto_valueValueInit(&v, NULL, corto_type(test_VoidParent_o), value);
    result = corto_deinitv(&v);
    return result;
}

test_Point* test_PointListInsertAlloc(test_PointList list) {
    test_Point* result;
    result = corto_calloc(corto_type_sizeof(corto_type(test_Point_o)));
    {
        corto_value v;
        corto_valueValueInit(&v, NULL, corto_type(test_Point_o), result);
        corto_initv(&v);
    }
    corto_llInsert(list, result);
    return result;
}

test_Point* test_PointListInsert(test_PointList list, test_Point* element) {
    test_Point *result = test_PointListInsertAlloc(list);
    corto_copyp(result, test_Point_o, element);
    return result;
}

test_Point* test_PointListAppendAlloc(test_PointList list) {
    test_Point* result;
    result = corto_calloc(corto_type_sizeof(corto_type(test_Point_o)));
    {
        corto_value v;
        corto_valueValueInit(&v, NULL, corto_type(test_Point_o), result);
        corto_initv(&v);
    }
    corto_llAppend(list, result);
    return result;
}

test_Point* test_PointListAppend(test_PointList list, test_Point* element) {
    test_Point *result = test_PointListAppendAlloc(list);
    corto_copyp(result, test_Point_o, element);
    return result;
}

test_Point* test_PointListTakeFirst(test_PointList list) {
    return (test_Point*)(corto_word)corto_llTakeFirst(list);
}

test_Point* test_PointListLast(test_PointList list) {
    return (test_Point*)(corto_word)corto_llLast(list);
}

void test_PointListClear(test_PointList list) {
    void *element;

    while((element = corto_llTakeFirst(list))) {
        {
            corto_value v;
            corto_valueValueInit(&v, NULL, corto_type(test_Point_o), element);
            corto_deinitv(&v);
        }
        corto_dealloc(element);
    }
}

test_Point* test_PointListGet(test_PointList list, corto_uint32 index) {
    return (test_Point*)(corto_word)corto_llGet(list, index);
}

corto_uint32 test_PointListSize(test_PointList list) {
    return corto_llSize(list);
}

test_selectItem* test_selectItemListInsertAlloc(test_selectItemList list) {
    test_selectItem* result;
    result = corto_calloc(corto_type_sizeof(corto_type(test_selectItem_o)));
    {
        corto_value v;
        corto_valueValueInit(&v, NULL, corto_type(test_selectItem_o), result);
        corto_initv(&v);
    }
    corto_llInsert(list, result);
    return result;
}

test_selectItem* test_selectItemListInsert(test_selectItemList list, test_selectItem* element) {
    test_selectItem *result = test_selectItemListInsertAlloc(list);
    corto_copyp(result, test_selectItem_o, element);
    return result;
}

test_selectItem* test_selectItemListAppendAlloc(test_selectItemList list) {
    test_selectItem* result;
    result = corto_calloc(corto_type_sizeof(corto_type(test_selectItem_o)));
    {
        corto_value v;
        corto_valueValueInit(&v, NULL, corto_type(test_selectItem_o), result);
        corto_initv(&v);
    }
    corto_llAppend(list, result);
    return result;
}

test_selectItem* test_selectItemListAppend(test_selectItemList list, test_selectItem* element) {
    test_selectItem *result = test_selectItemListAppendAlloc(list);
    corto_copyp(result, test_selectItem_o, element);
    return result;
}

test_selectItem* test_selectItemListTakeFirst(test_selectItemList list) {
    return (test_selectItem*)(corto_word)corto_llTakeFirst(list);
}

test_selectItem* test_selectItemListLast(test_selectItemList list) {
    return (test_selectItem*)(corto_word)corto_llLast(list);
}

void test_selectItemListClear(test_selectItemList list) {
    void *element;

    while((element = corto_llTakeFirst(list))) {
        {
            corto_value v;
            corto_valueValueInit(&v, NULL, corto_type(test_selectItem_o), element);
            corto_deinitv(&v);
        }
        corto_dealloc(element);
    }
}

test_selectItem* test_selectItemListGet(test_selectItemList list, corto_uint32 index) {
    return (test_selectItem*)(corto_word)corto_llGet(list, index);
}

corto_uint32 test_selectItemListSize(test_selectItemList list) {
    return corto_llSize(list);
}

void corto_objectListInsert(corto_objectList list, corto_object element) {
    corto_llInsert(list, (void*)(corto_word)element);
    corto_claim(element);
}

void corto_objectListAppend(corto_objectList list, corto_object element) {
    corto_llAppend(list, (void*)(corto_word)element);
    corto_claim(element);
}

corto_object corto_objectListTakeFirst(corto_objectList list) {
    return (corto_object)(corto_word)corto_llTakeFirst(list);
}

corto_object corto_objectListLast(corto_objectList list) {
    return (corto_object)(corto_word)corto_llLast(list);
}

void corto_objectListClear(corto_objectList list) {
    void *element;

    while((element = corto_llTakeFirst(list))) {
        corto_release(element);
    }
}

corto_object corto_objectListGet(corto_objectList list, corto_uint32 index) {
    return (corto_object)(corto_word)corto_llGet(list, index);
}

corto_uint32 corto_objectListSize(corto_objectList list) {
    return corto_llSize(list);
}

void corto_int32ListInsert(corto_int32List list, corto_int32 element) {
    corto_llInsert(list, (void*)(corto_word)element);
}

void corto_int32ListAppend(corto_int32List list, corto_int32 element) {
    corto_llAppend(list, (void*)(corto_word)element);
}

corto_int32 corto_int32ListTakeFirst(corto_int32List list) {
    return (corto_int32)(corto_word)corto_llTakeFirst(list);
}

corto_int32 corto_int32ListLast(corto_int32List list) {
    return (corto_int32)(corto_word)corto_llLast(list);
}

void corto_int32ListClear(corto_int32List list) {
    void *element;

    while((element = corto_llTakeFirst(list))) {
    }
}

corto_int32 corto_int32ListGet(corto_int32List list, corto_uint32 index) {
    return (corto_int32)(corto_word)corto_llGet(list, index);
}

corto_uint32 corto_int32ListSize(corto_int32List list) {
    return corto_llSize(list);
}

