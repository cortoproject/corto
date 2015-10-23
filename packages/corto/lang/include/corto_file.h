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

#include "corto_files.h"
#include "corto_ll.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_file_s* corto_file;

char* corto_fileLoad(const char* file);
corto_file corto_fileOpen(const char* file);
corto_file corto_fileAppend(const char* file);
corto_file corto_fileRead(const char* file);

FILE* corto_fileGet(corto_file file);
void corto_fileClose(corto_file);
char* corto_fileSearch(const char* file, corto_ll locations);

unsigned int corto_fileSize(corto_file);
unsigned int corto_fileTell(corto_file);

char* corto_fileReadLine(corto_file file, char* buf, unsigned int length);

char* corto_fileExtension(char* file, char* buffer);

#ifdef __cplusplus
}
#endif

#endif /* C_FILE_H_ */
