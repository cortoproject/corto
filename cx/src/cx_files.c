
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#if __linux__
#include <linux/limits.h>
#else
#include <limits.h>
#endif

#include "cx_files.h"
#include "cx_mem.h"

/*
 * Receives:
 * - the error code
 * - an initial message
 * The name for the error code will be appended.
 */
static void printError(int e, const char *msg) {
    char errorrepr[sizeof("ENAMETOOLONG")];
    switch (e) {
        case EACCES: sprintf(errorrepr, "EACCES"); break;
        case EEXIST: sprintf(errorrepr, "EEXIST"); break;
        case ELOOP: sprintf(errorrepr, "ELOOP"); break;
        case EMLINK: sprintf(errorrepr, "EMLINK"); break;
        case ENAMETOOLONG: sprintf(errorrepr, "ENAMETOOLONG"); break;
        case ENOENT: sprintf(errorrepr, "ENOENT"); break;
        case ENOSPC: sprintf(errorrepr, "ENOSPC"); break;
        case ENOTDIR: sprintf(errorrepr, "ENOTDIR"); break;
        case EROFS: sprintf(errorrepr, "EROFS"); break;
        default: sprintf(errorrepr, "unknown code"); break;
    }
    
    cx_error("(%s): %s.", errorrepr, msg);
}

int cx_mkdir(const char *name) {
    struct stat st = {0};
    int _errno;
    char msg[PATH_MAX];

    if (stat(name, &st) == -1) {
        if (mkdir(name, 0700)) {
            _errno = errno;
            goto error;
        }
    }

    return 0;
error:
    sprintf(msg, "Could not create directory %s", name);
    printError(_errno, msg);
    return -1;
}

int cx_cp(const char *sourcePath, const char *destinationPath) {
    int _errno;
    char msg[PATH_MAX];
    FILE *destinationFile;
    FILE *sourceFile;

    if (!(sourceFile = fopen(sourcePath, "rb"))) {
        _errno = errno;
        sprintf(msg, "Could not open source file %s", sourcePath);
        goto error;
    }
    
    if (!(destinationFile = fopen(destinationPath, "wb"))) {
        _errno = errno;
        sprintf(msg, "Could not open destination file %s", sourcePath);
        fclose(sourceFile);
        goto error;
    }

    // "no real standard portability"
    // http://www.cplusplus.com/reference/cstdio/fseek/
    if (fseek(sourceFile, 0, SEEK_END)) {
        _errno = errno;
        sprintf(msg, "Could not traverse source file %s", sourcePath);
        goto error_CloseFiles;
    }
    
    size_t fileSize;
    fileSize = (size_t)ftell(sourceFile);
    rewind(sourceFile);

    char *buffer = cx_malloc(fileSize);
    if (!buffer) {
        _errno = 0;
        sprintf(msg, "Cannot allocate buffer for copying files");
        goto error_CloseFiles;
    }

    if (fread(buffer, 1, fileSize, sourceFile) != fileSize) {
        _errno = 0;
        sprintf(msg, "Could not read the file %s", sourcePath);
        goto error_CloseFiles_FreeBuffer;
    }
    
    if (fwrite(buffer, 1, fileSize, destinationFile) != fileSize) {
        _errno = 0;
        sprintf(msg, "Could not write to the file %s", destinationPath);
        goto error_CloseFiles_FreeBuffer;
    }

    cx_dealloc(buffer);
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;

error_CloseFiles_FreeBuffer:
    free(buffer);
error_CloseFiles:
    fclose(sourceFile);
    fclose(destinationFile);
error:
    printError(_errno, msg);
    return -1;
}