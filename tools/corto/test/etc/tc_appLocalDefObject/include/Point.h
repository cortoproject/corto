/* Point.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef POINT__API_H
#define POINT__API_H

#include <corto/corto.h>
#include <include/_project.h>
#include <include/_type.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /Point */
POINT_EXPORT Point* _PointCreate(corto_int32 x, corto_int32 y);
#define PointCreate(x, y) _PointCreate(x, y)
#define PointCreate_auto(_id, x, y) Point* _id = PointCreate(x, y); (void)_id
POINT_EXPORT Point* _PointCreateChild(corto_object _parent, corto_string _id, corto_int32 x, corto_int32 y);
#define PointCreateChild(_parent, _id, x, y) _PointCreateChild(_parent, _id, x, y)
#define PointCreateChild_auto(_parent, _id, x, y) Point* _id = PointCreateChild(_parent, #_id, x, y); (void)_id
POINT_EXPORT corto_int16 _PointUpdate(Point* _this, corto_int32 x, corto_int32 y);
#define PointUpdate(_this, x, y) _PointUpdate(Point(_this), x, y)

POINT_EXPORT Point* _PointDeclare(void);
#define PointDeclare() _PointDeclare()
#define PointDeclare_auto(_id) Point* _id = PointDeclare(); (void)_id
POINT_EXPORT Point* _PointDeclareChild(corto_object _parent, corto_string _id);
#define PointDeclareChild(_parent, _id) _PointDeclareChild(_parent, _id)
#define PointDeclareChild_auto(_parent, _id) Point* _id = PointDeclareChild(_parent, #_id); (void)_id
POINT_EXPORT corto_int16 _PointDefine(Point* _this, corto_int32 x, corto_int32 y);
#define PointDefine(_this, x, y) _PointDefine(Point(_this), x, y)
POINT_EXPORT Point* _PointAssign(Point* _this, corto_int32 x, corto_int32 y);
#define Point__optional_NotSet NULL
#define Point__optional_Set(x, y) PointAssign((Point*)corto_calloc(sizeof(Point)), x, y)
#define Point__optional_SetCond(cond, x, y) cond ? PointAssign((Point*)corto_calloc(sizeof(Point)), x, y) : NULL
#define PointUnset(_this) _this ? corto_deinitp(_this, Point_o) : 0; corto_dealloc(_this); _this = NULL;
#define PointAssign(_this, x, y) _PointAssign(_this, x, y)
#define PointSet(_this, x, y) _this = _this ? _this : (Point*)corto_calloc(sizeof(Point)); _PointAssign(_this, x, y)
POINT_EXPORT corto_string _PointStr(Point* value);
#define PointStr(value) _PointStr(value)
POINT_EXPORT Point* PointFromStr(Point* value, corto_string str);
POINT_EXPORT corto_equalityKind PointCompare(Point* dst, Point* src);

POINT_EXPORT corto_int16 _PointInit(Point* value);
#define PointInit(value) _PointInit(value)
POINT_EXPORT corto_int16 _PointDeinit(Point* value);
#define PointDeinit(value) _PointDeinit(value)


#ifdef __cplusplus
}
#endif
#endif

