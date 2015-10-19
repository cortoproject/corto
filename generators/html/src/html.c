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
        } else {
            cx_warning("warning: documentation not found for '%s'\n", cx_nameof(o));
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
        } else {
            cx_warning("warning: documentation not found for '%s'\n", cx_nameof(o));
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
            "<tr><td>%s</td><td><a class=\"reference\"href=\"%s\">%s</a></td><td>%s</td></tr>\n",
            cx_nameof(cx_typeof(o)),
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

static int html_printCategory(
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

static cx_int16 cx_ser_base(cx_serializer s, cx_value *info, void *userData) {
    CX_UNUSED(s);
    CX_UNUSED(info);
    CX_UNUSED(userData);
//    printf("<h3>Inherited from %s</h3>\n", cx_nameof(info->is.member.t->type));
    return 0;
}

static cx_int16 cx_ser_member(cx_serializer s, cx_value *info, void *userData) {
    g_file file = userData;
    cx_member m = info->is.member.t;
    cx_string description = doc_getDescription(m);
    cx_id path;

    CX_UNUSED(s);

    g_fileWrite(file, "<tr>\n");
    g_fileWrite(file, 
        "<td><span class=\"octicon octicon-chevron-right\"></span>&nbsp;<a class='reference' href='#%s'>%s</a>"
        "&nbsp:&nbsp;<a class='reference' href='%s'>%s</a>", 
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

    if (cx_instanceof(cx_alias_o, m)) {
        cx_id id;
        g_fileWrite(file, "<br><span class='annotate'>alias&nbsp;of&nbsp;%s</span>", cx_fullname(cx_alias(m)->member, id));
    }

    g_fileWrite(file, "</td></tr>\n");

    return 0;
}

static struct cx_serializer_s html_memberSerializer(cx_modifier access, cx_operatorKind accessKind) {
    struct cx_serializer_s s;
    cx_serializerInit(&s);

    s.access = access;
    s.accessKind = accessKind;
    s.traceKind = CX_SERIALIZER_TRACE_NEVER;
    s.aliasAction = CX_SERIALIZER_ALIAS_PASSTHROUGH;
    s.metaprogram[CX_MEMBER] = cx_ser_member;
    s.metaprogram[CX_BASE] = cx_ser_base;

    return s;
}

static int html_printMembers(cx_object o, g_file file, cx_uint32 count, htmlTypeWalkData_t *data) {
    struct cx_serializer_s s = html_memberSerializer(CX_PRIVATE, CX_NOT);

    CX_UNUSED(data);

    g_fileWrite(file, "<table class='category'>\n");
    cx_metaWalk(&s, o, file);
    g_fileWrite(file, "</table>\n");
    return count;
}

static int html_printMethods(cx_object o, g_file file, cx_uint32 count, htmlTypeWalkData_t *data) {
    cx_string description = NULL;
    cx_vtable methods = cx_interface(o)->methods;

    CX_UNUSED(data);

    g_fileWrite(file, "<table class='category'>\n");
    cx_vtableForeach(methods, m) {
        cx_id path;
        cx_interface base = cx_interface(cx_parentof(m))->base;
        cx_function overrides = NULL;

        description = doc_getDescription(m);
        g_fileWrite(file, 
            "<tr><td><span class=\"octicon octicon-chevron-right\"></span>&nbsp;"
            "<a class='reference' href='#%s'>%s</a>&nbsp;:&nbsp;"
            "<a class='reference' href='%s'>%s</a>",
            cx_nameof(m),
            cx_nameof(m),
            html_fileFrom(o, cx_function(m)->returnType, path),
            cx_nameof(cx_function(m)->returnType));

        if (base) {
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

        if (cx_parentof(m) != o) {
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
    }
    g_fileWrite(file, "</table>\n");
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
        g_fileWrite(file, "<h2>Members</h2>\n");
        count = html_printMembers(o, file, count, &walkData);
        g_fileWrite(file, "<h2>Methods</h2>\n");
        count = html_printMethods(o, file, count, &walkData);
    } else {
        count = html_printCategory(o, file, "Functions", cx_type(cx_function_o), count, &walkData);
    }

    if (mask & PRINT_TYPES) {
        walkData.instanceof = FALSE;
        count = html_printCategory(o, file, "Classes", cx_type(cx_class_o), count, &walkData);
        count = html_printCategory(o, file, "Structs", cx_type(cx_struct_o), count, &walkData);
        count = html_printCategory(o, file, "Interfaces", cx_type(cx_interface_o), count, &walkData);
        count = html_printCategory(o, file, "Enumerations", cx_type(cx_enum_o), count, &walkData);
        count = html_printCategory(o, file, "Bitmasks", cx_type(cx_bitmask_o), count, &walkData);

        walkData.instanceof = TRUE;
        count = html_printCategory(o, file, "Primitives", cx_type(cx_primitive_o), count, &walkData);
        count = html_printCategory(o, file, "Collections", cx_type(cx_collection_o), count, &walkData);
        count = html_printCategory(o, file, "Delegates", cx_type(cx_delegate_o), count, &walkData);
        count = html_printCategory(o, file, "Other types", cx_type(cx_type_o), count, &walkData);
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

static int html_printPackage(cx_object o, g_file file, htmlData_t *data) {
    return html_printScope(o, file, PRINT_TYPES, data);
}

static int html_printClass(cx_object o, g_file file, htmlData_t *data) {
    return html_printScope(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
}

static int html_printStruct(cx_object o, g_file file, htmlData_t *data) {
    return html_printScope(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
}

static int html_printInterface(cx_object o, g_file file, htmlData_t *data) {
    return html_printScope(o, file, PRINT_TYPES | PRINT_MEMBERS, data);
}

static int html_printType(cx_object o, g_file file, htmlData_t *data) {
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

    g_fileWrite(file, "<div class='container-floating'>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<div class='col-md-9'>\n");
    g_fileIndent(file);

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
        g_fileWrite(file, "%s <a class='details' href='#details'>More...</a>\n", description);
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
    g_fileWrite(file, "<div class='col-md-3></div>\n");
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
        if (html_printType(o, file, data)) {
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

    if (!g_walkNoScope(g, html_walk, &data)) {
        goto error;
    }

    return 0;
error:
    return -1;
}
