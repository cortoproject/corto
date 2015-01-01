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

#define CXSH_COL_NAME     (32)
#define CXSH_COL_TYPE     (32)
#define CXSH_COL_STATE    (15)
#define CXSH_COL_ATTR     (10)
#define CXSH_COL_TOTAL      (CXSH_COL_NAME + CXSH_COL_TYPE + CXSH_COL_STATE + CXSH_COL_ATTR)

#define BLACK  "\033[1;30m"
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE   "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN   "\033[1;36m"
#define WHITE  "\033[1;37m"
#define NORMAL "\033[0;49m"
#define BOLD   "\033[1;30m"

#define SHELL_COLOR (BOLD)
#define ERROR_COLOR (RED)
#define TYPE_COLOR (BLUE)
#define OBJECT_COLOR (BLUE)
#define META_COLOR (MAGENTA)
#define INTERFACE_COLOR (BOLD)
#define HEADER_COLOR (WHITE)

static cx_object scope = NULL;

static void cxsh_color(const char *string) {
    printf("%s", string);
}

static void cxsh_printColumn(cx_string str, int width){
    printf("%s%*s", str, (int)(width - strlen(str)), " ");
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
static void cxsh_prompt(cx_object scope) {
    cx_id id;
    cx_fullname(scope, id);

    printf("%s%s%s %s$%s ", OBJECT_COLOR, id, NORMAL, SHELL_COLOR, NORMAL);
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
    char state[sizeof("valid | declared | defined")];
    char attr[sizeof("scope | writable | observable")];

    CX_UNUSED(udata);

    /* Get name of type */
    cx_fullname(cx_typeof(o), typeName);

    /* Print columns */
    printf("  ");
    cxsh_color(OBJECT_COLOR); cxsh_printColumn(cx_nameof(o), CXSH_COL_NAME); cxsh_color(NORMAL);
    cxsh_color(TYPE_COLOR); cxsh_printColumn(typeName, CXSH_COL_TYPE); cxsh_color(NORMAL);
    cxsh_color(META_COLOR);
    cxsh_printColumn(cxsh_stateStr(o, state), CXSH_COL_STATE);
    cxsh_printColumn(cxsh_attrStr(o, attr), CXSH_COL_ATTR);
    cxsh_color(NORMAL);

    printf("\n");
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

        scope = cx_scopeof(o);

        /* Indentation */
        if (*(cx_uint8*)userData) {
            printf("%*s", data->indent * 2, "");
        }

        /* Object */
        if (cx_parentof(cx_typeof(o)) == cortex_lang_o) {
            printf("%s%s%s %s", TYPE_COLOR, cx_nameof(cx_typeof(o)), NORMAL, cx_nameof(o));
        } else {
            printf("%s%s%s %s", TYPE_COLOR, cx_fullname(cx_typeof(o), id1), NORMAL, cx_nameof(o));
        }

        /* Scope operator or semicolon */
        if (scope && cx_rbtreeSize(scope)) {
            printf(" %s::%s\n", BOLD, NORMAL);
        } else {
            printf("%s;%s\n", BOLD, NORMAL);
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

/* Show object */
static int cxsh_show(char* object) {
    cx_object o;
    cx_id id;
    char state[sizeof("valid | declared | defined")];
    char attr[sizeof("scope | writable | observable")];
    struct cx_serializer_s s;
    cx_string_ser_t sdata;

    cx_toggleEcho(FALSE);

    if ((o = cx_resolve(scope, object))) {

        /* Initialize serializer userData */
        s = cx_string_ser(CX_PRIVATE, CX_NOT, CX_SERIALIZER_TRACE_ON_FAIL);
        sdata.buffer = NULL;
        sdata.length = 0;
        sdata.maxlength = 0;
        sdata.ptr = NULL;
        sdata.compactNotation = FALSE;
        sdata.prefixType = FALSE;

        /* Print object properties */
        if (o) {
            printf("%sname:%s         %s%s%s\n", INTERFACE_COLOR, NORMAL, OBJECT_COLOR, cx_fullname(o, id), NORMAL);
            printf("%stype:%s         %s%s%s\n", INTERFACE_COLOR, NORMAL, TYPE_COLOR, cx_fullname(cx_typeof(o), id), NORMAL);
            printf("%saddress:%s      <%p>\n", INTERFACE_COLOR, NORMAL, o);
            printf("%srefcount:%s     %d\n", INTERFACE_COLOR, NORMAL, cx_countof(o)-1); /* Correct for cxsh's own keep */
            printf("%sstate:%s        %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, cxsh_stateStr(o, state), NORMAL);
            printf("%sattributes:%s   %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, cxsh_attrStr(o, attr), NORMAL);
            if (cx_checkAttr(o, CX_ATTR_SCOPED)) {
                printf("%sparent:       %s%s%s\n", INTERFACE_COLOR, OBJECT_COLOR, cx_fullname(cx_parentof(o), id), NORMAL);
                if (cx_scopeof(o)) {
                    printf("%schildcount:%s   %d\n", INTERFACE_COLOR, NORMAL, cx_rbtreeSize(cx_scopeof(o)));
                }
            }
        }

        /* Serialize value to string */
        cx_serialize(&s, o, &sdata);
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
        }

        if (o) {
            cx_free_ext(NULL, o, "free expression result");
        }

        printf("\n");

        cx_toggleEcho(TRUE);
        return 0;
    } else {
        cx_error("expression '%s' does not resolve to object", object);
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
            cxsh_color(ERROR_COLOR);
            cx_error("%s", lastErr);
            cxsh_color(NORMAL);
        } else {
            cxsh_color(ERROR_COLOR);
            cx_error("expression '%s' did not resolve to a valid expression or command", cmd);
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

    quit = FALSE;

    while(!quit) {
        /* Print prompt */
        cxsh_prompt(scope);

        cmd[0] = '\0';

        /* Read command */
        if (fgets(cmd, 256, stdin) == 0) {
            continue;
        }

        /* Strip '\n' */
        cmd[strlen(cmd) - 1] = '\0';

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

    printf("cortex shell - type 'help' for instructions.\n");

    /* Parse arguments */
    for(i=1; i<argc; i++) {
        if ( cx_load(argv[i]) ) {
            printf("%s\n", cx_lasterror());
        }
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
