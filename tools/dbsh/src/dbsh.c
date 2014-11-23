/*
 * dbsh.c
 *
 *  Created on: Aug 21, 2012
 *      Author: sander
 */

#include "hyve.h"
#include "db_convert.h"
#include "db_string_ser.h"
#include "db_metawalk.h"
#include "db_class.h"
#include "db_loader.h"
#include "db_err.h"

#define DBSH_CMD_MAX (1024)

#define DBSH_COL_NAME     (32)
#define DBSH_COL_TYPE     (32)
#define DBSH_COL_STATE    (15)
#define DBSH_COL_ATTR     (10)
#define DBSH_COL_TOTAL	  (DBSH_COL_NAME + DBSH_COL_TYPE + DBSH_COL_STATE + DBSH_COL_ATTR)

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

static db_object scope = NULL;

static void dbsh_color(const char *string) {
	printf("%s", string);
}

static void dbsh_printColumn(db_string str, int width){
	printf("%s%*s", str, (int)(width - strlen(str)), " ");
}

static void dbsh_printColumnBar(int width) {
	while(width) {
		printf("=");
		width--;
	}
	printf("\n");
}

static void dbsh_printColumnHeader(void) {
	printf("  ");
	dbsh_printColumn("name", DBSH_COL_NAME);
	dbsh_printColumn("type", DBSH_COL_TYPE);
	dbsh_printColumn("state", DBSH_COL_STATE);
	dbsh_printColumn("attr", DBSH_COL_ATTR);
	dbsh_color(INTERFACE_COLOR);
	printf("\n");
	dbsh_printColumnBar(DBSH_COL_TOTAL);
	dbsh_color(NORMAL);
}

/* Print shell prompt */
static void dbsh_prompt(db_object scope) {
	db_id id;
	db_fullname(scope, id);

	printf("%s%s%s %s$%s ", OBJECT_COLOR, id, NORMAL, SHELL_COLOR, NORMAL);
}

/* Translate object state to string */
static char* dbsh_stateStr(db_object o, char* buff) {
	buff[0] = '\0';

    /* Get state */
    if (db_checkState(o, DB_VALID)) {
       strcpy(buff, "V");
    }
    if (db_checkState(o, DB_DECLARED)) {
       strcat(buff, "|DCL");
    }
    if (db_checkState(o, DB_DEFINED)) {
       strcat(buff, "|DEF");
    }

    return buff;
}

/* Translate object attributes to string */
static char* dbsh_attrStr(db_object o, char* buff) {
	db_bool first;
	*buff = '\0';

	first = TRUE;
	if (db_checkAttr(o, DB_ATTR_SCOPED)) {
		strcat(buff, "S");
		first = FALSE;
	}
	if (db_checkAttr(o, DB_ATTR_WRITABLE)) {
		if (!first) {
			strcat(buff, "|W ");
		} else {
			strcat(buff, "W ");
			first = FALSE;
		}
	}
	if (db_checkAttr(o, DB_ATTR_OBSERVABLE)) {
		if (!first) {
			strcat(buff, "|O ");
		} else {
			strcat(buff, "O");
		}
	}
    return buff;
}

static int dbsh_scopeWalk(db_object o, void* udata) {
	db_id typeName;
	char state[sizeof("valid | declared | defined")];
	char attr[sizeof("scope | writable | observable")];

	DB_UNUSED(udata);

	/* Get name of type */
	db_fullname(db_typeof(o), typeName);

	/* Print columns */
	printf("  ");
	dbsh_color(OBJECT_COLOR); dbsh_printColumn(db_nameof(o), DBSH_COL_NAME); dbsh_color(NORMAL);
	dbsh_color(TYPE_COLOR); dbsh_printColumn(typeName, DBSH_COL_TYPE); dbsh_color(NORMAL);
	dbsh_color(META_COLOR);
	dbsh_printColumn(dbsh_stateStr(o, state), DBSH_COL_STATE);
	dbsh_printColumn(dbsh_attrStr(o, attr), DBSH_COL_ATTR);
	dbsh_color(NORMAL);

	printf("\n");
	return 1;
}

/* List scope */
static void dbsh_ls(char* arg) {
	db_rbtree _scope;
	db_object o;

	if (arg && strlen(arg)) {
	    o = db_resolve(scope, arg);
	    if (!o) {
	    	dbsh_color(ERROR_COLOR);
	        db_error("expression '%s' did not resolve to object.", arg);
	        dbsh_color(NORMAL);
	        return;
	    }
	} else {
	    o = scope;
	    db_keep(o);
	}

	/* Get scope */
	_scope = db_scopeof(o);

	/* Print column header */
	dbsh_printColumnHeader();

	if (_scope && db_rbtreeSize(_scope)) {
        /* Walk scope, print contents */
        db_rbtreeWalk(_scope, dbsh_scopeWalk, NULL);

        if (db_rbtreeSize(_scope) == 1) {
            printf("total: %d object\n", db_rbtreeSize(_scope));
        } else {
            printf("total: %d objects\n", db_rbtreeSize(_scope));
        }
	} else {
	    printf("no objects.\n");
	}

	db_free(o);
}

