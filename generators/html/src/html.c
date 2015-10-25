#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <ctype.h>

#if __linux__
#include <linux/limits.h>
#else
#include <limits.h>
#endif

#include "html.h"
#include "corto.h"

typedef struct htmlData_t {
    const char *path;
    unsigned int level;
    const char *rootFullname;
    corto_generator generator;
} htmlData_t;

static char *html_shortId(corto_object o, corto_id id) {
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        if (corto_parentof(o) == corto_lang_o) {
            strcpy(id, corto_nameof(o));
        } else {
            corto_id buff;
            corto_fullname(o, buff);
            strcpy(id, buff + 2);
        }
    } else {
        corto_string str = corto_str(o, 0);
        strcpy(id, str);
        corto_dealloc(str);
    }
    return id;
}

/*
 * Create a folder for this object
 * Make an index.html file inside, contents are dependent on kind of object
 *     e.g. primitives are a plain value but classes include description
       of members
 * Make a data.json file inside
 * Call recursively for every object in this scope
 */
static char* html_pathToRoot(corto_object o, char* buffer, corto_uint32 *level) {
    if (corto_parentof(o)) {
        html_pathToRoot(corto_parentof(o), buffer, level);
    }
    if (corto_nameof(o)) {
        strcat(buffer, "/");
        strcat(buffer, corto_nameof(o));
    }
    if (level) {
        (*level)++;
    }
    return buffer;
}

static char* html_ref(
    corto_object from, 
    corto_object o, 
    corto_string name, 
    corto_string class, 
    char *result) 
{
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        corto_id buffer;
        corto_object p = corto_parentof(from);
        buffer[0] = '\0';
        while (p != root_o) {
            strcat(buffer, "../");
            p = corto_parentof(p);
        }
        if (strlen(buffer)) {
            buffer[strlen(buffer) - 1] = '\0';
        } else {
            strcpy(buffer, ".");
        }

        if (corto_instanceof(corto_package_o, o) ||
            corto_instanceof(corto_interface_o, o)) {
            html_pathToRoot(o, buffer, NULL);
            strcat(buffer, ".html");
            sprintf(result, 
                "<a href=\"%s\" class=\"%s\">%s</a>", 
                buffer,
                class,
                name);
        } else {
            html_pathToRoot(corto_parentof(o), buffer, NULL);
            strcat(buffer, ".html");
            strcat(buffer, "#");
            strcat(buffer, corto_nameof(o));
            sprintf(result, 
                "<a href=\"%s\" class=\"%s smoothScroll\">%s</a>", 
                buffer,
                class,
                name);
        }
    } else {
        result[0] = '\0';
    }

    return result;
}

static void html_getPath(corto_object o, char *buffer, htmlData_t *data, corto_uint32 *level) {
    strcpy(buffer, data->path);
    if (corto_nameof(o)) {
        html_pathToRoot(corto_parentof(o), buffer, level);
        strcat(buffer, "/");
        strcat(buffer, corto_nameof(o));
    }
}

typedef struct htmlTypeWalkData_t {
    g_file file;
    corto_type typeToWalk;
    corto_bool instanceof;
    corto_ll printed;
    corto_ll counted;
    htmlData_t *data;
} htmlTypeWalkData_t;

static int html_hasTypeWalk(corto_object o, void *userData) {
    htmlTypeWalkData_t *data = userData;

    if (((data->instanceof && corto_instanceof(data->typeToWalk, o)) || 
        (corto_typeof(o) == data->typeToWalk)) &&
        !corto_llHasObject(data->counted, o)) {
        corto_llAppend(data->counted, o);
    }

    return 1;
}

static corto_string doc_parse(corto_string input) {
    corto_string result = NULL;
    corto_function f = corto_function(corto_resolve(NULL, "md::parse"));
    if (corto_checkState(f, CORTO_DEFINED)) {
        corto_call(f, &result, input);
    }
    return result;
}

/* Reflection hack to get the description from a document */
static corto_string doc_getDescriptionFromDoc(corto_object doc) {
    corto_object cl = corto_resolve(NULL, "corto::md::Doc");
    corto_string result = "";

    if (cl) {
        if (doc) {
            corto_member m = corto_interface_resolveMember(cl, "description");
            if (m) {
                result = *(corto_string*)CORTO_OFFSET(doc, m->offset);
                if (!result) {
                    result = "";
                }
            } else {
                corto_critical("member description not found in doc class");
            }
        }
    }

    return result;
}

/* Reflection hack to get the description from a document */
static corto_string doc_getDescription(corto_object o) {
    return doc_getDescriptionFromDoc(corto_man(o));
}

/* Reflection hack to get the description from a document */
static corto_string doc_getTextFromDoc(corto_object doc) {
    corto_object cl = corto_resolve(NULL, "corto::md::Doc");
    corto_string result = "";

    if (cl) {
        if (doc) {
            corto_member m = corto_interface_resolveMember(cl, "text");
            if (m) {
                result = *(corto_string*)CORTO_OFFSET(doc, m->offset);
                if (!result) {
                    result = "";
                }
            } else {
                corto_critical("member text not found in doc class");
            }
        }
    }

    result = doc_parse(result);

    return result;
}

