/* ic__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef ic__API_H
#define ic__API_H

#include "ic__type.h"
#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::corto::ic::accumulator */
ic_accumulator ic_accumulator__create(cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);
ic_accumulator ic_accumulator__createChild(cx_object _parent, cx_string _name, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);

ic_accumulator ic_accumulator__declare(void);
ic_accumulator ic_accumulator__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_accumulator__define(ic_accumulator _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);
void ic_accumulator__update(ic_accumulator _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);
void ic_accumulator__set(ic_accumulator _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);
cx_string ic_accumulator__str(ic_accumulator value);
ic_accumulator ic_accumulator__fromStr(ic_accumulator value, cx_string str);
cx_int16 ic_accumulator__copy(ic_accumulator *dst, ic_accumulator src);
cx_int16 ic_accumulator__compare(ic_accumulator dst, ic_accumulator src);

/* ::corto::ic::address */
ic_address ic_address__create(cx_word value);
ic_address ic_address__createChild(cx_object _parent, cx_string _name, cx_word value);

ic_address ic_address__declare(void);
ic_address ic_address__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_address__define(ic_address _this, cx_word value);
void ic_address__update(ic_address _this, cx_word value);
void ic_address__set(ic_address _this, cx_word value);
cx_string ic_address__str(ic_address value);
ic_address ic_address__fromStr(ic_address value, cx_string str);
cx_int16 ic_address__copy(ic_address *dst, ic_address src);
cx_int16 ic_address__compare(ic_address dst, ic_address src);

/* ::corto::ic::derefKind */
ic_derefKind* ic_derefKind__create(void);
ic_derefKind* ic_derefKind__createChild(cx_object _parent, cx_string _name);

ic_derefKind* ic_derefKind__declare(void);
ic_derefKind* ic_derefKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_derefKind__define(ic_derefKind* _this, ic_derefKind value);
void ic_derefKind__update(ic_derefKind* _this, ic_derefKind value);
void ic_derefKind__set(ic_derefKind* _this, ic_derefKind value);
cx_string ic_derefKind__str(ic_derefKind value);
ic_derefKind* ic_derefKind__fromStr(ic_derefKind* value, cx_string str);
cx_int16 ic_derefKind__copy(ic_derefKind* *dst, ic_derefKind* src);
cx_int16 ic_derefKind__compare(ic_derefKind* dst, ic_derefKind* src);

cx_int16 ic_derefKind__init(ic_derefKind* value);
cx_int16 ic_derefKind__deinit(ic_derefKind* value);

/* ::corto::ic::element */
ic_element ic_element__create(ic_storage base_1, ic_node index);
ic_element ic_element__createChild(cx_object _parent, cx_string _name, ic_storage base_1, ic_node index);

ic_element ic_element__declare(void);
ic_element ic_element__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_element__define(ic_element _this, ic_storage base_1, ic_node index);
void ic_element__update(ic_element _this, ic_storage base_1, ic_node index);
void ic_element__set(ic_element _this, ic_storage base_1, ic_node index);
cx_string ic_element__str(ic_element value);
ic_element ic_element__fromStr(ic_element value, cx_string str);
cx_int16 ic_element__copy(ic_element *dst, ic_element src);
cx_int16 ic_element__compare(ic_element dst, ic_element src);

/* ::corto::ic::function */
ic_function ic_function__create(cx_function function);
ic_function ic_function__createChild(cx_object _parent, cx_string _name, cx_function function);

ic_function ic_function__declare(void);
ic_function ic_function__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_function__define(ic_function _this, cx_function function);
void ic_function__update(ic_function _this, cx_function function);
void ic_function__set(ic_function _this, cx_function function);
cx_string ic_function__str(ic_function value);
ic_function ic_function__fromStr(ic_function value, cx_string str);
cx_int16 ic_function__copy(ic_function *dst, ic_function src);
cx_int16 ic_function__compare(ic_function dst, ic_function src);

/* ::corto::ic::kind */
ic_kind* ic_kind__create(void);
ic_kind* ic_kind__createChild(cx_object _parent, cx_string _name);

ic_kind* ic_kind__declare(void);
ic_kind* ic_kind__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_kind__define(ic_kind* _this, ic_kind value);
void ic_kind__update(ic_kind* _this, ic_kind value);
void ic_kind__set(ic_kind* _this, ic_kind value);
cx_string ic_kind__str(ic_kind value);
ic_kind* ic_kind__fromStr(ic_kind* value, cx_string str);
cx_int16 ic_kind__copy(ic_kind* *dst, ic_kind* src);
cx_int16 ic_kind__compare(ic_kind* dst, ic_kind* src);

