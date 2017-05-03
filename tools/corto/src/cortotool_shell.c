/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "cortotool_shell.h"
#include "cortotool_shellengine.h"
#include "ctype.h"
#include "fnmatch.h"

#define CXSH_CMD_MAX (1024)

#define CXSH_COL_NAME     (46)
#define CXSH_COL_ID       (64)
#define CXSH_COL_TYPE     (32)
#define CXSH_COL_TOTAL    (CXSH_COL_NAME + CXSH_COL_TYPE)

#define SHELL_COLOR (CORTO_NORMAL)
#define ERROR_COLOR (CORTO_RED)
#define TYPE_COLOR (CORTO_MAGENTA)
#define OBJECT_COLOR (CORTO_CYAN)
#define META_COLOR (CORTO_MAGENTA)
#define INTERFACE_COLOR (CORTO_NORMAL)
#define HEADER_COLOR (CORTO_BOLD)

static corto_id scope;

/* Print color */
static void cxsh_color(const char *string) {
    printf("%s", string);
}

/* Find preferred character on which to break a string, in case it's too long
 * to fit on one column */
static corto_string cxsh_findPreferredBreak(corto_string str) {
    char ch, *ptr = str, *breakpt = str + strlen(str);
    while ((ch = *ptr)) {
        switch (ch) {
        case ' ':
        case ',':
        case '(':
        case ')':
        case '{':
        case '}':
            breakpt = ptr+1;
            break;
        default:
            break;
        }
        ptr++;
    }

    /* If no breakpoints were found, look again for scope operators. The reason
     * to not check for these in the first run is because it is preferred that
     * identifiers are on one line. */
    if (breakpt == (str + strlen(str))) {
        while ((ch = *ptr)) {
            switch (ch) {
            case ':':
                if (*(ptr + 1)) {
                    breakpt = ptr + 1;
                } else {
                    breakpt = ptr;
                }
                break;
            default:
                break;
            }
            ptr++;
        }
    }

    return breakpt;
}

static corto_string cxsh_printColumnValue(corto_string str, unsigned int width){
    corto_string result = NULL;
    if (strlen(str) < (width - 2)) {
        printf("%s%*s", str, (int)(width - strlen(str)), " ");
    } else {
        corto_id buffer;
        snprintf(buffer, width - 2, "%s", str);
        (*cxsh_findPreferredBreak(buffer)) = '\0';
        printf("%s%*s", buffer, width - (unsigned int)strlen(buffer), " ");
        result = str + strlen(buffer);
        if (*result == ' ') {
            result++;
        }
    }
    return result;
}

/* Print shell prompt */
static void cxsh_prompt(int enableColors, corto_id prompt) {

    if (enableColors) {
        sprintf(prompt, "%s<%s %s%s >%s ", CORTO_GREEN, CORTO_NORMAL, scope, CORTO_CYAN, CORTO_NORMAL);
    } else {
        sprintf(prompt, "< %s > ", scope);
    }
}

/* Translate object state to string */
static char* cxsh_stateStr(corto_object o, char* buff) {
    buff[0] = '\0';
    corto_int8 appended = 0;

    /* Get state */
    if (corto_checkState(o, CORTO_VALID)) {
       strcpy(buff, "V");
       appended++;
    }
    if (corto_checkState(o, CORTO_DECLARED)) {
        if (appended) {
            strcat(buff, "|");
        }
        strcat(buff, "DCL");
        appended++;
    }
    if (corto_checkState(o, CORTO_DEFINED)) {
        if (appended) {
            strcat(buff, "|");
        }
        strcat(buff, "DEF");
    }

    return buff;
}

/* Translate object attributes to string */
static char* cxsh_attrStr(corto_object o, char* buff) {
    corto_bool first;
    *buff = '\0';

    first = TRUE;
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        strcat(buff, "S");
        first = FALSE;
    }
    if (corto_checkAttr(o, CORTO_ATTR_WRITABLE)) {
        if (!first) {
            strcat(buff, "|W");
        } else {
            strcat(buff, "W");
            first = FALSE;
        }
    }
    if (corto_checkAttr(o, CORTO_ATTR_OBSERVABLE)) {
        if (!first) {
            strcat(buff, "|O");
        } else {
            strcat(buff, "O");
            first = FALSE;
        }
    }
    if (corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
        if (!first) {
            strcat(buff, "|P");
        } else {
            strcat(buff, "P");
        }
    }

    return buff;
}

