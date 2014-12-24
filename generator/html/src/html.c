
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

#if __linux__
#include <linux/limits.h>
#else
#include <limits.h>
#endif

#include "db_files.h"
#include "db_generator.h"
#include "db_serializer.h"
#include "html.h"
#include "hyve.h"
#include "json.h"

/*
 * Create a folder for this object
 * Make an index.html file inside, contents are dependent on kind of object
 *     e.g. primitives are a plain value but classes include description
       of members
 * Make a data.json file inside
 * Call recursively for every object in this scope
 */
static int gen_folder(db_object o, void *userData) {
    db_html_gen_t *data = userData;
    char folderPath[PATH_MAX];

    if (sprintf(folderPath, "%s/%s", data->path, db_nameof(o)) < 0) {
        db_error("Cannot create path for object \"%s\" in path:\"%s\".",
            db_nameof(o), data->path);
        goto error;
    }

    if (db_mkdir(folderPath)) {
        goto error;
    }

    db_html_gen_t scopeData = *data;
    scopeData.path = folderPath;

    return db_scopeWalk(o, gen_folder, &scopeData);
error:
    return 0;
}


/*
 * Prints the resulting json into a "data.json" file.
 */
static int gen_json(db_object o, void *userData) {
    db_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, TRUE, TRUE, TRUE};
    db_html_gen_t *htmlData = userData;
    char folderPath[PATH_MAX];
    char filepath[PATH_MAX];
    struct db_serializer_s serializer;
    FILE *file;

    if (sprintf(folderPath, "%s/%s", htmlData->path, db_nameof(o)) < 0) {
        goto error;
    }
    if (sprintf(filepath, "%s/data.js", folderPath) < 0) {
        goto error;
    }

    serializer = db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);
    db_serialize(&serializer, o, &jsonData);


    if ((file = fopen(filepath, "w")) == NULL) {
        goto error;
    }
    if (fprintf(file, "var thisObject = %s", jsonData.buffer) < 0) {
        goto error;
    }
    if (fflush(file)) {
        goto error;
    }
    if (fclose(file)) {
        goto error;
    }

    db_html_gen_t scopeData = *htmlData;
    scopeData.path = folderPath;

    return db_scopeWalk(o, gen_json, &scopeData);
error:
    return 0;
}

/*
 * Assumes that the file is already opened.
 * Returns 0 on success, -1 otherwise.
 */
static int printHtml(db_html_gen_t *data, FILE* file) {
    unsigned int level;

    #define _printHtml(text) if (fprintf(file, text) < 0) goto error;
    
    /* http://www.w3.org/TR/html5/syntax.html#writing */
    _printHtml("<!DOCTYPE html>\n");
    _printHtml("<html>\n");
    _printHtml("<head>");
    _printHtml("<meta charset=\"utf-8\">");

    /* This object */
    _printHtml("<script src=\"./data.js\"></script>");

    /* Parsing script */
    _printHtml("<script src=\"../");
    for (level = 1; level < data->level; level++) {
        _printHtml("../");
    }
    _printHtml("objectparse.js\"></script>");

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

static int gen_html(db_object o, void *userData) {
    db_html_gen_t *htmlData = userData;
    char folderPath[PATH_MAX];
    char filepath[PATH_MAX];
    FILE *file;

    if (sprintf(folderPath, "%s/%s", htmlData->path, db_nameof(o)) < 0) {
        goto error;
    }
    if (sprintf(filepath, "%s/index.html", folderPath) < 0) {
        goto error;
    }

    if ((file = fopen(filepath, "w")) == NULL) {
        goto error;
    }
    
    if (printHtml(htmlData, file)) {
        goto error_closeFile;
    }

    if (fflush(file)) { // TODO maybe this is unncessary
        goto error_closeFile;
    }
    
    fclose(file);

    db_html_gen_t childHtmlData = {folderPath, htmlData->level + 1};

    return db_scopeWalk(o, gen_html, &childHtmlData);

error_closeFile:
    fclose(file);
error:
    return 0;
}


db_int16 copyJsonParser(const char* path) {
    char sourcePath[PATH_MAX];
    char destinationPath[PATH_MAX];
    char *hyveHome = getenv("HYVE_HOME");
    char parserFilename[] = "objectparse.js";
    sprintf(sourcePath, "%s/generator/html/%s", hyveHome, parserFilename);
    sprintf(destinationPath, "%s/%s", path, parserFilename);
    if (db_cp(sourcePath, destinationPath)) {
        goto error;
    }
    return 0;
error:
    return -1;
}

db_int16 copyStyleSheet(const char* path) {
    char sourcePath[PATH_MAX];
    char destinationPath[PATH_MAX];
    char *hyveHome = getenv("HYVE_HOME");
    char stylesheetFilename[] = "object.css";
    sprintf(sourcePath, "%s/generator/html/%s", hyveHome, stylesheetFilename);
    sprintf(destinationPath, "%s/%s", path, stylesheetFilename);
    if (db_cp(sourcePath, destinationPath)) {
        goto error;
    }
    return 0;
error:
    return -1;
}


db_int16 hyve_genMain(db_generator g) {
    char filepath[PATH_MAX] = "./doc";

    db_html_gen_t data = {filepath, 1};
    int success;
    
    if (!(success = g_walkNoScope(g, gen_folder, &data))) {
        db_error("Error creating folders.");
    }

    if (success && !(success = !copyJsonParser(data.path))) {
        db_error("Cannot copy \"objectparse.js\".");
    }

    if (success && !(success = !copyStyleSheet(data.path))) {
        db_error("Cannot copy \"object.css\".");
    }
    
    if (success && !(success = g_walkNoScope(g, gen_json, &data))) {
        db_error("Error creating js files.");
    }
    
    if (success && !(success = g_walkNoScope(g, gen_html, &data))) {
        db_error("Error creating html files.");
    }

    return 0;
}
