/*
 * c_interface.c
 *
 *  Created on: Oct 4, 2012
 *      Author: sander
 */

#include "corto.h"
#include "corto_generator.h"
#include "c_common.h"

typedef struct docWalk_t {
    corto_generator g;
    g_file mdfile;
    corto_bool parsePackages;
    corto_bool parseTypes;
    corto_bool parseOthers;
    corto_class doc;
    corto_package package;
    corto_bool mdloaded;
} docWalk_t;

static char* doc_idEscape(corto_object from, corto_object o, corto_id buffer) {
    char *ptr = buffer, ch;
    int offset = 0;
    if (from) {
        corto_relname(from, o, buffer);
    } else {
        corto_fullname(o, buffer);
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

static char* doc_id(corto_generator g, corto_object o, corto_id buffer) {
    corto_object parents[CORTO_MAX_SCOPE_DEPTH];
    corto_uint32 count = 0;
    corto_object p = o;
    corto_object from = g_getCurrent(g);
    char *ptr = buffer + 7;

    strcpy(buffer, "::doc::");

    do {
        parents[count] = p;
        count++;
    } while((p != g_getCurrent(g)) && (p = corto_parentof(p)));

    do{
        count--;
        p = parents[count];
        if (corto_instanceof(corto_package_o, p)) {
            if (p == g_getCurrent(g)) {
                ptr = doc_idEscape(NULL, p, ptr);
            } else {
                *(ptr++) = '_';
                ptr = doc_idEscape(from, p, ptr);
            }
            from = p;
        } else if (corto_instanceof(corto_type_o, p)) {
            if (!corto_instanceof(corto_package_o, from)) {
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

static int doc_writeHeader(g_file file, corto_string name, corto_int32 level, corto_string description, corto_string text) {
    corto_int32 i;
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
static corto_string doc_getDescription(corto_class cl, corto_object doc) {
    corto_member m = corto_interface_resolveMember(cl, "description");

    corto_string result = NULL;
    if (m) {
        result = *(corto_string*)CORTO_OFFSET(doc, m->offset);
    } else {
        corto_critical("member description not found in doc class");
    }

    return result;
}

/* Reflection hack to get the description from a document */
static corto_string doc_getText(corto_class cl, corto_object doc) {
    corto_member m = corto_interface_resolveMember(cl, "text");

    corto_string result = NULL;
    if (m) {
        result = *(corto_string*)CORTO_OFFSET(doc, m->offset);
    } else {
        corto_critical("member description not found in doc class");
    }
    
    return result;
}

static int doc_walk(corto_object o, void *userData) {
    corto_id id, docId;
    docWalk_t *data = userData;
    corto_string description = NULL, text = NULL;

    doc_id(data->g, o, docId);
    corto_object doc = corto_resolve(NULL, docId);
    if (doc) {
        description = doc_getDescription(data->doc, doc);
        text = doc_getText(data->doc, doc);
    }

    if (corto_instanceof(corto_package_o, o)) {
        if ((o == g_getCurrent(data->g)) && data->parseOthers) {
            doc_writeHeader(data->mdfile, corto_fullname(o, id), 1, description, text);
            data->package = o;
        } else if ((o != g_getCurrent(data->g)) && data->parsePackages) {
            g_fileWrite(data->mdfile, "\n");
            doc_writeHeader(data->mdfile, corto_fullname(o, id), 1, description, text);
            docWalk_t privateData = *data;
            privateData.parseTypes = FALSE;
            privateData.parseOthers = TRUE;
            privateData.parsePackages = FALSE;
            privateData.package = o;
            if (!corto_scopeWalk(o, doc_walk, &privateData)) {
                goto error;
            }
            privateData.parseTypes = TRUE;
            privateData.parseOthers = FALSE;
            if (!corto_scopeWalk(o, doc_walk, &privateData)) {
                goto error;
            }
            privateData.parseTypes = FALSE;
            privateData.parsePackages = TRUE;
            if (!corto_scopeWalk(o, doc_walk, &privateData)) {
                goto error;
            }
        }
    } else if (corto_instanceof(corto_type_o, o) && data->parseTypes) {
        g_fileWrite(data->mdfile, "\n");
        doc_writeHeader(data->mdfile, corto_relname(data->package, o, id), 2, description, text);
        docWalk_t privateData = *data;
        privateData.parseTypes = FALSE;
        privateData.parseOthers = TRUE;
        if (!corto_scopeWalk(o, doc_walk, &privateData)) {
            goto error;
        }
        privateData.parseTypes = TRUE;
        privateData.parseOthers = FALSE;
        if (!corto_scopeWalk(o, doc_walk, &privateData)) {
            goto error;
        }
    } else if (corto_instanceof(corto_function_o, o) && data->parseOthers) {
        doc_writeHeader(data->mdfile, corto_nameof(o), 3, description, text);
        corto_parameterseqForeach(corto_function(o)->parameters, p) {
            corto_id paramDocId;
            sprintf(paramDocId, "%s::%s", docId, p.name);
            corto_object paramDoc = corto_resolve(NULL, paramDocId);
            if (paramDoc) {
                description = doc_getDescription(data->doc, paramDoc);
                text = doc_getText(data->doc, paramDoc);
            } else {
                description = NULL;
                text = NULL;
            }
            doc_writeHeader(data->mdfile, p.name, 4, description, text);
            if (paramDoc) corto_release(paramDoc);
        }

        if (corto_function(o)->returnType && 
           ((corto_function(o)->returnType->kind != CORTO_VOID || corto_function(o)->returnType->reference))) {
            corto_id returnDocId;
            sprintf(returnDocId, "%s::Returns", docId);
            corto_object returnDoc = corto_resolve(NULL, returnDocId);
            if (returnDoc) {
                description = doc_getDescription(data->doc, returnDoc);
                text = doc_getText(data->doc, returnDoc);
            } else {
                description = NULL;
                text = NULL;
            }
            doc_writeHeader(data->mdfile, "Returns", 4, description, text);
            if (returnDoc) corto_release(returnDoc);
        }
    } else if (corto_instanceof(corto_type_o, corto_parentof(o)) && data->parseOthers) {
        doc_writeHeader(data->mdfile, corto_nameof(o), 3, description, text);
    }

    return 1;
error:
    return 0;
}

/* Entry point for generator */
int corto_genMain(corto_generator g) {
    docWalk_t walkData;

    /* Default prefixes for corto namespaces */
    gen_parse(g, corto_o, FALSE, FALSE, "");
    gen_parse(g, corto_lang_o, FALSE, FALSE, "corto");

    /* Only regenerate if package md is available */
    if (corto_locate("::corto::md")) {
        walkData.doc = corto_class(corto_resolve(NULL, "::corto::md::Doc"));

        /* Load existing README file if available */
        if (!corto_load("README.md", 0, NULL)) {
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

        corto_release(walkData.doc);
    }

    return 0;
error:
    return -1;
}