static int cxsh_printRow(corto_string parent, corto_string id, corto_string type) {
    corto_string remaining = 0;
    corto_string objcolor;
    corto_uint32 colId = CXSH_COL_ID;
    corto_id fullId, searchId;

    sprintf(fullId, "%s/%s", parent, id);
    corto_cleanpath(fullId, fullId);
    sprintf(searchId, "%s/%s", scope, fullId);
    corto_cleanpath(searchId, searchId);

    corto_object obj = corto_find(NULL, searchId, CORTO_FIND_DEFAULT);
    if (obj) corto_release(obj);

    /* Print columns */
    if (obj) {
        objcolor = CORTO_GREEN;
    } else {
        objcolor = CORTO_BLUE;
    }
    cxsh_color(objcolor);
    remaining = cxsh_printColumnValue(fullId, colId);

    cxsh_color(TYPE_COLOR); printf("%s", type); cxsh_color(CORTO_NORMAL);
    printf("\n");

    /* Print remainder of the name */
    cxsh_color(objcolor);
    while (remaining) {
        printf("    ");
        remaining = cxsh_printColumnValue(remaining, CXSH_COL_ID - 4);
        printf("\n");
    }
    cxsh_color(CORTO_NORMAL);

    return obj ? 1 : 0;
}

/* List scope */
static void cxsh_ls(char* arg) {
    corto_uint32 i = 0, inStore = 0;
    corto_id buff;
    char ch;

    if (arg) {
        strcpy(buff, arg);

        /* Append * to argument */
        corto_uint32 l = strlen(buff);
        if ((ch = buff[l - 1]) != '*') {
            if (ch != '/') {
                strcat(buff, "/");
            }
            strcat(buff, "*");
        }
    } else {
        strcpy(buff, "*");
    }

    corto_iter iter;
    if (corto_select(scope, buff).iter(&iter)) {
        goto error;
    }

    while (corto_iter_hasNext(&iter)) {
        corto_result *item = corto_iter_next(&iter);
        inStore += cxsh_printRow(item->parent, item->id, item->type);
        i ++; /* Count objects so total can be printed */
    }

    if (!i) {
        printf("  no objects.\n\n");
    } else {
        printf("  %d objects (%d %sin store%s, %d %smounted%s)\n\n", i, 
            inStore, CORTO_GREEN, CORTO_NORMAL, i - inStore, CORTO_BLUE, CORTO_NORMAL);
    }

    return;
error:
    corto_error("%s", corto_lasterr());
}

/* Navigate scopes */
static void cxsh_cd(char* arg) {
    if (!arg || !strcmp(arg, "/")) {
        strcpy(scope, "/");
    } else {
        corto_id result;
        corto_int32 count = 0;
        strcpy(result, arg);

        if (result[strlen(result) - 1] == '/') {
            result[strlen(result) - 1] = '\0';
        }

        corto_seterr(NULL);

        corto_resultIter iter;
        if (corto_select(scope, arg).iter(&iter)) goto error;

        /* Reuse request to temporarily store result, count results */
        while (corto_iter_hasNext(&iter)) {
            corto_result *e = corto_iter_next(&iter);

            if (count) {
                corto_seterr("more than one result returned by 'cd %s' (%s/%s/%s)", arg, scope, e->parent, e->id);
                goto error;
            }
            /* Use fully qualified path for scope */
            sprintf(result, "%s/%s/%s", scope, e->parent, e->id);
            count++;
        }

        if (count == 1) {
            strcpy(scope, result);
            corto_cleanpath(scope, scope);
        } else {
            if (!corto_lasterr()) {
                corto_seterr("'%s' did not match any objects", arg);
            }
            goto error;
        }
    }

    return;
error:
    corto_error("%s", corto_lasterr());
}

