%{

#include "corto.h"
#include "Fast.h"
#include "Fast__private.h"

/* Forward declarations of yacc functions */
void yyerror(const char *str);
int yylex(void);
int yylex_destroy(void);
int yy_scan_string(const char* str);

#define PUSHLVALUE(l) Fast_Parser_pushLvalue(yparser(), l, FALSE); fast_op;
#define PUSHASSIGN(l)    Fast_Parser_pushLvalue(yparser(), l, TRUE); fast_op;
#define POPLVALUE()   Fast_Parser_popLvalue(yparser()); fast_op;

#define PUSHCOMPLEX(l) Fast_Parser_pushComplexType(yparser(), l); fast_op;
#define POPCOMPLEX() Fast_Parser_popComplexType(yparser()); fast_op;

/* Thread local storage key for parser */
extern cx_threadKey Fast_PARSER_KEY;

/* Obtain parser */
Fast_Parser yparser(void) {
    return (Fast_Parser)cx_threadTlsGet(Fast_PARSER_KEY);
}

#define fast_err(...) _fast_err(__VA_ARGS__); YYERROR;
#define fast_op if (Fast_Parser_isAbortSet(yparser())) {YYABORT;} else if (Fast_Parser_isErrSet(yparser())) {YYERROR;}

/* Report error */
void _fast_err(cx_string msg, ...) {
    va_list args;
    char msgbuff[1024];

    va_start(args, msg);
    vsprintf(msgbuff, msg, args);
    va_end(args);

    Fast_reportError(yparser()->filename, yparser()->line, yparser()->column, msgbuff, yparser()->token);

    yparser()->errors++;
}

void Fast_declarationSeqInsert( Fast_ParserDeclarationSeq *seq, Fast_ParserDeclaration *declaration )
{
    seq->length++;
    seq->buffer = cx_realloc(seq->buffer, sizeof(Fast_ParserDeclaration) * seq->length);
    memcpy(&seq->buffer[seq->length-1], declaration, sizeof(Fast_ParserDeclaration));
    seq->buffer[seq->length-1].name = cx_strdup(seq->buffer[seq->length-1].name);
}

Fast_Expression Fast_declarationSeqDo(Fast_Storage type, Fast_ParserDeclarationSeq *declarations, cx_bool isReference)
{
    unsigned int i;
    Fast_Comma result = Fast_CommaCreate();
    Fast_Expression expr = NULL;

    Fast_Parser_collect(yparser(), result);
    yparser()->variableCount = 0;
    for(i=0; i<declarations->length; i++)
    {
        if (!(declarations->buffer[i].storage = Fast_Parser_declaration(
            yparser(),
            type ? Fast_Object(type)->value : NULL,
            declarations->buffer[i].name,
            isReference))) {
                return NULL;
        }
        cx_dealloc(declarations->buffer[i].name);
        expr = Fast_Expression(declarations->buffer[i].storage);

        /* In a declaration of locals assignment is always a reference-assignment. */
        if (isReference) {
            expr = Fast_Expression(Fast_Parser_unaryExpr(yparser(), expr, CX_AND));
            Fast_Parser_collect(yparser(), expr);
        }

        Fast_Comma_addExpression(result, expr);
    }
    cx_dealloc(declarations->buffer);
    declarations->buffer = NULL;
    declarations->length = 0;

    return Fast_Expression(result);
}

%}


/* ======================================================================== */
/* Tokens */
/* ======================================================================== */

/* Error token */
%token ERROR

/* Value tokens */
%token BOOLEAN CHARACTER INTEGER SIGNEDINTEGER FLOATINGPOINT STRING NUL

/* Identifiers */
%token ID GID PACKAGE

/* Operators */
%token MUL_ASSIGN DIV_ASSIGN ADD_ASSIGN SUB_ASSIGN OR_ASSIGN AND_ASSIGN
%token UPDATE_ASSIGN LOR LAND LNOT LEQ GEQ EQ NEQ INC DEC SCOPE SCOPEPRE
%token SHIFT_LEFT SHIFT_RIGHT ARROW_LEFT ARROW_RIGHT ENDL TAB

/* Indentation */
%token INDENT DEDENT

