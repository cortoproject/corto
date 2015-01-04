
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
static int gen_folder(cx_object o, void *userData) {
    cx_html_gen_t *data = userData;
    char folderPath[PATH_MAX];

    if (sprintf(folderPath, "%s/%s", data->path, cx_nameof(o)) < 0) {
        cx_error("Cannot create path for object \"%s\" in path:\"%s\".",
            cx_nameof(o), data->path);
        goto error;
    }

    if (cx_mkdir(folderPath)) {
        goto error;
    }

    cx_html_gen_t scopeData = *data;
    scopeData.path = folderPath;

    return cx_scopeWalk(o, gen_folder, &scopeData);
error:
    return 0;
}


/*
 * Prints the resulting json into a "data.json" file.
 */
static int gen_json(cx_object o, void *userData) {
    cx_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, TRUE, TRUE, FALSE};
    cx_html_gen_t *htmlData = userData;
    char folderPath[PATH_MAX];
    char filepath[PATH_MAX];
    struct cx_serializer_s serializer;
    FILE *file;
    cx_id fullname;

    if (sprintf(folderPath, "%s/%s", htmlData->path, cx_nameof(o)) < 0) {
        goto error;
    }
    if (sprintf(filepath, "%s/data.js", folderPath) < 0) {
        goto error;
    }

    serializer = cx_json_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);
    cx_serialize(&serializer, o, &jsonData);

    cx_fullname(o, fullname);

    if ((file = fopen(filepath, "w")) == NULL) {
        goto error;
    }
    if (fprintf(file, "objects[\"%s\"] = %s;", fullname, jsonData.buffer) < 0) {
        goto error;
    }
    if (fflush(file)) {
        goto error;
    }
    if (fclose(file)) {
        goto error;
    }

    cx_html_gen_t scopeData = *htmlData;
    scopeData.path = folderPath;

    return cx_scopeWalk(o, gen_json, &scopeData);
error:
    return 0;
}

static int printIncludeScopeItem(cx_object o, void *userData) {
    FILE *file = userData;
    if (fprintf(file, "<script src=\"./%s/data.js\"></script>", cx_nameof(o)) < 0) {
        goto error;
    }
    return 1;
error:
    return 0;
}


/*
 * Assumes that the file is already opened.
 * Returns 0 on success, -1 otherwise.
 */
static int printHtml(cx_html_gen_t *data, cx_object o, FILE* file) {
    unsigned int level;
    cx_id fullname;

    #define _printHtml(text) if (fprintf(file, text) < 0) goto error;
    
    /* http://www.w3.org/TR/html5/syntax.html#writing */
    _printHtml("<!DOCTYPE html>\n");
    _printHtml("<html>\n");
    _printHtml("<head>");
    _printHtml("<meta charset=\"utf-8\">");

    /* jQuery */
    _printHtml("<script src=\"");
    for (level = 0; level < data->level; level++) {
        _printHtml("../");
    }
    _printHtml("jquery-1.11.2.min.js\"></script>");

    /* Parsing script */
    _printHtml("<script src=\"");
    for (level = 0; level < data->level; level++) {
        _printHtml("../");
    }
    _printHtml("objectparse.js\"></script>");

    /* This object */
    _printHtml("<script src=\"./data.js\"></script>");

    /* Parent object */
    if (data->level > 1) {
        _printHtml("<script src=\"../data.js\"></script>");
    }

    /* Child objects */
    if (!cx_scopeWalk(o, printIncludeScopeItem, file)) {
        cx_error("Error traversing scope children to include their \"data.js\"");
        goto error;
    }

    if (fprintf(file, "<script>rootName = \"%s\";</script>",
                data->rootFullname) < 0) {
        goto error;
    }

    /* This object name */
    cx_fullname(o, fullname);
    if (fprintf(file, "<script>thisName = \"%s\";</script>", fullname) < 0) {
        goto error;
    }

    /* CSS */
    _printHtml("<link href=\"../");
    for (level = 1; level < data->level; level++) {
        _printHtml("../");
    }
    _printHtml("object.css\" rel=\"stylesheet\">");

    _printHtml("</head>");
    _printHtml("<body><main></main></body>");
    _printHtml("</html>");
    
    #undef _printHtml
    
    return 0;
error:
    return -1;
}

