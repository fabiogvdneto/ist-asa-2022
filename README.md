**VARIABLES**

```
n   = número de linhas
m   = número de colunas
i   = índice de uma linha
j   = índice de uma coluna
c_i = índice da coluna pela qual a escada passa na i-ésima linha 
```

**REALIZATION**

TODO

**COMPILATION**

`g++ -std=c++11 -O3 -Wall <filename>.cpp -lm`

**TESTS**

Execution:
`./a.out < <test>`

Tests provided (inside tests folder):
- X.txt (result: 0)
- Y.txt (result: 1)
- W.txt (result: 58)
- Z.txt (result: 13807553414899)

**INSTANCE GENERATOR**

Compilation:
`g++ -std=c++11 -O3 -Wall ladrilho_valido.cpp -lm -o gerador`

Execution:
`./gerador <num-of-lines> <num-of-columns> <seed> > <test>`