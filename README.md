**VARIABLES**  
```
n   = número de linhas
m   = número de colunas
i   = índice de uma linha
j   = índice de uma coluna
c_i = índice da coluna pela qual a escada passa na i-ésima linha 
```

**REALIZATION**  
```
memo[i, 0] = 1  
memo[0, j] = 1  
memo[i, j] = (memo[i-1, c] - 1) * 2 + 1,   if (i > c)  
memo[i, j] = (memo[i, c-1] - 1) * 2 + 1,   if (c > i)  
memo[i, j] = (memo[i-1, c-1] - 1) * 4 + 2, if (i == c)
```

**RESULTS**

```
# INPUT  
4
5
0
2
3
5

# MATRIX  
1  1  1  1  1  
1  2  3
1  3

# OUTPUT
4

# Input
3
4
4
4
4

# Matrix
1  1  1  1
1  2  3  5
1  3  6 13

1x1 square 2x2 square   3x3 square
anterior + floor((m-2)/2)

# Output
13
```