/* Keywords */
%token KW_UPDATE KW_DECLARE KW_DEFINE KW_DESTRUCT KW_ON KW_SCOPE KW_SELF KW_SYNCHRONIZED
%token KW_IF KW_ELSE KW_WHILE KW_SWITCH KW_CASE KW_DEFAULT KW_BREAK KW_FOR KW_WAIT
%token KW_TRY KW_CATCH
%token KW_IMPORT
%token KW_LOCAL


/* ======================================================================== */
/* Types */
/* ======================================================================== */

/* Parser-types */
%union {
    /* Literals */
    cx_bool Boolean;
    cx_char Character;
    cx_uint64 Integer;
    cx_int64 SignedInteger;
    cx_float64 FloatingPoint;
    cx_string String;
    cx_object Reference;
    cx_string Identifier;
    cx_ll List;
    void *Null;
    void *Fast;
    cx_operatorKind Operator;
    int Mask;
    Fast_ParserDeclaration Declaration;
    Fast_ParserDeclarationSeq Declarations;
    Fast_ParserNew New;
    Fast_Storage Variable;
}

/* Valuetoken-types */
%type <Boolean> BOOLEAN
%type <Character> CHARACTER
%type <Integer> INTEGER
%type <SignedInteger> SIGNEDINTEGER
%type <FloatingPoint> FLOATINGPOINT
%type <String> STRING identifier_string
%type <String> ID GID function_argument function_arguments function_argumentList any_id
%type <Null> NUL

/* Syntax tree nodes */
%type <Fast>
    statement statements
    expr literal_expr primary_expr iter_expr postfix_expr unary_expr multiplicative_expr additive_expr shift_expr
    boolean_expr equality_expr and_expr xor_expr or_expr logical_and_expr logical_or_expr assignment_expr
    comma_expr bracket_expr conditional_expr wait_expr declaration declaration_expr declaration_ref
    function_declaration
    block block_start
    initializer initializer_expr initializer_braces init_key
    if_start if_statement switch_statement case_statement observer_statement observer_declaration update_statement
    while_statement while_until package_declaration

/* Operators */
%type <Operator>
    unary_operator assignment_operator multiplicative_operator additive_operator boolean_operator equality_operator

/* Objects */
%type <Reference>
    identifier identifier_id observer_dispatch

/* Observable mask */
/*%type <Mask>
    event_mask_norm event_mask event_mask_flags event_mask_childflags event_mask_baseflags
*/

%type <Mask>
    event_mask event_baseflag event_childflag event_flag

%type <Declarations>
    declaration_list

%type <Declaration>
    declaration_id

%%

/* ======================================================================== */
/* Statements */
/* ======================================================================== */
code
    : statements
    |
    ;

statements
    : statement { Fast_Parser_reset(yparser()); fast_op;}
    | statements statement { Fast_Parser_reset(yparser()); fast_op;}
    | error {
        $$=NULL;
        if(!yparser()->errors) {
            printf("unreported error:%d: Fast_Parser.c:%d\n", yparser()->line, yparser()->errLine);
        }
    }
    ;

statement
    : expr ENDL                 {Fast_Parser_addStatement(yparser(), $1); fast_op; Fast_Parser_define(yparser()); fast_op;}
    | if_statement              {Fast_Parser_addStatement(yparser(), $1); fast_op;}
    | while_statement           {Fast_Parser_addStatement(yparser(), $1); fast_op;}
    | switch_statement          {Fast_Parser_addStatement(yparser(), $1); fast_op;}
    | declaration ENDL          {$$=NULL;}
    | scope_statement           {$<Variable>$ = Fast_Parser_pushScope(yparser()); Fast_Parser_pushLvalue(yparser(),NULL, FALSE); fast_op;} scope {Fast_Parser_popScope(yparser(),$<Variable>2); fast_op;}
    | function_declaration ENDL {$$=NULL;}
    | function_implementation   {$$=NULL;}
    | observer_statement        {$$=NULL;}
    | update_statement          {Fast_Parser_addStatement(yparser(), $1); fast_op;}
    | block                     {Fast_Parser_addStatement(yparser(), $1); fast_op;}
    | package_declaration ENDL
    | ENDL                      {$$=NULL;}
    | TAB                       {Fast_Parser_error(yparser(), "usage of tabs is not allowed");}
    ;

