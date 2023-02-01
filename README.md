## Variables

Name | Description
---- | -----------
n    | number of lines
m    | maximum number of columns
i    | line index
j    | column index
c_i  | number of columns at line i 

## Compilation

`g++ -std=c++11 -O3 -Wall <filename>.cpp -lm`

## Tests

To run a test just execute: `./a.out < <test>`

Tests provided (inside tests folder):
- X.txt (result: 0)
- Y.txt (result: 1)
- W.txt (result: 58)
- Z.txt (result: 13807553414899)

## Instance Generator

How to compile:
`g++ -std=c++11 -O3 -Wall ladrilho_valido.cpp -lm -o gerador`

How to execute:
`./gerador <num-of-lines> <num-of-columns> <seed> > <test>`