/* Reflection hack to get the description from a document */
static corto_string doc_getText(corto_object o) {
    return doc_getTextFromDoc(corto_man(o));
}

static int html_typeWalk(corto_object o, void *userData) {
    htmlTypeWalkData_t *data = userData;
    corto_string description = "";

    description = doc_getDescription(o);

    if (((data->instanceof && corto_instanceof(data->typeToWalk, o)) || 
        (corto_typeof(o) == data->typeToWalk)) &&
        !corto_llHasObject(data->printed, o)) 
    {
        corto_id id;
        if (description && strlen(description)) {
            g_fileWrite(
                data->file, 
                "<tr><td>%s&nbsp;-&nbsp;"
                "<span class=\"description\">%s</span></td></tr>\n",
                html_ref(corto_parentof(o), o, corto_nameof(o), "reference", id),
                description);
        } else {
            g_fileWrite(
                data->file, 
                "<tr><td>%s",
                html_ref(corto_parentof(o), o, corto_nameof(o), "reference", id));            
        }
        corto_llAppend(data->printed, o);
    }

    return 1;
}

typedef enum html_printMask {
    PRINT_TYPES = 1,
    PRINT_MEMBERS = 2,
} html_printMask;

static int html_printType(
    corto_object o, 
    g_file file, 
    corto_string title, 
    corto_type type, 
    corto_uint32 count,
    htmlTypeWalkData_t *data) {

    data->typeToWalk = corto_type(type);
    corto_scopeWalk(o, html_hasTypeWalk, data);
    if (corto_llSize(data->counted) != count) {
        g_fileWrite(file, "<h2>%s</h2>\n", title);
        g_fileWrite(file, "<table class='category'>\n");
        corto_scopeWalk(o, html_typeWalk, data);
        g_fileWrite(file, "</table>\n");
        count = corto_llSize(data->counted);
    } 

    return count;  
}

static corto_int16 corto_ser_member(corto_serializer s, corto_value *info, void *userData) {
    g_file file = userData;
    corto_member m = info->is.member.t;
    corto_string description = doc_getDescription(m);
    corto_type topLevelType = corto_typeof(corto_valueObject(info));
    corto_id path, memberPath;
    corto_id id;

    CORTO_UNUSED(s);

    g_fileWrite(file, "<tr>\n");
    g_fileWrite(file,
        "<td>%s&nbsp:&nbsp;%s", 
        html_ref(corto_typeof(corto_valueObject(info)), m, corto_nameof(m), "reference", memberPath),
        html_ref(corto_typeof(corto_valueObject(info)), m->type, html_shortId(m->type, id), "reference", path));

    corto_member mptr = m;
    while ((!description || !strlen(description)) && mptr) {
        if (corto_instanceof(corto_alias_o, mptr)) {
            mptr = corto_alias(mptr)->member;
            description = doc_getDescription(mptr);
        } else {
            mptr = NULL;
        }
    }

    if (description && strlen(description)) {
        g_fileWrite(file, "&nbsp;-&nbsp;<span class='description'>%s</span>", description);
    }

    if (corto_parentof(m) != topLevelType) {
        corto_id id;
        g_fileWrite(file, "<br><span class='annotate'>from %s</span>\n", 
            corto_fullname(corto_parentof(m), id) + 2);
    }

    if (corto_instanceof(corto_alias_o, m)) {
        corto_id id;
        g_fileWrite(file, "<br><span class='annotate'>alias&nbsp;of&nbsp;%s</span>", 
            corto_fullname(corto_alias(m)->member, id) + 2);
    }

    g_fileWrite(file, "</td></tr>\n");

    return 0;
}

static corto_int16 corto_ser_memberDetail(corto_serializer s, corto_value *info, void *userData) {
    g_file file = userData;
    corto_member m = info->is.member.t;
    corto_string description = doc_getDescription(m);
    corto_id path;
    corto_id id;

    CORTO_UNUSED(s);

    corto_member mptr = m;
    while ((!description || !strlen(description)) && mptr) {
        if (corto_instanceof(corto_alias_o, mptr)) {
            mptr = corto_alias(mptr)->member;
            description = doc_getDescription(mptr);
        } else {
            mptr = NULL;
        }
    }

    g_fileWrite(file, "<a name=\"%s\"></a>\n", corto_nameof(m));
    g_fileWrite(file, "<h3 class='detail'>%s</h3>", corto_nameof(m));
    g_fileWrite(file, "<hr>\n");
    g_fileWrite(file, "<p>%s</p>\n", description);
    g_fileWrite(file, "<table class='category detail'>\n");
    g_fileWrite(file, "<tr><td>Type</td><td>%s</td></tr>\n", 
        html_ref(corto_parentof(m), m->type, html_shortId(m->type, id), "reference", path));
    g_fileWrite(file, "<tr><td>Access</td><td>%s</td></tr>\n", 
        html_ref(corto_parentof(m), corto_modifier_o, corto_modifierStr(m->modifiers), "reference-enum", path));
    if (m->type->reference) {
        g_fileWrite(file, "<tr><td>State</td><td>%s</td></tr>\n", 
            html_ref(corto_parentof(m), corto_state_o, corto_stateStr(m->state), "reference-enum", path));        
    }
    if (corto_instanceof(corto_alias_o, m)) {
        corto_id id;
        g_fileWrite(file, "<tr><td>Alias</td><td>%s</td></tr>\n",
            html_ref(corto_parentof(m), corto_alias(m)->member, html_shortId(corto_alias(m)->member, id), "reference", path));
    }
    g_fileWrite(file, "</table>\n");
    g_fileWrite(file, "</td></tr>\n");

    return 0;
}

