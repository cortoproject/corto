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
    cx_generator generator;
} htmlData_t;

/*
 * Create a folder for this object
 * Make an index.html file inside, contents are dependent on kind of object
 *     e.g. primitives are a plain value but classes include description
       of members
 * Make a data.json file inside
 * Call recursively for every object in this scope
 */
static char* html_pathToRoot(cx_object o, char* buffer, cx_uint32 *level) {
    if (cx_parentof(o)) {
        html_pathToRoot(cx_parentof(o), buffer, level);
    }
    if (cx_nameof(o)) {
        strcat(buffer, "/");
        strcat(buffer, cx_nameof(o));
    }
    if (level) {
        (*level)++;
    }
    return buffer;
}

static char* html_fileFrom(cx_object from, cx_object o, char *buffer) {
    cx_object p = cx_parentof(from);
    buffer[0] = '\0';
    while (p != root_o) {
        strcat(buffer, "../");
        p = cx_parentof(p);
    }
    buffer[strlen(buffer) - 1] = '\0';

    if (cx_instanceof(cx_package_o, o) ||
        cx_instanceof(cx_interface_o, o)) {
        html_pathToRoot(o, buffer, NULL);
        strcat(buffer, ".html");
    } else {
        html_pathToRoot(cx_parentof(o), buffer, NULL);
        strcat(buffer, ".html");
        strcat(buffer, "#");
        strcat(buffer, cx_nameof(o));
    }

    return buffer;
}

static void html_getPath(cx_object o, char *buffer, htmlData_t *data, cx_uint32 *level) {
    strcpy(buffer, data->path);
    if (cx_nameof(o)) {
        html_pathToRoot(cx_parentof(o), buffer, level);
        strcat(buffer, "/");
        strcat(buffer, cx_nameof(o));
    }
}

static char* html_getFile(cx_object from, cx_object o, char *buffer, htmlData_t *data, cx_uint32 *level) {
    if (from == cx_parentof(o)) {
        strcpy(buffer, cx_nameof(from));
        strcat(buffer, "/");
        strcat(buffer, cx_nameof(o));
        strcat(buffer, ".html");
    } else {
        html_getPath(o, buffer, data, level);
        strcat(buffer, ".html");
    }
    return buffer;
}

typedef struct htmlTypeWalkData_t {
    g_file file;
    cx_type typeToWalk;
    cx_bool instanceof;
    cx_ll printed;
    cx_ll counted;
    htmlData_t *data;
} htmlTypeWalkData_t;

static int html_hasTypeWalk(cx_object o, void *userData) {
    htmlTypeWalkData_t *data = userData;

    if (((data->instanceof && cx_instanceof(data->typeToWalk, o)) || 
        (cx_typeof(o) == data->typeToWalk)) &&
        !cx_llHasObject(data->counted, o)) {
        cx_llAppend(data->counted, o);
    }

    return 1;
}

/* Reflection hack to get the description from a document */
static cx_string doc_getDescription(cx_object o) {
    cx_object doc = cx_man(o);
    cx_object cl = cx_resolve(NULL, "corto::md::Doc");
    cx_string result = "";

    if (cl) {
        if (doc) {
            cx_member m = cx_interface_resolveMember(cl, "description");
            if (m) {
                result = *(cx_string*)CX_OFFSET(doc, m->offset);
                if (!result) {
                    result = "";
                }
            } else {
                cx_critical("member description not found in doc class");
            }
        }
    }

    return result;
}

/* Reflection hack to get the description from a document */
static cx_string doc_getText(cx_object o) {
    cx_object doc = cx_man(o);
    cx_object cl = cx_resolve(NULL, "corto::md::Doc");
    cx_string result = "";

    if (cl) {
        if (doc) {
            cx_member m = cx_interface_resolveMember(cl, "text");
            if (m) {
                result = *(cx_string*)CX_OFFSET(doc, m->offset);
                if (!result) {
                    result = "";
                }
            } else {
                cx_critical("member text not found in doc class");
            }
        }
    }

    return result;
}


