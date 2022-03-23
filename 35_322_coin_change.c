#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"
#include "hash.h"

// 深度优先搜索
void dfs(int* coins, int coinsSize, int remain, int minCoins, int* min, int begin)
{
    if(remain == 0) {
        if(minCoins<*min)
            *min = minCoins;
        //printf("%d\n", minCoins);
        return;
    }
    for(int i=begin; i>=0; i--)
    {
        int temp = remain/coins[i];
        if(temp >= 1)
        {
            for(int j=temp; j>=0; j--)
            {
                if(minCoins+j>*min)
                    continue;
                // printf("%d\n", i);
                dfs(coins, coinsSize, remain-j*coins[i], minCoins+j, min, i-1);
            }
        }
    }
}

int coinChange_(int* coins, int coinsSize, int amount)
{
    quick_sort(coins, 0, coinsSize-1);
    int min = 200;
    dfs(coins, coinsSize, amount, 0, &min, coinsSize-1);
    if(min != 200)
        return min;
    else
        return -1;
}

// 动态规划
// dp[i] = min{dp[i-c_j]} + 1 其中c_j为所有面额中的一个
int coinChange(int* coins, int coinsSize, int amount)
{
    int max = amount+1;
    int* dp = (int*)malloc(sizeof(int)*(amount+1));
    for(int i=0; i<amount+1; i++)
        dp[i] = max;

    dp[0] = 0;  // 定义定额0所需最小硬币为0
    for(int i=1; i<=amount; i++)
    {
        for(int j=0; j<coinsSize; j++)
        {
            if(coins[j]<=i && dp[i]>dp[i-coins[j]]+1)
            {
                dp[i] = dp[i-coins[j]]+1;
            }
        }
    }
    return dp[amount]>amount ? -1:dp[amount];
}

int main()
{
    int coins[12] = {411,412,413,414,415,416,417,418,419,420,421,422};
    //int coins[4] = {186, 419, 83, 408};
    //int coins[3] = {1, 2, 5};

    int minCoins = coinChange(coins, 12, 9864);
    printf("\n--------\n%d", minCoins);

    return 0;
}