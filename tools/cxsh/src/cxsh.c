/*
 * cxsh.c
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#include "cortex.h"
#include "cx_convert.h"
#include "cx_string_ser.h"
#include "cx_metawalk.h"
#include "cx_class.h"
#include "cx_loader.h"
#include "cx_err.h"

#define CXSH_CMD_MAX (1024)

#define CXSH_COL_NAME     (38)
#define CXSH_COL_TYPE     (22)
#define CXSH_COL_STATE    (12)
#define CXSH_COL_ATTR     (8)
#define CXSH_COL_TOTAL    (CXSH_COL_NAME + CXSH_COL_TYPE + CXSH_COL_STATE + CXSH_COL_ATTR)

#define BLACK  "\033[1;30m"
#define RED    "\033[1;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE   "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN   "\033[1;36m"
#define WHITE  "\033[1;37m"
#define NORMAL "\033[0;49m"
#define BOLD   "\033[1;30m"
#define GREY  "\033[0;37m"

#define SHELL_COLOR (BOLD)
#define ERROR_COLOR (RED)
#define TYPE_COLOR (GREEN)
#define OBJECT_COLOR (BLUE)
#define META_COLOR (MAGENTA)
#define INTERFACE_COLOR (BOLD)
#define HEADER_COLOR (BOLD)

static cx_object scope = NULL;

/* Print color */
static void cxsh_color(const char *string) {
    printf("%s", string);
}

/* Print a column of certain length */
static void cxsh_printColumn(cx_string str, int width){
    printf("%s%*s", str, (int)(width - strlen(str)), " ");
}

/* Find preferred character on which to break a string, in case it's too long
 * to fit on one column */
