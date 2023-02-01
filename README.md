# Project 1

In a nutshell, we want to tile a given area inside a rectangle delimited by a stairway.
To do that we can only use squares (of any size).
Our goal is to find the number of distinct configurations that allow us to fill that area.
All project details and examples can be found in the statement pdf.

The project submission includes a brief report (report.pdf) and the source code (main.cpp).

## Variables

Name | Description
---- | -----------
n    | number of lines
m    | maximum number of columns
i    | line index
j    | column index
c_i  | number of columns at line i 

## Compilation

Recommended way to compile the program: `g++ -std=c++11 -O3 -Wall <filename>.cpp -lm`

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