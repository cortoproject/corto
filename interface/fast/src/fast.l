%{

#include "hyve.h"
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
	Fast_Parser_collectHeap(yparser(), (db_word)o);
}

/* Escape string-token */
static int fast_escape(char* yptr, db_string ptr) {
	char ch;
	
	/* Do escape sequences */
	yptr = yytext+1;
	while((ch = *yptr)) {
		switch(ch) {
		case '\\':
			yptr++; ch = *yptr;
			switch(ch) {
			case 'a':
				*ptr = '\a';												
				break;
			case 'b':
				*ptr = '\b';
				break;
			case 'f':
				*ptr = '\f';
				break;
			case 'n':
				*ptr = '\n';
				break;
			case 'r':
				*ptr = '\r';
				break;
			case 't':
				*ptr = '\t';
				break;
			case 'v':
				*ptr = '\v';
				break;
			case '\'':
				*ptr = '\'';
				break;
			case '"':
				*ptr = '"';
				break;
			case '\\':
				*ptr = '\\';
				break;
			case '?':
				*ptr = '?';
				break;
			default:
				printf("invalid escape sequence '%c'",  ch);
				goto error;
				break;
			}
			ptr++;
			break;
		case '"':
			break;
		default:
			*ptr = ch;
			ptr++;
			break;
		}
		yptr++;
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

"//"							comment(); yparser()->line+=1;
"#"								comment(); yparser()->line+=1;

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

L?'(\\.|[^\\'])+'				TOKEN; yylval.Character = *(yytext+1); return CHARACTER;
0x[0-9a-fA-F]+					TOKEN; sscanf(yytext, "%" PRIu64, &yylval.Integer); return INTEGER; 
[0-9]+							TOKEN; sscanf(yytext, "%" PRIu64, &yylval.Integer); DB_UNUSED(yyunput); return INTEGER;
[0-9]+"."[0-9]+					TOKEN; yylval.FloatingPoint = atof(yytext); return FLOATINGPOINT;
"null"							TOKEN; yylval.Null = NULL; return NUL;
L?\"(\\.|[^\\"])*\"				TOKEN; yylval.String = malloc(strlen(yytext) + 1); lex_collect(yylval.String); return fast_escape(yytext+1,yylval.String) ? ERROR : STRING;
[\n]							TOKEN; yparser()->line++; yparser()->column = 1;
[ ]+							TOKEN; /* Ignore whitespaces */
[\t]+							TOKEN; yparser()->column+=3; /* Ignore tabs */

":"								TOKEN; return ':';
";"								TOKEN; return ';';
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
								
"#ind"							TOKEN; return INDENT;
"#ded"							TOKEN; return DEDENT;
"#column "[0-9]+				TOKEN; sscanf(yytext, "#column %u", &yparser()->column);

%%

/* Comment */
static void comment(void)
{
	char c;
	Fast_Parser p = yparser();

	while ((c = input()) && (c != -1) && (c != '\n')) {
		/*putchar(c);*/
		p->column = 1;
	}
}





