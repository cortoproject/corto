/*
 * cx_file.c
 *
 *  Created on: Feb 10, 2011
 *      Author: sander
 */

#include "cx_file.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "cx_ll.h"

/* Load all contents from file, close file afterwards, return contents */
char* cx_fileLoad(const char* filename) {
    FILE* file;
    char* content;
    unsigned int size;

    /* Open file for reading */
    file = fopen(filename, "r");
    if (!file) {
        return 0;
    }

    /* Determine file size */
    fseek (file, 0 , SEEK_END);
    size = ftell (file);
    rewind(file);

    /* Load contents in memory */
    content = malloc (size * sizeof(char) + 1);
    if (fread(content, 1, size, file) != size) {
        content = 0;
    } else {
        content[size] = '\0';
    }

    fclose(file);

    return content;
}

/* Open file */
cx_file cx_fileOpen(const char* file) {

    if (!strcmp(file, "<<")) {
        return (cx_file)stdin;
    } else if (!strcmp(file, ">>")) {
        return (cx_file)stdout;
    } else {
        return (cx_file)fopen(file, "w");
    }
}

/* Close file */
void cx_fileClose(cx_file file) {
    if (file) {
        fclose((FILE*)file);
    }
}

/* Get file - a noop in the current implementation */
FILE* cx_fileGet(cx_file file) {
    return (FILE*)file;
}

/* Test if file exists */
int cx_fileTest(const char* file) {
    cx_file exists;

    exists = 0;

    if (file) {
        exists = (cx_file)fopen(file, "r");
        cx_fileClose(exists);
    }

    return (exists != 0);
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

    if (cx_fileTest(filename)) {
        userData->result = filename;
        return 0;
    }

    return 1;
}

/* Search file in paths */
char* cx_fileSearch(const char* file, cx_ll locations) {
    fileSearchWalk_t walkData;

    walkData.file = file;
    walkData.result = 0;

    cx_llWalk(locations, (cx_walkAction)fileSearchWalk, &walkData);

    return walkData.result;
}

/* Get file size */
unsigned int cx_fileSize(cx_file file) {
    unsigned int size;

    /* Determine file size */
    fseek ((FILE*)file, 0 , SEEK_END);
    size = ftell ((FILE*)file);
    rewind((FILE*)file);

    return size;
}

/* Get file ptr */
unsigned int cx_fileTell(cx_file file) {
    return ftell((FILE*)file);
}

/* Read line from file */
char* cx_fileReadLine(cx_file file, char* buf, unsigned int length) {
    char c;
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


