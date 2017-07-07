
#include <corto/cdiff/cdiff.h>

/* Optimistically parse C / C++ sourcefiles, extract function headers & bodies
 * so they can be replaced by updated definitions & new definitions can be added
 * without losing original content. */ 

static void cdiff_addElem(
    corto_ll elements, 
    char *id, 
    char *header,
    char *body)
{
    cdiff_elem *elem = malloc (sizeof(cdiff_elem));

    if (id) {
        elem->kind = CDIFF_FUNCTION;
        elem->header = header;
        elem->body = body;
        elem->id = id;
    } else {
        elem->kind = CDIFF_TEXT;
        elem->id = NULL;
        elem->header = NULL;
        elem->body = body;
    }
    
    corto_ll_append(elements, elem);
}

static char* cdiff_skipMultiLineComment(char *src) {
    char *ptr, ch;
    for (ptr = src; (ch = *ptr); ptr ++) {
        if (ch == '*') {
            if (ptr[1] == '/') {
                ptr += 2;
                break;
            }
        }
    }

    return ptr;
}

static char* cdiff_skipLineComment(char *src) {
    char *ptr, ch;
    for (ptr = src; (ch = *ptr); ptr ++) {
        if (ch == '\n') {
            ptr ++;
            break;
        }
    }

    return ptr;
}

static char* cdiff_skipString(char *src) {
    char *ptr, ch;
    for (ptr = src; (ch = *ptr) && (ch != '"'); ptr ++) {
        if (ch == '\\') {
            ptr ++;
        }
    }

    return ptr;
}

static char* cdiff_next(char *src, char match) {
    char *ptr, ch;

    for (ptr = src; ptr && (ch = *ptr); ptr ++) {
        if (ch == match) {
            break;
        } else if (isspace(ch)) {
            /* Keep scanning */
        } else if (ch == '"') {
            ptr = cdiff_skipString(&ptr[1]);
        } else if (ch == '/') {
            /* Comment? */
            if (ptr[1] == '*') {
                ptr = cdiff_skipMultiLineComment(&ptr[2]);
            } else if (ptr[1] == '/') {
                ptr = cdiff_skipLineComment(&ptr[2]);
            }
        } else {
            break;
        }
    }

    return ptr;
}

static char* cdiff_scanId(char *src, corto_buffer *buffer, char** t_start) {
    char ch, *ptr = cdiff_next(src, 0);

    *t_start = NULL;

    /* Identifier found */
    if (isalpha(*ptr) || *ptr == '_') {
        *t_start = ptr;
    }

    /* Scan remainder of identifier */
    if (*t_start) {
        for (ptr ++; (ch = *ptr); ptr ++) {
            if (!isalpha(ch) && !isdigit(ch) && ch != '_' && ch != ':') {
                break;
            }
        }
    }

    /* Add scanned characters to buffer */
    corto_buffer_appendstrn(buffer, src, ptr - src);

    return ptr;
}

static char* cdiff_scanExpect(char *src, corto_buffer *buffer, char match, char** t_start) {
    char *ptr = cdiff_next(src, match);

    *t_start = NULL;

    /* Match found */
    if (match == *ptr) {
        *t_start = ptr;
        ptr ++;
    }

    /* Add scanned characters to buffer */
    corto_buffer_appendstrn(buffer, src, ptr - src);

    return ptr;
}

static char* cdiff_scanUntil(char *src, corto_buffer *buffer, char match, char** t_start) {
    char ch, *ptr;

    for (ptr = src; (ch = *ptr) && (ch != match); ptr = cdiff_next(ptr + 1, match));

    *t_start = NULL;

    /* Match found */
    if (match == ch) {
        *t_start = ptr;
        ptr ++;
    }

    /* Add scanned characters to buffer */
    corto_buffer_appendstrn(buffer, src, ptr - src);

    return ptr;
}

static char *cdiff_parseFunction(
    char *src, 
    char *id,
    corto_buffer *header, 
    corto_buffer *body) 
{
    char *t_start;

    /* Parse type identifier */
    char *ptr = cdiff_scanId(src, header, &t_start);
    if (!t_start) goto stop;

    /* Parse identifier */
    ptr = cdiff_scanId(ptr, header, &t_start);
    if (!t_start) goto stop;

    /* Copy identifier into buffer */
    if (t_start[0] == '_') t_start++; /* Support legacy files */
    strncpy(id, t_start, ptr - t_start);
    id[ptr - t_start] = '\0';

    /* Expect ( */
    ptr = cdiff_scanExpect(ptr, header, '(', &t_start);
    if (!t_start) goto stop;

    /* Scan for ) */
    ptr = cdiff_scanUntil(ptr, header, ')', &t_start);
    if (!t_start) goto stop;

    /* Scan for { */
    ptr = cdiff_scanExpect(ptr, header, '{', &t_start);
    if (!t_start) goto stop;

    /* Scan for } */
    ptr = cdiff_scanUntil(ptr, body, '}', &t_start);
    if (!t_start) goto stop;

    return ptr;
stop:
    id[0] = '\0';
    corto_buffer_reset(header);
    corto_buffer_reset(body);
    return src;
}

