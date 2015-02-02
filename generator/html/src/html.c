#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

#if __linux__
#include <linux/limits.h>
#else
#include <limits.h>
#endif

#include "cx_files.h"
#include "cx_generator.h"
#include "cx_object.h"
#include "cx_serializer.h"
#include "html.h"
#include "cortex.h"
#include "json.h"

/*
 * Create a folder for this object
 * Make an index.html file inside, contents are dependent on kind of object
 *     e.g. primitives are a plain value but classes include description
       of members
 * Make a data.json file inside
 * Call recursively for every object in this scope
 */
static void html_pathToRoot(cx_object o, char* buffer, cx_uint32 *level) {
    if (cx_parentof(o) && (cx_parentof(o) != root_o)) {
        html_pathToRoot(cx_parentof(o), buffer, level);
    }
    if (cx_nameof(o)) {
        strcat(buffer, "/");
        strcat(buffer, cx_nameof(o));
        if (level) {
            (*level)++;
        }
    }
}

static void html_getPath(cx_object o, char *buffer, cx_html_gen_t *data, cx_uint32 *level) {
    strcpy(buffer, data->path);
    if (cx_nameof(o)) {
        html_pathToRoot(cx_parentof(o), buffer, level);
        strcat(buffer, "/");
        strcat(buffer, cx_nameof(o));
    }
}

static int html_folderWalk(cx_object o, void *userData) {
    cx_html_gen_t *data = userData;
    char folderPath[PATH_MAX];

    html_getPath(o, folderPath, data, NULL);
    if (cx_mkdir(folderPath)) {
        goto error;
    }

    return cx_scopeWalk(o, html_folderWalk, data);
error:
    return 0;
}

/*
 * Add parents in root to object order
 */
static void html_parentWalk(cx_object o, g_file file) {
    if (cx_parentof(o) && (cx_parentof(o) != root_o)) {
        html_parentWalk(cx_parentof(o), file);
    }
    g_fileWrite(file, "o = o.declare('%s');\n", cx_nameof(o));
}

/*
 * Prints the resulting json into a "data.json" file.
 */
static cx_int32 html_jsonWalk(cx_object o, void *userData) {
    cx_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, FALSE, FALSE, FALSE};
    cx_html_gen_t *htmlData = userData;
    struct cx_serializer_s serializer;
    char filePath[PATH_MAX];
    g_file file;

    serializer = cx_json_ser(CX_PRIVATE, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

    /* Get path starting from root */
    html_getPath(o, filePath, htmlData, NULL);
    strcat(filePath, "/data.js");
    file = g_fileOpen(htmlData->generator, filePath);
    if (!file) {
        goto error;
    }

    g_fileWrite(file, "new function() {\n");
    g_fileIndent(file);

    g_fileWrite(file, "var o = cx.root;\n");
    html_parentWalk(o, file);

    if (cx_typeof(o)->kind != CX_VOID) {
        jsonData.serializeValue = TRUE;
        cx_serialize(&serializer, o, &jsonData);
        g_fileWrite(file, "o.value = %s;\n", jsonData.buffer);
        cx_dealloc(jsonData.buffer);
        memset(&jsonData, 0, sizeof(jsonData));
    }

    jsonData.serializeValue = FALSE;
    jsonData.serializeMeta = TRUE;
    cx_serialize(&serializer, o, &jsonData);
    g_fileWrite(file, "o.meta = %s;\n", jsonData.buffer);
    cx_dealloc(jsonData.buffer);

    g_fileDedent(file);
    g_fileWrite(file, "}();\n");

    return cx_scopeWalk(o, html_jsonWalk, htmlData);
error:
    return 0;
}

static int html_printScopeItemScriptWalk(cx_object o, void *userData) {
    g_file file = userData;
    g_fileWrite(file, "<script src=\"./%s/data.js\"></script>\n", cx_nameof(o));
    return 1;
}

/*
 * Assumes that the file is already opened.
 * Returns 0 on success, -1 otherwise.
 */
