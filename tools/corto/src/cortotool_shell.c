/*
 * corto_shell.c
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#include "cortotool_shell.h"
#include "cortotool_shellengine.h"
#include "ctype.h"
#include "fnmatch.h"

#define CXSH_CMD_MAX (1024)

#define CXSH_COL_NAME     (46)
#define CXSH_COL_ID       (18)
#define CXSH_COL_TYPE     (32)
#define CXSH_COL_TOTAL    (CXSH_COL_NAME + CXSH_COL_TYPE)

#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define GREY    "\033[0;37m"
#define NORMAL  "\033[0;49m"
#define BOLD    "\033[1;49m"

#define SHELL_COLOR (BOLD)
#define ERROR_COLOR (RED)
#define TYPE_COLOR (MAGENTA)
#define OBJECT_COLOR (CYAN)
#define META_COLOR (MAGENTA)
#define INTERFACE_COLOR (BOLD)
#define HEADER_COLOR (BOLD)

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
        sprintf(prompt, "%s%s%s %s$%s ", OBJECT_COLOR, scope, NORMAL, SHELL_COLOR, NORMAL);
    } else {
        sprintf(prompt, "%s $ ", scope);
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

static int cxsh_printRow(corto_string parent, corto_string id, corto_string name, corto_string type) {
    corto_string remaining = 0;
    corto_string objcolor = OBJECT_COLOR;
    corto_uint32 colId = CXSH_COL_ID;

    /* Print columns */
    cxsh_color(objcolor);
    if (strcmp(parent, scope) && strcmp(parent, ".")) {
        printf("%s/", parent);
        colId -= strlen(parent) + 1;
    }
    cxsh_printColumnValue(id, colId);
    cxsh_color(NORMAL);
    remaining = cxsh_printColumnValue(name, CXSH_COL_NAME);
    cxsh_color(TYPE_COLOR); printf("%s", type); cxsh_color(NORMAL);
    printf("\n");

    /* Print remainder of the name */
    while (remaining) {
        printf("%*s    ", CXSH_COL_ID, " ");
        remaining = cxsh_printColumnValue(remaining, CXSH_COL_NAME - 4);
        printf("\n");
    }

    return 1;
}