static char* cdiff_parseElem(
    char *src, 
    char *id, 
    corto_buffer *header, 
    corto_buffer *body) 
{
    char ch, *ptr = src;
    id[0] = '\0';

    if (isalpha(src[0])) {        
        /* Potential function */
        ptr = cdiff_parseFunction(src, id, header, body);

        /* It is possible that this was not a function. In that case, continue
         * parsing until hitting newline character */
    }

    /* Keep adding until newline is found */
    for (; (ch = *ptr) && (ch != '\n'); ptr++) {
        corto_buffer_appendstrn(body, &ch, 1);
    }
    if (ch) corto_buffer_appendstrn(body, &ch, 1);

    return ch ? ptr + 1 : ptr;
}

static corto_ll cdiff_parse(char *src) {
    corto_ll elements = corto_ll_new();
    corto_id id;
    char *ptr = src;

    corto_buffer header = CORTO_BUFFER_INIT, body = CORTO_BUFFER_INIT;
    id[0] = '\0';

    while ((ptr = cdiff_parseElem(ptr, id, &header, &body)) && *ptr) {
        char *h = corto_buffer_str(&header);
        char *b = corto_buffer_str(&body);
        cdiff_addElem(elements, id[0] ? strdup(id) : NULL, h, b);
    }

    char *h = corto_buffer_str(&header);
    char *b = corto_buffer_str(&body);
    cdiff_addElem(elements, id[0] ? strdup(id) : NULL, h, b);

    return elements;
}

/* Find existing parts in the code that must not be overwritten. */
static corto_ll cdiff_parseLegacy(char *code) {
    char *ptr = NULL;
    corto_ll result = corto_ll_new();

    ptr = code;

    while((ptr = strchr(ptr, '$'))) {
        cdiff_elemKind kind = CDIFF_TEXT;

        if (!memcmp(ptr, "$begin", 6)) {
            ptr += 6;
            kind = CDIFF_FUNCTION_LEGACY;
        } else if (!memcmp(ptr, "$header", 7)) {
            ptr += 7;
        } else {
            ptr ++;
            continue;
        }

        /* Find begin of identifier */
        if (*ptr == '(') {
            char *endptr;

            /* Find end of identifier */
            endptr = strstr(ptr, ") */");
            if (endptr) {
                corto_id identifier;

                /* Copy identifier string */
                *endptr = '\0';
                endptr += 3;

                if (strlen(ptr) >= sizeof(corto_id)) {
                    corto_seterr(
                        "%s: identifier of code-snippet exceeds %d characters", sizeof(corto_id));
                    goto error;
                }

                strcpy(identifier, ptr + 1);
                ptr = endptr + 1;

                /* Find $end */
                endptr = strstr(ptr, "$end");
                endptr -= 3; /* include comment begin token */

                if (endptr) {
                    cdiff_elem* el;
                    corto_string src;

                    if (kind != CDIFF_TEXT) {
                        endptr[0] = '}';
                        endptr[1] = '\n';
                        endptr[2] = '\0';
                        endptr += 3;
                    } else {
                        endptr[0] = '\n';
                        endptr[1] = '\0';
                        endptr += 2;
                    }
                    src = corto_strdup(ptr);

                    if(strstr(src, "$begin")) {
                        corto_seterr("code-snippet '%s' contains nested $begin (did you forget an $end?)",
                            identifier);
                        corto_dealloc(src);
                        goto error;
                    }

                    el = corto_alloc(sizeof(cdiff_elem));
                    el->kind = kind;
                    el->id = corto_strdup(identifier);
                    el->header = NULL;
                    el->body = src;
                    corto_ll_append(result, el);

                    ptr = endptr + 1;

                } else {
                    corto_warning("generator: missing $end after $begin(%s)", identifier);
                }
            } else {
                corto_warning("generator: missing ')' after $begin/$header");
            }
        } else {
            corto_warning("generator: missing '(' after $begin/$header");
        }
    }

    return result;
error:
    if (result) {
        corto_ll_free(result);
    }

    printf("error!\n");
    return NULL;
}