cx_int16 ic_kind__init(ic_kind* value);
cx_int16 ic_kind__deinit(ic_kind* value);

/* ::corto::ic::label */
ic_label ic_label__create(void);
ic_label ic_label__createChild(cx_object _parent, cx_string _name);

ic_label ic_label__declare(void);
ic_label ic_label__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_label__define(ic_label _this);
void ic_label__update(ic_label _this);
void ic_label__set(ic_label _this);
cx_string ic_label__str(ic_label value);
ic_label ic_label__fromStr(ic_label value, cx_string str);
cx_int16 ic_label__copy(ic_label *dst, ic_label src);
cx_int16 ic_label__compare(ic_label dst, ic_label src);

/* ::corto::ic::literal */
ic_literal ic_literal__create(cx_any value);
ic_literal ic_literal__createChild(cx_object _parent, cx_string _name, cx_any value);

ic_literal ic_literal__declare(void);
ic_literal ic_literal__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_literal__define(ic_literal _this, cx_any value);
void ic_literal__update(ic_literal _this, cx_any value);
void ic_literal__set(ic_literal _this, cx_any value);
cx_string ic_literal__str(ic_literal value);
ic_literal ic_literal__fromStr(ic_literal value, cx_string str);
cx_int16 ic_literal__copy(ic_literal *dst, ic_literal src);
cx_int16 ic_literal__compare(ic_literal dst, ic_literal src);

/* ::corto::ic::member */
ic_member ic_member__create(ic_storage base_1, cx_member member);
ic_member ic_member__createChild(cx_object _parent, cx_string _name, ic_storage base_1, cx_member member);

ic_member ic_member__declare(void);
ic_member ic_member__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_member__define(ic_member _this, ic_storage base_1, cx_member member);
void ic_member__update(ic_member _this, ic_storage base_1, cx_member member);
void ic_member__set(ic_member _this, ic_storage base_1, cx_member member);
cx_string ic_member__str(ic_member value);
ic_member ic_member__fromStr(ic_member value, cx_string str);
cx_int16 ic_member__copy(ic_member *dst, ic_member src);
cx_int16 ic_member__compare(ic_member dst, ic_member src);

/* ::corto::ic::node */
ic_node ic_node__create(void);
ic_node ic_node__createChild(cx_object _parent, cx_string _name);

ic_node ic_node__declare(void);
ic_node ic_node__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_node__define(ic_node _this);
void ic_node__update(ic_node _this);
void ic_node__set(ic_node _this);
cx_string ic_node__str(ic_node value);
ic_node ic_node__fromStr(ic_node value, cx_string str);
cx_int16 ic_node__copy(ic_node *dst, ic_node src);
cx_int16 ic_node__compare(ic_node dst, ic_node src);

/* ::corto::ic::object */
ic_object ic_object__create(cx_object ptr);
ic_object ic_object__createChild(cx_object _parent, cx_string _name, cx_object ptr);

ic_object ic_object__declare(void);
ic_object ic_object__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_object__define(ic_object _this, cx_object ptr);
void ic_object__update(ic_object _this, cx_object ptr);
void ic_object__set(ic_object _this, cx_object ptr);
cx_string ic_object__str(ic_object value);
ic_object ic_object__fromStr(ic_object value, cx_string str);
cx_int16 ic_object__copy(ic_object *dst, ic_object src);
cx_int16 ic_object__compare(ic_object dst, ic_object src);

/* ::corto::ic::op */
ic_op ic_op__create(cx_uint32 line, ic_opKind kind_1, ic_node s1, ic_node s2, ic_node s3, ic_derefKind s1Deref, ic_derefKind s2Deref, ic_derefKind s3Deref, cx_bool s1Any);
ic_op ic_op__createChild(cx_object _parent, cx_string _name, cx_uint32 line, ic_opKind kind_1, ic_node s1, ic_node s2, ic_node s3, ic_derefKind s1Deref, ic_derefKind s2Deref, ic_derefKind s3Deref, cx_bool s1Any);

ic_op ic_op__declare(void);
ic_op ic_op__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_op__define(ic_op _this, cx_uint32 line, ic_opKind kind_1, ic_node s1, ic_node s2, ic_node s3, ic_derefKind s1Deref, ic_derefKind s2Deref, ic_derefKind s3Deref, cx_bool s1Any);
void ic_op__update(ic_op _this, cx_uint32 line, ic_opKind kind_1, ic_node s1, ic_node s2, ic_node s3, ic_derefKind s1Deref, ic_derefKind s2Deref, ic_derefKind s3Deref, cx_bool s1Any);
void ic_op__set(ic_op _this, cx_uint32 line, ic_opKind kind_1, ic_node s1, ic_node s2, ic_node s3, ic_derefKind s1Deref, ic_derefKind s2Deref, ic_derefKind s3Deref, cx_bool s1Any);
cx_string ic_op__str(ic_op value);
ic_op ic_op__fromStr(ic_op value, cx_string str);
cx_int16 ic_op__copy(ic_op *dst, ic_op src);
cx_int16 ic_op__compare(ic_op dst, ic_op src);

