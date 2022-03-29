#include <stdio.h>
#include <stdlib.h>

// bool dfs(int* nums, int numsSize, int targetSum, int index, int currentSum)
// {
//     if(currentSum*2==targetSum)
//         return true;
//     else if(currentSum*2 > targetSum)
//         return false;

//     if(index+1<numsSize && dfs(nums, numsSize, targetSum, index+1, currentSum+nums[index+1]))
//         return true;
//     if(index+2<numsSize && dfs(nums, numsSize, targetSum, index+2, currentSum+nums[index+2]))
//         return true;
//     return false;
// }

// bool canPartition(int* nums, int numsSize)
// {
//     int sum = 0;
//     for(int i=0; i<numsSize; i++)
//         sum += nums[i];

//     return dfs(nums, numsSize, sum, -1, 0);
// }

int canPartition(int* nums, int numsSize)
{
    int sum = 0;
    for(int i=0; i<numsSize; i++)
        sum += nums[i];
    // 奇数则不存在符合题意结果
    if(sum & 1 == 1)
        return 0;
    
    // 动态规划
    int target = sum/2;
    int (*dp)[target+1] = (int (*)[target+1])malloc(sizeof(int)*(target+1)*numsSize);
    dp[0][0] = 0;

    for(int j=0; j<target+1; j++)
        dp[0][j] = 0;
    if(nums[0]<=target)
        dp[0][nums[0]] = 1;
    
    for(int i=1; i<numsSize; i++)
    {
        for(int j=0; j<target+1; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(nums[i]==j)
            {
                dp[i][j] = 1;
                continue;
            }
            if(nums[i]<j)
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            }
        }
    }
    return dp[numsSize-1][target];
}

int main()
{
    int nums[4] = {1, 5, 11, 5};
    int ans = canPartition(nums, 4);
    printf("%d", ans);
    return 0;
}