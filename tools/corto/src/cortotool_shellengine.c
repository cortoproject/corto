#include "cortotool_shellengine.h"
#include "corto.h"

#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#include "stdio.h"
#include "signal.h"
#include "termios.h"
#include "unistd.h"

#define CORTO_MAX_ARG 256
#define CORTO_MAX_HISTORY 1000
#define CORTO_MAX_CMDLENGTH 1000

static char cmdbuff[CORTO_MAX_CMDLENGTH];
static char cmdbuff_parsed[CORTO_MAX_CMDLENGTH];
static const char* argv[CORTO_MAX_ARG];
static unsigned int argc = 0;
static char* cmdHistory[CORTO_MAX_HISTORY];
static int cmdHistoryHead = 0;
static int cmdHistoryCount = 0;
static int cmdHistoryPtr = 0;
static char shell[CORTO_MAX_CMDLENGTH];
static corto_bool keepInput = FALSE;
static char keepStr[CORTO_MAX_CMDLENGTH];

typedef int cortoconsole_key;

#define XCON_KEY_TAB        9
#define XCON_KEY_ESC        27
#define XCON_KEY_BACKSPACE  127
#define XCON_KEY_UP         128
#define XCON_KEY_DOWN       129
#define XCON_KEY_LEFT       130
#define XCON_KEY_RIGHT      131

static int consolePos = 0;
static char returnchar = 10;

