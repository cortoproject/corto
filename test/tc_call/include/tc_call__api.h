/* tc_call__api.h
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_call__API_H
#define tc_call__API_H

#include "tc_call__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_call::Animal */
tc_Animal tc_Animal__new(void);
tc_Animal tc_Animal__declare(db_object _parent, db_string _name);
int tc_Animal__define(tc_Animal _this, tc_AnimalKind kind);
tc_Animal tc_Animal__create(tc_AnimalKind kind);

/* ::tc_call::Mammal */
tc_Mammal tc_Mammal__new(void);
tc_Mammal tc_Mammal__declare(db_object _parent, db_string _name);
int tc_Mammal__define(tc_Mammal _this, tc_MammalKind kind);
tc_Mammal tc_Mammal__create(tc_MammalKind kind);


#ifdef __cplusplus
}
#endif
#endif

