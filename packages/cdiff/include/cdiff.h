
#ifndef CORTO_CDIFF_H
#define CORTO_CDIFF_H

#include <corto/corto.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum cdiff_elemKind {
    CDIFF_TEXT,
    CDIFF_FUNCTION,
    CDIFF_FUNCTION_LEGACY
} cdiff_elemKind;

typedef struct cdiff_elem {
    cdiff_elemKind kind;
    char *id;
    char *header;
    char *body;
} cdiff_elem;

typedef struct cdiff_file_s *cdiff_file;
struct cdiff_file_s {
    char *name;
    bool isNew;
    bool isChanged;
    corto_ll elements;
    corto_ll legacyElements;
    cdiff_elem *cur;
    int writeTo; /* 0 = nothing, 1 = header, 2 = body */
    corto_buffer writeBuffer;
    int indent;
    bool newLine; /* Is next write starting on new line */
} cdiff_file_s;

cdiff_file cdiff_file_open(char *file);

void cdiff_file_elemBegin(cdiff_file file, char *fmt, ...);
void cdiff_file_elemEnd(cdiff_file file);

void cdiff_file_headerBegin(cdiff_file file);
void cdiff_file_headerEnd(cdiff_file file);

int16_t cdiff_file_bodyBegin(cdiff_file file); /* return 1 if body exists */
void cdiff_file_bodyEnd(cdiff_file file);

void cdiff_file_write(
    cdiff_file file,
    char *fmt,
    ...);

void cdiff_file_writeBuffer(
    cdiff_file file,
    corto_buffer *buffer);

void cdiff_file_indent(cdiff_file file);
void cdiff_file_dedent(cdiff_file file);

int16_t cdiff_file_close(cdiff_file file);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_CDIFF_H */

