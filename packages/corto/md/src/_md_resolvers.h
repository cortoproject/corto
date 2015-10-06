#ifndef _MD_RESOLVERS_H
#define _MD_RESOLVERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "md.h"
#include "_md_callbacks.h"

cx_object md_resolve(int level, cx_string name, md_parseData* data);

#ifdef __cplusplus
}
#endif

#endif /* _MD_RESOLVERS_H */