/* ======================================================================== */
/* Scoping */
/* ======================================================================== */
scope
    : SCOPE INDENT statements DEDENT {Fast_Parser_defineScope(yparser()); fast_op;}
    | SCOPE statement                {Fast_Parser_defineScope(yparser()); fast_op;}
    | SCOPEPRE {Fast_Parser_defineScope(yparser()); fast_op;} INDENT statements DEDENT
    | SCOPEPRE {Fast_Parser_defineScope(yparser()); fast_op;} statement
    ;

scope_statement
    : expr {if (!yparser()->variableCount) {yparser()->variables[0] = $1; yparser()->variableCount=1;}}
    | declaration
    ;

/* ======================================================================== */
/* Block (and loop until) */
/* ======================================================================== */
block_start
    : ':' INDENT {$$ = Fast_Parser_blockPush(yparser(), FALSE); fast_op;}
    ;

block
    : block_start statements {Fast_Parser_blockPop(yparser()); fast_op;} DEDENT     {$$=$1;}
    | ':' {$<Fast>$=Fast_Parser_blockPush(yparser(), FALSE); fast_op;} statement {Fast_Parser_blockPop(yparser()); fast_op; $$=$<Fast>2;}
    ;

/* ======================================================================== */
/* Function declarations */
/* ======================================================================== */
function_implementation
    : function_declaration {
        $<Fast>$ = Fast_Parser_declareFunctionParams(yparser(),$1); fast_op;
    } block {
        if ($<Fast>2) {
            Fast_Parser_bind(yparser(), $1, $<Fast>2); fast_op;
        }
    }
    | function_declaration {
        $<Fast>$ = Fast_Parser_declareFunctionParams(yparser(),$1); fast_op;
        Fast_Parser_blockPush(yparser(), FALSE); fast_op;
        Fast_Parser_pushReturnAsLvalue(yparser(), Fast_Object($1)->value); fast_op;
    } '=' expr ENDL {
        Fast_Parser_popLvalue(yparser()); fast_op;
        Fast_Parser_bindOneliner(yparser(), $1, $<Fast>2, $4); fast_op;
        Fast_Parser_blockPop(yparser()); fast_op;
    }
    ;

function_declaration
    : identifier any_id function_argumentList    {cx_id id; sprintf(id, "%s(%s)", $2, $3); cx_dealloc($3); $$ = Fast_Parser_declareFunction(yparser(), $1 ? Fast_Object($1)->value : NULL, id, NULL, FALSE); fast_op; }
    | identifier any_id function_argumentList identifier_string  {
        cx_id id;
        cx_type kind = cx_resolve(NULL, $4);
        if (!kind) {
            Fast_Parser_error(yparser(), "%s not found", $4);
            YYERROR;
        }
        sprintf(id, "%s(%s)", $2, $3);
        cx_dealloc($3);
        $$ = Fast_Parser_declareFunction(yparser(), $1 ? Fast_Object($1)->value : NULL, id, kind, FALSE); fast_op;
        cx_release(kind);
    }
    | identifier GID function_argumentList  {cx_id id; sprintf(id, "%s(%s)", $2, $3); cx_dealloc($3); $$ = Fast_Parser_declareFunction(yparser(), $1 ? Fast_Object($1)->value : NULL, id, NULL, FALSE); fast_op; }

    /* Reference returnvalue */
    | identifier '&' any_id function_argumentList   {cx_id id; sprintf(id, "%s(%s)", $3, $4); cx_dealloc($4); $$ = Fast_Parser_declareFunction(yparser(), $1 ? Fast_Object($1)->value : NULL, id, NULL, TRUE); fast_op; }
    | identifier '&' any_id function_argumentList identifier_string  {
        cx_id id;
        cx_type kind = cx_resolve(NULL, $5);
        if (!kind) {
            Fast_Parser_error(yparser(), "%s not found", $4);
            YYERROR;
        }
        sprintf(id, "%s(%s)", $3, $4);
        $$ = Fast_Parser_declareFunction(yparser(), $1 ? Fast_Object($1)->value : NULL, id, kind, TRUE); fast_op;
        cx_release(kind);
    }
    | identifier '&' GID function_argumentList  {cx_id id; sprintf(id, "%s(%s)", $3, $4); cx_dealloc($4); $$ = Fast_Parser_declareFunction(yparser(), $1 ? Fast_Object($1)->value : NULL, id, NULL, TRUE); fast_op; }
    ;

