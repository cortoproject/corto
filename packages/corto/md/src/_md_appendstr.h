#ifndef _MD_APPENDSTR_H
#define _MD_APPENDSTR_H

#include "md.h"
#include "_md_callbacks.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_bool md_appendstrbuff(md_parseData* data, char* str);
cx_bool md_appendstr(md_parseData* data, cx_string fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* _MD_APPENDSTR_H */
