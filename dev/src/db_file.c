/*
 * db_file.c
 *
 *  Created on: Feb 10, 2011
 *      Author: sander
 */

#include "db_file.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "db_ll.h"

/* Load all contents from file, close file afterwards, return contents */
char* db_fileLoad(const char* filename) {
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
db_file db_fileOpen(const char* file) {

	if (!strcmp(file, "<<")) {
		return (db_file)stdin;
	} else if (!strcmp(file, ">>")) {
		return (db_file)stdout;
	} else {
		return (db_file)fopen(file, "w");
	}
}

/* Close file */
void db_fileClose(db_file file) {
	if (file) {
		fclose((FILE*)file);
	}
}

/* Get file - a noop in the current implementation */
FILE* db_fileGet(db_file file) {
	return (FILE*)file;
}

/* Test if file exists */
int db_fileTest(const char* file) {
	db_file exists;

	exists = 0;

	if (file) {
		exists = db_fileOpen(file);
		db_fileClose(exists);
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

	if (db_fileTest(filename)) {
		userData->result = filename;
		return 0;
	}

	return 1;
}

/* Search file in paths */
char* db_fileSearch(const char* file, db_ll locations) {
	fileSearchWalk_t walkData;

	walkData.file = file;
	walkData.result = 0;

	db_llWalk(locations, (db_walkAction)fileSearchWalk, &walkData);

	return walkData.result;
}

/* Get file size */
unsigned int db_fileSize(db_file file) {
	unsigned int size;

	/* Determine file size */
	fseek ((FILE*)file, 0 , SEEK_END);
	size = ftell ((FILE*)file);
	rewind((FILE*)file);

	return size;
}

/* Get file ptr */
unsigned int db_fileTell(db_file file) {
	return ftell((FILE*)file);
}

/* Read line from file */
char* db_fileReadLine(db_file file, char* buf, unsigned int length) {
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


