# To implement the translation of different program constructs (arithmetic expressions and
selection statements) to equivalent three address codes.

## Implement a CFG grammar with associated semantic rules to translate the arithmetic expressions (including post/pre increment/decrement operators as completed in Lab #6) and two-way selection statements of C language to equivalent three address code.

## For running prob1:
```
make fname=prob1
./parser inp1.txt
```

Makefile is using ll as a linker. 

### Note:

<b>1. This parser accepts arthemetic expressions containing operators +, −, ∗, /, − (unary minus), pre/post increment/decrement operators, assignment operator (=), the parenthesis ( ) and statement termintor (;). </b>

<b>2. Make sure to separate all inputs (correct or incorrect) with semicolons as delimiters as specified in the question</b>
