/*
 * corto_shell.c
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#include "corto.h"
#include "corto_convert.h"
#include "corto_string_ser.h"
#include "corto_metawalk.h"
#include "corto_class.h"
#include "corto_loader.h"
#include "corto_err.h"
#include "cortotool_shellengine.h"

#define CXSH_CMD_MAX (1024)

#define CXSH_COL_NAME     (46)
#define CXSH_COL_TYPE     (32)
#define CXSH_COL_TOTAL    (CXSH_COL_NAME + CXSH_COL_TYPE)

#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[0;32m"
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

static corto_object scope = NULL;

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
static void cxsh_prompt(corto_object scope, int enableColors, corto_id prompt) {
    corto_id name;
    corto_fullname(scope, name);
    if (enableColors) {
        sprintf(prompt, "%s%s%s %s$%s ", OBJECT_COLOR, name, NORMAL, SHELL_COLOR, NORMAL);
    } else {
        sprintf(prompt, "%s $ ", name);
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

static int cxsh_printRow(corto_string parent, corto_string name, corto_string type) {
    corto_string remaining = 0;
    corto_string objcolor = OBJECT_COLOR;
    corto_int32 colName = CXSH_COL_NAME;

    /* Print columns */
    cxsh_color(objcolor);
    if (strcmp(parent, ".")) {
        printf("%s/", parent);
        colName -= strlen(parent) + 1;
    }
    remaining = cxsh_printColumnValue(name, colName);
    cxsh_color(NORMAL);
    cxsh_color(TYPE_COLOR); cxsh_printColumnValue(type, CXSH_COL_TYPE); cxsh_color(NORMAL);
    printf("\n");

    /* Print remainder of the name */
    while (remaining) {
        cxsh_color(objcolor);
        printf("    ");
        remaining = cxsh_printColumnValue(remaining, CXSH_COL_NAME - 4);
        cxsh_color(NORMAL);
        printf("\n");
    }
    return 1;
}

/* List scope */
static void cxsh_ls(char* arg) {
    corto_iter iter;
    corto_id buff;
    corto_uint32 i = 0;

    if (arg) {
        char lastCh = arg[strlen(arg) - 1];
        if ((lastCh != '/') && (lastCh != '.') && (lastCh != '*') && (lastCh != '?')) {
            sprintf(buff, "%s/*", arg);
        } else {
            strcpy(buff, arg);
        }
    } else {
        strcpy(buff, "*");
    }

    if (corto_select(scope, buff, &iter)) {
        corto_error("error: %s", corto_lasterr());
    } else {
        while (corto_iterHasNext(&iter)) {
            corto_selectItem *item = corto_iterNext(&iter);
            cxsh_printRow(item->parent, item->name, item->type);
            i ++;
        }

        if (!i) {
            corto_print("no objects.");
        } else if (i > 1) {
            corto_print("%d objects", i);
        } else {
            corto_print("%d object", i);
        }
    }
}

typedef struct cxsh_treeWalk_t {
    corto_uint8 indent;
    corto_uint32 count;
}cxsh_treeWalk_t;

/* Walk object-hierarchy */
static int cxsh_treeWalk(corto_object o, void* userData) {
    cxsh_treeWalk_t* data;

    data = userData;

    data->count++;

    /* Limit name-buffer to local scope */
    {
        corto_id id1;
        corto_string name;

        /* Indentation */
        if (*(corto_uint8*)userData) {
            printf("%*s", data->indent * 2, "");
        }

        /* Object */
        name = corto_nameof(o);
        if (corto_parentof(corto_typeof(o)) == corto_lang_o) {
            printf("%s%s%s %s", TYPE_COLOR, corto_nameof(corto_typeof(o)), NORMAL, name?name:"");
        } else {
            printf("%s%s%s %s", TYPE_COLOR, corto_fullname(corto_typeof(o), id1), NORMAL, name?name:"");
        }

        /* Scope operator */
        if (scope && corto_scopeSize(o)) {
            printf("%s::%s\n", BOLD, NORMAL);
        } else {
            printf("\n");
        }
    }

    /* Do recursive scopewalk */
    data->indent++;
    corto_scopeWalk(o, cxsh_treeWalk, userData);
    data->indent--;

    return 1;
}