typedef struct dbsh_treeWalk_t {
	db_uint8 indent;
	db_uint32 count;
}dbsh_treeWalk_t;

/* Walk object-hierarchy */
static int dbsh_treeWalk(db_object o, void* userData) {
    dbsh_treeWalk_t* data;

    data = userData;

    data->count++;

    /* Limit name-buffer to local scope */
    {
        db_id id1;
        db_rbtree scope;

        scope = db_scopeof(o);

        /* Indentation */
        if (*(db_uint8*)userData) {
            printf("%*s", data->indent * 2, "");
        }

        /* Object */
        if (db_parentof(db_typeof(o)) == hyve_lang_o) {
            printf("%s%s%s %s", TYPE_COLOR, db_nameof(db_typeof(o)), NORMAL, db_nameof(o));
        } else {
            printf("%s%s%s %s", TYPE_COLOR, db_fullname(db_typeof(o), id1), NORMAL, db_nameof(o));
        }

        /* Scope operator or semicolon */
        if (scope && db_rbtreeSize(scope)) {
            printf(" %s::%s\n", BOLD, NORMAL);
        } else {
            printf("%s;%s\n", BOLD, NORMAL);
        }
    }

    /* Do recursive scopewalk */
    data->indent++;
    db_scopeWalk(o, dbsh_treeWalk, userData);
    data->indent--;

    return 1;
}

/* Print object hierarchy */
static void dbsh_tree(char* arg) {
    db_object o;
    dbsh_treeWalk_t walkData;

    if (arg && strlen(arg)) {
        o = db_resolve(scope, arg);
        if (!o) {
        	dbsh_color(ERROR_COLOR);
            db_error("expression '%s' did not resolve to object.", arg);
            dbsh_color(NORMAL);
            return;
        }
    } else {
        o = scope;
        db_keep(o);
    }

    walkData.indent = 0;
    walkData.count = 0;
    dbsh_treeWalk(o, &walkData);

    printf("total: %d objects.\n", walkData.count);

    db_free(o);
}

/* Navigate scopes */
static void dbsh_cd(char* arg) {
    db_object o;
    db_object oldScope;

    oldScope = scope;

    if (!strlen(arg)) {
        scope = root_o;
        db_keep(scope);
    } else if (!strcmp(arg, "..")) {
        if (db_parentof(scope)) {
            scope = db_parentof(scope);
        } else {
        	dbsh_color(ERROR_COLOR);
            db_error("scope is root.");
            dbsh_color(NORMAL);
            return;
        }
        db_keep(scope);
    } else {
        o = db_resolve(scope, arg);
        if (o) {
            scope = o;
        } else {
        	dbsh_color(ERROR_COLOR);
            db_error("expression '%s' did not resolve to object.", arg);
            dbsh_color(NORMAL);
            return;
        }
    }

    db_free(oldScope);
}