function_argumentList
    : '(' ')'                       {$$ = cx_strdup("");}
    | '(' function_arguments ')'    {$$ = $2;}
    ;

function_arguments
    : function_argument                           {$$=cx_alloc(sizeof(cx_id));strcpy($$,$1); cx_dealloc($1);}
    | function_arguments ',' function_argument    {$$=$1; strcat($$,","); strcat($$,$3); cx_dealloc($3);}
    ;

function_argument
    : identifier any_id {
        $$=Fast_Parser_argumentToString(yparser(), $1 ? Fast_Object($1)->value : NULL, $2, FALSE); fast_op;
    }
    | identifier '&' any_id {
        $$=Fast_Parser_argumentToString(yparser(), $1 ? Fast_Object($1)->value : NULL, $3, TRUE); fast_op;
    }
    | '$' any_id {
        cx_id argid;
        sprintf(argid, "$%s", $2);
        if (!strcmp($2, "__line")) {
            $$=Fast_Parser_argumentToString(yparser(), cx_uint32_o, argid, FALSE); fast_op;
        } else {
            $$=Fast_Parser_argumentToString(yparser(), cx_string_o, argid, FALSE); fast_op;            
        }
    }
    ;

/* ======================================================================== */
/* Declarations */
/* ======================================================================== */

package_declaration
    : PACKAGE GID {
        Fast_Parser_pushPackage(yparser(), $2); fast_op;
    }
    ;

declaration
    : identifier declaration_list { $$=Fast_declarationSeqDo($1, &$2, FALSE); fast_op; $$=NULL; }
    | KW_LOCAL {yparser()->isLocal = TRUE;} declaration_ref     {$$=$3;}
    ;

declaration_ref
    : identifier declaration_list       {$$=Fast_declarationSeqDo($1, &$2, FALSE); fast_op;}
    | identifier '&' declaration_list   {$$=Fast_declarationSeqDo($1, &$3, TRUE); fast_op;}
    ;

declaration_list
    : declaration_id                        {$$.length = 0; $$.buffer = NULL; Fast_declarationSeqInsert(&$$, &$1);}
    | declaration_list ',' declaration_id   {Fast_declarationSeqInsert(&$1, &$3); $$ = $1;}
    ;

declaration_id
    : any_id    {$$.name = $1;}
    ;

/* ======================================================================== */
/* Initializer */
/* ======================================================================== */
initializer
    : init_list_value {$$=NULL;}
    | initializer ',' init_list_value
    ;

init_list_value
    : init_value
    | init_list_colon
    ;

init_value
    : initializer_braces
    | logical_or_expr           {if ($1) Fast_Parser_initValue(yparser(), $1); fast_op}
    ;

initializer_braces
    : '{' {Fast_Parser_initPush(yparser()); fast_op;} initializer {Fast_Parser_initPop(yparser()); fast_op;} '}' {$$=$3;}
    | '{' '}' {Fast_Parser_initPush(yparser()); fast_op; Fast_Parser_initPop(yparser()); fast_op; $$=NULL;}
    ;

init_list_colon
    : init_colon
    | init_list_colon init_colon
    ;

init_colon
    : any_id '=' {Fast_Parser_initMember(yparser(), $1); fast_op;} init_value
    | init_key '=' init_value
    ;

init_key
    : '@' {Fast_Parser_initKeyValuePush(yparser());} initializer_braces {Fast_Parser_initKeyValuePop(yparser());}
    | literal_expr {Fast_Parser_initKeyValueSet(yparser(), $1);}
    ;

