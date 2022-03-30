#include <stdio.h>
#include <stdlib.h>

int findTargetSumWays(int* nums, int numsSize, int target)
{
    int sum = 0;
    for(int i=0; i<numsSize; i++)
        sum += nums[i];
    int absTarget = abs(target);
    int (*dp)[sum+1] = (int (*)[sum+1])malloc(sizeof(int)*(sum+1)*numsSize);
    for(int j=0; j<sum+1; j++)
        dp[0][j] = 0;
    if(nums[0]==0)
        dp[0][nums[0]] = 2;
    else
        dp[0][nums[0]] = 1;

    for(int i=1; i<numsSize; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            dp[i][j] = (j-nums[i]>=-sum?dp[i-1][abs(j-nums[i])]:0) + (j+nums[i]<=sum?dp[i-1][j+nums[i]]:0);
        }
    }
    if(absTarget>sum)
        return 0;
    return dp[numsSize-1][absTarget];
}

int main()
{
    int nums[5] = {1, 1, 1, 1, 1};

    printf("%d", findTargetSumWays(nums, 5, 3));

    return 0;
}