/* Show object */
static int dbsh_show(char* object) {
    db_object o;
    db_id id;
    char state[sizeof("valid | declared | defined")];
    char attr[sizeof("scope | writable | observable")];
    struct db_serializer_s s;
    db_string_ser_t sdata;

    db_toggleEcho(FALSE);

    if ((o = db_resolve(scope, object))) {

    	/* Initialize serializer userData */
        s = db_string_ser(DB_PRIVATE, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
        sdata.buffer = NULL;
        sdata.length = 0;
        sdata.maxlength = 0;
        sdata.ptr = NULL;
        sdata.compactNotation = FALSE;
        sdata.prefixType = FALSE;

    	/* Print object properties */
        if (o) {
			printf("%sname:%s         %s%s%s\n", INTERFACE_COLOR, NORMAL, OBJECT_COLOR, db_fullname(o, id), NORMAL);
			printf("%stype:%s         %s%s%s\n", INTERFACE_COLOR, NORMAL, TYPE_COLOR, db_fullname(db_typeof(o), id), NORMAL);
			printf("%saddress:%s      <%p>\n", INTERFACE_COLOR, NORMAL, o);
			printf("%srefcount:%s     %d\n", INTERFACE_COLOR, NORMAL, db_countof(o)-1); /* Correct for dbsh's own keep */
			printf("%sstate:%s        %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, dbsh_stateStr(o, state), NORMAL);
			printf("%sattributes:%s   %s%s%s\n", INTERFACE_COLOR, NORMAL, META_COLOR, dbsh_attrStr(o, attr), NORMAL);
			if (db_checkAttr(o, DB_ATTR_SCOPED)) {
				printf("%sparent:       %s%s%s\n", INTERFACE_COLOR, OBJECT_COLOR, db_fullname(db_parentof(o), id), NORMAL);
				if (db_scopeof(o)) {
					printf("%schilds:%s       %d\n", INTERFACE_COLOR, NORMAL, db_rbtreeSize(db_scopeof(o)));
				}
			}
        }

        /* Serialize value to string */
        db_serialize(&s, o, &sdata);
        if (sdata.buffer) {
        	if (o) {
        		printf("%svalue:%s        ", INTERFACE_COLOR, NORMAL);
        	}

        	printf("%s\n", sdata.buffer);
            db_dealloc(sdata.buffer);
            sdata.buffer = NULL;
            sdata.ptr = NULL;
        }

        /* If object is a type, do a metawalk with the string-serializer */
        if (o) {
			if (db_class_instanceof(db_type_o, o) && db_checkState(o, DB_DEFINED)) {
			    s.access = DB_LOCAL | DB_READONLY | DB_PRIVATE;
			    s.accessKind = DB_NOT;
				db_metaWalk(&s, o, &sdata);
				if (sdata.buffer) {
					printf("%sinitializer:%s     %s\n", INTERFACE_COLOR, NORMAL, sdata.buffer);
					db_dealloc(sdata.buffer);
				}
			}
        }

        if (o) {
            db_free_ext(NULL, o, "free expression result");
        }

        printf("\n");

        db_toggleEcho(TRUE);
        return 0;
    } else {
    	db_error("expression '%s' does not resolve to object", object);
        db_toggleEcho(TRUE);
    	return -1;
    }
}

/* Import file */
static void dbsh_import(char* file) {
    db_load(file);
}

/* Drop scope */
static void dbsh_drop(char* name) {
	db_object o;

	o = db_resolve(scope, name);
	if (o) {
		db_drop(o);
		db_free(o);
	} else {
		dbsh_color(ERROR_COLOR);
		db_error("expression '%s' did not resolve to object.", scope);
		dbsh_color(NORMAL);
	}
}

static void dbsh_help(void) {
	printf("%sLyra shell help%s\n", HEADER_COLOR, NORMAL);
	printf("\n");
	printf("Use hyve-expressions to read or modify data in the hyve database.\n");
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
	printf("      that is supported by hyve.\n");
	printf("  %sclear%s\n", HEADER_COLOR, NORMAL);
	printf("      Clears the screen.\n");
	printf("  %sexit%s\n", HEADER_COLOR, NORMAL);
	printf("      Exit database shell.\n");
	printf("\n");
	printf("%sExamples:%s\n", HEADER_COLOR, NORMAL);
	printf("  %s$%s ls hyve::lang\n", SHELL_COLOR, NORMAL);
	printf("      List objects in scope 'hyve::lang'\n");
	printf("  %s$%s hyve::lang::class\n", SHELL_COLOR, NORMAL);
	printf("      Display object 'hyve::lang::class'\n");
	printf("\n");
}

static int dbsh_doCmd(char* cmd) {
	char arg[DBSH_CMD_MAX];

	arg[0] = '\0';

	/* ls */
    if (!memcmp(cmd, "ls", strlen("ls"))) {
        sscanf(cmd, "ls  %s", arg);
        dbsh_ls(arg);
    } else
    /* tree */
    if (!memcmp(cmd, "tree", strlen("tree"))) {
        sscanf(cmd, "tree %s", arg);
        dbsh_tree(arg);
    } else
    /* exit */
    if (!memcmp(cmd, "exit", strlen("exit"))) {
        goto quit;
    } else
    /* cd */
    if (!memcmp(cmd, "cd", strlen("cd"))) {
        sscanf(cmd, "cd %s", arg);
        dbsh_cd(arg);
    } else
    /* import */
    if (!memcmp(cmd, "import", strlen("import"))) {
        sscanf(cmd, "import %s", arg);
        dbsh_import(arg);
    } else/* drop */
    if (!memcmp(cmd, "drop", strlen("drop"))) {
    	sscanf(cmd, "drop %s", arg);
    	dbsh_drop(arg);
    } else if (!memcmp(cmd, "clear", strlen("clear"))) {
    	system("clear");
    } else if (!memcmp(cmd, "help", strlen("help"))) {
    	dbsh_help();
    } else {
    	db_char *lastErr;
    	if ((lastErr = db_lasterror())) {
    		dbsh_color(ERROR_COLOR);
    		db_error("%s", lastErr);
    		dbsh_color(NORMAL);
    	} else {
    		dbsh_color(ERROR_COLOR);
    		db_error("expression '%s' did not resolve to a valid expression or command", cmd);
    		dbsh_color(NORMAL);
    	}
    }

    return 0;
quit:
	return 1;
}

/* Shell */
static void dbsh_shell(void) {
	char cmd[DBSH_CMD_MAX];
	db_bool quit;

	quit = FALSE;

	while(!quit) {
		/* Print prompt */
		dbsh_prompt(scope);

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
            	if (dbsh_doCmd(cmd+1)) {
            		quit = TRUE;
            	}
            } else {
                if (dbsh_show(cmd)) {
                	if (dbsh_doCmd(cmd)) {
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
	db_start();

	printf("hyve shell - type 'help' for instructions.\n");

	/* Parse arguments */
	for(i=1; i<argc; i++) {
		if ( db_load(argv[i]) ) {
			printf("%s\n", db_lasterror());
		}
	}

	/* Assign scope to root */
	scope = root_o;
	db_keep(root_o); /* Keep scope */

	dbsh_shell();

	db_free(scope); /* Free scope */

	/* Stop database */
	db_stop();

	return 0;
}