static int html_printHtml(cx_object o, g_file file, cx_uint32 level) {
    cx_id name;
    cx_uint32 i;
    
    /* http://www.w3.org/TR/html5/syntax.html#writing */
    g_fileWrite(file, "<!DOCTYPE html>\n");
    g_fileWrite(file, "<html>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<head>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<meta charset=\"utf-8\">\n");

    /* jQuery */
    g_fileWrite(file, "<script src=\"");
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "jquery-1.11.2.min.js\"></script>\n");

    /* Parsing script */
    g_fileWrite(file, "<script src=\"");
    for (i = 0; i < level; i++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "cortex.js\"></script>\n");

    /* This object */
    g_fileWrite(file, "<script src=\"data.js\"></script>\n");

    /* Parent object */
    if (level > 1) {
        g_fileWrite(file, "<script src=\"../data.js\"></script>\n");
    }

    /* Parent object */
    g_fileWrite(file, "<script>cx.setMe('%s');</script>\n", cx_fullname(o, name));

    /* Child objects */
    if (!cx_scopeWalk(o, html_printScopeItemScriptWalk, file)) {
        cx_error("Error traversing scope children to include their \"data.js\"");
        goto error;
    }

    /* CSS */
    g_fileWrite(file, "<link href=\"../");
    for (i = 1; i < level; i++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "cortex.css\" rel=\"stylesheet\">\n");

    g_fileDedent(file);
    g_fileWrite(file, "</head>\n");
    g_fileWrite(file, "<body>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<div id='header'></div>\n", cx_fullname(o, name));
    g_fileWrite(file, "<div id='scope'></div>\n");
    g_fileWrite(file, "<div id='container'>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<div id='meta'></div>\n");
    g_fileWrite(file, "<div id='value'></div>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</div>\n");
    g_fileWrite(file, "<script>\n");
    g_fileIndent(file);
    g_fileWrite(file, "var _o = cx.resolve('%s');\n", cx_fullname(o, name));
    g_fileWrite(file, "$('#header').append(cx.toLink('%s', 'header', true));\n", name);
    g_fileWrite(file, "$('#scope').append(_o.scopeToHtml());\n");
    g_fileWrite(file, "$('#meta').append(_o.metaToHtml());\n");
    g_fileWrite(file, "$('#value').append(_o.toHtml());\n");
    g_fileDedent(file);
    g_fileWrite(file, "</script>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</body>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</html>\n");

    return 0;
error:
    return -1;
}

static int html_htmlWalk(cx_object o, void *userData) {
    cx_html_gen_t *htmlData = userData;
    char filePath[PATH_MAX];
    g_file file;
    cx_uint32 level = 1; /* Root is at 0 */

    html_getPath(o, filePath, htmlData, &level);
    strcat(filePath, "/index.html");
    file = g_fileOpen(htmlData->generator, filePath);
    if (!file) {
        goto error;
    }

    if (html_printHtml(o, file, level)) {
        goto error;
    }

    g_fileClose(file);

    return cx_scopeWalk(o, html_htmlWalk, htmlData);
error:
    return 0;
}

static cx_int16 html_copy(const char* path, const char *name) {
    char sourcePath[PATH_MAX];
    char destinationPath[PATH_MAX];
    char *cortexHome = getenv("CORTEX_HOME");
    sprintf(sourcePath, "%s/generator/html/%s", cortexHome, name);
    sprintf(destinationPath, "%s/%s", path, name);
    if (cx_cp(sourcePath, destinationPath)) {
        goto error;
    }
    return 0;
error:
    return -1;
}


cx_int16 cortex_genMain(cx_generator g) {
    const char docs_filename[] = "docs";
    int success;

    cx_mkdir(docs_filename);
    cx_html_gen_t data = {docs_filename, 1, "", g};
    
    if (!(success = g_walkNoScope(g, html_folderWalk, &data))) {
        cx_error("Error creating folders.");
    }

    if (success && !(success = !html_copy(data.path, "jquery-1.11.2.min.js"))) {
        cx_error("Cannot copy \"jQuery\".");
    }

    if (success && !(success = !html_copy(data.path, "cortex.js"))) {
        cx_error("Cannot copy \"cortex.js\".");
    }

    if (success && !(success = !html_copy(data.path, "cortex.css"))) {
        cx_error("Cannot copy \"cortex.css\".");
    }
    
    if (success && !(success = g_walkNoScope(g, html_jsonWalk, &data))) {
        cx_error("Error creating js files.");
    }
    
    if (success && !(success = g_walkNoScope(g, html_htmlWalk, &data))) {
        cx_error("Error creating html files.");
    }

    return 0;
}