corto_bool cxsh_readline(corto_string cmd) {
    char* read = 0;
    cmd[0] = '\0';

    /* Read command */
    if ((read = fgets(cmd, CXSH_CMD_MAX, stdin)) == 0) {
        goto empty;
    }

    /* Strip '\n' */
    cmd[strlen(cmd) - 1] = '\0';

    return read != NULL;
empty:
    return 0;
}

static corto_string cxsh_multiline(corto_string expr, corto_uint32 indent) {
    char cmd[CXSH_CMD_MAX];
    unsigned int len = strlen(expr);
    unsigned int multiline = 0;

    if (len && expr[len-1] == ':') {
        unsigned int cmdLen = 0;
        corto_id prompt;
        cxsh_prompt(FALSE, prompt);
        multiline = 1;

        do {
            corto_uint32 i;
            /* Print indent */
            cxsh_color(SHELL_COLOR);
            printf("%*s >", (unsigned int)strlen(prompt) - 2, "");
            cxsh_color(CORTO_BLUE);
            for(i = 0; i < (indent * 4 - 1); i++) {
                printf(".");
            }
            cxsh_color(CORTO_NORMAL);
            printf(" ");

            cxsh_readline(cmd);
            cmdLen = strlen(cmd);

            if (!cmdLen) break;

            /* Append command */
            expr = corto_realloc(expr, len + cmdLen + 1 + 1 + (indent * 4));
            strcat(expr, "\n");

            /* Insert indent */
            {
                char indentStr[CXSH_CMD_MAX];
                memset(indentStr, ' ', indent * 4);
                indentStr[indent * 4] = '\0';
                strcat(expr, indentStr);
            }
            strcat(expr, cmd);

            /* cmd can be a nested multiline expression */
            expr = cxsh_multiline(expr, indent + 1);
            len = strlen(expr);
        } while (cmdLen);
    }

    if (multiline && (indent == 1)) {
        expr = corto_realloc(expr, len + 1 + 1);
        strcat(expr, "\n");
    }

    return expr;
}

