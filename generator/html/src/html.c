
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

    if (mkdir(folderPath, S_IRWXU|S_IRWXG|S_IRWXO)) {
        int errno2 = errno;
        fprintf(stderr, "Error: cannot create %s\n", folderPath);
        switch(errno2) {
            case EACCES: fprintf(stderr, "Error: EACCES\n"); break;
            case EEXIST: fprintf(stderr, "Error: EEXIST\n"); break;
            case ELOOP: fprintf(stderr, "Error: ELOOP\n"); break;
            case EMLINK: fprintf(stderr, "Error: EMLINK\n"); break;
            case ENAMETOOLONG: fprintf(stderr, "Error: ENAMETOOLONG\n"); break;
            case ENOENT: fprintf(stderr, "Error: ENOENT\n"); break;
            case ENOSPC: fprintf(stderr, "Error: ENOSPC\n"); break;
            case ENOTDIR: fprintf(stderr, "Error: ENOTDIR\n"); break;
            case EROFS: fprintf(stderr, "Error: EROFS\n"); break;
            default: fprintf(stderr, "Unknown error: %d\n", errno2); break;
        }
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
    char filePath[PATH_MAX];
    struct db_serializer_s serializer;
    FILE *file;

    if (sprintf(folderPath, "%s/%s", htmlData->path, db_nameof(o)) < 0) {
        // printf("trying to create json in %s\n", folderPath);
        goto error;
    }
    if (sprintf(filePath, "%s/data.js", folderPath) < 0) {
        // printf("trying to write json %s\n", filePath);
        goto error;
    }

    serializer = db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);
    db_serialize(&serializer, o, &jsonData);


    if ((file = fopen(filePath, "w")) == NULL) {
        goto error;
    }
    if (fprintf(file, "%s", jsonData.buffer) < 0) {
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
    db_html_gen_t *data = userData;
    char htmlPath[PATH_MAX];
    if (sprintf(htmlPath, "%s/%s", data->path, "index.html") < 0) {
        goto error;
    }
    db_nameof(o);
    // todo recursive
error:
    return 0;
}


db_int16 hyve_genMain(db_generator g) {
    char path[PATH_MAX] = ".";
    db_html_gen_t data = {path};
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