/* Quick way to test whether there are members in a type: stop serializing with
 * an 'error' when one is encountered */
static corto_int16 corto_ser_memberTest(corto_serializer s, corto_value *info, void *userData) {
    CORTO_UNUSED(s);
    if (userData && corto_parentof(info->is.member.t) != userData) {
        return 0;
    }
    return -1;
}

static struct corto_serializer_s html_memberSerializer(corto_modifier access, corto_operatorKind accessKind) {
    struct corto_serializer_s s;
    corto_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = CORTO_SERIALIZER_TRACE_NEVER;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_PASSTHROUGH;
    s.metaprogram[CORTO_MEMBER] = corto_ser_member;

    return s;
}

static struct corto_serializer_s html_memberDetailSerializer(corto_modifier access, corto_operatorKind accessKind) {
    struct corto_serializer_s s;
    corto_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = CORTO_SERIALIZER_TRACE_NEVER;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_PASSTHROUGH;
    s.metaprogram[CORTO_MEMBER] = corto_ser_memberDetail;
    s.metaprogram[CORTO_BASE] = NULL;

    return s;
}

static struct corto_serializer_s html_memberTestSerializer(corto_modifier access, corto_operatorKind accessKind) {
    struct corto_serializer_s s;
    corto_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = CORTO_SERIALIZER_TRACE_NEVER;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_PASSTHROUGH;
    s.metaprogram[CORTO_MEMBER] = corto_ser_memberTest;

    return s;
}

static int html_printMembers(corto_object o, g_file file, corto_uint32 count, htmlTypeWalkData_t *data) {
    struct corto_serializer_s s = html_memberSerializer(CORTO_PRIVATE|CORTO_HIDDEN, CORTO_NOT);
    struct corto_serializer_s sTest = html_memberTestSerializer(CORTO_PRIVATE|CORTO_HIDDEN, CORTO_NOT);

    CORTO_UNUSED(data);

    if (corto_metaWalk(&sTest, o, NULL)) {
        g_fileWrite(file, "<h2>Members</h2>\n");
        g_fileWrite(file, "<table class='category'>\n");
        corto_metaWalk(&s, o, file);
        g_fileWrite(file, "</table>\n");        
    }

    return count;
}

static int html_printMemberDetail(corto_object o, g_file file) {
    struct corto_serializer_s s = html_memberDetailSerializer(CORTO_PRIVATE|CORTO_HIDDEN, CORTO_NOT);
    struct corto_serializer_s sTest = html_memberTestSerializer(CORTO_PRIVATE|CORTO_HIDDEN, CORTO_NOT);

    if (corto_metaWalk(&sTest, o, o)) {
        g_fileWrite(file, "<h2>Member Documentation</h2>\n");
        g_fileWrite(file, "<table class='category'>\n");
        corto_metaWalk(&s, o, file);
        g_fileWrite(file, "</table>\n");        
    }

    return 0;
}

typedef enum html_printFunctionKind {
    HTML_PRINT_METHODS,
    HTML_PRINT_FUNCTIONS,
} html_printFunctionKind;

static corto_function html_overrides(corto_interface base, corto_function m) {
    corto_function result = NULL;

    if (base && corto_instanceof(corto_method_o, m)) {
        result = corto_function(corto_interface_resolveMethod(base, corto_nameof(m)));
        if (result && 
            corto_instanceof(corto_method_o, result) && 
            corto_method(result)->_virtual) {
        } else {
            result = NULL;
        }
    }

    return result;
}

