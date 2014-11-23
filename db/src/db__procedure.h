/*
 * db__procedure.h
 *
 *  Created on: Oct 23, 2012
 *      Author: sander
 */

#ifndef DB__PROCEDURE_H_
#define DB__PROCEDURE_H_

#include "db_procedure.h"

#ifdef __cplusplus
extern "C" {
#endif

db_int16 db__function_bindParameter(db_function _this, db_parameter o);

#ifdef __cplusplus
}
#endif

#endif /* DB__PROCEDURE_H_ */
