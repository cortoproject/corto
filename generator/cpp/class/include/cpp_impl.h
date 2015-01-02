/*
 * cpp_classImpl.h
 *
 *  Created on: Dec 27, 2012
 *      Author: sander
 */

#ifndef CPP_CLASSIMPL_H_
#define CPP_CLASSIMPL_H_

#include "cortex.h"
#include "cx_generator.h"

#ifdef __cplusplus
extern "C" {
#endif

int cpp_impl(cx_object o, cx_generator g);
void cpp_constructorDecl(cx_generator g, g_file file, cx_interface o, cx_bool inlined);
void cpp_constructorScopedDecl(cx_generator g, g_file file, cx_interface o, cx_bool inlined);
void cpp_constructorHandleDecl(cx_generator g, g_file file, cx_interface o, cx_bool inlined);
void cpp_handleGetDecl(cx_generator g, g_file file, cx_interface o, cx_bool inlined);
void cpp_functionDecl(cx_generator g, g_file file, cx_function o, cx_bool inlined);
void cpp_functionDeclExt(cx_generator g, g_file file, cx_function o, cx_bool inlined, cx_bool virtualStub);
void cpp_memberGetter(cx_generator g, g_file file, cx_member o, cx_bool inlined);
void cpp_memberSetter(cx_generator g, g_file file, cx_member o, cx_bool inlined);
struct cx_serializer_s cpp_memberCountSerializer(void);

#ifdef __cplusplus
}
#endif

#endif /* CPP_CLASSIMPL_H_ */
