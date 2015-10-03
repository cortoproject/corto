#ifndef _MD_RENDERERS_H
#define _MD_RENDERERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "md.h"

struct md_parseData {
    cx_object destination;
    cx_object lastScope;
};

typedef struct md_parseData md_parseData;

int md_renderPackage(cx_object o, md_parseData* data);

int md_renderType(cx_object o, md_parseData* data);

int md_renderProcedure(cx_string name, md_parseData* data);

int md_renderArgument(cx_string name, md_parseData* data);

#ifdef __cplusplus
}
#endif

#endif /* _MD_RENDERERS_H */
