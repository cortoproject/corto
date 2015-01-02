/*
 * cx_util.h
 *
 *  Created on: Apr 10, 2012
 *      Author: sander
 */

#ifndef CX_UTIL_H_
#define CX_UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Mark variable(parameter) as unused */
#define CX_UNUSED(p) (void)p

/* Calculate offset */
#define CX_OFFSET(o, offset) (void*)(((uintptr_t)o) + ((uintptr_t)offset))

/* Determine alignment of struct */
#define CX_ALIGNMENT(t) ((cx_word)(&((struct {cx_char dummy;t alignMember;}*)(void *)0)->alignMember))

/* Determine offset based on size of type and alignment */
#define CX_ALIGN(size,alignment) ((((size-1)/alignment)+1)*alignment)

/* Hash for primitive typekinds. Enables quick lookup of transformations and operators for primitive types. */
#define CX_PWIDTH(width) ((width == CX_WIDTH_8) ? 0 : (width == CX_WIDTH_16) ? 1 : (width == CX_WIDTH_32) ? 2 : (width == CX_WIDTH_64) ? 3 : -1)
#define CX_TYPEHASH_VARWIDTH(kind, width) (kind * (CX_FLOAT+1)) + ((int[4]){0, CX_FLOAT, CX_FLOAT * 2, CX_FLOAT * 3}[CX_PWIDTH(width)])
#define CX_TYPEHASH(kind, width) (kind <= CX_FLOAT ? CX_TYPEHASH_VARWIDTH(kind, width) : CX_TYPEHASH_VARWIDTH(CX_FLOAT, CX_WIDTH_64) + (kind-CX_FLOAT))
#define CX_TYPEHASH_MAX (50)

/* 16bit value for convenient matching on scope-characters */
#define CX_SCOPE_HEX ((cx_uint16)(0x3A3A)) /* '::' */

#ifdef __cplusplus
}
#endif

#endif /* CX_UTIL_H_ */