static cx_string cxsh_findPreferredBreak(cx_string str) {
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

static cx_string cxsh_printColumnValue(cx_string str, unsigned int width){
    cx_string result = NULL;
    if (strlen(str) < (width - 2)) {
        printf("%s%*s", str, (int)(width - strlen(str)), " ");
    } else {
        cx_id buffer;
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

static void cxsh_printColumnBar(int width) {
    while(width) {
        printf("=");
        width--;
    }
    printf("\n");
}

static void cxsh_printColumnHeader(void) {
    printf("  ");
    cxsh_printColumn("name", CXSH_COL_NAME);
    cxsh_printColumn("type", CXSH_COL_TYPE);
    cxsh_printColumn("state", CXSH_COL_STATE);
    cxsh_printColumn("attr", CXSH_COL_ATTR);
    cxsh_color(INTERFACE_COLOR);
    printf("\n");
    cxsh_printColumnBar(CXSH_COL_TOTAL);
    cxsh_color(NORMAL);
}

/* Print shell prompt */
static void cxsh_prompt(cx_object scope, int enableColors, cx_id prompt) {
    cx_id name;
    cx_fullname(scope, name);
    if (enableColors) {
        sprintf(prompt, "%s%s%s %s$%s ", OBJECT_COLOR, name, NORMAL, SHELL_COLOR, NORMAL);
    } else {
        sprintf(prompt, "%s $ ", name);
    }
}

/* Translate object state to string */
static char* cxsh_stateStr(cx_object o, char* buff) {
    buff[0] = '\0';

    /* Get state */
    if (cx_checkState(o, CX_VALID)) {
       strcpy(buff, "V");
    }
    if (cx_checkState(o, CX_DECLARED)) {
       strcat(buff, "|DCL");
    }
    if (cx_checkState(o, CX_DEFINED)) {
       strcat(buff, "|DEF");
    }

    return buff;
}

/* Translate object attributes to string */
static char* cxsh_attrStr(cx_object o, char* buff) {
    cx_bool first;
    *buff = '\0';

    first = TRUE;
    if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
        strcat(buff, "S");
        first = FALSE;
    }
    if (cx_checkAttr(o, CX_ATTR_WRITABLE)) {
        if (!first) {
            strcat(buff, "|W");
        } else {
            strcat(buff, "W");
            first = FALSE;
        }
    }
    if (cx_checkAttr(o, CX_ATTR_OBSERVABLE)) {
        if (!first) {
            strcat(buff, "|O");
        } else {
            strcat(buff, "O");
        }
    }
    return buff;
}

static int cxsh_scopeWalk(cx_object o, void* udata) {
    cx_id typeName;
    cx_string remaining = 0;
    char state[sizeof("valid | declared | defined")];
    char attr[sizeof("scope | writable | observable")];

    CX_UNUSED(udata);

    /* Get name of type */
    if(cx_parentof(cx_typeof(o)) == cortex_lang_o) {
        strcpy(typeName, cx_nameof(cx_typeof(o)));
    } else {
        cx_fullname(cx_typeof(o), typeName);
    }

    /* Print columns */
    printf("  ");
    cxsh_color(OBJECT_COLOR); remaining = cxsh_printColumnValue(cx_nameof(o), CXSH_COL_NAME); cxsh_color(NORMAL);
    cxsh_color(TYPE_COLOR); cxsh_printColumnValue(typeName, CXSH_COL_TYPE); cxsh_color(NORMAL);
    cxsh_color(META_COLOR);
    cxsh_printColumnValue(cxsh_stateStr(o, state), CXSH_COL_STATE);
    cxsh_printColumnValue(cxsh_attrStr(o, attr), CXSH_COL_ATTR);
    cxsh_color(NORMAL);
    printf("\n");

    /* Print remainder of the name */
    while (remaining) {
        cxsh_color(OBJECT_COLOR);
        printf("    ");
        remaining = cxsh_printColumnValue(remaining, CXSH_COL_NAME - 4);
        cxsh_color(NORMAL);
        printf("\n");
    }
    return 1;
}

/* List scope */
static void cxsh_ls(char* arg) {
    cx_rbtree _scope;
    cx_object o;

    if (arg && strlen(arg)) {
        o = cx_resolve(scope, arg);
        if (!o) {
            cxsh_color(ERROR_COLOR);
            cx_error("expression '%s' did not resolve to object.", arg);
            cxsh_color(NORMAL);
            return;
        }
    } else {
        o = scope;
        cx_keep(o);
    }

    /* Get scope */
    _scope = cx_scopeof(o);

    /* Print column header */
    cxsh_printColumnHeader();

    if (_scope && cx_rbtreeSize(_scope)) {
        /* Walk scope, print contents */
        cx_rbtreeWalk(_scope, cxsh_scopeWalk, NULL);

        if (cx_rbtreeSize(_scope) == 1) {
            printf("total: %d object\n", cx_rbtreeSize(_scope));
        } else {
            printf("total: %d objects\n", cx_rbtreeSize(_scope));
        }
    } else {
        printf("no objects.\n");
    }

    cx_free(o);
}

typedef struct cxsh_treeWalk_t {
    cx_uint8 indent;
    cx_uint32 count;
}cxsh_treeWalk_t;

/* Walk object-hierarchy */
static int cxsh_treeWalk(cx_object o, void* userData) {
    cxsh_treeWalk_t* data;

    data = userData;

    data->count++;

    /* Limit name-buffer to local scope */
    {
        cx_id id1;
        cx_rbtree scope;
        cx_string name;

        scope = cx_scopeof(o);

        /* Indentation */
        if (*(cx_uint8*)userData) {
            printf("%*s", data->indent * 2, "");
        }

        /* Object */
        name = cx_nameof(o);
        if (cx_parentof(cx_typeof(o)) == cortex_lang_o) {
            printf("%s%s%s %s", TYPE_COLOR, cx_nameof(cx_typeof(o)), NORMAL, name?name:"");
        } else {
            printf("%s%s%s %s", TYPE_COLOR, cx_fullname(cx_typeof(o), id1), NORMAL, name?name:"");
        }

        /* Scope operator */
        if (scope && cx_rbtreeSize(scope)) {
            printf("%s::%s\n", BOLD, NORMAL);
        } else {
            printf("\n");
        }
    }

    /* Do recursive scopewalk */
    data->indent++;
    cx_scopeWalk(o, cxsh_treeWalk, userData);
    data->indent--;

    return 1;
}

/* Print object hierarchy */
static void cxsh_tree(char* arg) {
    cx_object o;
    cxsh_treeWalk_t walkData;

    if (arg && strlen(arg)) {
        o = cx_resolve(scope, arg);
        if (!o) {
            cxsh_color(ERROR_COLOR);
            cx_error("expression '%s' did not resolve to object.", arg);
            cxsh_color(NORMAL);
            return;
        }
    } else {
        o = scope;
        cx_keep(o);
    }

    walkData.indent = 0;
    walkData.count = 0;
    cxsh_treeWalk(o, &walkData);

    printf("total: %d objects.\n", walkData.count);

    cx_free(o);
}

/* Navigate scopes */
static void cxsh_cd(char* arg) {
    cx_object o;
    cx_object oldScope;

    oldScope = scope;

    if (!strlen(arg)) {
        scope = root_o;
        cx_keep(scope);
    } else if (!strcmp(arg, "..")) {
        if (cx_parentof(scope)) {
            scope = cx_parentof(scope);
        } else {
            cxsh_color(ERROR_COLOR);
            cx_error("scope is root.");
            cxsh_color(NORMAL);
            return;
        }
        cx_keep(scope);
    } else {
        o = cx_resolve(scope, arg);
        if (o) {
            scope = o;
        } else {
            cxsh_color(ERROR_COLOR);
            cx_error("expression '%s' did not resolve to object.", arg);
            cxsh_color(NORMAL);
            return;
        }
    }

    cx_free(oldScope);
}

cx_bool cxsh_readline(cx_string cmd) {
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

static cx_string cxsh_multiline(cx_string expr, cx_uint32 indent) {
    char cmd[CXSH_CMD_MAX];
    unsigned int len = strlen(expr);
    unsigned int multiline = 0;

    if (expr[len-1] == ':') {
        unsigned int cmdLen = 0;
        cx_id prompt;
        cxsh_prompt(scope, FALSE, prompt);
        multiline = 1;

        do {
            cx_uint32 i;
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
            expr = cx_realloc(expr, len + cmdLen + 1 + 1 + (indent * 4));
            strcat(expr, "\n");

            /* Insert indent */
            {
                char indentStr[CXSH_CMD_MAX];
                memset(indentStr, ' ', indent * 4);
                indentStr[indent * 4] = '\0';
                strcat(expr, indentStr);
            }
            strcat(expr, cmd);

            /*  cmd can be a nested multiline expression */
            expr = cxsh_multiline(expr, indent + 1);
            len = strlen(expr);
        } while (cmdLen);
    }

    if (multiline && (indent == 1)) {
        expr = cx_realloc(expr, len + 1 + 1);
        strcat(expr, "\n");
    }

    return expr;
}

/* Show expression */
static int cxsh_show(char* object) {
    cx_id id;
    char state[sizeof("valid | declared | defined")];
    char attr[sizeof("scope | writable | observable")];
    struct cx_serializer_s s;
    cx_string_ser_t sdata;
    cx_value result;
    char *expr = object;

    memset(&result, 0, sizeof(cx_value));

    cx_toggleEcho(FALSE);

    /* Check whether this is a multiline expression */
    expr = cxsh_multiline(cx_strdup(object), 1);

    if (!cx_expr(scope, expr, &result)) {
        cx_object o = NULL;
        if (result.kind == CX_OBJECT) {
            o = cx_valueObject(&result);
        }

        /* Initialize serializer userData */
        s = cx_string_ser(CX_PRIVATE, CX_NOT, CX_SERIALIZER_TRACE_ON_FAIL);
        memset(&sdata, 0, sizeof(cx_string_ser_t));
        sdata.enableColors = TRUE;

        /* Print object properties */
        if (o) {
            if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
                printf("%sname:%s         %s%s%s\n", INTERFACE_COLOR, NORMAL, OBJECT_COLOR, cx_fullname(o, id), NORMAL);
                printf("%sparent:       %s%s%s\n", INTERFACE_COLOR, OBJECT_COLOR, cx_fullname(cx_parentof(o), id), NORMAL);
            }            
            printf("%sstate:%s        %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, cxsh_stateStr(o, state), NORMAL);
            printf("%sattributes:%s   %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, cxsh_attrStr(o, attr), NORMAL);
            printf("%stype:%s         %s%s%s\n", INTERFACE_COLOR, NORMAL, OBJECT_COLOR, cx_fullname(cx_valueType(&result), id), NORMAL);
        }

        /* Serialize value to string */
        cx_serializeValue(&s, &result, &sdata);
        if (sdata.buffer) {
            if (o) {
                printf("%svalue:%s        ", INTERFACE_COLOR, NORMAL);
            }
            printf("%s\n", sdata.buffer);

            cx_dealloc(sdata.buffer);
            sdata.buffer = NULL;
            sdata.ptr = NULL;
        }

        /* If object is a type, do a metawalk with the string-serializer */
        if (o) {
            if (cx_class_instanceof(cx_type_o, o) && cx_checkState(o, CX_DEFINED)) {
                s.access = CX_LOCAL | CX_READONLY | CX_PRIVATE;
                s.accessKind = CX_NOT;
                cx_metaWalk(&s, o, &sdata);
                if (sdata.buffer) {
                    printf("%sinitializer:%s     %s\n", INTERFACE_COLOR, NORMAL, sdata.buffer);
                    cx_dealloc(sdata.buffer);
                }
            }
            printf("\n");
        }
        cx_dealloc(expr);
        cx_toggleEcho(TRUE);
        return 0;
    } else {
        cx_dealloc(expr);
        cx_toggleEcho(TRUE);
        return -1;
    }
}

/* Import file */
static void cxsh_import(char* file) {
    cx_load(file);
}

/* Drop scope */
static void cxsh_drop(char* name) {
    cx_object o;

    o = cx_resolve(scope, name);
    if (o) {
        cx_drop(o);
        cx_free(o);
    } else {
        cxsh_color(ERROR_COLOR);
        cx_error("expression '%s' did not resolve to object.", scope);
        cxsh_color(NORMAL);
    }
}

static void cxsh_help(void) {
    printf("%sCortex shell help%s\n", HEADER_COLOR, NORMAL);
    printf("\n");
    printf("Use cortex-expressions to read or modify data in the cortex database.\n");
    printf("If the expression resolves to an object the shell will display the object\n");
    printf("and its metadata. If shell-commands conflict with an objectname prefix the\n");
    printf("command with an '\\'.\n");
    printf("\n");
    printf("%sAvailable commands:%s\n", HEADER_COLOR, NORMAL);
    printf("  %sls [scope]%s\n", HEADER_COLOR, NORMAL);
    printf("      List contents of a scope. If no scope is provided the\n");
    printf("      contents of the current scope is listed.\n");
    printf("  %stree [scope]%s\n", HEADER_COLOR, NORMAL);
    printf("      Lists contents of a scope recursively. If no scope is\n");
    printf("      provided the current scope is listed.\n");
    printf("  %scd [scope]%s\n", HEADER_COLOR, NORMAL);
    printf("      Change current scope to specified scope.\n");
    printf("  %simport [file]%s\n", HEADER_COLOR, NORMAL);
    printf("      Load a file into the database. The file can be of any type\n");
    printf("      that is supported by cortex.\n");
    printf("  %sclear%s\n", HEADER_COLOR, NORMAL);
    printf("      Clears the screen.\n");
    printf("  %sexit%s\n", HEADER_COLOR, NORMAL);
    printf("      Exit database shell.\n");
    printf("\n");
    printf("%sExamples:%s\n", HEADER_COLOR, NORMAL);
    printf("  %s$%s ls cortex::lang\n", SHELL_COLOR, NORMAL);
    printf("      List objects in scope 'cortex::lang'\n");
    printf("  %s$%s cortex::lang::class\n", SHELL_COLOR, NORMAL);
    printf("      Display object 'cortex::lang::class'\n");
    printf("\n");
}

int cxsh_getErrorLocation(cx_string str) {
    int result = 0;

    /* Only give location when on the first line */
    if ((str[0] == '1') && (str[1] == ':')) {
        str += 2;
        result = atoi(str);
    }

    return result;
}

static int cxsh_doCmd(char* cmd) {
    char arg[CXSH_CMD_MAX];

    arg[0] = '\0';

    /* ls */
    if (!memcmp(cmd, "ls", strlen("ls"))) {
        sscanf(cmd, "ls  %s", arg);
        cxsh_ls(arg);
    } else
    /* tree */
    if (!memcmp(cmd, "tree", strlen("tree"))) {
        sscanf(cmd, "tree %s", arg);
        cxsh_tree(arg);
    } else
    /* exit */
    if (!memcmp(cmd, "exit", strlen("exit"))) {
        goto quit;
    } else
    /* cd */
    if (!memcmp(cmd, "cd", strlen("cd"))) {
        sscanf(cmd, "cd %s", arg);
        cxsh_cd(arg);
    } else
    /* import */
    if (!memcmp(cmd, "import", strlen("import"))) {
        sscanf(cmd, "import %s", arg);
        cxsh_import(arg);
    } else/* drop */
    if (!memcmp(cmd, "drop", strlen("drop"))) {
        sscanf(cmd, "drop %s", arg);
        cxsh_drop(arg);
    } else if (!memcmp(cmd, "clear", strlen("clear"))) {
        system("clear");
    } else if (!memcmp(cmd, "help", strlen("help"))) {
        cxsh_help();
    } else {
        cx_char *lastErr;
        if ((lastErr = cx_lasterror())) {
            unsigned int location = 0;
            cxsh_color(ERROR_COLOR);

            /* If lastError starts with a line:column: indication, print an arrow */
            if ((location = cxsh_getErrorLocation(lastErr))) {
                cx_id prompt;
                cxsh_prompt(scope, FALSE, prompt);
                printf("%*s^\n", location - 1 + (unsigned int)strlen(prompt), "");
            }

            do {
                cx_print("%s", lastErr);
            } while ((lastErr = cx_lasterror()));

            cxsh_color(NORMAL);
        } else {
            cxsh_color(ERROR_COLOR);
            cx_print("expression '%s' did not resolve to a valid expression or command", cmd);
            cxsh_color(NORMAL);
        }
    }

    return 0;
quit:
    return 1;
}

/* Shell */
static void cxsh_shell(void) {
    char cmd[CXSH_CMD_MAX];
    cx_bool quit;
    cx_id prompt;

    quit = FALSE;

    while(!quit) {
        /* Print prompt */
        cxsh_prompt(scope, TRUE, prompt);
        printf("%s", prompt);

        if (!cxsh_readline(cmd)) {
            continue;
        }

        /* Forward commands */
        if (strlen(cmd)) {
            if (cmd[0] == '/') {
                if (cxsh_doCmd(cmd+1)) {
                    quit = TRUE;
                }
            } else {
                if (cxsh_show(cmd)) {
                    if (cxsh_doCmd(cmd)) {
                        quit = TRUE;
                    }
                }
            }
        }
    }
}


int main(int argc, char* argv[]) {
    int i;

    /* Start database */
    cx_start();

    cxsh_color(SHELL_COLOR);
    printf("cortex shell - type 'help' for instructions.\n");
    cxsh_color(NORMAL);

    /* Parse arguments */
    for(i=1; i<argc; i++) {
        cx_load(argv[i]);
    }

    /* Assign scope to root */
    scope = root_o;
    cx_keep(root_o); /* Keep scope */

    cxsh_shell();

    cx_free(scope); /* Free scope */

    /* Stop database */
    cx_stop();

    return 0;
}