/* ======================================================================== */
/* Expressions */
/* ======================================================================== */
literal_expr
    : BOOLEAN               {$$=Fast_BooleanCreate($1); Fast_Parser_collect(yparser(), $$);}
    | CHARACTER             {$$=Fast_CharacterCreate($1); Fast_Parser_collect(yparser(), $$);}
    | INTEGER               {$$=Fast_IntegerCreate($1); Fast_Parser_collect(yparser(), $$);}
    | SIGNEDINTEGER         {$$=Fast_SignedIntegerCreate($1); Fast_Parser_collect(yparser(), $$);}
    | FLOATINGPOINT         {$$=Fast_FloatingPointCreate($1); Fast_Parser_collect(yparser(), $$);}
    | STRING                {$$=Fast_StringCreate($1); Fast_Parser_collect(yparser(), $$);}
    | NUL                   {$$=Fast_NullCreate(); Fast_Parser_collect(yparser(), $$);}
    ;

bracket_expr
    : '(' {PUSHLVALUE(NULL)} wait_expr ')' {POPLVALUE(); $$=$3;}
    ;

primary_expr
    : bracket_expr
    | literal_expr          {$$ = $1;}
    | identifier            {$$ = $1;}
    ;

iter_expr
    : primary_expr
    | '*' iter_expr {$$ = Fast_Parser_unaryExpr(yparser(), $2, CX_MUL); fast_op;}
    ;

postfix_expr
    : iter_expr
    | postfix_expr {PUSHCOMPLEX($1)} '[' expr ']' {$$ = Fast_Parser_elementExpr(yparser(), $1, $4); fast_op; POPCOMPLEX()}
    | postfix_expr '(' ')'                        {$$ = Fast_Parser_callExpr(yparser(), $1, NULL); fast_op;}
    | postfix_expr bracket_expr                   {$$ = Fast_Parser_callExpr(yparser(), $1, $2); fast_op;}
    | postfix_expr '.' any_id                     {Fast_String str = Fast_StringCreate($3); if (!str) {YYERROR;} $$ = Fast_Parser_memberExpr(yparser(), $1, Fast_Expression(str)); cx_release(str); fast_op;}
    | postfix_expr '.' KW_DESTRUCT                {Fast_String str = Fast_StringCreate("delete"); if (!str) {YYERROR;} $$ = Fast_Parser_memberExpr(yparser(), $1, Fast_Expression(str)); cx_release(str); fast_op;}
    | postfix_expr INC                            {$$ = Fast_Parser_postfixExpr(yparser(), $1, CX_INC); fast_op}
    | postfix_expr DEC                            {$$ = Fast_Parser_postfixExpr(yparser(), $1, CX_DEC); fast_op}
    ;

unary_expr
    : postfix_expr
    | unary_operator postfix_expr     {$$ = Fast_Parser_unaryExpr(yparser(), $2, $1); fast_op;}
    ;

unary_operator
    : '-' {$$ = CX_SUB;}
    | '~' {$$ = CX_NOT;}
    | '!' {$$ = CX_COND_NOT;}
    | LNOT {$$ = CX_COND_NOT;}
    | INC {$$ = CX_INC;}
    | DEC {$$ = CX_DEC;}
    | '&' {$$ = CX_AND;}
    ;

multiplicative_expr
    : unary_expr
    | multiplicative_expr {PUSHLVALUE($1)} multiplicative_operator unary_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, $3); fast_op;}
    ;

multiplicative_operator
    : '*' {$$ = CX_MUL;}
    | '/' {$$ = CX_DIV;}
    | '%' {$$ = CX_MOD;}
    ;

additive_expr
    : multiplicative_expr
    | additive_expr {PUSHLVALUE($1)} additive_operator multiplicative_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, $3); fast_op;}
    ;

additive_operator
    : '+' {$$ = CX_ADD;}
    | '-' {$$ = CX_SUB;}
    ;

shift_expr
    : additive_expr
    | shift_expr {PUSHLVALUE($1)} SHIFT_LEFT additive_expr  {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, CX_SHIFT_LEFT); fast_op;}
    | shift_expr {PUSHLVALUE($1)} SHIFT_RIGHT additive_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, CX_SHIFT_RIGHT); fast_op;}
    ;

and_expr
    : shift_expr
    | and_expr {PUSHLVALUE($1)} '&' shift_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, CX_AND); fast_op;}
    ;

xor_expr
    : and_expr
    | xor_expr {PUSHLVALUE($1)} '^' and_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, CX_XOR); fast_op;}
    ;

