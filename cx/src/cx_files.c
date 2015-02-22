
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
    
    cx_error("(%s): %s", errorrepr, msg);
}

int cx_fileTest(const char* file) {
    FILE* exists = NULL;

    if (file) {
        exists = fopen(file, "rb");
        if (exists) {
            fclose(exists);
        }
    }

    return (exists != 0);
}

int cx_touch(const char *file) {
    FILE* touch = NULL;

    if (file) {
        touch = fopen(file, "ab");
        if (touch) {
            fclose(touch);
        }
    }

    return touch ? 0 : -1;    
}

int cx_chdir(const char *name) {
    return chdir(name);
}

int cx_mkdir(const char *name) {
    int _errno;
    char msg[PATH_MAX];

    if (mkdir(name, 0700)) {
        _errno = errno;

        /* If error is ENOENT an element in the prefix of the name 
         * doesn't exist. Recursively create pathname, and retry. */
        if (errno == ENOENT) {
            /* Allocate so as to not run out of stackspace in recursive call */
            char *prefix = cx_strdup(name);
            char *ptr = &prefix[strlen(prefix)-1], ch;
            while ((ch = *ptr) && (ptr >= prefix)) {
                if (ch == '/') {
                    *ptr = '\0';
                    break;
                }
                ptr--;
            }
            if (ch == '/') {
                if (!cx_mkdir(prefix)) {
                    /* Retry current directory */
                    mkdir(name, 0700);
                } else {
                    goto error;
                }
            } else {
                goto error; /* If no prefix is found, report error */
            }
            cx_dealloc(prefix);
        }

        /* Post condition for function is that directory exists so don't
         * report an error if it already did. */
        if (errno != EEXIST) {
            goto error;
        }
    }

    return 0;
error:
    sprintf(msg, "could not create directory '%s'", name);
    printError(_errno, msg);
    return -1;
}

int cx_cp(const char *sourcePath, const char *destinationPath) {
    int _errno = 0;
    char msg[PATH_MAX];
    FILE *destinationFile;
    FILE *sourceFile;

    if (!(sourceFile = fopen(sourcePath, "rb"))) {
        _errno = errno;
        sprintf(msg, "could not open source file %s", sourcePath);
        goto error;
    }
    
    if (!(destinationFile = fopen(destinationPath, "wb"))) {
        _errno = errno;
        sprintf(msg, "could not open destination file %s", sourcePath);
        fclose(sourceFile);
        goto error;
    }

    /* "no real standard portability"
     * http://www.cplusplus.com/reference/cstdio/fseek/ */
    if (fseek(sourceFile, 0, SEEK_END)) {
        _errno = errno;
        sprintf(msg, "could not traverse source file %s", sourcePath);
        goto error_CloseFiles;
    }
    
    long fileSizeResult;
    size_t fileSize;
    fileSizeResult = ftell(sourceFile);
    if (fileSizeResult == -1) {
        sprintf(msg, "could not obtain filesize from file %s", sourcePath);
        goto error_CloseFiles;
    }
    /* Now we can be sure that fileSizeResult doesn't contain a 
     * negative value */
    fileSize = fileSizeResult;

    rewind(sourceFile);

    char *buffer = cx_malloc(fileSize);
    if (!buffer) {
        _errno = 0;
        sprintf(msg, "cannot allocate buffer for copying files");
        goto error_CloseFiles;
    }

    if (fread(buffer, 1, fileSize, sourceFile) != fileSize) {
        _errno = 0;
        sprintf(msg, "could not read the file %s", sourcePath);
        goto error_CloseFiles_FreeBuffer;
    }
    
    if (fwrite(buffer, 1, fileSize, destinationFile) != fileSize) {
        _errno = 0;
        sprintf(msg, "could not write to the file %s", destinationPath);
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
