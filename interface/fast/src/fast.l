%{

#include "cortex.h"
#include "Fast__type.h"
#include "y.tab.h"
#include "stdio.h"
#include "string.h"
#include "Fast_Parser.h"
#define MAX_DEPTH (72)

static void comment(void);
Fast_Parser yparser(void);

int nesting = 0; /* Ignore indents & newlines between {}, (), [] */
int trailing = 0; /* Ignore indents & newlines after a binary operator */
int block = 0; /* Ignore newline directly after an open scope/block */
unsigned int indent_stack[MAX_DEPTH];
unsigned int level = 0;

static int process_indent(char* line);

#define NEWLINE \
    yparser()->line++;\
    yparser()->column = 0;\

#define TOKEN\
    yparser()->column += strlen(yytext);\
    yparser()->token = yytext;\
    trailing = fast_trailingOperator();\
    block = fast_blockOperator();

void lex_collect(void *o) {
    Fast_Parser_collectHeap(yparser(), (cx_word)o);
}

/* The following operators can be trailing */
static char *operators[] = {
    "=", "+", "-", "*", "/", "%", "&", "|", "^", 
    "==", "!=", ">", "<", ">=", "<=", "||", "&&", ","};
static int fast_trailingOperator(void) {
    int length = sizeof(operators) / sizeof(char*);
    int i;
    if (yparser()->token) {    
        for(i = 0; i < length; i++) {
            if (!strcmp(operators[i], yparser()->token)) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

static int fast_blockOperator(void) {
    if (yparser()->token) {
        if (!strcmp(yparser()->token, ":") || 
            !strcmp(yparser()->token, "::") ||
            !strcmp(yparser()->token, ":::")) {
            return TRUE;
        }
    }
    return FALSE;
}

static int fast_isBlankLine(char *txt, int *isComment) {
    char *ptr = txt, ch;
    while ((ch = *ptr)) {
        if (ch == '/') {
            if (ptr[1] == '/') {
                *isComment = TRUE;
            }
        }
        if ((ch != ' ') && (ch != '\t') && (ch != '\n') && (ch != 13)) {
            return FALSE;
        }
        ptr++;
    }
    return TRUE;
}

/* Escape character */
static char *fast_charesc(char *in, cx_char *out) {
    switch(*in) {
    case '\\':
        in++;
        switch(*in) {
        case 'a':
            *out = '\a';                                                
            break;
        case 'b':
            *out = '\b';
            break;
        case 'f':
            *out = '\f';
            break;
        case 'n':
            *out = '\n';
            break;
        case 'r':
            *out = '\r';
            break;
        case 't':
            *out = '\t';
            break;
        case 'v':
            *out = '\v';
            break;
        case '\'':
            *out = '\'';
            break;
        case '0':
            *out = '\0';
            break;
        case '"':
            *out = '"';
            break;
        case '\\':
            *out = '\\';
            break;
        case '?':
            *out = '?';
            break;
        default:
            printf("invalid escape sequence '%c'",  *in);
            goto error;
            break;
        }
        break;
    default:
        *out = *in;
        break;    
    }

    return in + 1;
error:
    return NULL;
}

/* Escape string-token */
static int fast_stresc(char* yptr, cx_string ptr) {
    char ch;
    
    /* Do escape sequences */
    yptr = yytext+1;
    while((ch = *yptr) && (ch != '"')) {
        yptr = fast_charesc(yptr, ptr);
        if(!yptr) {
            goto error;
        }
        ptr++;
    }
    *ptr = '\0';
    
    return 0;
error:
    return -1;
}

static void fast_doIndents(int indent);

%}

id [_a-zA-Z][_a-zA-Z0-9]*
gid ("::"*{id})+

%%

^[ ]*[^ \n]+                    {
                                    /* Filter out empty lines */
                                    int isComment = FALSE;
                                    if (!fast_isBlankLine(yytext, &isComment)) {
                                        int last = yyleng - 1;
                                        int indent = isComment ? 0 : process_indent(yytext);
                                        while ((last >= 0) && (yytext[last] != ' ')) {
                                            unput(yytext[last]);
                                            last--;
                                        }
                                        fast_doIndents(indent);
                                    }
                                }

<<EOF>>                         {
                                    int indent = process_indent("");
                                    if (indent) {
                                        fast_doIndents(indent);
                                    } else {
                                        return EOF;
                                    }
                                }

"update"                        TOKEN; return KW_UPDATE;
"declare"                       TOKEN; return KW_DECLARE;
"define"                        TOKEN; return KW_DEFINE;
"delete"                        TOKEN; return KW_DESTRUCT;
"wait"                          TOKEN; return KW_WAIT;
"on"                            TOKEN; return KW_ON;
"self"                          TOKEN; return KW_SELF;
"scope"                         TOKEN; return KW_SCOPE;
"synchronized"                  TOKEN; return KW_SYNCHRONIZED;
"if"                            TOKEN; return KW_IF;
"else"                          TOKEN; return KW_ELSE;
"while"                         TOKEN; return KW_WHILE;
"switch"                        TOKEN; return KW_SWITCH;
"case"                          TOKEN; return KW_CASE;
"default"                       TOKEN; return KW_DEFAULT;
"break"                         TOKEN; return KW_BREAK;
"for"                           TOKEN; return KW_FOR;
"try"                           TOKEN; return KW_TRY;
"catch"                         TOKEN; return KW_CATCH;
"var"                           TOKEN; return KW_LOCAL;
"and"                           TOKEN; return LAND;
"or"                            TOKEN; return LOR;
"not"                           TOKEN; return LNOT;

true                            TOKEN; yylval.Boolean =  TRUE; return BOOLEAN;
false                           TOKEN; yylval.Boolean = FALSE; return BOOLEAN;

"#package"                      TOKEN; return PACKAGE;
"//"                            comment();
"#"                             comment();

"#i"                            TOKEN; return INDENT;
"#d"                            TOKEN; return DEDENT;

L?'(\\.|[^\\'])+'               TOKEN; fast_charesc(yytext+1, &yylval.Character); return CHARACTER;
0x[0-9a-fA-F]+                  TOKEN; sscanf(yytext, "%" PRIx64, &yylval.Integer); return INTEGER; 
[0-9]+                          TOKEN; sscanf(yytext, "%" PRIu64, &yylval.Integer); return INTEGER;
[0-9]+"."[0-9]+                 TOKEN; yylval.FloatingPoint = atof(yytext); return FLOATINGPOINT;
"null"                          TOKEN; yylval.Null = NULL; return NUL;
L?\"(\\.|[^\\"])*\"             TOKEN; yylval.String = malloc(strlen(yytext) + 1); lex_collect(yylval.String); return fast_stresc(yytext+1,yylval.String) ? ERROR : STRING;
[\t]+                           TOKEN; yparser()->column+=3; /* Ignore tabs */
":"                             TOKEN; return ':';
"\n"                            NEWLINE; if (!nesting && !trailing && !block) { return ENDL; }
";"                             NEWLINE; return ENDL;
"("                             TOKEN; nesting++; return '(';
")"                             TOKEN; nesting--; return ')';
"["                             TOKEN; nesting++; return '[';
"]"                             TOKEN; nesting--; return ']';
"{"                             TOKEN; nesting++; return '{';
"}"                             TOKEN; nesting--; return '}';
"."                             TOKEN; return '.';
","                             TOKEN; return ',';
"+"                             TOKEN; return '+';
"-"                             TOKEN; return '-';
"*"                             TOKEN; return '*';
"/"                             TOKEN; return '/';
"%"                             TOKEN; return '%';
"++"                            TOKEN; return INC;
"--"                            TOKEN; return DEC;
"!"                             TOKEN; return '!';
"&"                             TOKEN; return '&';
"~"                             TOKEN; return '~';
"<"                             TOKEN; return '<';
">"                             TOKEN; return '>';
"?"                             TOKEN; return '?';
"<="                            TOKEN; return LEQ;
">="                            TOKEN; return GEQ;
"=="                            TOKEN; return EQ;
"!="                            TOKEN; return NEQ;
"|"                             TOKEN; return '|';
"^"                             TOKEN; return '^';
"||"                            TOKEN; return LOR;
"&&"                            TOKEN; return LAND;
"="                             TOKEN; return '=';
"*="                            TOKEN; return MUL_ASSIGN;
"/="                            TOKEN; return DIV_ASSIGN;
"+="                            TOKEN; return ADD_ASSIGN;
"-="                            TOKEN; return SUB_ASSIGN;
"|="                            TOKEN; return OR_ASSIGN;
"&="                            TOKEN; return AND_ASSIGN;
":="                            TOKEN; return UPDATE_ASSIGN;
"::"                            TOKEN; return SCOPE;
":::"                           TOKEN; return SCOPEPRE;
"->"                            TOKEN; return ARROW_RIGHT;
"<-"                            TOKEN; return ARROW_LEFT;
"<<"                            TOKEN; return SHIFT_LEFT;
">>"                            TOKEN; return SHIFT_RIGHT;
"@"                             TOKEN; return '@';
"`"                             TOKEN; return '`';