static int html_printFunction(corto_function m, g_file file, corto_object o) {
    corto_id path, methodPad;
    corto_interface base = NULL;
    corto_function overrides = NULL;
    corto_string description = NULL;
    corto_id id;

    if (corto_instanceof(corto_interface_o, corto_parentof(m))) {
        base = corto_interface(corto_parentof(m))->base;
    }

    description = doc_getDescription(m);
    g_fileWrite(file, 
        "<tr><td>%s&nbsp;:&nbsp;%s",
        html_ref(o, m, corto_nameof(m), "reference", methodPad),
        html_ref(o, m->returnType, html_shortId(m->returnType, id), "reference reference-type", path));

    overrides = html_overrides(base, m);

    if (overrides && (!description || !strlen(description))) {
        corto_object optr = overrides;
        corto_interface i = base;
        while ((!description || !strlen(description)) && optr) {
            description = doc_getDescription(optr);
            i = corto_interface(corto_parentof(optr))->base;
            if (i) {
                optr = corto_interface_resolveMethod(i, corto_nameof(optr));
            } else {
                break;
            }
        }
    }

    if (description && strlen(description)) {
        g_fileWrite(file, 
            "&nbsp;-&nbsp;<span class='description'>%s</span>", 
            description);
    }

    if (overrides) {
        corto_id id;
        g_fileWrite(file, 
            "<br/><span class='annotate'>overrides %s</span>\n", 
            corto_fullname(overrides, id) + 2);
    }

    if (corto_parentof(m) != o) {
        corto_id id;
        g_fileWrite(file, 
            "<br/><span class='annotate'>from %s</span>\n", 
            corto_fullname(corto_parentof(m), id) + 2);        
    }

    g_fileWrite(file, "</td></tr>\n");

    return 0;
}

static int html_printFunctionDetail(corto_function m, g_file file, corto_object o) {
    corto_id id, path;
    corto_object doc = corto_man(m);
    corto_interface base = NULL;

    if (corto_instanceof(corto_interface_o, corto_parentof(m))) {
        base = corto_interface(corto_parentof(m))->base;
    }

    g_fileWrite(file, "<a name=\"%s\"></a>\n", corto_nameof(m));
    g_fileWrite(file, "<h3 class='detail'>");
    if (corto_instanceof(corto_method_o, m)) {
        if (corto_method(m)->_virtual) {
            g_fileWrite(file, "<span class='virtual'>virtual</span>&nbsp;");
        }
    }

    g_fileWrite(
        file, 
        "%s%s&nbsp;%s",
        html_ref(o, m->returnType, html_shortId(m->returnType, id), "", path),
        (!m->returnType->reference && m->returnsReference) ? "&" : "",
        corto_nameof(m));

    if (corto_instanceof(corto_method_o, m)) {
        corto_function overrides = html_overrides(base, m);
        if (overrides) {
            corto_id id, sigName;
            corto_signatureName(corto_fullname(overrides, id) + 2, sigName);
            g_fileWrite(file, 
                "&nbsp;<span class='overrides'>overrides %s</span>\n", 
                sigName);            
        }
    }

    g_fileWrite(file, "</h3>\n");
    g_fileWrite(file, "<hr>\n");

    corto_string description = doc_getDescription(m);
    g_fileWrite(file, "<p>%s</p>\n", description);

    corto_string text = doc_getText(m);
    g_fileWrite(file, "<p>%s</p>\n", text);

    corto_parameterseqForeach(m->parameters, p) {
        corto_object paramDoc = corto_lookup(doc, p.name);
        if (paramDoc) {
            corto_string description = doc_getDescriptionFromDoc(paramDoc);
            if (description && strlen(description)) {
                g_fileWrite(file, "<h4>%s%s : %s</h4>", 
                    p.name,
                    p.passByReference ? "&" : "",
                    html_ref(o, p.type, html_shortId(p.type, id), "", path));
                g_fileWrite(file, "<p>%s</p>", description);

                corto_string text = doc_getTextFromDoc(paramDoc);
                if (text) {
                    g_fileWrite(file, "<p>%s</p>", text);
                }
            }
        }
    }

    if ((m->returnType->kind != CORTO_VOID) || (m->returnType->reference)) {
        corto_object returnDoc = corto_lookup(doc, "Returns");
        corto_string description = returnDoc ? doc_getDescriptionFromDoc(returnDoc) : "";
        corto_string text = returnDoc ? doc_getTextFromDoc(returnDoc) : "";
        if (description && strlen(description)) {
            g_fileWrite(file, "<h4>Returns</h4>\n");
            g_fileWrite(file, "<p>%s</p>\n", description);
            if (text && strlen(text)) {
                g_fileWrite(file, "<p>%s</p>\n", text);
            }
        }
    }

    return 0;
}

static corto_bool html_functionsToPrint(
    corto_object o, 
    html_printFunctionKind kind, 
    corto_bool detail,
    corto_objectseq *seq_out) 
{
    corto_bool result = TRUE;

    if (kind == HTML_PRINT_METHODS) {
        seq_out->length = corto_interface(o)->methods.length;
        seq_out->buffer = (corto_object*)corto_interface(o)->methods.buffer;
        corto_objectseqForeach((*seq_out), m) {
            if (!detail || (corto_parentof(m) == o)) {
                result = TRUE;
                break;
            }
        }
        result = seq_out->length != 0;
    } else if (kind == HTML_PRINT_FUNCTIONS) {
        *seq_out = corto_scopeClaim(o);
        result = FALSE;
         corto_objectseqForeach((*seq_out), m) {
            if (corto_typeof(m) == (corto_type)corto_function_o) {
                if (!detail || (corto_parentof(m) == o)) {
                    result = TRUE;
                    break;
                }
            }
        }
    }

    return result;
}

