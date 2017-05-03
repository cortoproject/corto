/*
 * ptr.h
 *
 *  Created on: Aug 8, 2013
 *      Author: sander
 */

#ifndef CORTO_PTR_H_
#define CORTO_PTR_H_

#ifdef __cplusplus
extern "C" {
#endif

void corto_operatorInit(void);
CORTO_EXPORT void corto_ptr_castInit(void);

/* Create heap objects for non-reference types */
CORTO_EXPORT void* _corto_ptr_new(corto_type type);
CORTO_EXPORT void _corto_ptr_free(corto_type type, void *ptr);

CORTO_EXPORT int16_t corto_ptr_unaryOp(corto_type type, corto_operatorKind _operator, void* operand, void* result);
CORTO_EXPORT int16_t corto_ptr_binaryOp(corto_type type, corto_operatorKind _operator, void *operand1, void *operand2, void *result);
CORTO_EXPORT int16_t _corto_ptr_cast(corto_type fromType, void *from, corto_type toType, void *to);
CORTO_EXPORT char *_corto_ptr_str(void *p, corto_type type, uint32_t maxLength);
CORTO_EXPORT int16_t _corto_ptr_fromStr(void *p, corto_type type, char *string);
CORTO_EXPORT int16_t _corto_ptr_copy(void *dst, corto_type type, void *src);
CORTO_EXPORT corto_equalityKind _corto_ptr_compare(void *p1, corto_type type, void *p2);
CORTO_EXPORT int16_t _corto_ptr_init(void *v, corto_type type);
CORTO_EXPORT int16_t _corto_ptr_deinit(void *v, corto_type type);

CORTO_EXPORT void corto_setref(void* ptr, corto_object value);
CORTO_EXPORT void corto_setstr(corto_string* ptr, char *value);

#define corto_ptr_cast(fromType, from, toType, to) _corto_ptr_cast(corto_type(fromType), from, corto_type(toType), to)
#define corto_ptr_str(p, type, maxLength) _corto_ptr_str(p, corto_type(type), maxLength)
#define corto_ptr_fromStr(out, type, string) _corto_ptr_fromStr(out, corto_type(type), string)
#define corto_ptr_copy(p, type, src) _corto_ptr_copy(p, corto_type(type), src)
#define corto_ptr_compare(p1, type, p2) _corto_ptr_compare(p1, corto_type(type), p2)
#define corto_ptr_init(p, type) _corto_ptr_init(p, corto_type(type))
#define corto_ptr_deinit(p, type) _corto_ptr_deinit(p, corto_type(type))
#define corto_ptr_new(type) _corto_ptr_new(corto_type(type))
#define corto_ptr_free(type, ptr) _corto_ptr_free(corto_type(type), ptr)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_PTR_H_ */