/* Read one character without having to wait for a return */
int cortotool_getch(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void cortoconsole_resetPos(void) {
    consolePos = 0;
}

void cortoconsole_clear(void) {
    int i;

    /* Move cursur back */
    for (i = 0; i < consolePos; i++) {
        putc('\b', stdout);
    }

    for (i = 0; i < consolePos; i++) {
        putc(' ', stdout);
    }

    for (i = 0; i < consolePos; i++) {
        putc('\b', stdout);
    }

    consolePos = 0;
}

void cortoconsole_puts(const char* s) {
    consolePos = strlen(s);
    printf("%s", s);
}

void cortoconsole_moveCursor(int pos) {
    int i;
    for (i = 0; i < consolePos - pos; i++) {
        putc('\b', stdout);
    }
    consolePos = pos;
}

/* getch function */
int cortoconsole_getch(void) {
    cortoconsole_key ch;

    ch = cortotool_getch();

    if (ch == returnchar) {
        consolePos = 0;

    /* Escape character, special key (GNOME terminal) */
    } else if (ch == 27) {
        ch = cortotool_getch();
        if (ch == 91) {
            ch = cortotool_getch();
            if (ch == 65) {
                ch = XCON_KEY_UP;
            } else if (ch == 66) {
                ch = XCON_KEY_DOWN;
            } else if (ch == 67) {
                ch = XCON_KEY_RIGHT;
            } else if (ch == 68) {
                ch = XCON_KEY_LEFT;
            }
        }
    }

    return ch;
}


/*
static void corto_shellEngine_sigint(int sig) {
    (void) signal(SIGINT, corto_shellEngine_sigint);
}
*/

static void corto_shellEngine_moveHistoryPtrBack(int* ptr) {
    (*ptr)--;
    if (*ptr < 0) {
        *ptr = cmdHistoryCount - 1;
    }
}

static void corto_shellEngine_moveHistoryPtrFwd(int* ptr) {
    (*ptr)++;
    if (*ptr >= cmdHistoryCount) {
        *ptr = 0;
    }
}

static void corto_shellEngine_resetHistoryToHead(void) {
    if (cmdHistoryCount) {
        cmdHistoryPtr = cmdHistoryHead;
        if (cmdHistoryPtr < 0) {
            cmdHistoryPtr = cmdHistoryCount;
        }
    } else {
        cmdHistoryPtr = 0;
    }
}

static void corto_shellEngine_addHistory(const char* str) {
    char *prev = NULL;
    if (cmdHistoryHead) {
        prev = cmdHistory[cmdHistoryHead - 1];
    } else {
        prev = cmdHistory[CORTO_MAX_HISTORY - 1];
    }

    /* Don't add double subsequent entries */
    if (!prev || strcmp(str, prev)) {
        if (cmdHistoryHead >= CORTO_MAX_HISTORY) {
            cmdHistoryHead = 0;
        }

        if (cmdHistory[cmdHistoryHead]) {
            free(cmdHistory[cmdHistoryHead]);
        } else {
            cmdHistoryCount++;
        }

        cmdHistory[cmdHistoryHead] = strdup(str);
        cmdHistoryHead++;
    }
}

/* Up key pressed */
static const char* corto_shellEngine_getHistory(void) {
    const char* result;
    int nextHead;

    if (cmdHistoryCount) {
        nextHead = cmdHistoryHead;
        corto_shellEngine_moveHistoryPtrFwd(&nextHead);
        if (cmdHistoryPtr != nextHead) {
            corto_shellEngine_moveHistoryPtrBack(&cmdHistoryPtr);
        }
        result = cmdHistory[cmdHistoryPtr];

    } else {
        result = NULL;
    }

    return result;
}

/* Down key pressed */
static const char* corto_shellEngine_getHistoryUp(void) {
    const char* result;
    int prevHead;

    if (cmdHistoryCount) {
        prevHead = cmdHistoryHead;
        corto_shellEngine_moveHistoryPtrBack(&prevHead);
        if (cmdHistoryPtr != prevHead) {
            corto_shellEngine_moveHistoryPtrFwd(&cmdHistoryPtr);
        }
        result = cmdHistory[cmdHistoryPtr];

    } else {
        result = NULL;
    }

    return result;
}

/* Parse command into command structures (argc, argv) */
static void corto_shellEngine_parseCommand(void) {
    corto_bool arg;
    corto_bool quotes;
    const char* argPtr;
    char* inPtr;

    arg = FALSE;
    quotes = FALSE;
    argPtr = NULL;

    /* Copy commandbuffer to buffer for parsed command */
    strcpy(cmdbuff_parsed, cmdbuff);

    /* Parse command */
    inPtr = cmdbuff_parsed;
    arg = FALSE;
    argc = 0;
    argPtr = NULL;
    quotes = FALSE;
    while (*inPtr != '\0') {
        switch (*inPtr) {
        case '\'':
        case '"':
            quotes = !quotes;
            if (arg) {
                argv[argc] = argPtr;
                argc++;
                arg = FALSE;
                *inPtr = '\0';
            }
            break;

        case ' ':
            if (arg && !quotes) {
                argv[argc] = argPtr;
                argc++;
                arg = FALSE;
                *inPtr = '\0';
            }
            break;

        default:
            if (!arg) {
                argPtr = inPtr;
                arg = TRUE;
            }
            break;
        }
        inPtr++;

        if (*inPtr == '\0') {
            if (arg) {
                argv[argc] = argPtr;
                argc++;
                arg = FALSE;
            }
        }
    }

    /* Append trailing zero */
    argv[argc] = NULL;
}

/* Keep the input for the next readInput call */
void corto_shellEngine_keepInput(void) {
    keepInput = TRUE;
}

/* Append the command string */
void corto_shellEngine_cmdAppend(const char* arg) {
    strcat(cmdbuff, arg);
}

/* Generic auto-expand function (TAB-callback) */
static corto_bool corto_shellAutoExpand(char *arg, corto_expandCallback expand) {
    corto_ll items = NULL;
    corto_bool result = FALSE;

    items = expand(arg);

  	if (items && corto_llSize(items)) {
        corto_id append;
        append[0] = '\0';
        int first = 0;

    		/* If more items match, items are printed to console. In that case, signal that
    		 * the command-input (which will be auto-completed) must be saved for the next readInput call.
    		 * result = FALSE tells that the readInput call should quit immediately, which, in effect
    		 * will start a new prompt with the old input.
    		 */
    		if (corto_llSize(items) >= 2) {
      			corto_shellEngine_keepInput();
            result = TRUE;

            printf("\n");
            corto_iter iter = corto_llIter(items);
            while (corto_iterHasNext(&iter)) {
                corto_string str = corto_iterNext(&iter);
                printf("%s ", str);
                if (!first) {
                    strcpy(append, str + strlen(arg));
                } else {
                    int i = 0;
                    char chstr, chappend;
                    char *ptr = &str[strlen(arg)];
                    while ((chstr = ptr[i]) && (chappend = append[i]) &&
                           (chstr == chappend)) {
                        i++;
                    }
                    append[i] = '\0';
                }
                first++;
            }
            printf("\n");
    		} else {
            strcpy(append, &(((corto_string)corto_llGet(items, 0))[strlen(arg)]));
        }

        corto_shellEngine_cmdAppend(append);

        corto_iter iter = corto_llIter(items);
        while (corto_iterHasNext(&iter)) {
            corto_dealloc(corto_iterNext(&iter));
        }
        corto_llFree(items);
  	}

  	return result;
}

/* Read from stdin */
int corto_shellEngine_readInput(
    corto_commandCallback cmd,
    corto_expandCallback expand)
{
    unsigned int buffLoc, cursor;
    unsigned int ch;
    const char* historyPtr;
    int result = 0;
    corto_bool execute = TRUE;

    /* Print shell */
    printf("%s", shell);

    buffLoc = 0;
    cursor = 0;
    cmdbuff[0] = '\0';

    /* If keepInput was set, replace cmdbuff with old commandstring */
    if (keepInput) {
        strcpy(cmdbuff, keepStr);
        cortoconsole_puts(cmdbuff);
        cursor = buffLoc = strlen(cmdbuff);
    }

    /* Reset keepinput */
    keepInput = FALSE;

    /* Move to first history record */
    corto_shellEngine_resetHistoryToHead();

    ch = cortoconsole_getch();
    while ((ch != 10) && (strlen(cmdbuff) < CORTO_MAX_CMDLENGTH)) {
        execute = TRUE;

        /* Parse cmd into argc and argv */
        corto_shellEngine_parseCommand();

        switch (ch) {
        case XCON_KEY_TAB:
            if (expand) {
                execute = !corto_shellAutoExpand(cmdbuff, expand);
                cursor = strlen(cmdbuff);
            }
            break;

        case XCON_KEY_BACKSPACE:
            if (buffLoc) {
                cmdbuff[buffLoc - 1] = '\0';
                cursor--;
            }
            break;

        case XCON_KEY_UP:
            historyPtr = corto_shellEngine_getHistory();
            if (historyPtr) {
                cortoconsole_clear();
                strcpy(cmdbuff, historyPtr);
                cursor = buffLoc = strlen(historyPtr);
            }
            break;

        case XCON_KEY_DOWN:
            historyPtr = corto_shellEngine_getHistoryUp();
            if (historyPtr) {
                cortoconsole_clear();
                strcpy(cmdbuff, historyPtr);
                cursor = buffLoc = strlen(historyPtr);
            }
            break;

        case XCON_KEY_LEFT:
            if (cursor) {
                cursor--;
            }
            break;

        case XCON_KEY_RIGHT:
            if (cursor < buffLoc)
                cursor++;
            break;

        default:
            if (consolePos == buffLoc) {
                cmdbuff[buffLoc] = ch;
                cmdbuff[buffLoc + 1] = '\0';
            } else {
                memmove(&cmdbuff[consolePos] + 1, &cmdbuff[consolePos], buffLoc - consolePos + 1);
                cmdbuff[consolePos] = ch;
            }
            cursor++;
            break;
        }

        if (!execute) {
            break;
        }

        cortoconsole_clear();
        buffLoc = strlen(cmdbuff);
        cortoconsole_puts(cmdbuff);
        cortoconsole_moveCursor(cursor);

        ch = cortoconsole_getch();
    }

    printf("\n");

    /* Execute command */
    if (cmd && execute && argc) {
        /* Parse cmd into argc and argv */
        corto_shellEngine_parseCommand();

        /* Call the callback function for commands */
        result = cmd(argc, argv, cmdbuff);
    }

    /* Add command to history */
    if (execute) {
        corto_shellEngine_addHistory(cmdbuff);
    }

    if (keepInput) {
        strcpy(keepStr, cmdbuff);
    }

    /* Always reset console at end of input */
    cortoconsole_resetPos();

    return result;
}

void corto_shellEngine_prompt(const char* fmt, ...) {
    va_list argList;
    va_start(argList, fmt);

    vsprintf(shell, fmt, argList);

    va_end(argList);
}
