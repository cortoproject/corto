/* fixture__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef fixture__API_H
#define fixture__API_H

#include "fixture__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::fixture::Dog */
fixture_Dog fixture_Dog__new(void);
fixture_Dog fixture_Dog__declare(db_object _parent, db_string _name);
int fixture_Dog__define(fixture_Dog _this, fixture_DogBreed breed, db_string name, db_uint8 age, fixture_Dog lover);
fixture_Dog fixture_Dog__create(fixture_DogBreed breed, db_string name, db_uint8 age, fixture_Dog lover);


#ifdef __cplusplus
}
#endif
#endif