static int html_typeWalk(cx_object o, void *userData) {
    htmlTypeWalkData_t *data = userData;
    cx_string description = "";

    description = doc_getDescription(o);

    if (((data->instanceof && cx_instanceof(data->typeToWalk, o)) || 
        (cx_typeof(o) == data->typeToWalk)) &&
        !cx_llHasObject(data->printed, o)) 
    {
        cx_id id;
        g_fileWrite(
            data->file, 
            "<tr><td><a class=\"reference\"href=\"%s\">%s</a>&nbsp;-&nbsp;"
            "<span class=\"description\">%s</span></td></tr>\n",
            html_getFile(cx_parentof(o), o, id, data->data, NULL), 
            cx_nameof(o), 
            description);
        cx_llAppend(data->printed, o);
    }

    return 1;
}

typedef enum html_printMask {
    PRINT_TYPES = 1,
    PRINT_MEMBERS = 2,
} html_printMask;

static int html_printType(
    cx_object o, 
    g_file file, 
    cx_string title, 
    cx_type type, 
    cx_uint32 count,
    htmlTypeWalkData_t *data) {

    data->typeToWalk = cx_type(type);
    cx_scopeWalk(o, html_hasTypeWalk, data);
    if (cx_llSize(data->counted) != count) {
        g_fileWrite(file, "<h2>%s</h2>\n", title);
        g_fileWrite(file, "<table class='category'>\n");
        cx_scopeWalk(o, html_typeWalk, data);
        g_fileWrite(file, "</table>\n");
        count = cx_llSize(data->counted);
    } 

    return count;  
}

static cx_int16 cx_ser_member(cx_serializer s, cx_value *info, void *userData) {
    g_file file = userData;
    cx_member m = info->is.member.t;
    cx_string description = doc_getDescription(m);
    cx_type topLevelType = cx_typeof(cx_valueObject(info));
    cx_id path;

    CX_UNUSED(s);

    g_fileWrite(file, "<tr>\n");
    g_fileWrite(file,
        "<td><a class='reference' href='#%s'>%s</a>"
        "&nbsp:&nbsp;<a class='reference reference-type' href='%s'>%s</a>", 
        cx_nameof(m),
        cx_nameof(m),
        html_fileFrom(cx_parentof(m), m->type, path),
        cx_nameof(m->type));

    cx_member mptr = m;
    while ((!description || !strlen(description)) && mptr) {
        if (cx_instanceof(cx_alias_o, mptr)) {
            mptr = cx_alias(mptr)->member;
            description = doc_getDescription(mptr);
        } else {
            mptr = NULL;
        }
    }

    if (description && strlen(description)) {
        g_fileWrite(file, "&nbsp;-&nbsp;<span class='description'>%s</span>", description);
    }

    if (cx_parentof(m) != topLevelType) {
        cx_id id;
        g_fileWrite(file, "<br><span class='annotate'>from %s</span>\n", cx_fullname(cx_parentof(m), id));
    }

    if (cx_instanceof(cx_alias_o, m)) {
        cx_id id;
        g_fileWrite(file, "<br><span class='annotate'>alias&nbsp;of&nbsp;%s</span>", cx_fullname(cx_alias(m)->member, id));
    }

    g_fileWrite(file, "</td></tr>\n");

    return 0;
}

