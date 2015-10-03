#ifndef _MD_RESOLVERS_H
#define _MD_RESOLVERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "md.h"
#include "_md_renderers.h"

cx_object md_resolvePackage(cx_string name, md_parseData* data);
cx_object md_resolveType(cx_string name, md_parseData* data);
cx_object md_resolveMethod(cx_string name, md_parseData* data);


#ifdef __cplusplus
}
#endif

#endif /* _MD_RESOLVERS_H */
