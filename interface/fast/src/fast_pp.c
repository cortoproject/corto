/*
 * fast_pp.c
 *
 *  Created on: May 29, 2012
 *      Author: sander
 */

#include "Fast_pp.h"
#include "db_mem.h"
#include "db_err.h"
#include "db_util.h"
#include "stdio.h"
 
/* Preprocess code - the main job of this function is to insert indent\dedent\column tokens */
static db_int32 fast_pp_code(db_string filename, db_string code, db_string result, db_uint32* size) {
	db_char *ptr, *rptr, *lptr;
	db_char ch;
	db_uint32 indentation[LANG_MAX_INDENT];
	db_uint32 indentationDepth;
	db_uint32 curIndent;
	db_uint32 line;

	ptr = code;

	indentationDepth = 0;
	indentation[indentationDepth] = 0;
	curIndent = 0;
	line = 1;
	rptr = result;

	while((ch = *ptr)) {
		curIndent = 0;

		/* Check if line is not just plain whitespace or comment (in that case, don't bother indentation) */

		lptr = ptr;
		while(lptr && (ch = *lptr)  && (ch != '\n') && (ch != '\0')) {
		    switch(ch) {
		    case ' ':
		    case '\t':
		    case 13: /* ASCII carriage return */
		        lptr++;
		        break;
		    case '/':
		        lptr++;
		        if (*lptr == '/') { /* Comment */
		            while((ch = *lptr) && (ch != '\n') && (ch != '\0')) { /* Skip until end of line */
		                lptr++;
		            }
		        }
		        break;
		    default:
		        lptr = NULL;
		        break;
		    }
		}

		ch = *ptr;

		/* If line is not just whitespaces, check indentation */
		if (!lptr) {

            /* Count indentation at beginning of line */
            while((ch == '\t') || (ch == ' ')) {
                if (ch == '\t') curIndent += 4;
                if (ch == ' ') curIndent += 1;
                ptr++;
                ch = *ptr;
            }

            /* Check if indent tokens must be inserted */
            if (curIndent > indentation[indentationDepth]) {
                indentationDepth++;
                indentation[indentationDepth] = curIndent;
                *size += strlen("#ind ");
                if (rptr) {
                    strcpy(rptr, "#ind ");
                    rptr += strlen("#ind ");
                }
            } else

            /* Check if dedent tokens must be inserted */
            if (curIndent < indentation[indentationDepth]) {
                while(curIndent < indentation[indentationDepth]) {
                    *size += strlen("#ded ");
                    if (rptr) {
                        strcpy(rptr, "#ded ");
                        rptr += strlen("#ded ");
                    }
                    indentationDepth--;
                }
                *size -= curIndent;
                if (!indentationDepth && curIndent) {
                    db_error("%s:%d: invalid indentation.", filename, line);
                    goto error;
                }   
            }

            /* Insert column position */
            if (curIndent) {
                *size += strlen("#column 512 ");
                if (rptr) {
                    sprintf(rptr, "#column %d ", curIndent);
                    rptr += strlen(rptr);
                }
                if (curIndent < 10)
                    (*size)++;
                else if (curIndent < 100) {
                    *size += 2;
                } else if (curIndent < 1000) {
                    *size += 3;
                }
            }
		}

        /* Scan until end of line */
		while(ch && (ch != '\n')) {
            if (rptr) {
                *rptr = ch;
                rptr++;
            }

            ptr++;
            ch = *ptr;
        }

        if (rptr && ch) {
            *rptr = '\n';
            rptr++;
        }
        if (ch) {
            ptr++;
            line++;
        }
	}

	/* Do remaining dedents */
	while(indentationDepth) {
	    *size += strlen("#ded ");
	    if (rptr) {
            strcpy(rptr, "#ded ");
            rptr += strlen("#ded ");
	    }
	    indentationDepth--;
	}

	if (rptr) {
		*rptr = '\0';
	}

	*size += strlen(code);

	return 0;
error:
	return -1;

}

/* List code */
void fast_ppList(db_string code) {
	db_char* ptr;
	db_char ch;
	db_uint32 line;

	line = 1;
	ptr = code;

	while(*ptr) {
		printf("%d: ", line);

		while((ch = *ptr) && (ch != '\n')) {
			printf("%c", ch);
			ptr++;
		}
		printf("\n");
		ptr++;
		line++;
	}
}

/* Preprocess code */
db_string fast_pp(db_string filename, db_string code) {
	db_uint32 size,checkSize;
	db_string result;
    db_bool appendNewline = FALSE;

	size = 0;
	checkSize = 0;
    appendNewline = code[strlen(code)-1] != '\n'; /* Automatically insert newline at the end of file */

	/* Do dryrun to get allocation size */
	if (fast_pp_code(filename, code, NULL, &size)) {
	    db_trace("cortex: %s: preprocessor failed.");
		goto error;
	}

	/* Allocate size for preprocessed string */
	result = db_malloc(size + 1 + appendNewline); /* Assuming true is 1 */

	/* Re-run preprocessor */
	if (fast_pp_code(filename, code, result, &checkSize)) {
	    db_error("preprocessor failed");
	    goto error;
	}

    if (appendNewline) {
        db_uint32 length = strlen(result);
        result[length] = '\n';
        result[length+1] = '\0';
    }

	db_assert(size == checkSize, "calculated size of preprocessed code-string does not match actual value.");
	db_assert((size+appendNewline) >= strlen(result), "calculated size of preprocessed code-string does not match stringlength (%d vs. %d).", size, strlen(result));

	return result;
error:
	return NULL;
}