static cx_int16 cx_ser_memberDetail(cx_serializer s, cx_value *info, void *userData) {
    g_file file = userData;
    cx_member m = info->is.member.t;
    cx_string description = doc_getDescription(m);
    cx_id path;

    CX_UNUSED(s);

    cx_member mptr = m;
    while ((!description || !strlen(description)) && mptr) {
        if (cx_instanceof(cx_alias_o, mptr)) {
            mptr = cx_alias(mptr)->member;
            description = doc_getDescription(mptr);
        } else {
            mptr = NULL;
        }
    }

    g_fileWrite(file, "<a name=\"%s\"></a>\n", cx_nameof(m));
    g_fileWrite(file, "<h3 class='detail'>%s</h3>", cx_nameof(m));
    g_fileWrite(file, "<hr>\n");
    g_fileWrite(file, "<p>%s</p>\n", description);
    g_fileWrite(file, "<table class='category detail'>\n");
    g_fileWrite(file, "<tr><td>Type</td><td><a class='reference' href='%s'>%s</a></td></tr>\n", 
        html_fileFrom(cx_parentof(m), m->type, path), 
        cx_nameof(m->type));
    g_fileWrite(file, "<tr><td>Access</td><td><a class='reference-enum' href='%s'>%s</a></td></tr>\n", 
        html_fileFrom(cx_parentof(m), cx_modifier_o, path),
        cx_modifierStr(m->modifiers));
    if (m->type->reference) {
        g_fileWrite(file, "<tr><td>State</td><td><a class='reference-enum' href='%s'>%s</a></td></tr>\n", 
            html_fileFrom(cx_parentof(m), cx_state_o, path),
            cx_stateStr(m->state));        
    }
    if (cx_instanceof(cx_alias_o, m)) {
        cx_id id;
        g_fileWrite(file, "<tr><td>Alias</td><td><a class='reference' href='%s'>%s</a></td></tr>\n",
            html_fileFrom(cx_parentof(m), cx_alias(m)->member, path),
            cx_fullname(cx_alias(m)->member, id));
    }
    g_fileWrite(file, "</table>\n");

    g_fileWrite(file, "</td></tr>\n");

    return 0;
}

/* Quick way to test whether there are members in a type: stop serializing with
 * an 'error' when one is encountered */
static cx_int16 cx_ser_memberTest(cx_serializer s, cx_value *info, void *userData) {
    CX_UNUSED(s);
    if (userData && cx_parentof(info->is.member.t) != userData) {
        return 0;
    }
    return -1;
}

static struct cx_serializer_s html_memberSerializer(cx_modifier access, cx_operatorKind accessKind) {
    struct cx_serializer_s s;
    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = CX_SERIALIZER_TRACE_NEVER;
    s.aliasAction = CX_SERIALIZER_ALIAS_PASSTHROUGH;
    s.metaprogram[CX_MEMBER] = cx_ser_member;

    return s;
}

static struct cx_serializer_s html_memberDetailSerializer(cx_modifier access, cx_operatorKind accessKind) {
    struct cx_serializer_s s;
    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = CX_SERIALIZER_TRACE_NEVER;
    s.aliasAction = CX_SERIALIZER_ALIAS_PASSTHROUGH;
    s.metaprogram[CX_MEMBER] = cx_ser_memberDetail;
    s.metaprogram[CX_BASE] = NULL;

    return s;
}

static struct cx_serializer_s html_memberTestSerializer(cx_modifier access, cx_operatorKind accessKind) {
    struct cx_serializer_s s;
    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = CX_SERIALIZER_TRACE_NEVER;
    s.aliasAction = CX_SERIALIZER_ALIAS_PASSTHROUGH;
    s.metaprogram[CX_MEMBER] = cx_ser_memberTest;

    return s;
}

static int html_printMembers(cx_object o, g_file file, cx_uint32 count, htmlTypeWalkData_t *data) {
    struct cx_serializer_s s = html_memberSerializer(CX_PRIVATE|CX_HIDDEN, CX_NOT);
    struct cx_serializer_s sTest = html_memberTestSerializer(CX_PRIVATE|CX_HIDDEN, CX_NOT);

    CX_UNUSED(data);

    if (cx_metaWalk(&sTest, o, NULL)) {
        g_fileWrite(file, "<h2>Members</h2>\n");
        g_fileWrite(file, "<table class='category'>\n");
        cx_metaWalk(&s, o, file);
        g_fileWrite(file, "</table>\n");        
    }

    return count;
}

static int html_printMemberDetail(cx_object o, g_file file, cx_uint32 count, htmlTypeWalkData_t *data) {
    struct cx_serializer_s s = html_memberDetailSerializer(CX_PRIVATE|CX_HIDDEN, CX_NOT);
    struct cx_serializer_s sTest = html_memberTestSerializer(CX_PRIVATE|CX_HIDDEN, CX_NOT);

    CX_UNUSED(data);

    if (cx_metaWalk(&sTest, o, o)) {
        g_fileWrite(file, "<h2>Member Documentation</h2>\n");
        g_fileWrite(file, "<table class='category'>\n");
        cx_metaWalk(&s, o, file);
        g_fileWrite(file, "</table>\n");        
    }

    return count;
}