/* Show expression */
static int cxsh_show(char* object) {
    corto_id id;
    char state[sizeof("valid | declared | defined")];
    char attr[sizeof("scope | writable | observable | persistent")];
    corto_walk_opt s;
    corto_string_ser_t sdata;
    corto_value result;
    char *expr = object;
    corto_object scope_o = NULL;

    memset(&result, 0, sizeof(corto_value));

    /* Check whether this is a multiline expression */
    expr = cxsh_multiline(corto_strdup(object), 1);
    scope_o = corto_resolve(root_o, scope);
    if (!scope_o) {
        corto_seterr("invalid scope '%s'", scope);
        return -1;
    }

    corto_object result_obj = corto_resolve(scope_o, expr);

    if (result_obj) {
        result = corto_value_object(result_obj, NULL);
        corto_object o = NULL;
        if (result.kind == CORTO_OBJECT) {
            o = corto_value_objectof(&result);
        }

        /* Release scope as soon as possible */
        corto_release(scope_o);

        /* Print object properties */
        if (o) {
            if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
                if (o == root_o) {
                    printf("%sname:%s         %s/%s\n",
                      INTERFACE_COLOR, CORTO_NORMAL, OBJECT_COLOR, CORTO_NORMAL);
                } else {
                    printf("%sname:%s         %s%s%s\n",
                      INTERFACE_COLOR,
                      CORTO_NORMAL,
                      OBJECT_COLOR,
                      corto_idof(o),
                      CORTO_NORMAL);
                }
                if (o != root_o) {
                    corto_fullpath(id, corto_parentof(o));
                    printf("%sparent:       %s%s%s\n",
                      INTERFACE_COLOR, OBJECT_COLOR,
                      id,
                      CORTO_NORMAL);
                }
            }
            if (corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
                corto_object owner = corto_ownerof(o);

                if (corto_checkState(o, CORTO_DEFINED)) {
                    printf("%sowner:%s        %s%s\n",
                        INTERFACE_COLOR,
                        OBJECT_COLOR,
                        owner ? corto_fullpath(NULL, owner) : "<this>",
                        CORTO_NORMAL);
                }
            }
            if (corto_checkState(o, CORTO_VALID)) {
                printf("%sstate:%s        %s%s%s\n", INTERFACE_COLOR, CORTO_NORMAL, META_COLOR, cxsh_stateStr(o, state), CORTO_NORMAL);
            } else {
                printf("%sstate:        %s%s\n", CORTO_RED, cxsh_stateStr(o, state), CORTO_NORMAL);
            }
            printf("%sattributes:%s   %s%s%s\n", INTERFACE_COLOR, CORTO_NORMAL, META_COLOR, cxsh_attrStr(o, attr), CORTO_NORMAL);
            printf("%stype:%s         %s%s%s\n", INTERFACE_COLOR, CORTO_NORMAL, META_COLOR,
                corto_fullpath(NULL, corto_value_typeof(&result)), CORTO_NORMAL);
        }

        /* Initialize serializer userData */
        s = corto_string_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
        memset(&sdata, 0, sizeof(corto_string_ser_t));
        sdata.enableColors = TRUE;
        s.access = CORTO_PRIVATE;
        s.accessKind = CORTO_NOT;
        s.aliasAction = CORTO_WALK_ALIAS_IGNORE;
        s.optionalAction = CORTO_WALK_OPTIONAL_IF_SET;

        /* Serialize value to string */
        if (corto_value_ptrof(&result)) {
            corto_value_walk(&s, &result, &sdata);
            corto_string str = corto_buffer_str(&sdata.buffer);
            if (str) {
                if (o) {
                    printf("%svalue:%s        ", INTERFACE_COLOR, CORTO_NORMAL);
                }
                printf("%s\n", str);

                corto_dealloc(str);
                sdata.buffer.buf = NULL;
                sdata.ptr = NULL;
            }
        }

        if (o) {
            if (corto_class_instanceof(corto_type_o, o) && corto_checkState(o, CORTO_DEFINED)) {
                s.access = CORTO_LOCAL | CORTO_READONLY | CORTO_PRIVATE | CORTO_HIDDEN;
                s.accessKind = CORTO_NOT;
                s.aliasAction = CORTO_WALK_ALIAS_IGNORE;
                s.optionalAction = CORTO_WALK_OPTIONAL_IF_SET;
                corto_metawalk(&s, o, &sdata);
                corto_string str = corto_buffer_str(&sdata.buffer);
                if (str) {
                    printf("%sinitializer:%s  %s\n", INTERFACE_COLOR, CORTO_NORMAL, str);
                    corto_dealloc(str);
                }
            }
            printf("\n");
        }

        corto_dealloc(expr);
        return 0;
    } else {
        corto_release(scope_o);
        corto_dealloc(expr);
        return -1;
    }
}

/* Import file */
static void cxsh_import(char* file) {
    corto_load(file, 0, NULL);
}

/* Drop scope */
static void cxsh_delete(char* name) {
    corto_id id;
    corto_object o;

    sprintf(id, "%s/%s", scope, name);

    o = corto_resolve(root_o, id);
    if (o) {
        corto_delete(o);
        corto_release(o);
    } else {
        corto_error("expression '%s' did not resolve to object.", id);
        printf("\n");
    }
}

