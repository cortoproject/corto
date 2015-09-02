/*
 * c_file.h
 *
 *  Created on: Feb 10, 2011
 *      Author: sander
 *
 *      Convenience functions for filehandling - more utility than abstraction.
 */

#ifndef C_FILE_H_
#define C_FILE_H_

#include "cx_files.h"
#include "cx_ll.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cx_file_s* cx_file;

char* cx_fileLoad(const char* file);
cx_file cx_fileOpen(const char* file);
cx_file cx_fileAppend(const char* file);
cx_file cx_fileRead(const char* file);

FILE* cx_fileGet(cx_file file);
void cx_fileClose(cx_file);
char* cx_fileSearch(const char* file, cx_ll locations);

unsigned int cx_fileSize(cx_file);
unsigned int cx_fileTell(cx_file);

char* cx_fileReadLine(cx_file file, char* buf, unsigned int length);

#ifdef __cplusplus
}
#endif

#endif /* C_FILE_H_ */