cdiff_file cdiff_file_open (char* filename) {
    cdiff_file result = malloc(sizeof(struct cdiff_file_s));

    /* Store current working directory in case the application using this
     * function changes the cwd before closing the file. */
    corto_asprintf(&result->name, "%s/%s", corto_cwd(), filename);

    result->elements = NULL;
    result->legacyElements = NULL;
    result->isChanged = false;
    result->writeBuffer = CORTO_BUFFER_INIT;
    result->writeTo = 0;
    result->indent = 0;
    result->newLine = true;
    result->cur = NULL;

    char *source = corto_fileLoad(result->name);
    if (source) {
        result->isNew = false;

        /* Check for legacy */
        if (strstr(source, "$CORTO_GENERATED")) {
            if (strstr(source, "$begin") || strstr(source, "$header")) {
                result->legacyElements = cdiff_parseLegacy(source);
                if (!result->legacyElements) {
                    goto error;
                }

                result->isChanged = true;
                result->isNew = true;
            }
        }

        /* Parse file (only when not parsing legacy file) */
        if (!result->legacyElements) {
            result->elements = cdiff_parse(source);
            if (!result->elements) {
                goto error;
            }
        }

        free(source);

    } else {
        corto_lasterr(); /* silence warning */
        result->isNew = true;
    }

    return result;
error:
    if (source) {
        free(source);
    }
    return NULL;
}

static bool cdiff_file_writeElement(FILE *f, char *element, bool prevIsNl) {
    /* Filter out newlines */
    if (!prevIsNl || element[0] != '\n' || element[1] != '\0') {
        fwrite(element, strlen(element), 1, f);
        if (element[0] == '\n' && element[1] == '\0') {
            prevIsNl = true;
        }
    }

    char last = element[strlen(element) - 2];

    /* Auto-insert newline after } */
    if (last == '}') {
        fwrite("\n", 1, 1, f);
        prevIsNl = true;
    }

    free(element);

    return prevIsNl;
}

static void cdiff_file_writeElements(FILE *f, corto_ll elements) {
    corto_iter it = corto_ll_iter(elements);
    bool prevIsNl = false;

    while (corto_iter_hasNext(&it)) {
        cdiff_elem *el = corto_iter_next(&it);

        if (el->header) {
            prevIsNl = cdiff_file_writeElement(f, el->header, prevIsNl);
        }

        if (el->body) {
            prevIsNl = cdiff_file_writeElement(f, el->body, prevIsNl);
        }

        if (el->id) free(el->id);
        free(el);
    }

    corto_ll_free(elements);
}

int16_t cdiff_file_close (cdiff_file file) {
    /* If file didn't change, no need to overwrite file (speeds up building) */
    if (file->isChanged) {
        /* Open file for writing */
        FILE *f = fopen(file->name, "w");

        /* Write & cleanup elements */
        cdiff_file_writeElements(f, file->elements);

        if (file->legacyElements) {
            cdiff_file_writeElements(f, file->legacyElements);
        }

        fclose(f);

        free(file->name);
        free(file);
    }

    return 0;
}

static cdiff_elem* cdiff_file_elemFind(corto_ll elements, char *id) {
    corto_iter it = corto_ll_iter(elements);
    cdiff_elem *el = NULL;

    while (corto_iter_hasNext(&it)) {
        el = corto_iter_next(&it);

        if (el->id) {
            if (el->kind == CDIFF_FUNCTION_LEGACY) {
                corto_id legacyId, queryId;
                strcpy(queryId, id);

                /* Strip namespace from id as using different generator prefix
                 * can impact how package names map to the full id */
                char *ptr = strchr(el->id, '(');
                if (!ptr) {
                    ptr = &el->id[strlen(el->id) - 1];
                } else {
                    ptr[0] = '\0';
                    ptr --;
                }

                int count = 0;
                while (count < 2 && (--ptr) != el->id) {
                    if (ptr[0] == '/') count ++;
                }
                if (ptr[0] == '/') ptr ++;

                strcpy(legacyId, ptr);
                char ch;
                for (ptr = legacyId; (ch = *ptr); ptr ++) {
                    if (ch == '/') *ptr = '_';
                }

                /* Strip _v from query */
                int length = strlen(queryId);
                if (queryId[length - 2] == '_' && queryId[length - 1] == 'v') {
                    queryId[length - 2] = '\0';
                }

                /* Legacy id can be the full name, not relative to the
                 * package so there is no straightforward translation from
                 * id to function name. If id string occurs anywhere in the
                 * legacy id, it's a match. */
                if ((ptr = strstr(queryId, legacyId))) {
                    /* Ensure there aren't any trailing characters */
                    if (strlen(ptr) == strlen(legacyId)) {
                        break;
                    }
                }

                /* If query is in the form '...Main' it could refer to the main
                 * function of a package which is stored with id 'main' */
                if (strstr(queryId, "Main")) {
                    if (!strcmp(legacyId, "main")) {
                        break;
                    }
                }
            } else if (el->id && !strcmp(el->id, id)) {
                break;
            }
        }
        el = NULL;
    }

    return el;
}

