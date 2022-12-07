n   = número de linhas
m   = número de colunas
i   = índice de uma linha
j   = índice de uma coluna
c_i = índice da coluna pela qual a escada passa na i-ésima linha 

memo[i, 0] = 1
memo[0, j] = 1
memo[i, j] = (memo[i-1, c] - 1) * 2 + 1,   if (i > c)
memo[i, j] = (memo[i, c-1] - 1) * 2 + 1,   if (c > i)
memo[i, j] = (memo[i-1, c-1] - 1) * 4 + 2, if (i == c)

----
INPUT
3
4
4
4
4
----
MATRIX
1  1  1  1 
1  2  3  5 
1  3  6 13
----
OUTPUT
13

----
INPUT
4
5
0
2
3
5
----
MATRIX
1  1  1  1  1 
1  2  3 
1  3
----
OUTPUT
4

----
INPUT
4
6
5
5
6
6
----
MATRIX
1  1  1  1  1  1 
1  2  3  5  9 17 
1  3  6 13 21
1  5 13 22 43
----
OUTPUT
13