/*
 * cx_util.h
 *
 *  Created on: Apr 10, 2012
 *      Author: sander
 */

#ifndef DB_UTIL_H_
#define DB_UTIL_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Mark variable(parameter) as unused */
#define DB_UNUSED(p) (void)p

/* Calculate offset */
#define DB_OFFSET(o, offset) (void*)(((uintptr_t)o) + ((uintptr_t)offset))

/* Determine alignment of struct */
#define DB_ALIGNMENT(t) ((cx_word)(&((struct {cx_char dummy;t alignMember;}*)(void *)0)->alignMember))

/* Determine offset based on size of type and alignment */
#define DB_ALIGN(size,alignment) ((((size-1)/alignment)+1)*alignment)

/* Hash for primitive typekinds. Enables quick lookup of transformations and operators for primitive types. */
#define DB_PWIDTH(width) ((width == DB_WIDTH_8) ? 0 : (width == DB_WIDTH_16) ? 1 : (width == DB_WIDTH_32) ? 2 : (width == DB_WIDTH_64) ? 3 : -1)
#define DB_TYPEHASH_VARWIDTH(kind, width) (kind * (DB_FLOAT+1)) + ((int[4]){0, DB_FLOAT, DB_FLOAT * 2, DB_FLOAT * 3}[DB_PWIDTH(width)])
#define DB_TYPEHASH(kind, width) (kind <= DB_FLOAT ? DB_TYPEHASH_VARWIDTH(kind, width) : DB_TYPEHASH_VARWIDTH(DB_FLOAT, DB_WIDTH_64) + (kind-DB_FLOAT))
#define DB_TYPEHASH_MAX (50)

/* 16bit value for convenient matching on scope-characters */
#define DB_SCOPE_HEX ((cx_uint16)(0x3A3A)) /* '::' */

#ifdef __cplusplus
}
#endif

#endif /* DB_UTIL_H_ */
