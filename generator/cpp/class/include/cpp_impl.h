/*
 * cpp_classImpl.h
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#ifndef CPP_CLASSIMPL_H_
#define CPP_CLASSIMPL_H_

#include "cortex.h"
#include "db_generator.h"

#ifdef __cplusplus
extern "C" {
#endif

int cpp_impl(db_object o, db_generator g);
void cpp_constructorDecl(db_generator g, g_file file, db_interface o, db_bool inlined);
void cpp_constructorScopedDecl(db_generator g, g_file file, db_interface o, db_bool inlined);
void cpp_constructorHandleDecl(db_generator g, g_file file, db_interface o, db_bool inlined);
void cpp_handleGetDecl(db_generator g, g_file file, db_interface o, db_bool inlined);
void cpp_functionDecl(db_generator g, g_file file, db_function o, db_bool inlined);
void cpp_functionDeclExt(db_generator g, g_file file, db_function o, db_bool inlined, db_bool virtualStub);
void cpp_memberGetter(db_generator g, g_file file, db_member o, db_bool inlined);
void cpp_memberSetter(db_generator g, g_file file, db_member o, db_bool inlined);
struct db_serializer_s cpp_memberCountSerializer(void);

#ifdef __cplusplus
}
#endif

#endif /* CPP_CLASSIMPL_H_ */
