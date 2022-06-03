#!/bin/bash

bison -v -d --file-prefix=y miniL.y
flex miniL.lex
gcc -o miniL y.tab.c lex.yy.c -lfl