static void cxsh_help(void) {
    printf("%sCorto shell help%s\n", HEADER_COLOR, CORTO_NORMAL);
    printf("\n");
    printf("Use corto-expressions to read or modify data in the corto database.\n");
    printf("If the expression resolves to an object the shell will display the object\n");
    printf("and its metadata. If shell-commands conflict with an objectname prefix the\n");
    printf("command with an '\\'.\n");
    printf("\n");
    printf("%sAvailable commands:%s\n", HEADER_COLOR, CORTO_NORMAL);
    printf("  %sls [expr]%s\n", HEADER_COLOR, CORTO_NORMAL);
    printf("      Lists result of select expression. If no expression is\n");
    printf("      provided, ls lists the contents of the current scope.\n");
    printf("  %stree [scope]%s\n", HEADER_COLOR, CORTO_NORMAL);
    printf("      Lists contents of a scope recursively. If no scope is\n");
    printf("      provided the current scope is listed.\n");
    printf("  %scd [scope]%s\n", HEADER_COLOR, CORTO_NORMAL);
    printf("      Change current scope to specified scope.\n");
    printf("  %simport [file]%s\n", HEADER_COLOR, CORTO_NORMAL);
    printf("      Load a file into the database. The file can be of any type\n");
    printf("      that is supported by corto.\n");
    printf("  %sclear%s\n", HEADER_COLOR, CORTO_NORMAL);
    printf("      Clears the screen.\n");
    printf("  %sexit%s\n", HEADER_COLOR, CORTO_NORMAL);
    printf("      Exit database shell.\n");
    printf("\n");
    printf("%sExamples:%s\n", HEADER_COLOR, CORTO_NORMAL);
    printf("  %s$%s ls corto/lang\n", SHELL_COLOR, CORTO_NORMAL);
    printf("      List objects in scope 'corto/lang'\n");
    printf("  %s$%s ls //w*\n", SHELL_COLOR, CORTO_NORMAL);
    printf("      Lists all objects that start with the letter 'w'\n");
    printf("  %s$%s corto/lang/class\n", SHELL_COLOR, CORTO_NORMAL);
    printf("      Display object 'corto/lang/class'\n");
    printf("  %s$%s class.base\n", SHELL_COLOR, CORTO_NORMAL);
    printf("      Resolves 'base' member of class object. Requires the corto\n");
    printf("      scripting language to be installed.\n");
    printf("\n");
}

int cxsh_getErrorLocation(corto_string str) {
    int result = 0;

    /* Only give location when on the first line */
    if (strchr(str, ':')) {
        result = atoi(str);
        if (!result) {
            result = 1;
        }
    }

    return result;
}


static void cxsh_goodbye(char *cmd) {
    int bs;
    corto_id prompt;
    cxsh_prompt(TRUE, prompt);

    for (bs = 0; bs < (strlen(prompt) + strlen(cmd)); bs++) {
        printf("\b");
    }
    for (bs = 0; bs < (strlen(prompt) + strlen(cmd)); bs++) {
        printf(" ");
    }
    for (bs = 0; bs < (strlen(prompt) + strlen(cmd)); bs++) {
        printf("\b");
    }
    printf("Bye!\n");
}


static int cxsh_doCmd(int argc, char* argv[], char *cmd) {
    CORTO_UNUSED(argc);

    /* ls */
    if (!strcmp(argv[0], "ls")) {
      cxsh_ls(argv[1]);
    } else
    /* exit */
    if (!strcmp(argv[0], "exit")) {
        cxsh_goodbye(cmd);
        goto quit;
    } else
    /* cd */
    if (!strcmp(argv[0], "cd")) {
        cxsh_cd(argv[1]);
    } else
    /* import */
    if (!strcmp(argv[0], "import")) {
        cxsh_import(argv[1]);
    } else
    /* drop */
    if (!strcmp(argv[0], "delete")) {
        cxsh_delete(argv[1]);
    } else
    /* clear */
    if (!strcmp(argv[0], "clear")) {
        system("clear");
    } else
    /* help */
    if (!strcmp(argv[0], "help")) {
        cxsh_help();
    } else {
        corto_char *lastErr;

        if (cxsh_show(cmd)) {
            if ((lastErr = corto_lasterr())) {
                unsigned int location = 0;

                /* If lastError starts with a line:column: indication, print an arrow */
                if ((location = cxsh_getErrorLocation(lastErr))) {
                    corto_id prompt;
                    cxsh_prompt(FALSE, prompt);
                    lastErr = strchr(lastErr, ':') + 2;
                    corto_error("%*s^\n%s", location - 1 + (unsigned int)strlen(prompt), "", lastErr);
                } else {
                    corto_error("error: %s", lastErr);
                }
            } else {
                corto_error("'%s' does not resolve to a valid object or expression", cmd);
            }
        }
    }

    return 0;
quit:
    return 1;
}

typedef struct cxsh_memberSer_t {
    char *prefix;
    char *filter;
    corto_ll results;
} cxsh_memberSer_t;