static int gen_html(cx_object o, void *userData) {
    static cx_id rootFullname = "";
    cx_html_gen_t *htmlData = userData;
    char folderPath[PATH_MAX];
    char filepath[PATH_MAX];
    FILE *file;

    if (sprintf(folderPath, "%s/%s", htmlData->path, cx_nameof(o)) < 0) {
        goto error;
    }
    if (sprintf(filepath, "%s/index.html", folderPath) < 0) {
        goto error;
    }

    if ((file = fopen(filepath, "w")) == NULL) {
        goto error;
    }
    
    if (htmlData->level == 1) {
        cx_fullname(o, rootFullname);
        htmlData->rootFullname = rootFullname;
    }

    if (printHtml(htmlData, o, file)) {
        goto error_closeFile;
    }

    if (fflush(file)) {
        goto error_closeFile;
    }
    
    fclose(file);

    cx_html_gen_t childHtmlData = {folderPath, htmlData->level + 1, rootFullname};

    return cx_scopeWalk(o, gen_html, &childHtmlData);

error_closeFile:
    fclose(file);
error:
    return 0;
}


static cx_int16 copyJQuery(const char *path) {
    char sourcePath[PATH_MAX];
    char destinationPath[PATH_MAX];
    char *cortexHome = getenv("CORTEX_HOME");
    char parserFilename[] = "jquery-1.11.2.min.js";
    sprintf(sourcePath, "%s/generator/html/%s", cortexHome, parserFilename);
    sprintf(destinationPath, "%s/%s", path, parserFilename);
    if (cx_cp(sourcePath, destinationPath)) {
        goto error;
    }
    return 0;
error:
    return -1;
}


static cx_int16 copyJsonParser(const char *path) {
    char sourcePath[PATH_MAX];
    char destinationPath[PATH_MAX];
    char *cortexHome = getenv("CORTEX_HOME");
    char parserFilename[] = "objectparse.js";
    sprintf(sourcePath, "%s/generator/html/%s", cortexHome, parserFilename);
    sprintf(destinationPath, "%s/%s", path, parserFilename);
    if (cx_cp(sourcePath, destinationPath)) {
        goto error;
    }
    return 0;
error:
    return -1;
}


static cx_int16 copyStyleSheet(const char* path) {
    char sourcePath[PATH_MAX];
    char destinationPath[PATH_MAX];
    char *cortexHome = getenv("CORTEX_HOME");
    char stylesheetFilename[] = "object.css";
    sprintf(sourcePath, "%s/generator/html/%s", cortexHome, stylesheetFilename);
    sprintf(destinationPath, "%s/%s", path, stylesheetFilename);
    if (cx_cp(sourcePath, destinationPath)) {
        goto error;
    }
    return 0;
error:
    return -1;
}


cx_int16 cortex_genMain(cx_generator g) {
    char filepath[PATH_MAX] = "./doc";

    cx_html_gen_t data = {filepath, 1, ""};
    int success;
    
    if (!(success = g_walkNoScope(g, gen_folder, &data))) {
        cx_error("Error creating folders.");
    }

    if (success && !(success = !copyJQuery(data.path))) {
        cx_error("Cannot copy \"jQuery\".");
    }

    if (success && !(success = !copyJsonParser(data.path))) {
        cx_error("Cannot copy \"objectparse.js\".");
    }

    if (success && !(success = !copyStyleSheet(data.path))) {
        cx_error("Cannot copy \"object.css\".");
    }
    
    if (success && !(success = g_walkNoScope(g, gen_json, &data))) {
        cx_error("Error creating js files.");
    }
    
    if (success && !(success = g_walkNoScope(g, gen_html, &data))) {
        cx_error("Error creating html files.");
    }

    return 0;
}
