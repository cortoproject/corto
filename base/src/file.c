/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <include/base.h>

/* Load all contents from file, close file afterwards, return contents */
char* corto_fileLoad(const char* filename) {
    FILE* file;
    char* content;
    int size;

    /* Open file for reading */
    file = fopen(filename, "r");
    if (!file) {
        corto_seterr("%s (%s)", strerror(errno), filename);
        goto error;
    }

    /* Determine file size */
    fseek (file, 0 , SEEK_END);
    size = ftell (file);
    if (size == -1) {
        goto error;
    }
    rewind(file);

    /* Load contents in memory */
    content = malloc (size + 1);
    if (fread(content, 1, size, file) != (unsigned int)size) {
        corto_dealloc(content);
        content = NULL;
    } else {
        content[size] = '\0';
    }

    fclose(file);

    return content;
error:
    return NULL;
}

/* Open file */
corto_file corto_fileOpen(const char* file) {

    if (!strcmp(file, "<<")) {
        return (corto_file)stdin;
    } else if (!strcmp(file, ">>")) {
        return (corto_file)stdout;
    } else {
        return (corto_file)fopen(file, "w");
    }
}

/* Open file for appending */
corto_file corto_fileAppend(const char* file) {

    if (!strcmp(file, "<<")) {
        return (corto_file)stdin;
    } else if (!strcmp(file, ">>")) {
        return (corto_file)stdout;
    } else {
        return (corto_file)fopen(file, "a");
    }
}

/* Open file for reading */
corto_file corto_fileRead(const char* file) {

    if (!strcmp(file, "<<")) {
        return (corto_file)stdin;
    } else if (!strcmp(file, ">>")) {
        return (corto_file)stdout;
    } else {
        return (corto_file)fopen(file, "r");
    }
}

/* Close file */
void corto_fileClose(corto_file file) {
    if (file) {
        fclose((FILE*)file);
    }
}

/* Get file - a noop in the current implementation */
FILE* corto_fileGet(corto_file file) {
    return (FILE*)file;
}

typedef struct fileSearchWalk_t {
    const char* file;
    char* result;
}fileSearchWalk_t;

/* Search file */
int fileSearchWalk(const char* location, fileSearchWalk_t* userData) {
    char* filename;

    filename = malloc(strlen(userData->file) + strlen(location) + 1 + 1);

    sprintf(filename, "%s/%s", location, userData->file);

    if (corto_fileTest(filename)) {
        userData->result = filename;
        return 0;
    }

    corto_dealloc(filename);

    return 1;
}

/* Search file in paths */
char* corto_fileSearch(const char* file, corto_ll locations) {
    fileSearchWalk_t walkData;

    walkData.file = file;
    walkData.result = 0;

    corto_ll_walk(locations, (corto_elementWalk_cb)fileSearchWalk, &walkData);

    return walkData.result;
}

int corto_fileTest(const char* filefmt, ...) {
    FILE* exists = NULL;
    va_list arglist;

    va_start(arglist, filefmt);
    char *file = corto_venvparse(filefmt, arglist);
    va_end(arglist);

    if (file) {
        errno = 0;
        exists = fopen(file, "rb");
        if (exists) {
            fclose(exists);
        } else if ((errno != ENOENT) && (errno != ENOTDIR)) {
            corto_seterr("%s: %s", file, strerror(errno));
        }
    }

    corto_dealloc(file);

    return (exists != 0);
}

/* Get file size */
unsigned int corto_fileSize(corto_file file) {
    unsigned int size;

    /* Determine file size */
    fseek ((FILE*)file, 0 , SEEK_END);
    size = ftell ((FILE*)file);
    rewind((FILE*)file);

    return size;
}

/* Get file ptr */
unsigned int corto_fileTell(corto_file file) {
    return ftell((FILE*)file);
}

/* Read line from file */
char* corto_fileReadLine(corto_file file, char* buf, unsigned int length) {
    int c;
    char* ptr;

    if (!file) {
        return 0;
    }

    c = EOF;
    ptr = buf;

    while (!feof((FILE*)file)) {

        c = fgetc((FILE*)file);
        if ((c == '\n') || (c == EOF)) {
            break;
        }

        *ptr = c;
        ptr++;
        if ((unsigned int)(ptr - buf) == (length - 1)) {
            break;
        }
    }

    *ptr = '\0';

    return (c == EOF) ? 0 : buf;
}

/* Get file extension */
char* corto_fileExtension(char* file, char* buffer) {
    char *ptr, *bptr;
    char ch;

    bptr = buffer;

    ptr = file + strlen(file);
    while (ptr >= file) {
        if (*ptr == '.') break;
        ptr--;
    }
    if (ptr >= file) {
        ptr++;
        while ((ch = *ptr) && ((bptr - buffer) < CORTO_MAX_FILE_EXTENSION)) {
            *bptr = ch;
            ptr++;
            bptr++;
        }
    }
    if ((bptr - buffer) >= CORTO_MAX_FILE_EXTENSION) {
        return NULL;
    } else {
        *bptr = '\0';
        return buffer;
    }
}

/* Get file base */
char* corto_fileBase(char* file, char* buffer) {
    strcpy(buffer, file);
    char *ch = strrchr(buffer, '.');
    if (ch) {
        *ch = '\0';
    }
    return buffer;
}

/* Get file path */
char* corto_filePath(char* file, char* buffer) {
    int32_t i;

    strcpy(buffer, file);
    i = strlen(buffer);
    while (i >= 0) {
        if ((buffer[i] == '/') || (buffer[i] == '\\')) {
            buffer[i] = '\0';
            break;
        }
        i--;
    }

    return (i != -1) ? buffer : NULL;
}

bool corto_fileEof(corto_file file) {
    return feof((FILE*)file);
}
