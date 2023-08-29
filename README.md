# Compiler-Design

This repository includes files from my Compiler Design Laboratory course (CS301P) at Indian Institute of Technology Tirupati

**Course Objective**: To learn the principles, techniques and tools required in developing compilers in a systematic way; To gain an understanding on different theoretical and systems concepts from computer science coming together in building a compiler.

## Installation of Dependencies
Follow the instructions in this link to install lex and yacc: [Click here](https://faculty.ksu.edu.sa/sites/default/files/lex_and_yacc_installation.pdf)

### Lexers and Grammars for C Syntax and CFGs and other Grammars
This repository contains a collection of lexers and grammars written using Lex/Flex. These lexers are designed to tokenize input C code and recognize specific patterns in the code. The grammars are implemented to parse and analyze context-free grammars (CFGs) and regular grammars (RGs).


### Steps to run the files

**Step 1:** Open the directory **cs21b027_labx** in terminal. \newline
**Step 2:** Run the following commands

```
make clean
make fname=lexer.l
./lexer input.txt
```

> Note that you can rename **lexer.l** as whichever lex file you want to compile.
> Replace **./lexer** with the executable file created after make command: **./<filename>**
> Also, you can use any input file apart from **input.txt**.


Make sure to check if you have lex/flex installed. Also, running `make clean` after you have completed running the programs is a good practice. 