static int html_printFunctions (
    corto_object o, 
    g_file file, 
    corto_string title, 
    html_printFunctionKind kind, 
    corto_bool detail) 
{
    corto_objectseq functions;

    corto_bool objectsToPrint = html_functionsToPrint(o, kind, detail, &functions);
    if (objectsToPrint) {
        g_fileWrite(file, "<h2>%s</h2>\n", title);
        g_fileWrite(file, "<table class='category' id=\"%s\">\n", title);

        if (kind != HTML_PRINT_FUNCTIONS) {
            corto_vtableForeach(functions, m) {
                if (!detail) {
                    html_printFunction(corto_function(m), file, o);
                } else if (corto_parentof(m) == o) {
                    html_printFunctionDetail(corto_function(m), file, o);
                }
            }
        } else {
            corto_objectseqForeach(functions, m) {
                if (corto_typeof(m) == (corto_type)corto_function_o) {
                    if (!detail) {
                        html_printFunction(m, file, o);
                    } else {
                        html_printFunctionDetail(corto_function(m), file, o);                        
                    }
                }
            }
        }

        g_fileWrite(file, "</table>\n");
    }

    if (kind == HTML_PRINT_FUNCTIONS) {
        corto_scopeRelease(functions);
    }

    return 0;
}

int html_printPrimitiveDetail(corto_object t, g_file file) {

    corto_string description = doc_getDescription(t);
    corto_string text = doc_getText(t);

    g_fileWrite(file, "<a name=\"%s\"></a>\n", corto_nameof(t));
    g_fileWrite(file, "<h3 class='detail'>%s</h3>", corto_nameof(t));
    g_fileWrite(file, "<hr>\n");
    g_fileWrite(file, "<p>%s</p>\n", description);
    g_fileWrite(file, "<p>%s</p>\n", text);

    return 0;
}

int html_printEnumDetail(corto_object t, g_file file) {

    corto_string description = doc_getDescription(t);
    corto_string text = doc_getText(t);

    g_fileWrite(file, "<a name=\"%s\"></a>\n", corto_nameof(t));
    g_fileWrite(file, "<h3 class='detail'><span class='enumtype'>%s</span> %s</h3>", 
        corto_nameof(corto_typeof(t)), corto_nameof(t));
    g_fileWrite(file, "<hr>\n");
    g_fileWrite(file, "<p>%s</p>\n", description);

    g_fileWrite(file, "<table class='category'>\n");
    corto_objectseqForeach(corto_enum(t)->constants, c) {
        corto_string description = doc_getDescription(c);
        if (corto_typeof(t) == corto_type(corto_enum_o)) {
            g_fileWrite(
                file, 
                "<tr><td><span class='constant'>%s</span></td><td>%d</td><td>%s</td></tr>\n",
                corto_nameof(c), 
                *(corto_constant*)c,
                description);
        } else {
            g_fileWrite(
                file, 
                "<tr><td><span class='constant'>%s</span></td><td>0x%x</td><td>%s</td></tr>\n",
                corto_nameof(c), 
                *(corto_constant*)c,
                description);            
        }
    }
    g_fileWrite(file, "</table>\n");

    g_fileWrite(file, "<p>%s</p>\n", text);

    return 0;
}

int html_detailWalk(corto_object o, g_file file, corto_type type, int (*callback)(corto_object, g_file), htmlTypeWalkData_t *data) {
    corto_objectseq scope = corto_scopeClaim(o);

    CORTO_UNUSED(o);

    corto_objectseqForeach(scope, t) {
        if (((data->instanceof && corto_instanceof(type, t)) || 
                (corto_typeof(t) == type)) &&
                !corto_llHasObject(data->printed, t)) {
            if (callback) {
                callback(t, file);
            }
            corto_llAppend(data->printed, t);
        }
    }

    corto_scopeRelease(scope);

    return 0;
}

static int html_printScope(corto_object o, g_file file, html_printMask mask, htmlData_t *data) {
    htmlTypeWalkData_t walkData;
    corto_uint32 count = 0;

    walkData.instanceof = TRUE;
    walkData.printed = corto_llNew();
    walkData.counted = corto_llNew();
    walkData.file = file;
    walkData.data = data;

    if (mask & PRINT_MEMBERS) {
        count = html_printMembers(o, file, count, &walkData);
        count = html_printFunctions(o, file, "Methods", HTML_PRINT_METHODS, FALSE);
        count = html_printFunctions(o, file, "Functions", HTML_PRINT_FUNCTIONS, FALSE);
    }

    if (mask & PRINT_TYPES) {
        walkData.instanceof = FALSE;
        count = html_printType(o, file, "Classes", corto_type(corto_class_o), count, &walkData);
        count = html_printType(o, file, "Structs", corto_type(corto_struct_o), count, &walkData);
        count = html_printType(o, file, "Interfaces", corto_type(corto_interface_o), count, &walkData);
        count = html_printType(o, file, "Enumerations", corto_type(corto_enum_o), count, &walkData);
        count = html_printType(o, file, "Bitmasks", corto_type(corto_bitmask_o), count, &walkData);

        walkData.instanceof = TRUE;
        count = html_printType(o, file, "Primitives", corto_type(corto_primitive_o), count, &walkData);
        count = html_printType(o, file, "Collections", corto_type(corto_collection_o), count, &walkData);
        count = html_printType(o, file, "Delegates", corto_type(corto_delegate_o), count, &walkData);
        count = html_printType(o, file, "Other types", corto_type(corto_type_o), count, &walkData);
        
        if (!(mask & PRINT_MEMBERS)) {
            count = html_printFunctions(o, file, "Functions", HTML_PRINT_FUNCTIONS, FALSE);
        }
    }

    return 0;
}

