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

#include "db_ll.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct db_file_s* db_file;

char* db_fileLoad(const char* file);

db_file db_fileOpen(const char* file);
FILE* db_fileGet(db_file file);
void db_fileClose(db_file);
int db_fileTest(const char* file);
char* db_fileSearch(const char* file, db_ll locations);

unsigned int db_fileSize(db_file);
unsigned int db_fileTell(db_file);

char* db_fileReadLine(db_file file, char* buf, unsigned int length);

#ifdef __cplusplus
}
#endif

#endif /* C_FILE_H_ */