/* List scope */
static void cxsh_ls(char* arg) {
    corto_uint32 i = 0;
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

    while (corto_iterHasNext(&iter)) {
        corto_result *item = corto_iterNext(&iter);
        cxsh_printRow(item->parent, item->id, item->name, item->type);
        i ++; /* Count objects so total can be printed */
    }

    if (!i) {
        corto_info("  no objects.");
    } else if (i > 1) {
        corto_info("  %d objects\n", i);
    } else {
        corto_info("  %d object\n", i);
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
        while (corto_iterHasNext(&iter)) {
            corto_result *e = corto_iterNext(&iter);

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
            cxsh_color(BLUE);
            for(i = 0; i < (indent * 4 - 1); i++) {
                printf(".");
            }
            cxsh_color(NORMAL);
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
    struct corto_serializer_s s;
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

    if (!corto_expr(scope_o, expr, &result)) {
        corto_object o = NULL;
        if (result.kind == CORTO_OBJECT) {
            o = corto_value_getObject(&result);
        }

        /* Release scope as soon as possible */
        corto_release(scope_o);

        /* Print object properties */
        if (o) {
            if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
                if (o == root_o) {
                    printf("%sname:%s         %s/%s\n",
                      INTERFACE_COLOR, NORMAL, OBJECT_COLOR, NORMAL);
                } else {
                    printf("%sname:%s         %s%s%s\n",
                      INTERFACE_COLOR,
                      NORMAL,
                      OBJECT_COLOR,
                      corto_idof(o),
                      NORMAL);
                }
                if (o != root_o) {
                    char *parentPtr = corto_fullpath(id, corto_parentof(o));
                    if (strcmp(parentPtr, "/")) {
                        parentPtr += 1;
                    }
                    printf("%sparent:       %s%s%s\n",
                      INTERFACE_COLOR, OBJECT_COLOR,
                      parentPtr,
                      NORMAL);
                }
            }
            if (corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
                corto_object owner = corto_ownerof(o);

                if (corto_checkState(o, CORTO_DEFINED)) {
                    printf("%sowner:%s        %s%s\n",
                        INTERFACE_COLOR,
                        OBJECT_COLOR,
                        owner ? corto_fullpath(NULL, owner) : "<this>",
                        NORMAL);
                }
            }
            if (corto_checkState(o, CORTO_VALID)) {
                printf("%sstate:%s        %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, cxsh_stateStr(o, state), NORMAL);
            } else {
                printf("%sstate:        %s%s\n", RED, cxsh_stateStr(o, state), NORMAL);
            }
            printf("%sattributes:%s   %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, cxsh_attrStr(o, attr), NORMAL);
            printf("%stype:%s         %s%s%s\n", INTERFACE_COLOR, NORMAL, OBJECT_COLOR,
                corto_fullpath(NULL, corto_value_getType(&result)), NORMAL);
        }

        /* Initialize serializer userData */
        s = corto_string_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
        memset(&sdata, 0, sizeof(corto_string_ser_t));
        sdata.enableColors = TRUE;
        s.access = CORTO_PRIVATE;
        s.accessKind = CORTO_NOT;
        s.aliasAction = CORTO_SERIALIZER_ALIAS_IGNORE;
        s.optionalAction = CORTO_SERIALIZER_OPTIONAL_IF_SET;

        /* Serialize value to string */
        if (corto_value_getPtr(&result)) {
            corto_serializeValue(&s, &result, &sdata);
            corto_string str = corto_buffer_str(&sdata.buffer);
            if (str) {
                if (o) {
                    printf("%svalue:%s        ", INTERFACE_COLOR, NORMAL);
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
                s.aliasAction = CORTO_SERIALIZER_ALIAS_IGNORE;
                s.optionalAction = CORTO_SERIALIZER_OPTIONAL_IF_SET;
                corto_metaWalk(&s, o, &sdata);
                corto_string str = corto_buffer_str(&sdata.buffer);
                if (str) {
                    printf("%sinitializer:%s     %s\n", INTERFACE_COLOR, NORMAL, str);
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
    printf("%sCorto shell help%s\n", HEADER_COLOR, NORMAL);
    printf("\n");
    printf("Use corto-expressions to read or modify data in the corto database.\n");
    printf("If the expression resolves to an object the shell will display the object\n");
    printf("and its metadata. If shell-commands conflict with an objectname prefix the\n");
    printf("command with an '\\'.\n");
    printf("\n");
    printf("%sAvailable commands:%s\n", HEADER_COLOR, NORMAL);
    printf("  %sls [expr]%s\n", HEADER_COLOR, NORMAL);
    printf("      Lists result of select expression. If no expression is\n");
    printf("      provided, ls lists the contents of the current scope.\n");
    printf("  %stree [scope]%s\n", HEADER_COLOR, NORMAL);
    printf("      Lists contents of a scope recursively. If no scope is\n");
    printf("      provided the current scope is listed.\n");
    printf("  %scd [scope]%s\n", HEADER_COLOR, NORMAL);
    printf("      Change current scope to specified scope.\n");
    printf("  %simport [file]%s\n", HEADER_COLOR, NORMAL);
    printf("      Load a file into the database. The file can be of any type\n");
    printf("      that is supported by corto.\n");
    printf("  %sclear%s\n", HEADER_COLOR, NORMAL);
    printf("      Clears the screen.\n");
    printf("  %sexit%s\n", HEADER_COLOR, NORMAL);
    printf("      Exit database shell.\n");
    printf("\n");
    printf("%sExamples:%s\n", HEADER_COLOR, NORMAL);
    printf("  %s$%s ls corto/lang\n", SHELL_COLOR, NORMAL);
    printf("      List objects in scope 'corto/lang'\n");
    printf("  %s$%s ls //w*\n", SHELL_COLOR, NORMAL);
    printf("      Lists all objects that start with the letter 'w'\n");
    printf("  %s$%s corto/lang/class\n", SHELL_COLOR, NORMAL);
    printf("      Display object 'corto/lang/class'\n");
    printf("  %s$%s class.base\n", SHELL_COLOR, NORMAL);
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

static int cxsh_doCmd(int argc, char* argv[], char *cmd) {
    CORTO_UNUSED(argc);

    /* ls */
    if (!strcmp(argv[0], "ls")) {
      cxsh_ls(argv[1]);
    } else
    /* exit */
    if (!strcmp(argv[0], "exit")) {
        printf("Bye!\n");
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
  corto_serializer s,
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
struct corto_serializer_s cxsh_memberSer(void) {
    struct corto_serializer_s s;

    corto_serializerInit(&s);

    s.access = CORTO_PRIVATE;
    s.accessKind = CORTO_NOT;
    s.traceKind = CORTO_SERIALIZER_TRACE_ON_FAIL;
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
                    struct corto_serializer_s ser = cxsh_memberSer();
                    corto_metaWalk(&ser, t, &walkData);

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
            while (corto_iterHasNext(&iter)) {
                corto_result *item = corto_iterNext(&iter);
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
                while (corto_iterHasNext(&iter)) {
                    corto_result *item = corto_iterNext(&iter);
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
                while (corto_iterHasNext(&iter)) {
                    corto_result *item = corto_iterNext(&iter);
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
    while (corto_iterHasNext(&iter)) {
        result++;
        break;
    }
    if (!result) {
        if (corto_select(scope, expr).iter(&iter)) goto error;
        while (corto_iterHasNext(&iter)) {
            corto_iterNext(&iter);
            result++;
            break;
        }
    }
    if (!result) {
        if (corto_select(scope, expr).iter(&iter)) goto error;
        while (corto_iterHasNext(&iter)) {
            corto_iterNext(&iter);
            result++;
            break;
        }
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
        printf("%s%s%s", BOLD, buff, NORMAL);
        return 1;
    } else {
        return 0;
    }
}

/* Print single object */
void cxsh_printObject(char *expr, char *str) {
    corto_uint32 count = cxsh_countSelect(expr);
    if (count) {
        printf("%s%s%s", CYAN, str, NORMAL);
    } else {
        printf("%s", str);
    }
}

/* Print single object */
void cxsh_printMember(char *expr, char *str) {
    if (cxsh_exprType(expr)) {
        printf("%s%s%s", BLUE, str, NORMAL);
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
                printf("%s%c%s", CYAN, ch, NORMAL);
            } else if (ch == '"') {
                printf("%s%c%s", RED, ch, NORMAL);
            } else {
                printf("%s%c%s", BOLD, ch, NORMAL);
            }

            bptr = buff;
            token++;

            if (ch == '"') {
                while ((ch = *(++ptr)) && (ch != '"')) {
                    *bptr = ch;
                    bptr++;
                }
                if (ch) {
                    *bptr = '"';
                    bptr++;
                }
                *bptr = '\0';
                printf("%s%s%s", RED, buff, NORMAL);
                bptr = buff;
            } else if (ch == '.') {
                isMember = TRUE;
            } else {
                isMember = FALSE;
            }
        } else if ((bptr == buff) && isdigit(ch)) {
            printf("%s%c%s", GREEN, ch, NORMAL);
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
    int i;

    cxsh_color(SHELL_COLOR);
    printf("corto shell - type 'help' for instructions.\n");
    cxsh_color(NORMAL);

    /* Start loader mount */
    corto_loader p = corto_create(corto_loader_o);
    if (!p) {
        corto_error("corto: failed to create package mount: %s", corto_lasterr());
    }

    /* Parse arguments */
    for(i=1; i<argc; i++) {
        if (!strcmp(argv[i], "-d")) {
            CORTO_DEBUG_ENABLED = TRUE;
        } else {
            corto_load(argv[i], argc-i, &argv[i]);
            break;
        }
    }

    /* Set scope to root */
    strcpy(scope, "/");
    cxsh_shell();

    /* Delete loader mount */
    if (p) {
        corto_delete(p);
    }

    return 0;
}

void cortotool_shellHelp(void) {
    printf("Usage: corto shell [files] [packages]\n");
    printf("\n");
    printf("Start the corto shell. You can provide additional files or\n");
    printf("packages to load.\n");
    printf("\n");
}
