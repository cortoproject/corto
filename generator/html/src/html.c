#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

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
 * Prints the resulting json into a "data.json" file.
 */
static cx_int32 html_jsonWalk(cx_object o, void *userData) {
    cx_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, TRUE, TRUE, FALSE};
    cx_html_gen_t *htmlData;
    struct cx_serializer_s serializer;
    char *folderPath;
    char *filepath;
    g_file file;
    cx_id fullname;
    int length;
    cx_int32 result;

    htmlData = userData;

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

    serializer = cx_json_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);
    cx_serialize(&serializer, o, &jsonData);
    
    file = g_fileOpen(htmlData->generator, filepath);
    cx_fullname(o, fullname);
    g_fileWrite(file, "objects[\"%s\"] = %s;", fullname, jsonData.buffer);

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
    cx_id fullname;
    
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
    g_fileWrite(file, "objectparse.js\"></script>\n");

    /* This object */
    g_fileWrite(file, "<script src=\"./data.js\"></script>\n");

    /* Parent object */
    if (data->level > 1) {
        g_fileWrite(file, "<script src=\"../data.js\"></script>\n");
    }

    /* Child objects */
    if (!cx_scopeWalk(o, html_printScopeItemScriptWalk, file)) {
        cx_error("Error traversing scope children to include their \"data.js\"");
        goto error;
    }

    g_fileWrite(file, "<script>rootName = \"%s\";</script>\n", data->rootFullname);

    /* This object name */
    cx_fullname(o, fullname);
    g_fileWrite(file, "<script>thisName = \"%s\";</script>\n", fullname);

    /* CSS */
    g_fileWrite(file, "<link href=\"../");
    for (level = 1; level < data->level; level++) {
        g_fileWrite(file, "../");
    }
    g_fileWrite(file, "object.css\" rel=\"stylesheet\">\n");

    g_fileDedent(file);
    g_fileWrite(file, "</head>\n");
    g_fileWrite(file, "<body>\n");
    g_fileIndent(file);
    g_fileWrite(file, "<main>\n");
    g_fileWrite(file, "</main>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</body>\n");
    g_fileDedent(file);
    g_fileWrite(file, "</html>\n");

    return 0;
error:
    return -1;
}

static int html_HtmlWalk(cx_object o, void *userData) {
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

    result = cx_scopeWalk(o, html_HtmlWalk, &childHtmlData);
    cx_dealloc(folderPath);
    return result;
error2:
    cx_dealloc(filepath);
error1:
    cx_dealloc(folderPath);
error:
    return 0;
}


static cx_int16 html_copyJQueryFile(const char *path) {
    const char jqueryFilename[] = "jquery-1.11.2.min.js";
    char *cortexHome = getenv("CORTEX_HOME");

    char *sourcePath;
    char *destinationPath;
    int length;

    length = snprintf(NULL, 0, "%s/generator/html/%s", cortexHome, jqueryFilename);
    if (length < 0) {
        cx_error("snprintf failed for parser filename");
        goto error;
    }
    sourcePath = cx_malloc(length + 1);
    sprintf(sourcePath, "%s/generator/html/%s", cortexHome, jqueryFilename);

    length = snprintf(NULL, 0, "%s/%s", path, jqueryFilename);
    if (length < 0) {
        cx_error("snprintf failed for ");
        goto error1;
    }
    destinationPath = cx_malloc(length + 1);
    sprintf(destinationPath, "%s/%s", path, jqueryFilename);

    if (cx_cp(sourcePath, destinationPath)) {
        goto error1;
    }
    return 0;

error1:
    cx_dealloc(sourcePath);
error:
    return -1;
}


static cx_int16 html_copyJsonParserFile(const char *path) {
    const char parserFilename[] = "objectparse.js";
    char *cortexHome = getenv("CORTEX_HOME");

    char *sourcePath;
    char *destinationPath;
    int length;
    
    length = snprintf(NULL, 0, "%s/generator/html/%s", cortexHome, parserFilename);
    if (length < 0) {
        cx_error("snprintf failed");
        goto error1;
    }
    sourcePath = cx_malloc(length + 1);
    sprintf(sourcePath, "%s/generator/html/%s", cortexHome, parserFilename);

    length = snprintf(NULL, 0, "%s/%s", path, parserFilename);
    if (length < 0) {
        cx_error("snprintf failed");
        goto error2;
    }
    destinationPath = cx_malloc(length + 1);
    sprintf(destinationPath, "%s/%s", path, parserFilename);

    if (cx_cp(sourcePath, destinationPath)) {
        goto error3;
    }

    cx_dealloc(destinationPath);
    cx_dealloc(sourcePath);
    return 0;

error3:
    cx_dealloc(destinationPath);
error2:
    cx_dealloc(sourcePath);
error1:
    return -1;
}


static cx_int16 html_copyStyleSheetFile(const char* path) {
    const char stylesheetFilename[] = "object.css";
    char *cortexHome = getenv("CORTEX_HOME");

    char *sourcePath;
    char *destinationPath;
    int length;
    
    length = snprintf(NULL, 0, "%s/generator/html/%s", cortexHome, stylesheetFilename);
    if (length < 0) {
        cx_error("snprintf failed");
        goto error;
    }
    sourcePath = cx_malloc(length + 1);
    sprintf(sourcePath, "%s/generator/html/%s", cortexHome, stylesheetFilename);

    length = snprintf(NULL, 0, "%s/%s", path, stylesheetFilename);
    if (length < 0) {
        cx_error("snprintf failed");
        goto error;
    }
    destinationPath = cx_malloc(length + 1);
    sprintf(destinationPath, "%s/%s", path, stylesheetFilename);

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

    if (success && !(success = !html_copyJQueryFile(data.path))) {
        cx_error("Cannot copy \"jQuery\".");
    }

    if (success && !(success = !html_copyJsonParserFile(data.path))) {
        cx_error("Cannot copy \"objectparse.js\".");
    }

    if (success && !(success = !html_copyStyleSheetFile(data.path))) {
        cx_error("Cannot copy \"object.css\".");
    }
    
    if (success && !(success = g_walkNoScope(g, html_jsonWalk, &data))) {
        cx_error("Error creating js files.");
    }
    
    if (success && !(success = g_walkNoScope(g, html_HtmlWalk, &data))) {
        cx_error("Error creating html files.");
    }

    return 0;
}
