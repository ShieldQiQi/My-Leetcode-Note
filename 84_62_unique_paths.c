#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n)
{
    int **dp = (int**)malloc(sizeof(int*)*m);
    for (int i=0; i<m; i++)
        dp[i] = (int*)malloc(sizeof(int)*n);
    
    dp[0][0] = 1;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (i || j)
                dp[i][j] = (i-1>=0?dp[i-1][j]:0) + (j-1>=0?dp[i][j-1]:0);
        }
    }

    return dp[m-1][n-1];
}

int main()
{

    printf("%d ", uniquePaths(3, 7));

    return 0;
}
