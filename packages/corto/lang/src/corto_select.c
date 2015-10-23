
#include "corto.h"
#include "ctype.h"
#include "jsw_rbtree.h"

extern corto_threadKey CORTO_KEY_SELECT;
#define CORTO_SELECT_MAX_OP (32)

typedef enum corto_selectToken {
	TOKEN_NONE,
	TOKEN_IDENTIFIER,
	TOKEN_SCOPE,
	TOKEN_TREE,
	TOKEN_PARENT,
	TOKEN_ASTERISK,
	TOKEN_WILDCARD,
} corto_selectToken;

typedef struct corto_selectOp {
	corto_selectToken token;
	char *start;
} corto_selectOp;

typedef struct corto_selectStack {
	corto_object o; /* Object of whose scope is being iterated */
	jsw_rbtrav_t trav; /* Persistent tree iterator */
	corto_iter iter;
} corto_selectStack;

typedef struct corto_selectData {
	corto_id expr;                            /* Full expression */
	corto_selectOp program[CORTO_SELECT_MAX_OP]; /* Parsed program */
	corto_uint8 programSize;
	corto_selectStack stack[CORTO_SELECT_MAX_OP]; /* Execution stack */
	corto_uint8 stackSize;
	corto_uint8 sp;
	corto_object next;
}corto_selectData;

static corto_selectData* corto_selectDataGet(void) {
	corto_selectData* result;

	result = corto_threadTlsGet(CORTO_KEY_SELECT);
	if (!result) {
		result = corto_calloc(sizeof(corto_selectData));
	}

	return result;
}

static int corto_selectParse(corto_selectData *data) {
	char *ptr, *start, ch;
	int op = 0;

	ptr = data->expr;
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
				corto_seterr("invalid usage of ':'");
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
				corto_seterr("invalid character '%c", ch);
				goto error;
			}
			break;
		}
		data->program[op].start = start;
		if (++op == CORTO_SELECT_MAX_OP) {
			corto_seterr("expression is too long");
			goto error;
		}
	}

	data->programSize = op;

	return 0;
error:
	return -1;
}

static char* corto_selectTokenStr(corto_selectToken t) {
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

static int corto_selectValidate(corto_selectData *data) {
	int op;
	corto_selectToken t, tprev = TOKEN_NONE;
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
		case TOKEN_PARENT:
			switch(tprev) {
			case TOKEN_TREE:
			case TOKEN_PARENT:
				goto error;
			default: break;
			}
			break;
		case TOKEN_WILDCARD:
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
		default:
			break;
		}
		tprev = t;
	}

	return 0;
error:
	corto_seterr("unexpected '%s' after '%s'", 
		corto_selectTokenStr(t),
		corto_selectTokenStr(tprev));
	return -1;
}

static int corto_selectRun(corto_selectData *data) {
	CORTO_UNUSED(data);
	return 0;
}

static int corto_selectHasNext(corto_iter *iter) {
	corto_selectData *data = corto_selectDataGet();
	CORTO_UNUSED(iter);

	if (!data->next) {
		if (corto_selectRun(data)) {
			goto error;
		}
	}

	return data->next != NULL;
error:
	return -1;
}

static void* corto_selectNext(corto_iter *iter) {
	corto_selectData *data = corto_selectDataGet();
	CORTO_UNUSED(iter);

	return data->next;
}

corto_int16 corto_select(corto_object scope, corto_string expr, corto_iter *iter_out) {
	corto_selectData *data = corto_selectDataGet();
	CORTO_UNUSED(scope);

	strcpy(data->expr, expr);

	iter_out->hasNext = corto_selectHasNext;
	iter_out->next = corto_selectNext;

	if (corto_selectParse(data)) {
		corto_seterr("select '%s' failed: %s", expr, corto_lasterr());
		goto error;
	}

	if (corto_selectValidate(data)) {
		corto_seterr("select '%s' failed: %s", expr, corto_lasterr());
		goto error;
	}

	return 0;
error:
	return -1;
}
