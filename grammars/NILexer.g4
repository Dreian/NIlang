lexer grammar NILexer;

Int: DIGIT+;
Bool: TRUE | FALSE;
Typename: BOOLEAN | INTEGER;

LT: '<';
GT: '>';
LEQ: '<=';
GEQ: '>=';
EQ: '=';
NEQ: '<>';
AND: 'and';
OR: 'or';
NOT: 'not';
TRUE: 'true';
FALSE: 'false';

ASSIGN: ':=';
COMMA: ',';
DOT: '.';
COLON: ':';
SEMI: ';';
PLUS: '+';
MINUS: '-';
TIMES: '*';
DIV: 'div';

LPAR: '(';
RPAR: ')';
VAR: 'var';

BOOLEAN: 'boolean';
INTEGER: 'integer';
IF: 'if';
THEN: 'then';
ELSE: 'else';
WHILE: 'while';
DO: 'do';
BEGIN: 'begin';
END: 'end';
PRINT: 'print';

Ident: LETTER (LETTER | DIGIT | UNDER)*;

WS: [ \t\r\n]+ -> skip;
DIGIT: [0-9];
LETTER: [a-zA-Z];
UNDER: '_';


