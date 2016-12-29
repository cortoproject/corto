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

#include "corto/ll.h"
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_file_s* corto_file;

CORTO_EXPORT char* corto_fileLoad(const char* file);
CORTO_EXPORT corto_file corto_fileOpen(const char* file);
CORTO_EXPORT corto_file corto_fileAppend(const char* file);
CORTO_EXPORT corto_file corto_fileRead(const char* file);

CORTO_EXPORT FILE* corto_fileGet(corto_file file);
CORTO_EXPORT void corto_fileClose(corto_file);
CORTO_EXPORT char* corto_fileSearch(const char* file, corto_ll locations);
CORTO_EXPORT int corto_fileTest(const char* filefmt, ...);

CORTO_EXPORT unsigned int corto_fileSize(corto_file);
CORTO_EXPORT unsigned int corto_fileTell(corto_file);
CORTO_EXPORT corto_bool corto_fileEof(corto_file);

CORTO_EXPORT char* corto_fileReadLine(corto_file file, char* buf, unsigned int length);

CORTO_EXPORT char* corto_fileExtension(char* file, char* buffer);
CORTO_EXPORT char* corto_filePath(char* file, char* buffer);

#ifdef __cplusplus
}
#endif

#endif /* C_FILE_H_ */
