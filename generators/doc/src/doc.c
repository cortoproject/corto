/*
 * c_interface.c
 *
 *  Created on: Oct 4, 2012
 *      Author: sander
 */

#include "corto.h"
#include "cx_generator.h"
#include "c_common.h"

typedef struct docWalk_t {
    cx_generator g;
    g_file mdfile;
    cx_bool parsePackages;
    cx_bool parseTypes;
    cx_bool parseOthers;
    cx_class doc;
    cx_package package;
    cx_bool mdloaded;
} docWalk_t;

static char* doc_idEscape(cx_object from, cx_object o, cx_id buffer) {
    char *ptr = buffer, ch;
    int offset = 0;
    if (from) {
        cx_relname(from, o, buffer);
    } else {
        cx_fullname(o, buffer);
    }

    for (; (ch = *ptr); ptr++) {
        if (ch == ':') {
            ptr[-offset] = '_';
            offset++;
            ptr++;
        } else {
            ptr[-offset] = ch;
        }
    }

    ptr[-offset] = '\0';

    return ptr - offset;
}

static char* doc_id(cx_generator g, cx_object o, cx_id buffer) {
    cx_object parents[CX_MAX_SCOPE_DEPTH];
    cx_uint32 count = 0;
    cx_object p = o;
    cx_object from = g_getCurrent(g);
    char *ptr = buffer + 7;

    strcpy(buffer, "::doc::");

    do {
        parents[count] = p;
        count++;
    } while((p != g_getCurrent(g)) && (p = cx_parentof(p)));

    do{
        count--;
        p = parents[count];
        if (cx_instanceof(cx_package_o, p)) {
            if (p == g_getCurrent(g)) {
                ptr = doc_idEscape(NULL, p, ptr);
            } else {
                *(ptr++) = '_';
                ptr = doc_idEscape(from, p, ptr);
            }
            from = p;
        } else if (cx_instanceof(cx_type_o, p)) {
            if (!cx_instanceof(cx_package_o, from)) {
                *(ptr++) = '_';
            } else {
                *(ptr++) = ':';
                *(ptr++) = ':';
            }
            ptr = doc_idEscape(from, p, ptr);
            from = p;
        } else {
            *(ptr++) = ':';
            *(ptr++) = ':';
            ptr = doc_idEscape(parents[count + 1], p, ptr);
        }
    } while (count);

    return buffer;
}

static int doc_writeHeader(g_file file, cx_string name, cx_int32 level, cx_string description, cx_string text) {
    cx_int32 i;
    for (i = 0; i < level; i++) {
        if (g_fileWrite(file, "#")) {
            goto error;
        }
    }
    if (g_fileWrite(file, " %s\n", name)) {
        goto error;
    }
    if (description) {
        if (g_fileWrite(file, "%s\n", description)) {
            goto error;
        }
        if (text) {
            if (g_fileWrite(file, "%s\n", text)) {
                goto error;
            }
        }
    } 

    return 0;
error:
    return -1;
}

/* Reflection hack to get the description from a document */
static cx_string doc_getDescription(cx_class cl, cx_object doc) {
    cx_member m = cx_interface_resolveMember(cl, "description");

    cx_string result = NULL;
    if (m) {
        result = *(cx_string*)CX_OFFSET(doc, m->offset);
    } else {
        cx_critical("member description not found in doc class");
    }

    return result;
}

/* Reflection hack to get the description from a document */
static cx_string doc_getText(cx_class cl, cx_object doc) {
    cx_member m = cx_interface_resolveMember(cl, "text");

    cx_string result = NULL;
    if (m) {
        result = *(cx_string*)CX_OFFSET(doc, m->offset);
    } else {
        cx_critical("member description not found in doc class");
    }
    
    return result;
}