static corto_int16 cxsh_ser_member(
  corto_walk_opt* s,
  corto_value *info,
  void *userData)
{
    cxsh_memberSer_t *data = userData;
    corto_string m = corto_idof(info->is.member.t);
    CORTO_UNUSED(s);

    if (m && !fnmatch(data->filter, m, 0)) {
        corto_id str;
        sprintf(str, "%s.%s", data->prefix, m);
        corto_llAppend(data->results, corto_strdup(str));
    }

    return 0;
}

/* Resolve members for type */
corto_walk_opt cxsh_memberSer(void) {
    corto_walk_opt s;

    corto_walk_init(&s);

    s.access = CORTO_PRIVATE;
    s.accessKind = CORTO_NOT;
    s.traceKind = CORTO_WALK_TRACE_ON_FAIL;
    s.metaprogram[CORTO_MEMBER] = cxsh_ser_member;
    return s;
}

/* Obtain type of expression */
corto_type cxsh_exprType(corto_string expr) {
    CORTO_UNUSED(expr);

    corto_type result = NULL;
    /*corto_function parseLine =
        corto_resolve(NULL, "/corto/ast/Parser/parseType");

    if (parseLine) {
        corto_object scope_o = corto_resolve(root_o, scope);
        if (!scope_o) {
            return NULL;
        }
        corto_call(parseLine, &result, expr, scope_o);
        corto_release(scope_o);
        corto_lasterr();
    }*/

    return result;
}


/* Return result for TAB expansion */
corto_ll cxsh_shellExpand(int argc, const char* argv[], char *cmd) {
    corto_ll result = corto_llNew();
    corto_iter iter;
    corto_id expr;

    /* If there is no space between command and first
     * arg, space must be inserted */
    corto_bool firstArgSpace =
      argc == 1 ? cmd[strlen(cmd) - 1] == ' ' : TRUE;

    /* For selection of scopes, auto-append a '/' */
    corto_bool appendSlash = FALSE;

    if (argc) {
        if (!strcmp(argv[0], "cd") || !strcmp(argv[0], "ls")) {
            appendSlash = TRUE;
            if (argc >= 2) {
                strcpy(expr, argv[1]);
            } else {
                strcpy(expr, "");
            }

            /* If first argument doesn't end with a space, insert space on first
             * tab. */
            if (!firstArgSpace) {
                corto_llFree(result);
                result = NULL;
            } else {
                strcat(expr, "*");
            }
        } else {
            strcpy(expr, cmd);
            strcat(expr, "*");
        }
    } else {
        strcpy(expr, "*");
    }

    if (result) {
        char *ptr, *memberPtr = NULL;
        ptr = expr;

        /* Find last member expression */
        if (ptr) {
            while ((ptr = strchr(ptr + 1, '.'))) {
                memberPtr = ptr;
            }
        }

        if (memberPtr) {
            corto_id objExpr; strcpy(objExpr, expr);
            objExpr[memberPtr - expr] = '\0';
            corto_id filter; strcpy(filter, &expr[memberPtr - expr + 1]);
            corto_type t = NULL;
            if ((t = cxsh_exprType(objExpr))) {
                if (corto_instanceof(corto_interface_o, t)) {
                    cxsh_memberSer_t walkData = {objExpr, filter, result};

                    /* Add members to auto complete */
                    corto_walk_opt ser = cxsh_memberSer();
                    corto_metawalk(&ser, t, &walkData);

                    /* Add methods to auto complete */
                    corto_int32 i;
                    for (i = 0; i < corto_interface(t)->methods.length; i++) {
                        corto_object m = corto_interface(t)->methods.buffer[i];
                        corto_id method, sigName;
                        corto_signatureName(corto_idof(m), sigName);
                        if (!fnmatch(filter, sigName, 0)) {
                            sprintf(method, "%s.%s(", objExpr, sigName);
                            corto_llAppend(result, corto_strdup(method));
                        }
                    }
                }
            }
        } else {
            corto_int32 i = 0;
            if (corto_select(scope, expr).iter(&iter)) goto error;
            while (corto_iter_hasNext(&iter)) {
                corto_result *item = corto_iter_next(&iter);
                corto_id scopedItem;
                if (strcmp(item->parent, ".")) {
                    sprintf(scopedItem, "%s/%s", item->parent, item->id);
                } else {
                    strcpy(scopedItem, item->id);
                }
                if (appendSlash) {
                    strcat(scopedItem, "/");
                }
                corto_llAppend(result, corto_strdup(scopedItem));
                i++;
            }

            if (!i) {
                if (corto_select("/corto", expr).iter(&iter)) goto error;
                while (corto_iter_hasNext(&iter)) {
                    corto_result *item = corto_iter_next(&iter);
                    corto_id scopedItem;
                    if (strcmp(item->parent, ".")) {
                        sprintf(scopedItem, "corto/%s/%s", item->parent, item->id);
                    } else {
                        sprintf(scopedItem, "corto/%s", item->id);
                    }
                    if (appendSlash) {
                        strcat(scopedItem, "/");
                    }
                    corto_llAppend(result, corto_strdup(scopedItem));
                    i++;
                }
            }

            if (!i) {
                if (corto_select("/corto/lang", expr).iter(&iter)) goto error;
                while (corto_iter_hasNext(&iter)) {
                    corto_result *item = corto_iter_next(&iter);
                    corto_id scopedItem;
                    if (strcmp(item->parent, ".")) {
                        sprintf(scopedItem, "corto/lang/%s/%s", item->parent, item->name);
                    } else {
                        sprintf(scopedItem, "corto/lang/%s", item->name);
                    }
                    if (appendSlash) {
                        strcat(scopedItem, "/");
                    }
                    corto_llAppend(result, corto_strdup(scopedItem));
                    i++;
                }
            }
        }

        if (!argc || !firstArgSpace) {
            if (!fnmatch(expr, "cd", 0)) corto_llAppend(result, corto_strdup ("cd"));
            if (!fnmatch(expr, "ls", 0)) corto_llAppend(result, corto_strdup ("ls"));
            if (!fnmatch(expr, "tree", 0)) corto_llAppend(result, corto_strdup ("tree"));
            if (!fnmatch(expr, "delete", 0)) corto_llAppend(result, corto_strdup ("delete"));
            if (!fnmatch(expr, "import", 0)) corto_llAppend(result, corto_strdup ("import"));
            if (!fnmatch(expr, "exit", 0)) corto_llAppend(result, corto_strdup ("exit"));
            if (!fnmatch(expr, "clear", 0)) corto_llAppend(result, corto_strdup ("clear"));
            if (!fnmatch(expr, "help", 0)) corto_llAppend(result, corto_strdup ("help"));
        }
    }

    return result;
error:
    corto_llFree(result);
    corto_error("%s", corto_lasterr());
    return NULL;
}

