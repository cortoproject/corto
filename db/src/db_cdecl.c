/*
 * db_conv_cdecl.c
 *
 *  Created on: May 22, 2012
 *      Author: sander
 */

#include "db_call.h"
#include "db_mem.h"
#include "db_err.h"
#include "db_util.h"

enum db_cdeclKind {
	CDECL_WORD_RETURN,
	CDECL_DOUBLE_RETURN,
	CDECL_COMPLEX_RETURN
};

/* Get cdeclKind of function type */
static enum db_cdeclKind db_getCdeclKind(db_function t) {
	enum db_cdeclKind result;
	db_type returnType;

	result = CDECL_WORD_RETURN;

	if (t->returnType && (returnType = t->returnType->real)) {
        switch(returnType->kind) {
        case DB_VOID:
            break;
        case DB_PRIMITIVE:
            switch(((db_primitive)returnType)->kind) {
            case DB_FLOAT:
                switch(((db_primitive)returnType)->width) {
                case DB_WIDTH_64:
                    result = CDECL_DOUBLE_RETURN;
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            break;
        case DB_COLLECTION:
            switch(db_collection(returnType)->kind) {
            case DB_ARRAY:
            case DB_SEQUENCE:
                result = CDECL_COMPLEX_RETURN;
                break;
            case DB_LIST:
            case DB_MAP:
                break;
            }
            break;
        default:
            if (!returnType->reference) {
                result = CDECL_COMPLEX_RETURN;
            }
            break;
        }
	}

	return result;
}

/* Call function with word-sized returntype */
void db_call_cdecl_word(void(*_f)(void), volatile db_uint32 _size, db_void* result, db_word* args);

/* Call function with double-sized returntype */
void db_call_cdecl_double(void(*_f)(void), db_uint32 _size, db_void* result, db_word* args);

/* Call function with complex returntype */
void db_call_cdecl_complex(void(*_f)(void), db_uint32 _size, db_void* result, db_word* args);

/* Call cdecl function */
void db_call_cdecl(db_function f, db_void* result, void* args) {
    if (!f->impludata) {
        switch(db_getCdeclKind(f)) {
        case CDECL_WORD_RETURN:
            f->impludata = (db_word)db_call_cdecl_word;
            break;
        case CDECL_DOUBLE_RETURN:
            f->impludata = (db_word)db_call_cdecl_double;
            break;
        case CDECL_COMPLEX_RETURN:
            f->impludata = (db_word)db_call_cdecl_complex;
            break;
        default:
            db_critical("invalid cdecl kind returned by db_getCdeclKind.");
            /* no break */
        }
    }
    ((void(*)(void(*_f)(void),db_uint32,db_void*,db_word*))f->impludata)((void(*)(void))f->impl, f->size, result, args);
}