/* Print object hierarchy */
static void cxsh_tree(char* arg) {
    corto_object o;
    cxsh_treeWalk_t walkData;

    if (arg && strlen(arg)) {
        o = corto_resolve(scope, arg);
        if (!o) {
            cxsh_color(ERROR_COLOR);
            corto_error("expression '%s' did not resolve to object.", arg);
            cxsh_color(NORMAL);
            printf("\n");
            return;
        }
    } else {
        o = scope;
        corto_claim(o);
    }

    walkData.indent = 0;
    walkData.count = 0;
    cxsh_treeWalk(o, &walkData);

    printf("total: %d objects.\n", walkData.count);

    corto_release(o);
}

/* Navigate scopes */
static void cxsh_cd(char* arg) {
    corto_object o;
    corto_object oldScope;

    oldScope = scope;
    if (!arg) {
        arg = "/";
    }

    if (!strlen(arg)) {
        scope = root_o;
        corto_claim(scope);
    } else if (!strcmp(arg, "..")) {
        if (corto_parentof(scope)) {
            scope = corto_parentof(scope);
        } else {
            cxsh_color(ERROR_COLOR);
            corto_error("scope is root.");
            cxsh_color(NORMAL);
            return;
        }
        corto_claim(scope);
    } else {
        o = corto_resolve(scope, arg);
        if (o) {
            scope = o;
        } else {
            cxsh_color(ERROR_COLOR);
            corto_error("expression '%s' did not resolve to object.", arg);
            cxsh_color(NORMAL);
            printf("\n");
            return;
        }
    }

    corto_release(oldScope);
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

    if (expr[len-1] == ':') {
        unsigned int cmdLen = 0;
        corto_id prompt;
        cxsh_prompt(scope, FALSE, prompt);
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

    memset(&result, 0, sizeof(corto_value));

    /* Check whether this is a multiline expression */
    expr = cxsh_multiline(corto_strdup(object), 1);

    if (!corto_expr(scope, expr, &result)) {
        corto_object o = NULL;
        if (result.kind == CORTO_OBJECT) {
            o = corto_valueObject(&result);
        }

        /* Print object properties */
        if (o) {
            if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
                if (o == root_o) {
                    printf("%sname:%s         %s/%s\n", INTERFACE_COLOR, NORMAL, OBJECT_COLOR, NORMAL);
                } else {
                    printf("%sname:%s         %s%s%s\n", INTERFACE_COLOR, NORMAL, OBJECT_COLOR, corto_nameof(o), NORMAL);
                }
                if (o != root_o) {
                    printf("%sparent:       %s%s%s\n", INTERFACE_COLOR, OBJECT_COLOR, corto_fullname(corto_parentof(o), id) + 1, NORMAL);
                }
            }
            if (corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
                corto_time t = corto_timestampof(o);
                corto_object owner = corto_ownerof(o);
                corto_id ownerId;
                printf("%stimestamp:%s    %d.%.9d%s\n", INTERFACE_COLOR, GREEN, t.tv_sec, t.tv_nsec, NORMAL);

                if (corto_checkState(o, CORTO_DEFINED)) {
                    printf("%sowner:%s        %s%s\n",
                        INTERFACE_COLOR,
                        OBJECT_COLOR,
                        owner ? corto_fullname(owner, ownerId) : "<this>",
                        NORMAL);
                }
            }
            if (corto_checkState(o, CORTO_VALID)) {
                printf("%sstate:%s        %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, cxsh_stateStr(o, state), NORMAL);
            } else {
                printf("%sstate:        %s%s\n", RED, cxsh_stateStr(o, state), NORMAL);
            }
            printf("%sattributes:%s   %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, cxsh_attrStr(o, attr), NORMAL);
            printf("%stype:%s         %s%s%s\n", INTERFACE_COLOR, NORMAL, OBJECT_COLOR, corto_fullname(corto_valueType(&result), id) + 1, NORMAL);
        }

        /* Initialize serializer userData */
        s = corto_string_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
        memset(&sdata, 0, sizeof(corto_string_ser_t));
        sdata.enableColors = TRUE;
        s.access = CORTO_PRIVATE;
        s.accessKind = CORTO_NOT;
        s.aliasAction = CORTO_SERIALIZER_ALIAS_IGNORE;

        /* Serialize value to string */
        corto_serializeValue(&s, &result, &sdata);
        if (sdata.buffer) {
            if (o) {
                printf("%svalue:%s        ", INTERFACE_COLOR, NORMAL);
            }
            printf("%s\n", sdata.buffer);

            corto_dealloc(sdata.buffer);
            sdata.buffer = NULL;
            sdata.ptr = NULL;
        }

        if (o) {
            if (corto_class_instanceof(corto_type_o, o) && corto_checkState(o, CORTO_DEFINED)) {
                s.access = CORTO_LOCAL | CORTO_READONLY | CORTO_PRIVATE | CORTO_HIDDEN;
                s.accessKind = CORTO_NOT;
                s.aliasAction = CORTO_SERIALIZER_ALIAS_FOLLOW;
                corto_metaWalk(&s, o, &sdata);
                if (sdata.buffer) {
                    printf("%sinitializer:%s     %s\n", INTERFACE_COLOR, NORMAL, sdata.buffer);
                    corto_dealloc(sdata.buffer);
                }
            }
            printf("\n");
        }

        corto_dealloc(expr);
        return 0;
    } else {
        corto_dealloc(expr);
        return -1;
    }
}

/* Import file */
static void cxsh_import(char* file) {
    corto_load(file, 0, NULL);
}

/* Drop scope */
static void cxsh_drop(char* name) {
    corto_object o;

    o = corto_resolve(scope, name);
    if (o) {
        corto_drop(o);
        corto_release(o);
    } else {
        cxsh_color(ERROR_COLOR);
        corto_error("expression '%s' did not resolve to object.", scope);
        cxsh_color(NORMAL);
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
    /* tree */
    if (!strcmp(argv[0], "tree")) {
        cxsh_tree(argv[1]);
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
    if (!strcmp(argv[0], "drop")) {
        cxsh_drop(argv[1]);
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

        if (*cmd == '/') {
            cmd++;
        }

        if (cxsh_show(cmd)) {
            if ((lastErr = corto_lasterr())) {
                unsigned int location = 0;

                /* If lastError starts with a line:column: indication, print an arrow */
                if ((location = cxsh_getErrorLocation(lastErr))) {
                    corto_id prompt;
                    cxsh_prompt(scope, FALSE, prompt);
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

/* Return result for TAB expansion */
corto_ll cxsh_shellExpand(int argc, char* argv[], char *cmd) {
    corto_ll result = corto_llNew();
    corto_iter iter;
    corto_id expr;

    /* If there is no space between command and first
     * arg, space must be inserted */
    corto_bool firstArgSpace =
      argc == 1 ? cmd[strlen(cmd) - 1] == ' ' : TRUE;

    /* For selection of scopes, auto-append a '/' */
    corto_bool appendSlash = FALSE;

    /* Is expression resolving a member? */
    corto_bool resolveMember = FALSE;

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
        if (resolveMember) {
        } else {
            corto_select(scope, expr, &iter);
            while (corto_iterHasNext(&iter)) {
                corto_selectItem *item = corto_iterNext(&iter);
                corto_id scopedItem;
                if (strcmp(item->parent, ".")) {
                    sprintf(scopedItem, "%s/%s", item->parent, item->name);
                } else {
                    strcpy(scopedItem, item->name);
                }
                if (appendSlash) {
                    strcat(scopedItem, "/");
                }
                corto_llAppend(result, corto_strdup(scopedItem));
            }
        }
    }

    return result;
}

/* Execute command */
int cxsh_command(int argc, char* argv[], char *cmd) {
    return cxsh_doCmd(argc, argv, cmd);
}

/* Shell */
static void cxsh_shell(void) {
    corto_bool quit;
    corto_id prompt;

    quit = FALSE;

    while (!quit) {
        /* Set prompt */
        cxsh_prompt(scope, TRUE, prompt);
        corto_shellEngine_prompt(prompt);

        /* Read input */
        if (corto_shellEngine_readInput(cxsh_command, cxsh_shellExpand)) {
            quit = TRUE;
        }
    }
}

int cortotool_shell(int argc, char* argv[]) {
    int i;

    cxsh_color(SHELL_COLOR);
    printf("corto shell - type 'help' for instructions.\n");
    cxsh_color(NORMAL);

    /* Parse arguments */
    for(i=1; i<argc; i++) {
        if (!strcmp(argv[i], "-d")) {
            CORTO_DEBUG_ENABLED = TRUE;
        } else {
            corto_load(argv[i], argc-i, &argv[i]);
            break;
        }
    }

    /* Assign scope to root */
    scope = root_o;
    corto_claim(root_o); /* Keep scope */

    cxsh_shell();

    corto_release(scope); /* Free scope */

    return 0;
}

void cortotool_shellHelp(void) {
    printf("Usage: corto shell [files] [packages]\n");
    printf("\n");
    printf("Start the corto shell. You can provide additional files or\n");
    printf("packages to load.\n");
    printf("\n");
}