/* Execute command */
int cxsh_command(int argc, char* argv[], char *cmd) {
    return cxsh_doCmd(argc, argv, cmd);
}

/* Count number of results from select */
corto_uint32 cxsh_countSelect(char *expr) {
    corto_uint32 result = 0;
    corto_iter iter;
    if (corto_select(scope, expr).iter(&iter)) goto error;
    while (corto_iter_hasNext(&iter)) {
        corto_iter_next(&iter);
        result++;
        break;
    }
    corto_iter_release(&iter);
    if (!result) {
        if (corto_select("corto/lang", expr).iter(&iter)) goto error;
        while (corto_iter_hasNext(&iter)) {
            corto_iter_next(&iter);
            result++;
            break;
        }
        corto_iter_release(&iter);
    }
    if (!result) {
        if (corto_select("corto", expr).iter(&iter)) goto error;
        while (corto_iter_hasNext(&iter)) {
            corto_iter_next(&iter);
            result++;
            break;
        }
        corto_iter_release(&iter);
    }

    return result;
error:
    return 0;
}

/* Print command */
int cxsh_printCommand(char* buff) {
    if (!strcmp(buff, "cd") ||
      !strcmp(buff, "ls") ||
      !strcmp(buff, "tree") ||
      !strcmp(buff, "exit") ||
      !strcmp(buff, "import") ||
      !strcmp(buff, "delete") ||
      !strcmp(buff, "help") ||
      !strcmp(buff, "clear")) {
        printf("%s%s%s", CORTO_BOLD, buff, CORTO_NORMAL);
        return 1;
    } else {
        return 0;
    }
}

