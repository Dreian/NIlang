parser grammar NIParser;

options {
  tokenVocab = NILexer;
}

prog: (var_specs)? begin_end DOT EOF
;

exp: minus_exp
   | not_exp
   | binop_exp
   | bool_binop_exp
   | term
;

term: par_exp
    | int_term
    | bool_term
    | ident_term
;

int_term: Int
;

bool_term: Bool
;

ident_term: Ident
;

par_exp: LPAR exp RPAR
;

not_exp: NOT exp
;

minus_exp: MINUS exp
;

binop_exp: term (TIMES | DIV) exp
         | term (PLUS | MINUS) exp
         | term (EQ | NEQ | LEQ | GEQ | GT | LT) exp
;

bool_binop_exp: term AND exp
              | term OR exp
;

stat: assignment
    | if_then_else
    | if_then
    | while_loop
    | print
;

assignment: Ident ASSIGN exp
;

if_then: IF exp THEN stat_block
;

if_then_else: IF exp THEN stat_block ELSE stat_block
;

while_loop: WHILE exp DO stat_block
;

print: PRINT LPAR exp RPAR
;

var_decl: Ident COLON Typename
;

var_specs: VAR (var_decl SEMI)+
;

stat_seq: stat (SEMI stat)*
;

stat_block: stat
          | begin_end
;

begin_end: BEGIN stat_seq END
;