static int html_printScopeDetail(corto_object o, g_file file, html_printMask mask, htmlData_t *data) {
    htmlTypeWalkData_t walkData;

    walkData.instanceof = TRUE;
    walkData.printed = corto_llNew();
    walkData.counted = NULL; 
    walkData.file = file;
    walkData.data = data;

    corto_string description = doc_getDescription(o);
    if (description && strlen(description)) {
        g_fileWrite(file, "<a name='details'></a>\n");
        g_fileWrite(file, "<hr>\n");
        g_fileWrite(file, "<h2>Detailed description</h2>\n");
        g_fileWrite(file, "<p>%s</p>\n", description);
        g_fileWrite(file, "<p>%s</p>\n", doc_getText(o));
    }

    if (mask & PRINT_MEMBERS) {
        html_printMemberDetail(o, file);
        html_printFunctions(o, file, "Method Documentation", HTML_PRINT_METHODS, TRUE);
    }

    if (mask & PRINT_TYPES) {
        /* Check whether there are types in this scope */
        corto_bool hasTypes = FALSE;
        corto_objectseq scope = corto_scopeClaim(o);

        corto_objectseqForeach(scope, t) {
            if (corto_instanceof(corto_type_o, t) && !corto_instanceof(corto_interface_o, t)) {
                hasTypes = TRUE;
            }
        }

        if (hasTypes) {
            walkData.instanceof = FALSE;
            g_fileWrite(file, "<h2>Type Documentation</h2>\n");
            html_detailWalk(o, file, corto_type(corto_enum_o), html_printEnumDetail, &walkData);
            html_detailWalk(o, file, corto_type(corto_bitmask_o), html_printEnumDetail, &walkData);
            html_detailWalk(o, file, corto_type(corto_boolean_o), html_printPrimitiveDetail, &walkData);
            html_detailWalk(o, file, corto_type(corto_character_o), html_printPrimitiveDetail, &walkData);
            html_detailWalk(o, file, corto_type(corto_int_o), html_printPrimitiveDetail, &walkData);
            html_detailWalk(o, file, corto_type(corto_uint_o), html_printPrimitiveDetail, &walkData);
            html_detailWalk(o, file, corto_type(corto_float_o), html_printPrimitiveDetail, &walkData);
            html_detailWalk(o, file, corto_type(corto_text_o), html_printPrimitiveDetail, &walkData);
            html_detailWalk(o, file, corto_type(corto_binary_o), html_printPrimitiveDetail, &walkData);

            walkData.instanceof = TRUE;

            /* Ensure that interfaces are excluded from generation */
            html_detailWalk(o, file, corto_type(corto_interface_o), NULL, &walkData);

            /* Print types that haven't been printed yet */
            html_detailWalk(o, file, corto_type(corto_type_o), html_printPrimitiveDetail, &walkData);
        }

        html_printFunctions(o, file, "Function Documentation", HTML_PRINT_FUNCTIONS, TRUE);
    }

    corto_llFree(walkData.printed);

    return 0;
}

static int html_printParents(corto_object o, g_file file, htmlData_t *data) {
    corto_object parents[CORTO_MAX_SCOPE_DEPTH];
    corto_object p = o;
    corto_uint32 i = 0;
    corto_id capitalizedTypeName;

    CORTO_UNUSED(data);

    while(p) {
        parents[i] = p;
        p = corto_parentof(p);
        i++;
    }
    g_fileWrite(file, "<p class='parents'>\n");
    while(i) {
        corto_uint32 j = 0;
        i--;
        if (i) {
            g_fileWrite(file, "<a href=\"");
            for (j = 0; j < i; j ++) {
                g_fileWrite(file, "../");
            }
            g_fileWrite(file, "%s.html\">", corto_nameof(parents[i]));
        }

        if (corto_nameof(parents[i])) {
            g_fileWrite(file, "%s", corto_nameof(parents[i]));
        } else {
            g_fileWrite(file, "root");
        }
        strcpy(capitalizedTypeName, corto_nameof(corto_typeof(parents[i])));
        capitalizedTypeName[0] = toupper(capitalizedTypeName[0]);
        g_fileWrite(file, " %s", capitalizedTypeName);
        if (i) {
            g_fileWrite(file, "</a>");
        }
        if (i) {
            g_fileWrite(file, " <span class=\"octicon octicon-chevron-right\"></span> ");
        }
    }
    g_fileWrite(file, "\n");
    g_fileWrite(file, "</p>\n");

    return 0;
}

