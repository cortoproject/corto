#ifndef _MD_APPENDSTR_H
#define _MD_APPENDSTR_H

#include "md.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_bool md_appendstrbuff(md_Doc data, char* str);
cx_bool md_appendstr(cx_object data, cx_string fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* _MD_APPENDSTR_H */
