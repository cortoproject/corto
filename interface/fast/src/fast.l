%{

#include "cortex.h"
#include "Fast__type.h"
#include "y.tab.h"
#include "stdio.h"
#include "string.h"
#include "Fast_Parser.h"

static void comment(void);
Fast_Parser yparser(void);

#define TOKEN\
	yparser()->column += strlen(yytext);\
	yparser()->token = yytext;\

void lex_collect(void *o) {
	Fast_Parser_collectHeap(yparser(), (cx_word)o);
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

%}

id [_a-zA-Z][_a-zA-Z0-9]*
gid ("::"*{id})+

%%

"//"							TOKEN; comment();
"#"								comment();

"update"						TOKEN; return KW_UPDATE;
"declare"                       TOKEN; return KW_DECLARE;
"define"                        TOKEN; return KW_DEFINE;
"delete"                      	TOKEN; return KW_DESTRUCT;
"wait"							TOKEN; return KW_WAIT;
"on"							TOKEN; return KW_ON;
"self"							TOKEN; return KW_SELF;
"scope"                         TOKEN; return KW_SCOPE;
"synchronized"					TOKEN; return KW_SYNCHRONIZED;
"if"							TOKEN; return KW_IF;
"else"							TOKEN; return KW_ELSE;
"while"							TOKEN; return KW_WHILE;
"switch"						TOKEN; return KW_SWITCH;
"case"							TOKEN; return KW_CASE;
"default"						TOKEN; return KW_DEFAULT;
"break"							TOKEN; return KW_BREAK;
"for"							TOKEN; return KW_FOR;
"try"							TOKEN; return KW_TRY;
"catch"							TOKEN; return KW_CATCH;
"import"						TOKEN; return KW_IMPORT;
"var"							TOKEN; return KW_LOCAL;
"and"                           TOKEN; return LAND;
"or"                            TOKEN; return LOR;
"not"                           TOKEN; return LNOT;

true							TOKEN; yylval.Boolean =  TRUE; return BOOLEAN;
false							TOKEN; yylval.Boolean = FALSE; return BOOLEAN;

L?'(\\.|[^\\'])+'				TOKEN; fast_charesc(yytext+1, &yylval.Character); return CHARACTER;
0x[0-9a-fA-F]+					TOKEN; sscanf(yytext, "%" PRIx64, &yylval.Integer); return INTEGER; 
[0-9]+							TOKEN; sscanf(yytext, "%" PRIu64, &yylval.Integer); return INTEGER;
[0-9]+"."[0-9]+					TOKEN; yylval.FloatingPoint = atof(yytext); return FLOATINGPOINT;
"null"							TOKEN; yylval.Null = NULL; return NUL;
L?\"(\\.|[^\\"])*\"				TOKEN; yylval.String = malloc(strlen(yytext) + 1); lex_collect(yylval.String); return fast_stresc(yytext+1,yylval.String) ? ERROR : STRING;
[ ]+							TOKEN; /* Ignore whitespaces */
[\t]+							TOKEN; yparser()->column+=3; /* Ignore tabs */

"\n#ind"						TOKEN; yparser()->line++; return INDENT;
"#ded"							TOKEN; return DEDENT;
"#column "[0-9]+				TOKEN; sscanf(yytext, "#column %u", &yparser()->column);
":"								TOKEN; return ':';
";"								TOKEN; return ';';
[\n]							TOKEN; yparser()->line++; yparser()->column = 1; return ENDL;
"("								TOKEN; return '(';
")"								TOKEN; return ')';
"["								TOKEN; return '[';
"]"								TOKEN; return ']';
"."								TOKEN; return '.';
"{"								TOKEN; return '{';
"}"								TOKEN; return '}';
","								TOKEN; return ',';
"+"								TOKEN; return '+';
"-"								TOKEN; return '-';
"*"								TOKEN; return '*';
"/"								TOKEN; return '/';
"%"								TOKEN; return '%';
"++"							TOKEN; return INC;
"--"							TOKEN; return DEC;
"!"								TOKEN; return '!';
"&"								TOKEN; return '&';
"~"								TOKEN; return '~';
"<"								TOKEN; return '<';
">"								TOKEN; return '>';
"?"                             TOKEN; return '?';
"<="							TOKEN; return LEQ;
">="							TOKEN; return GEQ;
"=="							TOKEN; return EQ;
"!="							TOKEN; return NEQ;
"|"								TOKEN; return '|';
"^"								TOKEN; return '^';
"||"							TOKEN; return LOR;
"&&"							TOKEN; return LAND;
"="								TOKEN; return '=';
"*="							TOKEN; return MUL_ASSIGN;
"/="							TOKEN; return DIV_ASSIGN;
"+="							TOKEN; return ADD_ASSIGN;
"-="							TOKEN; return SUB_ASSIGN;
"|="							TOKEN; return OR_ASSIGN;
"&="							TOKEN; return AND_ASSIGN;
"::"							TOKEN; return SCOPE;
":::"							TOKEN; return SCOPEPRE;
"->"							TOKEN; return ARROW_RIGHT;
"<-"							TOKEN; return ARROW_LEFT;
"<<"							TOKEN; return SHIFT_LEFT;
">>"							TOKEN; return SHIFT_RIGHT;
"@"								TOKEN; return '@';
"`"								TOKEN; return '`';

{id}							TOKEN;yylval.Identifier = strdup(yytext); lex_collect(yylval.Identifier); return ID;						
{gid}							TOKEN; yylval.Identifier = strdup(yytext); lex_collect(yylval.Identifier); return GID;

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
		/*putchar(c);*/
		p->column = 1;
	}
	if (c == EOF) {
		void Fast_Parser_error(Fast_Parser p, cx_string fmt, ...);
		Fast_Parser_error(p, "end of file encountered in comment");
		exit(1);
	} else {
		unput('\n');
	}
}