/* ::corto::ic::opKind */
ic_opKind* ic_opKind__create(void);
ic_opKind* ic_opKind__createChild(cx_object _parent, cx_string _name);

ic_opKind* ic_opKind__declare(void);
ic_opKind* ic_opKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_opKind__define(ic_opKind* _this, ic_opKind value);
void ic_opKind__update(ic_opKind* _this, ic_opKind value);
void ic_opKind__set(ic_opKind* _this, ic_opKind value);
cx_string ic_opKind__str(ic_opKind value);
ic_opKind* ic_opKind__fromStr(ic_opKind* value, cx_string str);
cx_int16 ic_opKind__copy(ic_opKind* *dst, ic_opKind* src);
cx_int16 ic_opKind__compare(ic_opKind* dst, ic_opKind* src);

cx_int16 ic_opKind__init(ic_opKind* value);
cx_int16 ic_opKind__deinit(ic_opKind* value);

/* ::corto::ic::program */
ic_program ic_program__create(cx_string filename);
ic_program ic_program__createChild(cx_object _parent, cx_string _name, cx_string filename);

ic_program ic_program__declare(void);
ic_program ic_program__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_program__define(ic_program _this, cx_string filename);
void ic_program__update(ic_program _this, cx_string filename);
void ic_program__set(ic_program _this, cx_string filename);
cx_string ic_program__str(ic_program value);
ic_program ic_program__fromStr(ic_program value, cx_string str);
cx_int16 ic_program__copy(ic_program *dst, ic_program src);
cx_int16 ic_program__compare(ic_program dst, ic_program src);

/* ::corto::ic::scope */
ic_scope ic_scope__create(ic_scope parent, cx_bool isFunction);
ic_scope ic_scope__createChild(cx_object _parent, cx_string _name, ic_scope parent, cx_bool isFunction);

ic_scope ic_scope__declare(void);
ic_scope ic_scope__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_scope__define(ic_scope _this, ic_scope parent, cx_bool isFunction);
void ic_scope__update(ic_scope _this, ic_scope parent, cx_bool isFunction);
void ic_scope__set(ic_scope _this, ic_scope parent, cx_bool isFunction);
cx_string ic_scope__str(ic_scope value);
ic_scope ic_scope__fromStr(ic_scope value, cx_string str);
cx_int16 ic_scope__copy(ic_scope *dst, ic_scope src);
cx_int16 ic_scope__compare(ic_scope dst, ic_scope src);

/* ::corto::ic::storage */
ic_storage ic_storage__create(cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);
ic_storage ic_storage__createChild(cx_object _parent, cx_string _name, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);

ic_storage ic_storage__declare(void);
ic_storage ic_storage__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_storage__define(ic_storage _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);
void ic_storage__update(ic_storage _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);
void ic_storage__set(ic_storage _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn);
cx_string ic_storage__str(ic_storage value);
ic_storage ic_storage__fromStr(ic_storage value, cx_string str);
cx_int16 ic_storage__copy(ic_storage *dst, ic_storage src);
cx_int16 ic_storage__compare(ic_storage dst, ic_storage src);

/* ::corto::ic::storageKind */
ic_storageKind* ic_storageKind__create(void);
ic_storageKind* ic_storageKind__createChild(cx_object _parent, cx_string _name);

ic_storageKind* ic_storageKind__declare(void);
ic_storageKind* ic_storageKind__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_storageKind__define(ic_storageKind* _this, ic_storageKind value);
void ic_storageKind__update(ic_storageKind* _this, ic_storageKind value);
void ic_storageKind__set(ic_storageKind* _this, ic_storageKind value);
cx_string ic_storageKind__str(ic_storageKind value);
ic_storageKind* ic_storageKind__fromStr(ic_storageKind* value, cx_string str);
cx_int16 ic_storageKind__copy(ic_storageKind* *dst, ic_storageKind* src);
cx_int16 ic_storageKind__compare(ic_storageKind* dst, ic_storageKind* src);

cx_int16 ic_storageKind__init(ic_storageKind* value);
cx_int16 ic_storageKind__deinit(ic_storageKind* value);

/* ::corto::ic::variable */
ic_variable ic_variable__create(cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn, cx_bool isParameter, cx_bool isReturn);
ic_variable ic_variable__createChild(cx_object _parent, cx_string _name, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn, cx_bool isParameter, cx_bool isReturn);

