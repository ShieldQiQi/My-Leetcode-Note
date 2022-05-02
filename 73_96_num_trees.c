#include <stdio.h>
#include <stdlib.h>

int dfs(int low, int high)
{
    int ans = 0;
    for (int i=low; i<=high; i++) {
        int left_num = 1, right_num = 1;
        if (i-low>1)
            left_num = dfs(low, i-1);
        if (high-i>1)
            right_num = dfs(i+1, high);
        ans += left_num * right_num;
    }
    return ans;
}


int numTrees(int n)
{
    int ans = 0;
    int *dp = (int*)malloc(sizeof(int)*(n+1));
    dp[0] = 1;
    for (int i=1; i<=n; i++) {
        dp[i] = 0;
        for(int j=1; j<=i; j++)
            dp[i] += dp[j-1]*dp[i-j]; 
    }
    return dp[n];
}

int main()
{
    printf("%d", numTrees(4));
    return 0;
}