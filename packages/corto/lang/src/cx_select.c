
#include "corto.h"
#include "ctype.h"
#include "jsw_rbtree.h"

extern cx_threadKey CX_KEY_SELECT;
#define CX_SELECT_MAX_OP (32)

typedef enum cx_selectToken {
	TOKEN_NONE,
	TOKEN_IDENTIFIER,
	TOKEN_SCOPE,
	TOKEN_TREE,
	TOKEN_PARENT,
	TOKEN_ASTERISK,
	TOKEN_WILDCARD,
} cx_selectToken;

typedef struct cx_selectOp {
	cx_selectToken token;
	char *start;
} cx_selectOp;

typedef struct cx_selectData {
	cx_id expr;                  /* Full expression */
	char *ptr;                   /* Pointer to current location */
	cx_selectOp program[CX_SELECT_MAX_OP]; /* Parsed program */
	cx_uint8 programSize;
}cx_selectData;

static cx_selectData* cx_selectDataGet(void) {
	cx_selectData* result;

	result = cx_threadTlsGet(CX_KEY_SELECT);
	if (!result) {
		result = cx_calloc(sizeof(cx_selectData));
	}

	return result;
}

static int cx_selectParse(cx_selectData *data) {
	char *ptr, *start, ch;
	int op = 0;

	ptr = data->ptr;
	for (; (ch = *ptr); data->program[op].start = ptr, ptr++) {
		start = ptr;
		switch(ch) {
		case '.':
			if (ptr[1] == '.') {
				data->program[op].token = TOKEN_PARENT;
				ptr++;
			} else {
				data->program[op].token = TOKEN_TREE;
			}
			break;
		case ':':
			if (ptr[1] == ':') {
				data->program[op].token = TOKEN_SCOPE;
				ptr++;
			} else {
				cx_seterr("invalid usage of ':'");
				goto error;
			}
			break;
		default:
			while((ch = *ptr++) && (isalnum(ch) || (ch == '*') || (ch == '?'))) {}
			ptr--; /* Go back one character to adjust for lookahead of one */
			int len = ptr - start;
			if (len) {
				if (len == 1) {
					if (*(ptr - 1) == '?') {
						data->program[op].token = TOKEN_WILDCARD;
					} else if (*(ptr - 1) == '*') {
						data->program[op].token = TOKEN_ASTERISK;
					} else {
						data->program[op].token = TOKEN_IDENTIFIER;
					}
				} else {
					data->program[op].token = TOKEN_IDENTIFIER;
				}
			} else {
				cx_seterr("invalid character '%c", ch);
				goto error;
			}
			break;
		}
		data->program[op].start = start;
		op++;
	}

	data->programSize = op;

	return 0;
error:
	return -1;
}

static char* cx_selectTokenStr(cx_selectToken t) {
	switch(t) {
	case TOKEN_NONE: return "none";
	case TOKEN_IDENTIFIER: return "identifier";
	case TOKEN_SCOPE: return "::";
	case TOKEN_TREE: return ".";
	case TOKEN_ASTERISK: return "*";
	case TOKEN_WILDCARD: return "?";
	case TOKEN_PARENT: return "..";
	}
	return NULL;
}

static int cx_selectValidate(cx_selectData *data) {
	int op;
	cx_selectToken t, tprev = TOKEN_NONE;
	for (op = 0; op < data->programSize; op++) {
		t = data->program[op].token;
		switch(t) {
		case TOKEN_IDENTIFIER:
			switch(tprev) {
			case TOKEN_IDENTIFIER:
			case TOKEN_ASTERISK:
			case TOKEN_WILDCARD:
			case TOKEN_PARENT:
				goto error;
			default: break;
			}
			break;
		case TOKEN_SCOPE:
			switch(tprev) {
			case TOKEN_SCOPE:
				goto error;
			default: break;
			}
			break;
		case TOKEN_TREE:
			switch(tprev) {
			case TOKEN_TREE:
			case TOKEN_PARENT:
				goto error;
			default: break;
			}
			break;
		case TOKEN_PARENT:
			switch(tprev) {
			case TOKEN_TREE:
			case TOKEN_PARENT:
				goto error;
			default: break;
			}
			break;
		case TOKEN_ASTERISK:
			switch(tprev) {
			case TOKEN_IDENTIFIER:
			case TOKEN_PARENT:
			case TOKEN_ASTERISK:
			case TOKEN_WILDCARD:
				goto error;
			default: break;
			}
			break;
		case TOKEN_WILDCARD:
			switch(tprev) {
			case TOKEN_IDENTIFIER:
			case TOKEN_PARENT:
			case TOKEN_ASTERISK:
			case TOKEN_WILDCARD:
				goto error;
			default: break;
			}
			break;
		default:
			break;
		}
		tprev = t;
	}

	return 0;
error:
	cx_seterr("unexpected '%s' after '%s'", 
		cx_selectTokenStr(t),
		cx_selectTokenStr(tprev));
	return -1;
}

static int cx_selectHasNext(cx_iter *iter) {
	return 0;
}

static void* cx_selectNext(cx_iter *iter) {
	return NULL;
}

cx_int16 cx_select(cx_object scope, cx_string expr, cx_iter *iter_out) {
	cx_selectData *data = cx_selectDataGet();

	strcpy(data->expr, expr);
	data->ptr = data->expr;

	iter_out->hasNext = cx_selectHasNext;
	iter_out->next = cx_selectNext;

	if (cx_selectParse(data)) {
		cx_seterr("select '%s' failed: %s", expr, cx_lasterr());
		goto error;
	}

	if (cx_selectValidate(data)) {
		cx_seterr("select '%s' failed: %s", expr, cx_lasterr());
		goto error;
	}

	return 0;
error:
	return -1;
}
