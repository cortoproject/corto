#include <errno.h>
#include <stdio.h>

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
static int html_folderWalk(cx_object o, void *userData) {
    cx_html_gen_t *data = userData;
    char *folderPath;
    int length;

    length = snprintf(NULL, 0, "%s/%s", data->path, cx_nameof(o));
    if (length < 0) {
        cx_error("cannot create path for object \"%s\" in path:\"%s\"",
            cx_nameof(o), data->path);
        goto error;
    }
    folderPath = cx_malloc(length + 1);
    sprintf(folderPath, "%s/%s", data->path, cx_nameof(o));

    if (cx_mkdir(folderPath)) {
        goto error1;
    }

    cx_html_gen_t scopeData = *data;
    scopeData.path = folderPath;

    return cx_scopeWalk(o, html_folderWalk, &scopeData);
error1:
    cx_dealloc(folderPath);
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
    char *folderPath;
    char *filepath;
    g_file file;
    int length;
    cx_int32 result;

    serializer = cx_json_ser(CX_PRIVATE, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

    length = snprintf(NULL, 0, "%s/%s", htmlData->path, cx_nameof(o));
    if (length < 0) {
        cx_error("snprintf failed for folder path");
        goto error;
    }
    folderPath = cx_malloc(length + 1);
    sprintf(folderPath, "%s/%s", htmlData->path, cx_nameof(o));

    length = snprintf(NULL, 0, "%s/data.js", folderPath);
    if (length < 0) {
        cx_error("snprintf failed for the data.js file path");
        goto error1;
    }
    filepath = cx_malloc(length + 1);
    sprintf(filepath, "%s/data.js", folderPath);

    file = g_fileOpen(htmlData->generator, filepath);

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

    cx_html_gen_t scopeData = *htmlData;
    scopeData.path = folderPath;

    cx_dealloc(filepath);
    result = cx_scopeWalk(o, html_jsonWalk, &scopeData);
    cx_dealloc(folderPath);
    return result;

error1:
    cx_dealloc(folderPath);
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
static int html_printHtml(cx_html_gen_t *data, cx_object o, g_file file) {
    unsigned int level;
    cx_id name;
    
    /* http://www.w3.org/TR/html5/syntax.html#writing */
    g_fileWrite(file, "<!DOCTYPE html>\n");
    g_fileWrite(file, "<html>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<head>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<meta charset=\"utf-8\">\n");

    /* jQuery */
    g_fileWrite(file, "<script src=\"");
    for (level = 0; level < data->level; level++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "jquery-1.11.2.min.js\"></script>\n");

    /* Parsing script */
    g_fileWrite(file, "<script src=\"");
    for (level = 0; level < data->level; level++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "cortex.js\"></script>\n");

    /* This object */
    g_fileWrite(file, "<script src=\"data.js\"></script>\n");

    /* Parent object */
    if (data->level > 1) {
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
    for (level = 1; level < data->level; level++) {
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
    g_fileWrite(file, "$('#header').append(cx.toLink('%s', 'header'));\n");
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
    static cx_id rootFullname = "";

    cx_html_gen_t *htmlData;
    char *folderPath;
    char *filepath;
    g_file file;
    int length;
    int result;

    htmlData = userData;

    length = snprintf(NULL, 0, "%s/%s", htmlData->path, cx_nameof(o));
    if (length < 0) {
        cx_error("snprintf failed");
        goto error;
    }
    folderPath = cx_malloc(length + 1);
    sprintf(folderPath, "%s/%s", htmlData->path, cx_nameof(o));

    length = snprintf(NULL, 0, "%s/index.html", folderPath);
    if (length < 0) {
        cx_error("snprintf failed");
        goto error1;
    }
    filepath = cx_malloc(length + 1);
    sprintf(filepath, "%s/index.html", folderPath);

    file = g_fileOpen(htmlData->generator, filepath);
    cx_dealloc(filepath);
    if (htmlData->level == 1) {
        cx_fullname(o, rootFullname);
        htmlData->rootFullname = rootFullname;
    }

    if (html_printHtml(htmlData, o, file)) {
        goto error2;
    }

    cx_html_gen_t childHtmlData = {folderPath, htmlData->level + 1,
        rootFullname, htmlData->generator};

    result = cx_scopeWalk(o, html_htmlWalk, &childHtmlData);
    cx_dealloc(folderPath);
    return result;
error2:
    cx_dealloc(filepath);
error1:
    cx_dealloc(folderPath);
error:
    return 0;
}

static cx_int16 html_copy(const char* path, const char *name) {
    char *sourcePath;
    char *destinationPath;
    int length;
    char *cortexHome = getenv("CORTEX_HOME");
    
    length = snprintf(NULL, 0, "%s/generator/html/%s", cortexHome, name);
    if (length < 0) {
        cx_error("snprintf failed");
        goto error;
    }
    sourcePath = cx_malloc(length + 1);
    sprintf(sourcePath, "%s/generator/html/%s", cortexHome, name);

    length = snprintf(NULL, 0, "%s/%s", path, name);
    if (length < 0) {
        cx_error("snprintf failed");
        goto error1;
    }
    destinationPath = cx_malloc(length + 1);
    sprintf(destinationPath, "%s/%s", path, name);

    if (cx_cp(sourcePath, destinationPath)) {
        cx_error("failed to copy %s", name);
        goto error;
    }

    cx_dealloc(destinationPath);
    cx_dealloc(sourcePath);
    return 0;
error1:
    cx_dealloc(sourcePath);
error:
    return -1;
}


cx_int16 cortex_genMain(cx_generator g) {
    const char docs_filename[] = "doc";
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
