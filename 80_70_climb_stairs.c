#include <stdio.h>
#include <stdlib.h>

void dfs(int remain, int *ans)
{
    if (remain - 1 > 0) {
        dfs(remain - 1, ans);
    } else if (remain - 1 == 0) {
        *ans += 1;
        return;
    } else {
        return;
    }
    if (remain - 2 > 0) {
        dfs(remain - 2, ans);
    } else if (remain - 2 == 0) {
        *ans += 1;
        return;
    } else {
        return;
    }
}

int climbStairs(int n)
{
    // int ans = 0;
// DFS回溯
    // dfs(n, &ans);
// 数学方法
    // int num = 1, den = 1, count, min;
    // for (int i=0; i<=n; i++) {
    //     count = (n - i)/2;
    //     min = i<count?i:count;
    //     if ((n-i)%2 == 0) {
    //         for (int j=0; j<min; j++)
    //             num *= (count+i-j);
    //         while (min) {
    //             den *= min;
    //             min--;
    //         }
    //         ans += num/den;
    //         num = den = 1;
    //     }
    // }
// 动态规划
    int *dp = (int*)malloc(sizeof(int)*(n+1));
    dp[0] = dp[1] = 1;
    for (int i = 2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[n];
}

int main()
{
    for (int i=1; i<=45; i++) {
        printf("%d %d\n", i, climbStairs(i));
    }
    return 0;
}