/* Print single object */
void cxsh_printObject(char *expr, char *str) {
    corto_uint32 count = cxsh_countSelect(expr);
    if (count) {
        printf("%s%s%s", CORTO_CYAN, str, CORTO_NORMAL);
    } else {
        printf("%s", str);
    }
}

/* Print single object */
void cxsh_printMember(char *expr, char *str) {
    if (cxsh_exprType(expr)) {
        printf("%s%s%s", CORTO_BLUE, str, CORTO_NORMAL);
    } else {
        printf("%s", str);
    }
}

/* Color-code command */
void cxsh_print(const char *arg) {
    corto_id buff, expr;
    const char *ptr = arg;
    char *bptr = buff, *exprPtr = expr, ch;
    *exprPtr = '\0';
    corto_uint32 token = 0;
    corto_bool isMember = FALSE;

    for (; (ch = *ptr); ptr ++) {
        if ((ch == '/') ||
            (ch == ' ') ||
            (ch == '{') || (ch == '}') ||
            (ch == '.') ||
            (ch == ',') ||
            (ch == '"') ||
            (ch == '(') || (ch == ')') ||
            (ch == '[') || (ch == ']')) {

            *bptr = '\0';
            if (token || !cxsh_printCommand(buff)) {
                if (isMember) {
                    cxsh_printMember(expr, buff);
                } else {
                    cxsh_printObject(expr, buff);
                }
            }
            if (ch == '/') {
                printf("%s%c%s", CORTO_CYAN, ch, CORTO_NORMAL);
            } else {
                printf("%s%c%s", CORTO_BOLD, ch, CORTO_NORMAL);
            }

            bptr = buff;
            token++;
        } else if ((bptr == buff) && isdigit(ch)) {
            printf("%s%c%s", CORTO_GREEN, ch, CORTO_NORMAL);
            bptr = buff;
            token++;
        } else {
            *bptr++ = ch;
        }
        if ((ch == ' ') || (ch == '{')) {
            exprPtr = expr;
        } else {
            *exprPtr++ = ch;
        }
        *exprPtr = '\0';
    }
    *bptr = '\0';
    *exprPtr = '\0';
    if (token || !cxsh_printCommand(buff)) {
      if (isMember) {
          cxsh_printMember(expr, buff);
      } else {
          cxsh_printObject(expr, buff);
      }
    }
}

/* Shell */
static void cxsh_shell(void) {
    corto_bool quit;
    corto_id prompt;

    quit = FALSE;

    while (!quit) {
        /* Set prompt */
        cxsh_prompt(TRUE, prompt);
        corto_shellEngine_prompt(prompt);

        /* Read input */
        if (corto_shellEngine_readInput(
          cxsh_print,
          (corto_commandCallback)cxsh_command,
          cxsh_shellExpand)) {
            quit = TRUE;
        }
    }
}

corto_int16 cortotool_shell(int argc, char* argv[]) {
    int i, bs;

    corto_errfmt("%k: %f:%l: %c: %m");

    cxsh_color(SHELL_COLOR);
    printf("corto shell - type 'help' for instructions.\n");
    cxsh_color(CORTO_NORMAL);

    /* Parse arguments */
    for(i=1; i<argc; i++) {
        if (!strcmp(argv[i], "-d")) {
            CORTO_DEBUG_ENABLED = TRUE;
        } else {
            corto_load(argv[i], argc-i, &argv[i]);
            break;
        }
    }

    for (i = 0; i < 3; i ++) {
        for (bs = 0; bs < 6; bs ++) {
            printf("\b");
        }
        printf("%s<%s%*s>%s ", CORTO_GREEN, CORTO_CYAN, i, "", CORTO_NORMAL);
        fflush(stdout);
        corto_sleep(0, 40000000);
    }

    for (bs = 0; bs < 6; bs ++) {
        printf("\b");
    }

    /* Set scope to root */
    strcpy(scope, "/");
    cxsh_shell();

    return 0;
}

void cortotool_shellHelp(void) {
    printf("Usage: corto shell [files] [packages]\n");
    printf("\n");
    printf("Start the corto shell. You can provide additional files or\n");
    printf("packages to load.\n");
    printf("\n");
}