static int html_printInheritance(corto_interface o, g_file file) {
    if (o->base) {
        g_fileWrite(file, "<table class='category'>\n");
        corto_id id, path;
        g_fileWrite(file, "<tr><td>Base</td><td>%s</td></tr>\n", 
            html_ref(o, o->base, html_shortId(o->base, id), "reference", path));
        if (corto_instanceof(corto_struct_o, o)) {
            g_fileWrite(file, "<tr><td>Access</td><td>%s</td></tr>",
                html_ref(o, corto_modifier_o, corto_modifierStr(corto_struct(o)->baseAccess), "reference-enum", path));
        }
    }

    if (corto_instanceof(corto_class_o, o) && corto_class(o)->implements.length) {
        corto_int32 count = 0;

        if (!o->base) {
            g_fileWrite(file, "<table class='category'>\n");   
        }

        g_fileWrite(file, "<tr><td>Implements</td><td>");
        corto_interfaceseqForeach(corto_class(o)->implements, i) {
            corto_id path;
            if (count) {
                g_fileWrite(file, ", ");
            }
            g_fileWrite(file, "%s", 
                html_ref(o, i, corto_nameof(i), "reference", path));
            count++;
        }
        g_fileWrite(file, "</td></tr>\n");

        g_fileWrite(file, "</table>\n");
    } else if (o->base) {
        g_fileWrite(file, "</table>\n");
    }

    return 0;
}

static int html_printPackage(corto_object o, g_file file, htmlData_t *data) {
    html_printScope(o, file, PRINT_TYPES, data);
    html_printScopeDetail(o, file, PRINT_TYPES, data);
    return 0;
}

static int html_printClass(corto_object o, g_file file, htmlData_t *data) {
    html_printInheritance(o, file);
    html_printScope(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
    html_printScopeDetail(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
    return 0;
}

static int html_printStruct(corto_object o, g_file file, htmlData_t *data) {
    return html_printScope(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
}

static int html_printInterface(corto_object o, g_file file, htmlData_t *data) {
    return html_printScope(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
}

static g_file html_openIndexHtml(corto_object o, htmlData_t *data) {
    char filePath[PATH_MAX];
    g_file file;
    corto_uint32 level = 0; /* Root is at 0 */
    corto_uint32 i;

    html_getPath(corto_parentof(o), filePath, data, &level);

    if (corto_mkdir(filePath)) {
        printf("failed to create dir '%s' (%s)\n", filePath, corto_lasterr());
        goto error;
    }

    strcat(filePath, "/");
    strcat(filePath, corto_nameof(o));
    strcat(filePath, ".html");
    file = g_fileOpen(data->generator, filePath);
    if (!file) {
        printf("failed to open file\n");
        goto error;
    }

    g_fileWrite(file, "<!DOCTYPE html>\n");
    g_fileWrite(file, "<html>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<head>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<meta charset=\"utf-8\">\n");
    g_fileWrite(file, "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">");
    g_fileWrite(file, "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    
    g_fileWrite(file, "<link href=\"");  
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "bootstrap.min.css\" rel=\"stylesheet\">\n");
    g_fileWrite(file, 
        "<link href='https://fonts.googleapis.com/css?family=Open+Sans:400,300,600' rel='stylesheet' type='text/css'>\n");
    g_fileWrite(file, "<link href=\"");  
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    } 
    g_fileWrite(file, "octicons.css\" rel=\"stylesheet\">\n");
    g_fileWrite(file, "<link href=\"");  
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    } 
    g_fileWrite(file, "cortodoc.css\" rel=\"stylesheet\">\n");
    g_fileWrite(file, "<script src=\"");
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "jquery-1.11.2.min.js\"></script>\n");
    g_fileWrite(file, "<script src=\"");
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "bootstrap.min.js\"></script>\n");
    g_fileWrite(file, "<script src=\"");
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "smoothscroll.js\"></script>\n");
    g_fileWrite(file, "<title>%s | Corto documentation</title>\n", corto_nameof(o));
    g_fileDedent(file);
    g_fileWrite(file, "</head>\n");
    g_fileWrite(file, "<body>\n");
    g_fileIndent(file);

    g_fileWrite(file, "<div class=\"container-fluid\"><nav class=\"navbar navbar-doc\">\n");
    g_fileWrite(file, "<div class=\"container-fluid\">\n");
    g_fileWrite(file, "<div class=\"navbar-header\">\n");
    g_fileWrite(file, "<a class='navbar-brand' href=\"http://corto.io\"><img src=\"");
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "cortologo.png\" width=\"100px\"></a>\n");
    g_fileWrite(file, "</div>\n");

    g_fileWrite(file, "<div id=\"navbar\" class=\"navbar-collapse collapse\">\n");
    g_fileWrite(file, "<ul class=\"nav navbar-nav navbar-right\">\n");
    g_fileWrite(file, "<li><a href=\"http://corto.io/getstarted.html\">TUTORIAL</a></li>\n");
    g_fileWrite(file, "<li><a href=\"http://corto.io/doc/corto/lang.html\">REFERENCE DOCUMENTATION</a></li>\n");
    g_fileWrite(file, "<li><a href=\"https://github.com/cortoproject/corto/wiki\">WIKI</a></li>\n");
    g_fileWrite(file, "<li><a href=\"https://github.com/cortoproject/examples\">EXAMPLES</a></li>\n");
    g_fileWrite(file, "</ul>\n");
    g_fileWrite(file, "</div>\n");

    g_fileWrite(file, "</nav></div>\n");

    g_fileWrite(file, "<div class='container-fluid' style='margin-top: 80px'>\n");
    g_fileIndent(file);

    g_fileWrite(file, "<div class='col-md-9'>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<p class='title'>Reference Documentation</p>\n");
    if (html_printParents(o, file, data)) {
        goto error;
    }

    g_fileWrite(file, "<div class='package'>\n");
    g_fileIndent(file);

    corto_id capitalizedTypeName;
    strcpy(capitalizedTypeName, corto_nameof(corto_typeof(o)));
    capitalizedTypeName[0] = toupper(capitalizedTypeName[0]);
    if (g_fileWrite(file, "<h1>%s %s</h1>\n", corto_nameof(o), capitalizedTypeName)) {
        goto error;
    }

    corto_string description = doc_getDescription(o);
    if (description && strlen(description)) {
        g_fileWrite(file, "<p>%s <a class='details smoothScroll' href='#details'>More...</a></p>\n", description);
    }

    return file;