or_expr
    : xor_expr
    | or_expr {PUSHLVALUE($1)} '|' xor_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, CX_OR); fast_op;}
    ;

boolean_expr
    : or_expr
    | boolean_expr {PUSHLVALUE($1)} boolean_operator or_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, $3); fast_op;}
    ;

boolean_operator
    : '<' {$$ = CX_COND_LT;}
    | '>' {$$ = CX_COND_GT;}
    | LEQ {$$ = CX_COND_LTEQ;}
    | GEQ {$$ = CX_COND_GTEQ;}
    ;

equality_expr
    : boolean_expr
    | equality_expr {PUSHLVALUE($1)} equality_operator boolean_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, $3); fast_op;}
    ;

equality_operator
    : EQ {$$ = CX_COND_EQ;}
    | NEQ {$$ = CX_COND_NEQ;}
    ;

logical_and_expr
    : equality_expr
    | logical_and_expr {PUSHLVALUE($1)} LAND equality_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, CX_COND_AND); fast_op;}
    ;

logical_or_expr
    : logical_and_expr
    | logical_or_expr {PUSHLVALUE($1)} LOR logical_and_expr {POPLVALUE()} {$$ = Fast_Parser_binaryExpr(yparser(), $1, $4, CX_COND_OR); fast_op;}
    ;

initializer_expr
    : {$<Fast>$ = Fast_Parser_initPushExpression(yparser()); fast_op;} initializer_braces {$$=$<Fast>1;}
    | logical_or_expr
    ;

conditional_expr
    : initializer_expr
    | initializer_expr '?' conditional_expr ':' conditional_expr {$$=Fast_Parser_ternaryExpr(yparser(), $1, $3, $5); fast_op;}
    ;

comma_expr
    : conditional_expr
    | comma_expr ',' conditional_expr {
        if ($1 && $3) {
            if (Fast_Node($1)->kind != Fast_CommaExpr) {
                $$ = Fast_CommaCreate(); fast_op;
                Fast_Comma_addExpression($$, $1); fast_op;
                Fast_Parser_collect(yparser(), $$); fast_op;
            }
            Fast_Comma_addExpression($$, $3); fast_op;
        }
    }
    ;

assignment_expr
    : comma_expr
    | assignment_expr {PUSHASSIGN($1)} assignment_operator comma_expr {POPLVALUE()} {
        $$ = Fast_Parser_binaryExpr(yparser(), $1, $4, $3); fast_op;
    }
    ;

assignment_operator
    : '=' {$$ = CX_ASSIGN;}
    | ADD_ASSIGN {$$ = CX_ASSIGN_ADD;}
    | SUB_ASSIGN {$$ = CX_ASSIGN_SUB;}
    | MUL_ASSIGN {$$ = CX_ASSIGN_MUL;}
    | DIV_ASSIGN {$$ = CX_ASSIGN_DIV;}
    | AND_ASSIGN {$$ = CX_ASSIGN_AND;}
    | OR_ASSIGN  {$$ = CX_ASSIGN_OR;}
    | UPDATE_ASSIGN {$$ = CX_ASSIGN_UPDATE;}
    ;

wait_expr
    : assignment_expr
    | KW_WAIT assignment_expr                            {$$ = Fast_Parser_waitExpr(yparser(), $2, NULL); fast_op;}
    | KW_WAIT assignment_expr KW_FOR logical_or_expr    {$$ = Fast_Parser_waitExpr(yparser(), $2, $4); fast_op;}
    ;

