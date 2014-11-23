/* tc_stringser__api.c
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "tc_stringser__meta.h"
#include "tc_stringser__api.h"

tc_classCompositeCollection tc_classCompositeCollection__new(void) {
    return db_new(db_typedef(tc_classCompositeCollection_o));
}

tc_classCompositeCollection tc_classCompositeCollection__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_classCompositeCollection_o));
}

int tc_classCompositeCollection__define(tc_classCompositeCollection _this, tc_arrayOfClassInherit a, tc_arrayOfClassNested b, tc_sequenceOfClassInherit c, tc_listOfClassNested d, tc_listOfClassInherit e) {
    memcpy(_this->a, a, sizeof(tc_arrayOfClassInherit));
    memcpy(_this->b, b, sizeof(tc_arrayOfClassNested));
    _this->c = c;
    _this->d = d;
    _this->e = e;
    return db_define(_this);
}

tc_classCompositeCollection tc_classCompositeCollection__create(tc_arrayOfClassInherit a, tc_arrayOfClassNested b, tc_sequenceOfClassInherit c, tc_listOfClassNested d, tc_listOfClassInherit e) {
    tc_classCompositeCollection _this;
    _this = db_new(db_typedef(tc_classCompositeCollection_o));
    memcpy(_this->a, a, sizeof(tc_arrayOfClassInherit));
    memcpy(_this->b, b, sizeof(tc_arrayOfClassNested));
    _this->c = c;
    _this->d = d;
    _this->e = e;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

tc_classInherit tc_classInherit__new(void) {
    return db_new(db_typedef(tc_classInherit_o));
}

tc_classInherit tc_classInherit__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_classInherit_o));
}

int tc_classInherit__define(tc_classInherit _this, db_bool a, db_char b, db_int32 c, db_float32 d, db_string e, tc_color f, tc_moveMode g, db_bool a_1, db_char b_1, db_int32 c_1, db_float32 d_1, db_string e_1, tc_color f_1, tc_moveMode g_1) {
    tc_classPrimitives(_this)->a = a;
    tc_classPrimitives(_this)->b = b;
    tc_classPrimitives(_this)->c = c;
    tc_classPrimitives(_this)->d = d;
    tc_classPrimitives(_this)->e = (e ? db_strdup(e) : NULL);
    tc_classPrimitives(_this)->f = f;
    tc_classPrimitives(_this)->g = g;
    _this->a = a_1;
    _this->b = b_1;
    _this->c = c_1;
    _this->d = d_1;
    _this->e = (e_1 ? db_strdup(e_1) : NULL);
    _this->f = f_1;
    _this->g = g_1;
    return db_define(_this);
}

tc_classInherit tc_classInherit__create(db_bool a, db_char b, db_int32 c, db_float32 d, db_string e, tc_color f, tc_moveMode g, db_bool a_1, db_char b_1, db_int32 c_1, db_float32 d_1, db_string e_1, tc_color f_1, tc_moveMode g_1) {
    tc_classInherit _this;
    _this = db_new(db_typedef(tc_classInherit_o));
    tc_classPrimitives(_this)->a = a;
    tc_classPrimitives(_this)->b = b;
    tc_classPrimitives(_this)->c = c;
    tc_classPrimitives(_this)->d = d;
    tc_classPrimitives(_this)->e = (e ? db_strdup(e) : NULL);
    tc_classPrimitives(_this)->f = f;
    tc_classPrimitives(_this)->g = g;
    _this->a = a_1;
    _this->b = b_1;
    _this->c = c_1;
    _this->d = d_1;
    _this->e = (e_1 ? db_strdup(e_1) : NULL);
    _this->f = f_1;
    _this->g = g_1;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

tc_classNested tc_classNested__new(void) {
    return db_new(db_typedef(tc_classNested_o));
}

tc_classNested tc_classNested__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_classNested_o));
}

int tc_classNested__define(tc_classNested _this, tc_classPrimitives a, tc_classInherit b, tc_arrayOfInt c, tc_sequenceOfInt d, tc_listOfInt e) {
    a ? db_keep_ext(_this, a, "element <0xa021ac8>.a") : 0; _this->a = a;
    b ? db_keep_ext(_this, b, "element <0xa021ac8>.b") : 0; _this->b = b;
    memcpy(_this->c, c, sizeof(tc_arrayOfInt));
    _this->d = d;
    _this->e = e;
    return db_define(_this);
}

tc_classNested tc_classNested__create(tc_classPrimitives a, tc_classInherit b, tc_arrayOfInt c, tc_sequenceOfInt d, tc_listOfInt e) {
    tc_classNested _this;
    _this = db_new(db_typedef(tc_classNested_o));
    a ? db_keep_ext(_this, a, "element <0xa021ac8>.a") : 0; _this->a = a;
    b ? db_keep_ext(_this, b, "element <0xa021ac8>.b") : 0; _this->b = b;
    memcpy(_this->c, c, sizeof(tc_arrayOfInt));
    _this->d = d;
    _this->e = e;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

tc_classPrimitives tc_classPrimitives__new(void) {
    return db_new(db_typedef(tc_classPrimitives_o));
}

tc_classPrimitives tc_classPrimitives__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_classPrimitives_o));
}

int tc_classPrimitives__define(tc_classPrimitives _this, db_bool a, db_char b, db_int32 c, db_float32 d, db_string e, tc_color f, tc_moveMode g) {
    _this->a = a;
    _this->b = b;
    _this->c = c;
    _this->d = d;
    _this->e = (e ? db_strdup(e) : NULL);
    _this->f = f;
    _this->g = g;
    return db_define(_this);
}

tc_classPrimitives tc_classPrimitives__create(db_bool a, db_char b, db_int32 c, db_float32 d, db_string e, tc_color f, tc_moveMode g) {
    tc_classPrimitives _this;
    _this = db_new(db_typedef(tc_classPrimitives_o));
    _this->a = a;
    _this->b = b;
    _this->c = c;
    _this->d = d;
    _this->e = (e ? db_strdup(e) : NULL);
    _this->f = f;
    _this->g = g;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

