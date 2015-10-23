/*
 * corto_util.h
 *
 *  Created on: Apr 10, 2012
 *      Author: sander
 */

#ifndef CORTO_UTIL_H_
#define CORTO_UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Mark variable(parameter) as unused */
#define CORTO_UNUSED(p) (void)p

/* Calculate offset */
#define CORTO_OFFSET(o, offset) (void*)(((uintptr_t)o) + ((uintptr_t)offset))

/* Determine alignment of struct */
#define CORTO_ALIGNMENT(t) ((corto_word)(&((struct {corto_char dummy;t alignMember;}*)(void *)0)->alignMember))

/* Determine offset based on size of type and alignment */
#define CORTO_ALIGN(size,alignment) ((((size-1)/alignment)+1)*alignment)

/* Hash for primitive typekinds. Enables quick lookup of transformations and operators for primitive types. */
#define CORTO_PWIDTH(width) ((width == CORTO_WIDTH_8) ? 0 : (width == CORTO_WIDTH_16) ? 1 : (width == CORTO_WIDTH_32) ? 2 : (width == CORTO_WIDTH_64) ? 3 : -1)
#define CORTO_TYPEHASH_VARWIDTH(kind, width) (kind * (CORTO_FLOAT+1)) + ((int[4]){0, CORTO_FLOAT, CORTO_FLOAT * 2, CORTO_FLOAT * 3}[CORTO_PWIDTH(width)])
#define CORTO_TYPEHASH(kind, width) (kind <= CORTO_FLOAT ? CORTO_TYPEHASH_VARWIDTH(kind, width) : CORTO_TYPEHASH_VARWIDTH(CORTO_FLOAT, CORTO_WIDTH_64) + (kind-CORTO_FLOAT))
#define CORTO_TYPEHASH_MAX (50)

/* 16bit value for convenient matching on scope-characters */
#define CORTO_SCOPE_HEX ((corto_uint16)(0x3A3A)) /* '::' */

#ifdef __cplusplus
}
#endif

#endif /* CORTO_UTIL_H_ */
