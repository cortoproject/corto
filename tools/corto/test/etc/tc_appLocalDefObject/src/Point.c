/* Point.c
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#include <include/Point.h>
#include <include/_api.h>
Point* _PointCreate(corto_int32 x, corto_int32 y) {
    Point* _this;
    _this = Point(corto_declare(Point_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((Point*)_this)->x = x;
        ((Point*)_this)->y = y;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

Point* _PointCreateChild(corto_object _parent, corto_string _id, corto_int32 x, corto_int32 y) {
    Point* _this;
    _this = Point(corto_declareChild(_parent, _id, Point_o));
    if (!_this) {
        return NULL;
    }
    if (!corto_checkState(_this, CORTO_DEFINED)) {
        ((Point*)_this)->x = x;
        ((Point*)_this)->y = y;
        if (corto_define(_this)) {
            corto_release(_this);
            _this = NULL;
        }
    }
    return _this;
}

corto_int16 _PointUpdate(Point* _this, corto_int32 x, corto_int32 y) {
    CORTO_UNUSED(_this);
    if (!corto_updateBegin(_this)) {
        if ((corto_typeof(corto_typeof(_this)) == (corto_type)corto_target_o) && !corto_owned(_this)) {
            ((Point*)((Point*)CORTO_OFFSET(_this, ((corto_type)Point_o)->size)))->x = x;
            ((Point*)((Point*)CORTO_OFFSET(_this, ((corto_type)Point_o)->size)))->y = y;
        } else {
            ((Point*)_this)->x = x;
            ((Point*)_this)->y = y;
        }
        corto_updateEnd(_this);
    } else {
        return -1;
    }
    return 0;
}

Point* _PointDeclare(void) {
    Point* _this;
    _this = Point(corto_declare(Point_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

Point* _PointDeclareChild(corto_object _parent, corto_string _id) {
    Point* _this;
    _this = Point(corto_declareChild(_parent, _id, Point_o));
    if (!_this) {
        return NULL;
    }
    return _this;
}

corto_int16 _PointDefine(Point* _this, corto_int32 x, corto_int32 y) {
    CORTO_UNUSED(_this);
    ((Point*)_this)->x = x;
    ((Point*)_this)->y = y;
    return corto_define(_this);
}

Point* _PointAssign(Point* _this, corto_int32 x, corto_int32 y) {
    CORTO_UNUSED(_this);
    ((Point*)_this)->x = x;
    ((Point*)_this)->y = y;
    return _this;
}

corto_string _PointStr(Point* value) {
    corto_string result;
    corto_value v;
    v = corto_value_value(corto_type(Point_o), value);
    result = corto_strv(&v, 0);
    return result;
}

Point* PointFromStr(Point* value, corto_string str) {
    corto_fromStrp(&value, corto_type(Point_o), str);
    return value;
}

corto_equalityKind PointCompare(Point* dst, Point* src) {
    return corto_comparep(dst, Point_o, src);
}

corto_int16 _PointInit(Point* value) {
    corto_int16 result;
    memset(value, 0, corto_type(Point_o)->size);
    corto_value v;
    v = corto_value_value(corto_type(Point_o), value);
    result = corto_initv(&v);
    return result;
}

corto_int16 _PointDeinit(Point* value) {
    corto_int16 result;
    corto_value v;
    v = corto_value_value(corto_type(Point_o), value);
    result = corto_deinitv(&v);
    return result;
}

