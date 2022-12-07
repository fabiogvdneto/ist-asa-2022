#include <stdio.h>

int main() {
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    int memo[n][m];
    int c[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", c+n-i-1);
    }

    int res = 0;

    for (int i = 0; (i < n); i++) {
        for (int j = 0; (j < c[i]); j++) {
            if ((i == 0) || (j == 0)) {
                memo[i][j] = 1;
            } else if (i > j) {
                memo[i][j] = (memo[i-1][j] - 1) * 2 + 1;
            } else if (j > i) {
                memo[i][j] = (memo[i][j-1] - 1) * 2 + 1;
            } else {
                memo[i][j] = (memo[i-1][j-1] - 1) * 4 + 2;
            }

            printf("%d ", memo[i][j]);
        }
        printf("\n");
    }
    
    printf("%d\n", res);

    return 1;
}