static int doc_walk(cx_object o, void *userData) {
    cx_id id, docId;
    docWalk_t *data = userData;
    cx_string description = NULL, text = NULL;

    doc_id(data->g, o, docId);
    cx_object doc = cx_resolve(NULL, docId);
    if (doc) {
        description = doc_getDescription(data->doc, doc);
        text = doc_getText(data->doc, doc);
    } else {
        if (cx_instanceof(cx_package_o, o) || 
            cx_instanceof(cx_type_o, o) || 
            cx_instanceof(cx_type_o, cx_parentof(o))) 
        {
            if (data->mdloaded) {
                cx_warning("warning: object '%s' is not documented (%s)", cx_fullname(o, id), docId);
            }
        }
    }

    if (cx_instanceof(cx_package_o, o)) {
        if ((o == g_getCurrent(data->g)) && data->parseOthers) {
            doc_writeHeader(data->mdfile, cx_fullname(o, id), 1, description, text);
            data->package = o;
        } else if ((o != g_getCurrent(data->g)) && data->parsePackages) {
            g_fileWrite(data->mdfile, "\n");
            doc_writeHeader(data->mdfile, cx_fullname(o, id), 1, description, text);
            docWalk_t privateData = *data;
            privateData.parseTypes = FALSE;
            privateData.parseOthers = TRUE;
            privateData.parsePackages = FALSE;
            privateData.package = o;
            if (!cx_scopeWalk(o, doc_walk, &privateData)) {
                goto error;
            }
            privateData.parseTypes = TRUE;
            privateData.parseOthers = FALSE;
            if (!cx_scopeWalk(o, doc_walk, &privateData)) {
                goto error;
            }
            privateData.parseTypes = FALSE;
            privateData.parsePackages = TRUE;
            if (!cx_scopeWalk(o, doc_walk, &privateData)) {
                goto error;
            }
        }
    } else if (cx_instanceof(cx_type_o, o) && data->parseTypes) {
        g_fileWrite(data->mdfile, "\n");
        doc_writeHeader(data->mdfile, cx_relname(data->package, o, id), 2, description, text);
        docWalk_t privateData = *data;
        privateData.parseTypes = FALSE;
        privateData.parseOthers = TRUE;
        if (!cx_scopeWalk(o, doc_walk, &privateData)) {
            goto error;
        }
        privateData.parseTypes = TRUE;
        privateData.parseOthers = FALSE;
        if (!cx_scopeWalk(o, doc_walk, &privateData)) {
            goto error;
        }
    } else if (cx_instanceof(cx_function_o, o) && data->parseOthers) {
        doc_writeHeader(data->mdfile, cx_nameof(o), 3, description, text);
        cx_parameterseqForeach(cx_function(o)->parameters, p) {
            cx_id paramDocId;
            sprintf(paramDocId, "%s::%s", docId, p.name);
            cx_object paramDoc = cx_resolve(NULL, paramDocId);
            if (paramDoc) {
                description = doc_getDescription(data->doc, paramDoc);
                text = doc_getText(data->doc, paramDoc);
            } else {
                description = NULL;
                text = NULL;
            }
            doc_writeHeader(data->mdfile, p.name, 4, description, text);
            if (paramDoc) cx_release(paramDoc);
        }

        if (cx_function(o)->returnType && 
           ((cx_function(o)->returnType->kind != CX_VOID || cx_function(o)->returnType->reference))) {
            cx_id returnDocId;
            sprintf(returnDocId, "%s::Returns", docId);
            cx_object returnDoc = cx_resolve(NULL, returnDocId);
            if (returnDoc) {
                description = doc_getDescription(data->doc, returnDoc);
                text = doc_getText(data->doc, returnDoc);
            } else {
                description = NULL;
                text = NULL;
            }
            doc_writeHeader(data->mdfile, "Returns", 4, description, text);
            if (returnDoc) cx_release(returnDoc);
        }
    } else if (cx_instanceof(cx_type_o, cx_parentof(o)) && data->parseOthers) {
        doc_writeHeader(data->mdfile, cx_nameof(o), 3, description, text);
    }

    return 1;
error:
    return 0;
}

/* Entry point for generator */
int corto_genMain(cx_generator g) {
    docWalk_t walkData;

    /* Default prefixes for corto namespaces */
    gen_parse(g, corto_o, FALSE, FALSE, "");
    gen_parse(g, corto_lang_o, FALSE, FALSE, "cx");

    /* Only regenerate if package md is available */
    if (cx_locate("::corto::md")) {
        walkData.doc = cx_class(cx_resolve(NULL, "::corto::md::Doc"));

        /* Load existing README file if available */
        if (!cx_load("README.md", 0, NULL)) {
            walkData.mdloaded = TRUE;
        } else {
            walkData.mdloaded = FALSE;
        }

        /* Walk objects, generate document haders */
        walkData.mdfile = g_fileOpen(g, "README.md");
        walkData.g = g;
        walkData.parseTypes = FALSE;
        walkData.parseOthers = TRUE;
        walkData.parsePackages = FALSE;
        walkData.package = NULL;
        if (!g_walk(g, doc_walk, &walkData)) {
            goto error;
        }

        walkData.parseTypes = TRUE;
        walkData.parseOthers = FALSE;
        if (!g_walk(g, doc_walk, &walkData)) {
            goto error;
        }

        walkData.parseTypes = FALSE;
        walkData.parsePackages = TRUE;
        if (!g_walk(g, doc_walk, &walkData)) {
            goto error;
        }

        cx_release(walkData.doc);
    }

    return 0;
error:
    return -1;
}