ic_variable ic_variable__declare(void);
ic_variable ic_variable__declareChild(cx_object _parent, cx_string _name);
cx_int16 ic_variable__define(ic_variable _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn, cx_bool isParameter, cx_bool isReturn);
void ic_variable__update(ic_variable _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn, cx_bool isParameter, cx_bool isReturn);
void ic_variable__set(ic_variable _this, cx_string name, cx_type type, cx_bool isReference, cx_bool holdsReturn, cx_bool isParameter, cx_bool isReturn);
cx_string ic_variable__str(ic_variable value);
ic_variable ic_variable__fromStr(ic_variable value, cx_string str);
cx_int16 ic_variable__copy(ic_variable *dst, ic_variable src);
cx_int16 ic_variable__compare(ic_variable dst, ic_variable src);


/* <0x7f8b80d0e128> */
#define ic_label_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    ic_label elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void ic_label_list__insert(ic_label_list list, ic_label element);
void ic_label_list__append(ic_label_list list, ic_label element);
ic_label ic_label_list__takeFirst(ic_label_list list);
ic_label ic_label_list__last(ic_label_list list);
void ic_label_list__clear(ic_label_list list);
ic_label ic_label_list__get(ic_label_list list, cx_uint32 index);
cx_uint32 ic_label_list__size(ic_label_list list);

/* <0x7f8b80d0eb98> */
#define ic_literal_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    ic_literal elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void ic_literal_list__insert(ic_literal_list list, ic_literal element);
void ic_literal_list__append(ic_literal_list list, ic_literal element);
ic_literal ic_literal_list__takeFirst(ic_literal_list list);
ic_literal ic_literal_list__last(ic_literal_list list);
void ic_literal_list__clear(ic_literal_list list);
ic_literal ic_literal_list__get(ic_literal_list list, cx_uint32 index);
cx_uint32 ic_literal_list__size(ic_literal_list list);

/* <0x7f8b80d0b308> */
#define ic_node_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    ic_node elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void ic_node_list__insert(ic_node_list list, ic_node element);
void ic_node_list__append(ic_node_list list, ic_node element);
ic_node ic_node_list__takeFirst(ic_node_list list);
ic_node ic_node_list__last(ic_node_list list);
void ic_node_list__clear(ic_node_list list);
ic_node ic_node_list__get(ic_node_list list, cx_uint32 index);
cx_uint32 ic_node_list__size(ic_node_list list);

/* <0x7f8b80d0f658> */
#define ic_op_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    ic_op elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void ic_op_list__insert(ic_op_list list, ic_op element);
void ic_op_list__append(ic_op_list list, ic_op element);
ic_op ic_op_list__takeFirst(ic_op_list list);
ic_op ic_op_list__last(ic_op_list list);
void ic_op_list__clear(ic_op_list list);
ic_op ic_op_list__get(ic_op_list list, cx_uint32 index);
cx_uint32 ic_op_list__size(ic_op_list list);

/* <0x7f8b80d0da28> */
#define ic_scope_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    ic_scope elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void ic_scope_list__insert(ic_scope_list list, ic_scope element);
void ic_scope_list__append(ic_scope_list list, ic_scope element);
ic_scope ic_scope_list__takeFirst(ic_scope_list list);
ic_scope ic_scope_list__last(ic_scope_list list);
void ic_scope_list__clear(ic_scope_list list);
ic_scope ic_scope_list__get(ic_scope_list list, cx_uint32 index);
cx_uint32 ic_scope_list__size(ic_scope_list list);

/* <0x7f8b80d0d378> */
#define ic_storage_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    ic_storage elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void ic_storage_list__insert(ic_storage_list list, ic_storage element);
void ic_storage_list__append(ic_storage_list list, ic_storage element);
ic_storage ic_storage_list__takeFirst(ic_storage_list list);
ic_storage ic_storage_list__last(ic_storage_list list);
void ic_storage_list__clear(ic_storage_list list);
ic_storage ic_storage_list__get(ic_storage_list list, cx_uint32 index);
cx_uint32 ic_storage_list__size(ic_storage_list list);

/* <0x7f8b80d0e838> */
#define cx_function_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_function elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void cx_function_list__insert(cx_function_list list, cx_function element);
void cx_function_list__append(cx_function_list list, cx_function element);
cx_function cx_function_list__takeFirst(cx_function_list list);
cx_function cx_function_list__last(cx_function_list list);
void cx_function_list__clear(cx_function_list list);
cx_function cx_function_list__get(cx_function_list list, cx_uint32 index);
cx_uint32 cx_function_list__size(cx_function_list list);

#ifdef __cplusplus
}
#endif
#endif