void cdiff_file_elemBegin(cdiff_file file, char *fmt, ...) {
    corto_assert(file != NULL, "NULL specified for file");

    if (!file->elements) {
        file->elements = corto_ll_new();
    }

    cdiff_elem *el = NULL;
    char *id = NULL;

    if (fmt) {
        va_list args;
        va_start(args, fmt);
        corto_vasprintf(&id, fmt, args);
        va_end(args);

        el = cdiff_file_elemFind(file->elements, id);
        if (!el && file->legacyElements) {
            el = cdiff_file_elemFind(file->legacyElements, id);
        }
    }

    if (!el) {
        el = malloc (sizeof(cdiff_elem));
        el->id = id;
        el->header = NULL;
        el->body = NULL;
        el->kind = id ? CDIFF_FUNCTION : CDIFF_TEXT;
        file->isChanged = true;

        if (!file->elements) {
            file->elements = corto_ll_new();
        }
        corto_ll_append(file->elements, el);
    } else {
        free(id);
    }

    file->cur = el;
    file->writeTo = 0;
}

void cdiff_file_elemEnd(cdiff_file file) {
    corto_assert(file != NULL, "NULL specified for file");
    corto_assert(file->writeTo == 0, "finish header or body before closing element");
    file->cur = NULL;
}

void cdiff_file_headerBegin(cdiff_file file) {
    corto_assert(file != NULL, "NULL specified for file");
    corto_assert(file->cur != NULL, "select element before starting header");
    corto_assert(file->writeTo != 2, "end body before start writing to header");

    file->writeTo = 1;
    file->writeBuffer = CORTO_BUFFER_INIT;
}

void cdiff_file_headerEnd(cdiff_file file) {
    corto_assert(file != NULL, "NULL specified for file");
    corto_assert(file->writeTo == 1, "not writing to header");

    char *header = corto_buffer_str(&file->writeBuffer);
    if (!file->cur->header) {
        file->cur->header = header;
    } else if (strcmp(header, file->cur->header)) {
        corto_ptr_setstr(&file->cur->header, header);
        file->isChanged = TRUE;
    }

    file->writeTo = 0;
}

int16_t cdiff_file_bodyBegin(cdiff_file file) {
    corto_assert(file != NULL, "NULL specified for file");
    corto_assert(file->cur != NULL, "select element before starting body");
    corto_assert(file->writeTo != 1, "end header before start writing to body");

    /* Test if body is already set */
    if (file->cur->body) {
        return 1;
    }

    file->writeBuffer = CORTO_BUFFER_INIT;
    file->writeTo = 2;

    return 0;
}

void cdiff_file_bodyEnd(cdiff_file file) {
    corto_assert(file != NULL, "NULL specified for file");
    corto_assert(file->writeTo == 2, "not writing to body");

    file->cur->body = corto_buffer_str(&file->writeBuffer);

    file->writeTo = 0;
    file->isChanged = TRUE;
}

void cdiff_file_write(
    cdiff_file file, 
    char *fmt, 
    ...) 
{
    corto_assert(file != NULL, "NULL specified for file");

    if (file->newLine && file->indent) {
        int i;
        for (i = 0; i < file->indent * 4; i++) {
            corto_buffer_appendstrn(&file->writeBuffer, " ", 1);
        }
    }

    va_list args;
    va_start(args, fmt);
    corto_buffer_vappend(&file->writeBuffer, fmt, args);
    va_end(args);

    /* If no element specified for writing, write to new text element. */
    if (!file->cur && file->isNew) {
        cdiff_elem *el = corto_calloc(sizeof(cdiff_elem));
        el->kind = CDIFF_TEXT;
        el->body = corto_buffer_str(&file->writeBuffer);
        if (!file->elements) {
            file->elements = corto_ll_new();
        }
        corto_ll_append(file->elements, el);
        file->writeBuffer = CORTO_BUFFER_INIT;
    }

    file->newLine = fmt[strlen(fmt) - 1] == '\n';
}

void cdiff_file_writeBuffer(
    cdiff_file file,
    corto_buffer *buffer)
{
    char *str = corto_buffer_str(buffer);
    cdiff_file_write(file, "%s", str);
    free(str);
}

void cdiff_file_indent(cdiff_file file) {
    corto_assert(file != NULL, "NULL specified for file");
    file->indent ++;
}

void cdiff_file_dedent(cdiff_file file) {
    corto_assert(file != NULL, "NULL specified for file");
    corto_assert(file->indent != 0, "too many dedents");
    file->indent --;
}

int cortomain(int argc, char *argv[]) {
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    return 0;
}