{id}                            TOKEN; yylval.Identifier = strdup(yytext); lex_collect(yylval.Identifier); return ID;                        
{gid}                           TOKEN; yylval.Identifier = strdup(yytext); lex_collect(yylval.Identifier); return GID;

" "                             yparser()->column += 1;

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

/* Comment */
static void comment(void)
{
    char c;
    Fast_Parser p = yparser();

    while ((c = input()) && (c != EOF) && (c != '\n')) {
    }

    if (c == EOF) {
        void Fast_Parser_error(Fast_Parser p, cx_string fmt, ...);
        Fast_Parser_error(p, "end of file encountered in comment");
        exit(1);
    } else {
        unput('\n');
    }
}

static unsigned int white_count(char* line) {
    unsigned int count = 0;
    while (*line == ' ') {
        count++;
        line++;
    }
    return count;
}

static int process_indent(char* line) {
    int result = 0;

    if (nesting || trailing) {
        /* Ignore indents while nested. */
        return 0;
    }

    unsigned int indent = white_count(line);

    if (indent == indent_stack[level]) {
        return 0;
    }

    if (indent > indent_stack[level]) {
        indent_stack[++level] = indent;
        return 1;
    }

    while (indent < indent_stack[level]) {
        result--;
        --level;
    }

    return result;
}

static void fast_doIndents(int indent) {
    if (indent > 0) {
        unput(' ');
        unput('i');
        unput('#');
    } else if (indent) {
        while (indent) {
            unput(' ');
            unput('d');
            unput('#');
            indent++;
        }
    }
}

