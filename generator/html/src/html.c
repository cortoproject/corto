
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
        fprintf(stderr, "Error: cannot create path for object \"%s\" in path:\"%s\"",
            db_nameof(o), data->path);
        goto error;
    }

    if (mkdir(folderPath, S_IRWXU)) {
        int errno2 = errno;
        fprintf(stderr, "Error: cannot create %s, error code: ", folderPath);
        switch(errno2) {
            case EACCES: fprintf(stderr, "EACCES"); break;
            case EEXIST: fprintf(stderr, "EEXIST"); break;
            case ELOOP: fprintf(stderr, "ELOOP"); break;
            case EMLINK: fprintf(stderr, "EMLINK"); break;
            case ENAMETOOLONG: fprintf(stderr, "ENAMETOOLONG"); break;
            case ENOENT: fprintf(stderr, "ENOENT"); break;
            case ENOSPC: fprintf(stderr, "ENOSPC"); break;
            case ENOTDIR: fprintf(stderr, "ENOTDIR"); break;
            case EROFS: fprintf(stderr, "EROFS"); break;
            default: fprintf(stderr, "%d (unknown)", errno2); break;
        }
        fprintf(stderr, "\n");
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
    db_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, TRUE, TRUE, FALSE};
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
    if (fprintf(file, "thisObject = %s", jsonData.buffer) < 0) {
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


static int gen_html(db_object o, void* userData) {
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
    if (fprintf(file,
        "<!DOCTYPE html>"
        "<html>"
            "<head>"
                "<script src=\"./data.js\"></script>"
            "</head>"
            "<body>"
                "<main></main>"
            "</body>"
        "</html>"
        ) < 0) {
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

    return db_scopeWalk(o, gen_html, &scopeData);
error:
    return 0;
}


db_int16 copyJsonParser(const char* path) {
    
    // create db_files.h > db_copy

    return 0;
error:
    return -1;
}

db_int16 hyve_genMain(db_generator g) {
    char filepath[PATH_MAX] = "./doc";


    db_html_gen_t data = {path, 1};
    int result;
    
    if (!(result = g_walkNoScope(g, gen_folder, &data))) {
        fprintf(stderr, "Error creating folders\n");
    }
    
    if (!(result && (result = g_walkNoScope(g, gen_json, &data)))) {
        fprintf(stderr, "Error creating js files\n");
    }
    
    if (!(result && (result = g_walkNoScope(g, gen_html, &data)))) {
        fprintf(stderr, "Error creating html files\n");
    }
    return 0;
}