error:
    return NULL;
}

static void html_closeIndexHtml(g_file file) {
    g_fileDedent(file);
    g_fileWrite(file, "</div>\n");
    g_fileWrite(file, "<div class='col-md-3'></div>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</div>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</div>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</body>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</html>\n");
    g_fileClose(file);
}

static int html_walk(corto_object o, void *userData) {
    htmlData_t *data = userData;
    g_file file = NULL;
    corto_bool exploreScope = TRUE;

    if (corto_instanceof(corto_package_o, o)) {
        file = html_openIndexHtml(o, data);
        if (html_printPackage(o, file, data)) {
            goto error;
        }
    } else if (corto_instanceof(corto_class_o, o)) {
        file = html_openIndexHtml(o, data);
        if (html_printClass(o, file, data)) {
            goto error;
        }
    } else if (corto_instanceof(corto_struct_o, o)) {
        file = html_openIndexHtml(o, data);
        if (html_printStruct(o, file, data)) {
            goto error;
        }
    } else if (corto_instanceof(corto_interface_o, o)) {
        file = html_openIndexHtml(o, data);
        if (html_printInterface(o, file, data)) {
            goto error;
        }
    }

    if (file) {
        html_closeIndexHtml(file);
    }

    if (exploreScope) {
        if (!corto_scopeWalk(o, html_walk, data)) {
            goto error;
        }
    }
    return 1;
error:
    return 0;
}

static corto_int16 html_copy(const char* path, const char *name) {
    char sourcePath[PATH_MAX];
    char destinationPath[PATH_MAX];
    char *cortoHome = getenv("CORTO_HOME");
    sprintf(sourcePath, "%s/etc/corto/%s.%s/generators/%s", cortoHome, 
        CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR, name);
    sprintf(destinationPath, "%s/%s", path, name);
    if (corto_cp(sourcePath, destinationPath)) {
        goto error;
    }
    return 0;
error:
    return -1;
}

corto_int16 corto_genMain(corto_generator g) {
    const char docsFilename[] = "doc";
    corto_object md;

    system("rm -rf doc");
    corto_mkdir(docsFilename);
    htmlData_t data = {docsFilename, 1, "", g};

    /* If the markdown package is not yet built, don't do HTML generation */
    if (!(md = corto_resolve(NULL, "corto::md"))) {
        return 0;        
    } else {
        corto_release(md);
    }

    if (html_copy(data.path, "jquery-1.11.2.min.js")) {
        goto error;
    }

    if (html_copy(data.path, "bootstrap.min.js")) {
        goto error;
    }

    if (html_copy(data.path, "smoothscroll.js")) {
        goto error;
    }
    
    if (html_copy(data.path, "bootstrap.min.css")) {
        goto error;
    }

    if (html_copy(data.path, "cortodoc.css")) {
        goto error;
    }

    if (html_copy(data.path, "octicons.css")) {
        goto error;
    }

    if (html_copy(data.path, "octicons.ttf")) {
        goto error;
    }

    if (html_copy(data.path, "cortologo.png")) {
        goto error;
    }

    if (!g_walkNoScope(g, html_walk, &data)) {
        goto error;
    }

    return 0;
error:
    return -1;
}
