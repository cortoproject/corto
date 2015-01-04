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
static int html_folderWalk(cx_object o, void *userData) {
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

    return cx_scopeWalk(o, html_folderWalk, &scopeData);
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
    char folderPath[PATH_MAX];
    char filepath[PATH_MAX];
    g_file file;
    cx_id fullname;

    htmlData = userData;

    if (sprintf(folderPath, "%s/%s", htmlData->path, cx_nameof(o)) < 0) {
        goto error;
    }
    if (sprintf(filepath, "%s/data.js", folderPath) < 0) {
        goto error;
    }

    serializer = cx_json_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);
    cx_serialize(&serializer, o, &jsonData);
    
    file = g_fileOpen(htmlData->generator, filepath);
    cx_fullname(o, fullname);
    g_fileWrite(file, "objects[\"%s\"] = %s;", fullname, jsonData.buffer);

    cx_html_gen_t scopeData = *htmlData;
    scopeData.path = folderPath;

    return cx_scopeWalk(o, html_jsonWalk, &scopeData);
error:
    return 0;
}

static int html_printScopeItemScriptWalk(cx_object o, void *userData) {
    g_file file = userData;
    g_fileWrite(file, "<script src=\"./%s/data.js\"></script>", cx_nameof(o));
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
    g_fileWrite(file, "</html>");

    return 0;
error:
    return -1;
}

static int html_HtmlWalk(cx_object o, void *userData) {
    static cx_id rootFullname = "";
    cx_html_gen_t *htmlData = userData;
    char folderPath[PATH_MAX];
    char filepath[PATH_MAX];
    g_file file;

    if (sprintf(folderPath, "%s/%s", htmlData->path, cx_nameof(o)) < 0) {
        goto error;
    }
    if (sprintf(filepath, "%s/index.html", folderPath) < 0) {
        goto error;
    }

    file = g_fileOpen(htmlData->generator, filepath);
    
    if (htmlData->level == 1) {
        cx_fullname(o, rootFullname);
        htmlData->rootFullname = rootFullname;
    }

    if (html_printHtml(htmlData, o, file)) {
        goto error;
    }

    cx_html_gen_t childHtmlData = {folderPath, htmlData->level + 1,
        rootFullname, htmlData->generator};

    return cx_scopeWalk(o, html_HtmlWalk, &childHtmlData);

error:
    return 0;
}


static cx_int16 html_copyJQueryFile(const char *path) {
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


static cx_int16 html_copyJsonParserFile(const char *path) {
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


static cx_int16 html_copyStyleSheetFile(const char* path) {
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
