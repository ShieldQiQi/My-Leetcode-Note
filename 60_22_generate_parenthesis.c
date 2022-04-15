#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize)
{
    char ***dp = (char***)malloc(sizeof(char**)*(n+1));
    int *count = (int*)malloc(sizeof(int)*(n+1));
    count[0] = 1;
    dp[0] = (char**)malloc(sizeof(char*));
    dp[1] = (char**)malloc(sizeof(char*));
    dp[1][0] = (char*)malloc(sizeof(char)*3);
    count[1] = 1;
    dp[1][0][0] = '(';
    dp[1][0][1] = ')';
    dp[1][0][2] = NULL;

    for(int i=2; i<=n; i++)
    {
        count[i] = 0;
        for(int j=0; j<i; j++)
            count[i] += count[j]*count[i-1-j];
        dp[i] = (char**)malloc(sizeof(char*)*count[i]);
        
        int index = 0;
        dp[i][index] = (char*)malloc(sizeof(char)*2*n+1);
        dp[i][index][0] = '(';
        dp[i][index][2*n] = NULL;
        for(int j=i-1; j>=0; j--)
        {
            for(int m=1; m<=count[j]; m++)
            {
                memcpy(dp[i][index]+1, dp[j][m-1], j*2);
                dp[i][index][2*j+1] = ')';
                int k = i-j-1;
                for(int q=1; q<=count[k]; q++)
                {
                    memcpy(dp[i][index]+2+j*2, dp[k][q-1], k*2);
                    if(index==count[i]-1)
                        break;
                    index++;
                    dp[i][index] = (char*)malloc(sizeof(char)*2*n+1);
                    dp[i][index][0] = '(';
                    memcpy(dp[i][index]+1, dp[j][m-1], j*2);
                    dp[i][index][2*j+1] = ')';
                    dp[i][index][2*n] = NULL;
                }
            }
        }
    }
    *returnSize = count[n];
    return dp[n];
}

int main()
{
    int returnSize;
    char **ans = generateParenthesis(4, &returnSize);
    for(int i=0;i<returnSize; i++)
    {
        int j=0;
        while(ans[i][j] != NULL)
        {
            printf("%c", ans[i][j]);
            j++;
        }
        printf(",");
    }
    return 0;
}