declaration_expr
    : wait_expr
    | wait_expr ':' {
        Fast_Parser_initDeclareStaged(yparser(), NULL); fast_op;
        Fast_Parser_initPushStatic(yparser()); fast_op;
    } initializer {
        Fast_Parser_initPop(yparser()); fast_op;
        $$ = NULL;
    }
    | wait_expr ':' {
        Fast_Parser_initDeclareStaged(yparser(), NULL); fast_op;
        Fast_Parser_initPushStatic(yparser()); fast_op;
        Fast_Parser_initPop(yparser()); fast_op;
        $$ = NULL;
    }
    | declaration ':' {Fast_Parser_initPushStatic(yparser()); fast_op;} initializer {Fast_Parser_initPop(yparser()); fast_op;}
    | declaration '{' {Fast_Parser_initPushStatic(yparser()); fast_op;} initializer {Fast_Parser_initPop(yparser()); fast_op;} '}'
    | declaration '{' {Fast_Parser_initPushStatic(yparser()); fast_op; Fast_Parser_initPop(yparser()); fast_op;} '}'
    | declaration ':' {Fast_Parser_initPushStatic(yparser()); fast_op; Fast_Parser_initPop(yparser()); fast_op;}
    | declaration '=' {
        if (!yparser()->isLocal && !yparser()->blockCount) {
            _fast_err("invalid usage of assignment operator, initialize objects with ':'");
            YYERROR;
        }
        Fast_Parser_pushLvalue(yparser(), $1, TRUE);
    } comma_expr  {
        $$ = Fast_Parser_binaryExpr(yparser(), $1, $4, CX_ASSIGN); fast_op;
        Fast_Parser_popLvalue(yparser());
    }
    ;

expr
    : declaration_expr
    ;

/* ======================================================================== */
/* Identifier */
/* ======================================================================== */
identifier
    : identifier_id
    | identifier {
        $<Variable>$ = Fast_Storage(Fast_Parser_initPushIdentifier(yparser(), (Fast_Expression)$1)); fast_op
    } initializer_braces {
        $$ = $<Variable>2;
        if ($$) {
            Fast_Parser_define(yparser()); fast_op;
        }
    }
    ;

identifier_id
    : identifier_string {$$ = Fast_Parser_lookup(yparser(), $1); fast_op;}
    ;

identifier_string
    : GID
    | any_id
    ;

any_id
    : ID
    | '@' KW_SCOPE {$$ = "scope";}
    | '@' KW_UPDATE {$$ = "update";}
    | '@' KW_DECLARE {$$ = "declare";}
    | '@' KW_DEFINE {$$ = "define";}
    | '@' KW_DESTRUCT {$$ = "destruct";}
    | '@' KW_WAIT {$$ = "wait";}
    | '@' KW_ON {$$ = "on";}
    | '@' KW_SELF {$$ = "self";}
    | '@' KW_SYNCHRONIZED {$$ = "synchronized";}
    | '@' KW_IF {$$ = "if";}
    | '@' KW_ELSE {$$ = "else";}
    | '@' KW_WHILE {$$ = "while";}
    | '@' KW_SWITCH {$$ = "switch";}
    | '@' KW_CASE {$$ = "case";}
    | '@' KW_DEFAULT {$$ = "default";}
    | '@' KW_BREAK {$$ = "break";}
    | '@' KW_FOR {$$ = "for";}
    | '@' KW_TRY {$$ = "try";}
    | '@' KW_CATCH {$$ = "catch";}
    | '@' KW_IMPORT {$$ = "import";}
    | '@' KW_LOCAL {$$ = "local";}
    | '@' LAND {$$ = "and";}
    | '@' LOR {$$ = "or";}
    | '@' LNOT {$$ = "not";}
    | '@' SCOPE {$$ = "::";}
    | KW_DECLARE {$$ = "declare";}
    | KW_DEFINE {$$ = "define";}
    ;

/* ======================================================================== */
/* If statement */
/* ======================================================================== */
if_statement
    : if_start block                         {$$=Fast_Parser_ifStatement(yparser(), $1, $2, NULL); fast_op;}
    | if_start block KW_ELSE block            {Fast_If nestedIf = Fast_If(Fast_Parser_ifStatement(yparser(), NULL, $4, NULL)); fast_op; $$=Fast_Parser_ifStatement(yparser(), $1, $2, nestedIf); fast_op;}
    | if_start block KW_ELSE if_statement     {$$=Fast_Parser_ifStatement(yparser(), $1, $2, $4); fast_op;}
    ;

if_start
    : KW_IF wait_expr        {$$=$2;}
    ;

/* ======================================================================== */
/* While statement */
/* ======================================================================== */
while_statement
    : while_until block     {$$ = Fast_Parser_whileStatement(yparser(), $1, $2, FALSE); fast_op;}
    | while_until ENDL        {$$ = Fast_Parser_whileStatement(yparser(), $1, yparser()->block, TRUE); fast_op;}
    ;

