/* tc_jsonser__api.h
 *
 *  Generated on Dec 15 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_jsonser__API_H
#define tc_jsonser__API_H

#include "tc_jsonser__type.h"
#include "hyve.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::tc_jsonser::Dog */
tc_jsonser_Dog tc_jsonser_Dog__new(void);
tc_jsonser_Dog tc_jsonser_Dog__declare(db_object _parent, db_string _name);
int tc_jsonser_Dog__define(tc_jsonser_Dog _this, tc_jsonser_DogBreed breed, db_string name, db_uint8 age, tc_jsonser_Dog lover);
tc_jsonser_Dog tc_jsonser_Dog__create(tc_jsonser_DogBreed breed, db_string name, db_uint8 age, tc_jsonser_Dog lover);


#ifdef __cplusplus
}
#endif
#endif