typedef enum html_printFunctionKind {
    HTML_PRINT_METHODS,
    HTML_PRINT_FUNCTIONS,
    HTML_PRINT_METAPROCEDURES
} html_printFunctionKind;

static int html_printFunction(cx_function m, g_file file, cx_object o) {
    cx_id path;
    cx_interface base = cx_interface(cx_parentof(m))->base;
    cx_function overrides = NULL;
    cx_string description = NULL;

    description = doc_getDescription(m);
    g_fileWrite(file, 
        "<tr><td>"
        "<a class='reference' href='#%s'>%s</a>&nbsp;:&nbsp;"
        "<a class='reference reference-type' href='%s'>%s</a>",
        cx_nameof(m),
        cx_nameof(m),
        html_fileFrom(o, m->returnType, path),
        cx_nameof(m->returnType));

    if (base && cx_instanceof(cx_method_o, m)) {
        overrides = cx_function(cx_interface_resolveMethod(base, cx_nameof(m)));
        if (overrides && 
            cx_instanceof(cx_method_o, overrides) && 
            cx_method(overrides)->_virtual) {
        } else {
            overrides = NULL;
        }
    }

    if (overrides && (!description || !strlen(description))) {
        cx_object optr = overrides;
        cx_interface i = base;
        while ((!description || !strlen(description)) && optr) {
            description = doc_getDescription(optr);
            i = cx_interface(cx_parentof(optr))->base;
            if (i) {
                optr = cx_interface_resolveMethod(i, cx_nameof(optr));
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

    if (cx_instanceof(cx_metaprocedure_o, m) || (cx_parentof(m) != o)) {
        cx_id id;
        g_fileWrite(file, 
            "<br/><span class='annotate'>from %s</span>\n", 
            cx_fullname(cx_parentof(m), id));
    }

    if (overrides) {
        cx_id id;
        g_fileWrite(file, 
            "<br/><span class='annotate'>overrides %s</span>\n", 
            cx_fullname(overrides, id));
    }

    g_fileWrite(file, "</td></tr>\n");

    return 0;
}

static int html_printFunctions(
    cx_object o, 
    g_file file, 
    cx_string title, 
    html_printFunctionKind kind, 
    cx_uint32 count,
    htmlTypeWalkData_t *data) 
{
    cx_vtable methods;
    cx_objectseq functions;
    cx_object typeBase = o;
    cx_bool objectsToPrint = TRUE;
    CX_UNUSED(data);

    if (kind == HTML_PRINT_METAPROCEDURES) {
        methods = cx_type(o)->metaprocedures;
    } else if (kind == HTML_PRINT_METHODS) {
        methods = cx_interface(o)->methods;
        objectsToPrint = methods.length != 0;
    } else if (kind == HTML_PRINT_FUNCTIONS) {
        functions = cx_scopeClaim(o);
        objectsToPrint = FALSE;
         cx_objectseqForeach(functions, m) {
            if (cx_typeof(m) == (cx_type)cx_function_o) {
                objectsToPrint = TRUE;
                break;
            }
        }
    }

    if (objectsToPrint) {
        g_fileWrite(file, "<h2>%s</h2>\n", title);
        g_fileWrite(file, "<table class='category'>\n");
        do {
            if (kind != HTML_PRINT_FUNCTIONS) {
                cx_vtableForeach(methods, m) {
                    html_printFunction(cx_function(m), file, o);
                }
            } else {
                cx_objectseqForeach(functions, m) {
                    if (cx_typeof(m) == (cx_type)cx_function_o) {
                        html_printFunction(m, file, o);
                    }
                }
            }

            if ((kind == HTML_PRINT_METAPROCEDURES) && cx_instanceof(cx_interface_o, o)) {
                typeBase = cx_interface(typeBase)->base;
                if (typeBase) {
                    methods = cx_type(typeBase)->metaprocedures;
                } else {
                    break;
                }
            }
        } while (kind == HTML_PRINT_METAPROCEDURES);
        g_fileWrite(file, "</table>\n");
    }

    if (kind == HTML_PRINT_FUNCTIONS) {
        cx_scopeRelease(functions);
    }

    return count;
}

static int html_printScope(cx_object o, g_file file, html_printMask mask, htmlData_t *data) {
    htmlTypeWalkData_t walkData;
    cx_uint32 count = 0;

    walkData.instanceof = TRUE;
    walkData.printed = cx_llNew();
    walkData.counted = cx_llNew();
    walkData.file = file;
    walkData.data = data;

    if (mask & PRINT_MEMBERS) {
        count = html_printMembers(o, file, count, &walkData);
        count = html_printFunctions(o, file, "Methods", HTML_PRINT_METHODS, count, &walkData);
        count = html_printFunctions(o, file, "Functions", HTML_PRINT_FUNCTIONS, count, &walkData);
        count = html_printFunctions(cx_typeof(o), file, "Metaprocedures", HTML_PRINT_METAPROCEDURES, count, &walkData);
    }

    if (mask & PRINT_TYPES) {
        walkData.instanceof = FALSE;
        count = html_printType(o, file, "Classes", cx_type(cx_class_o), count, &walkData);
        count = html_printType(o, file, "Structs", cx_type(cx_struct_o), count, &walkData);
        count = html_printType(o, file, "Interfaces", cx_type(cx_interface_o), count, &walkData);
        count = html_printType(o, file, "Enumerations", cx_type(cx_enum_o), count, &walkData);
        count = html_printType(o, file, "Bitmasks", cx_type(cx_bitmask_o), count, &walkData);

        walkData.instanceof = TRUE;
        count = html_printType(o, file, "Primitives", cx_type(cx_primitive_o), count, &walkData);
        count = html_printType(o, file, "Collections", cx_type(cx_collection_o), count, &walkData);
        count = html_printType(o, file, "Delegates", cx_type(cx_delegate_o), count, &walkData);
        count = html_printType(o, file, "Other types", cx_type(cx_type_o), count, &walkData);
        
        if (!(mask & PRINT_MEMBERS)) {
            count = html_printFunctions(o, file, "Functions", HTML_PRINT_FUNCTIONS, count, &walkData);
        }
    }

    return 0;
}

static int html_printScopeDetail(cx_object o, g_file file, html_printMask mask, htmlData_t *data) {
    htmlTypeWalkData_t walkData;
    cx_uint32 count = 0;

    walkData.instanceof = TRUE;
    walkData.printed = cx_llNew();
    walkData.counted = cx_llNew();
    walkData.file = file;
    walkData.data = data;

    if (mask & PRINT_MEMBERS) {
        count = html_printMemberDetail(o, file, count, &walkData);
        /*count = html_printFunctionDetail(o, file, "Method Documentation", HTML_PRINT_METHODS, count, &walkData);
        count = html_printFunctionDetail(o, file, "Function Documentation", HTML_PRINT_FUNCTIONS, count, &walkData);
        count = html_printFunctionDetail(o, file, "Metaprocedure Documentation", HTML_PRINT_METAPROCEDURES, count, &walkData);*/
    }

    if (mask & PRINT_TYPES) {
        /*walkData.instanceof = FALSE;
        count = html_printTypeDetail(o, file, "Enumerations", cx_type(cx_enum_o), count, &walkData);
        count = html_printTypeDetail(o, file, "Bitmasks", cx_type(cx_bitmask_o), count, &walkData);

        walkData.instanceof = TRUE;
        count = html_printTypeDetail(o, file, "Primitives", cx_type(cx_primitive_o), count, &walkData);
        count = html_printTypeDetail(o, file, "Collections", cx_type(cx_collection_o), count, &walkData);
        count = html_printTypeDetail(o, file, "Other types", cx_type(cx_type_o), count, &walkData);
        
        if (!(mask & PRINT_MEMBERS)) {
            count = html_printFunctions(o, file, "Functions", HTML_PRINT_FUNCTIONS, count, &walkData);
        }*/
    }

    return 0;
}

static int html_printParents(cx_object o, g_file file, htmlData_t *data) {
    cx_object parents[CX_MAX_SCOPE_DEPTH];
    cx_object p = o;
    cx_uint32 i = 0;
    cx_id capitalizedTypeName;

    CX_UNUSED(data);

    while(p) {
        parents[i] = p;
        p = cx_parentof(p);
        i++;
    }
    g_fileWrite(file, "<p class='parents'>\n");
    while(i) {
        cx_uint32 j = 0;
        i--;
        if (i) {
            g_fileWrite(file, "<a href=\"");
            for (j = 0; j < i; j ++) {
                g_fileWrite(file, "../");
            }
            g_fileWrite(file, "%s.html\">", cx_nameof(parents[i]));
        }

        if (cx_nameof(parents[i])) {
            g_fileWrite(file, "%s", cx_nameof(parents[i]));
        } else {
            g_fileWrite(file, "root");
        }
        strcpy(capitalizedTypeName, cx_nameof(cx_typeof(parents[i])));
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

static int html_printInheritance(cx_interface o, g_file file) {
    if (o->base) {
        g_fileWrite(file, "<table class='category'>\n");
        cx_id id, path;
        g_fileWrite(file, "<tr><td>Base</td><td><a class='reference' href='%s'>%s</a></td></tr>\n", 
            html_fileFrom(o, o->base, path),
            cx_fullname(o->base, id));
        if (cx_instanceof(cx_struct_o, o)) {
            g_fileWrite(file, "<tr><td>Access</td><td><a class='reference-enum' href='%s'>%s</a></td></tr>",
                html_fileFrom(o, cx_modifier_o, path), 
                cx_modifierStr(cx_struct(o)->baseAccess));
        }
    }

    if (cx_instanceof(cx_class_o, o) && cx_class(o)->implements.length) {
        cx_int32 count = 0;

        if (!o->base) {
            g_fileWrite(file, "<table class='category'>\n");   
        }

        g_fileWrite(file, "<tr><td>Implements</td><td>");
        cx_interfaceseqForeach(cx_class(o)->implements, i) {
            cx_id path;
            if (count) {
                g_fileWrite(file, ", ");
            }
            g_fileWrite(file, "<a class='reference' href='%s'>%s</a>", 
                html_fileFrom(o, i, path),
                cx_nameof(i));
            count++;
        }
        g_fileWrite(file, "</td></tr>\n");

        g_fileWrite(file, "</table>\n");
    } else if (o->base) {
        g_fileWrite(file, "</table>\n");
    }



    return 0;
}

static int html_printPackage(cx_object o, g_file file, htmlData_t *data) {
    html_printScope(o, file, PRINT_TYPES, data);
    html_printScopeDetail(o, file, PRINT_TYPES, data);
    return 0;
}

static int html_printClass(cx_object o, g_file file, htmlData_t *data) {
    html_printInheritance(o, file);
    html_printScope(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
    html_printScopeDetail(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
    return 0;
}

static int html_printStruct(cx_object o, g_file file, htmlData_t *data) {
    return html_printScope(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
}

static int html_printInterface(cx_object o, g_file file, htmlData_t *data) {
    return html_printScope(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
}

static int html_printOther(cx_object o, g_file file, htmlData_t *data) {
    return html_printScope(o, file, PRINT_TYPES, data);
}

static g_file html_openIndexHtml(cx_object o, htmlData_t *data) {
    char filePath[PATH_MAX];
    g_file file;
    cx_uint32 level = 0; /* Root is at 0 */
    cx_uint32 i;

    html_getPath(cx_parentof(o), filePath, data, &level);

    if (cx_mkdir(filePath)) {
        printf("failed to create dir '%s' (%s)\n", filePath, cx_lasterr());
        goto error;
    }

    strcat(filePath, "/");
    strcat(filePath, cx_nameof(o));
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
    g_fileWrite(file, "<link href=\"");  
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    } 
    g_fileWrite(file, "bootstrap.min.css\" rel=\"stylesheet\">\n");
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
    g_fileWrite(file, "<title>%s | Corto documentation</title>", cx_nameof(o));
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
    g_fileWrite(file, "<li><a href=\"http://corto.io/getstarted.html\" target=\"_blank\">TUTORIAL</a></li>\n");
    g_fileWrite(file, "<li><a href=\"https://github.com/cortoproject/corto/wiki/Documentation\" target=\"_blank\">WIKI</a></li>\n");
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

    cx_id capitalizedTypeName;
    strcpy(capitalizedTypeName, cx_nameof(cx_typeof(o)));
    capitalizedTypeName[0] = toupper(capitalizedTypeName[0]);
    if (g_fileWrite(file, "<h1>%s %s</h1>\n", cx_nameof(o), capitalizedTypeName)) {
        goto error;
    }
    g_fileWrite(file, "<hr>\n");

    cx_string description = doc_getDescription(o);
    if (description && strlen(description)) {
        g_fileWrite(file, "<p>%s <a class='details' href='#details'>More...</a></p>\n", description);
    }

    return file;
error:
    return NULL;
}

static void html_closeIndexHtml(cx_object o, g_file file) {
    cx_string description = doc_getDescription(o);
    if (description && strlen(description)) {
        g_fileWrite(file, "<a name='details'></a>\n");
        g_fileWrite(file, "<h2>Detailed description</h2>\n");
        g_fileWrite(file, "<p>%s</p>\n", description);
        g_fileWrite(file, "<p>%s</p>\n", doc_getText(o));
    }

    g_fileDedent(file);
    g_fileWrite(file, "</div>\n");
    g_fileWrite(file, "<div class='col-md-3'></div>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</div>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</div>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</body>\n");
    g_fileWrite(file, "</html>\n");
    g_fileClose(file);
}

static int html_walk(cx_object o, void *userData) {
    htmlData_t *data = userData;
    g_file file = NULL;
    cx_bool exploreScope = TRUE;

    if (cx_instanceof(cx_package_o, o)) {
        file = html_openIndexHtml(o, data);
        if (html_printPackage(o, file, data)) {
            goto error;
        }
    } else if (cx_instanceof(cx_class_o, o)) {
        file = html_openIndexHtml(o, data);
        if (html_printClass(o, file, data)) {
            goto error;
        }
    } else if (cx_instanceof(cx_struct_o, o)) {
        file = html_openIndexHtml(o, data);
        if (html_printStruct(o, file, data)) {
            goto error;
        }
    } else if (cx_instanceof(cx_interface_o, o)) {
        file = html_openIndexHtml(o, data);
        if (html_printInterface(o, file, data)) {
            goto error;
        }
    } else if (cx_instanceof(cx_enum_o, o)) {
        file = html_openIndexHtml(o, data);
        exploreScope = FALSE;
    } else if (cx_instanceof(cx_bitmask_o, o)) {
        file = html_openIndexHtml(o, data);
        exploreScope = FALSE;
    } else if (cx_instanceof(cx_type_o, o)) {
        file = html_openIndexHtml(o, data);
        if (html_printOther(o, file, data)) {
            goto error;
        }
        exploreScope = FALSE;
    }

    if (file) {
        html_closeIndexHtml(o, file);
    }

    if (exploreScope) {
        if (!cx_scopeWalk(o, html_walk, data)) {
            goto error;
        }
    }
    return 1;
error:
    return 0;
}

static cx_int16 html_copy(const char* path, const char *name) {
    char sourcePath[PATH_MAX];
    char destinationPath[PATH_MAX];
    char *cortoHome = getenv("CORTO_HOME");
    sprintf(sourcePath, "%s/etc/corto/%s/generators/%s", cortoHome, CORTO_VERSION, name);
    sprintf(destinationPath, "%s/%s", path, name);
    if (cx_cp(sourcePath, destinationPath)) {
        goto error;
    }
    return 0;
error:
    return -1;
}

cx_int16 corto_genMain(cx_generator g) {
    const char docsFilename[] = "doc";

    cx_mkdir(docsFilename);
    htmlData_t data = {docsFilename, 1, "", g};

    if (html_copy(data.path, "jquery-1.11.2.min.js")) {
        goto error;
    }

    if (html_copy(data.path, "bootstrap.min.js")) {
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