while_until
    : KW_WHILE wait_expr {$$=$2;}
    ;

/* ======================================================================== */
/* Switch statement */
/* ======================================================================== */
switch_statement
    : KW_SWITCH wait_expr ':' case_list INDENT switch_statements DEDENT    {$$=NULL;}
    | KW_SWITCH wait_expr ':' switch_statements DEDENT                    {$$=NULL;}
    ;

switch_statements
    : statement
    | case_statement
    | switch_statements statement
    | switch_statements case_statement
    ;

case_statement
    : DEDENT case_list INDENT    {$$=NULL;}
    ;

case_list
    : case_label
    | case_list case_label
    ;

case_label
    : KW_CASE wait_expr ':'
    | KW_DEFAULT   ':'
    ;

/* ======================================================================== */
/* Observer statement */
/* ======================================================================== */
observer_statement
    : observer_declaration block {}
    | observer_declaration ENDL {yparser()->blockCount--;}
    ;

observer_declaration
    : observer_dispatch event_mask assignment_expr  {$$=NULL; Fast_Parser_observerDeclaration(yparser(), NULL, $3, $2, $1); fast_op;}
    ;

observer_dispatch
    : KW_ON                 {$$=NULL; Fast_Parser_observerPush(yparser());}
    ;

event_mask
    : event_flag
    | event_mask '|' event_flag         {$$ = $1 | $3;}
    ;

event_flag
    : event_baseflag
    | event_childflag
    | event_baseflag event_childflag    {$$ = $1 | $2;}
    ;

event_baseflag
    : KW_UPDATE         {$$ = CX_ON_UPDATE;}
    | KW_DECLARE        {$$ = CX_ON_DECLARE;}
    | KW_DEFINE         {$$ = CX_ON_DEFINE;}
    | KW_DESTRUCT       {$$ = CX_ON_DELETE;}
    ;

event_childflag
    : KW_SELF           {$$ = CX_ON_SELF;}
    | KW_SCOPE          {$$ = CX_ON_SCOPE;}
    | KW_SYNCHRONIZED   {$$ = CX_ON_VALUE;}
    ;

/* ======================================================================== */
/* Update statement */
/* ======================================================================== */
update_statement
    : KW_UPDATE postfix_expr ENDL    {$$ = Fast_Parser_updateStatement(yparser(), $2, NULL); fast_op;}
    | KW_UPDATE postfix_expr block  {$$ = Fast_Parser_updateStatement(yparser(), $2, $3); fast_op;}
    ;


%%

/* ======================================================================== */
/* Parser */
/* ======================================================================== */

void yyerror(const char *str)
{
    Fast_Parser p = yparser();
    Fast_reportError(p->filename, p->line, p->column, (cx_string)str, p->token);
    p->errors++;
}

/* Parse sourcecode */
int fast_yparse(Fast_Parser parser, cx_uint32 line, cx_uint32 column) {
    int len = strlen(parser->source);

    /* Prepend and append the source with a newline */
    char *sourceWithNewline = cx_alloc(len + 3);
    sourceWithNewline[0] = '\n';
    strcpy(sourceWithNewline + 1, parser->source);
    sourceWithNewline[len + 1] = '\n';
    sourceWithNewline[len + 2] = '\0';

    /* Set pointer to source */
    yy_scan_string((char *) sourceWithNewline);

    /* Start parsing */
    parser->line = line;
    parser->column = column;

    yparser()->blockCount = 0;

    if (!parser->block) {
        parser->block = Fast_BlockCreate(NULL);
        parser->block->isRoot = TRUE;

        /* Declare argv variable */
        cx_type t = cx_resolve(NULL, "sequence{string}");
        Fast_Block_declare(parser->block, "argv", t, TRUE, FALSE);
        cx_release(t);
    }

    if (!parser->scope) {
        cx_setref(&parser->scope, root_o);
    }

    /* Compensate for insertion of the extra \n */
    parser->line--;
    yyparse();

    /* Destroy lexer resources */
    /*yylex_destroy();*/

    /* Set token to NULL - it points to lexer-memory */
    yparser()->token = NULL;
    cx_dealloc(sourceWithNewline);

    return yparser()->errors;
}
