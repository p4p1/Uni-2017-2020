# evalexpr

A LL Mathematical Parser written in Haskell.
" ""
How to use make
./funEvalExpr "3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1"
""

BNF grammar
S         ::= op_low
op_low    ::= op_high[['+'|'-']op_high]*
op_high   ::= path[[''|'/'|'%']path]
path      ::= '('S')'|number
number    ::= ['0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9']+
