#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int maxCoins(int* nums, int numsSize)
{
    int (*dp)[numsSize+2] = (int(*)[numsSize+2])malloc(sizeof(int)*(numsSize+2)*(numsSize+2));
    memset(dp, 0, sizeof(int)*(numsSize+2)*(numsSize+2));
    int *tmp = (int*)malloc(sizeof(int)*(numsSize+2));
    tmp[0] = tmp[numsSize+1] = 1;
    for (int i=1; i<=numsSize; i++)
        tmp[i] = nums[i-1];
    
    for (int len=3; len<=numsSize+2; len++) {
        for (int i=0; i<=numsSize+2-len; i++) {
            int max = 0;
            for (int k=i+1; k<i+len-1; k++)
                max = fmax(max, tmp[i]*tmp[k]*tmp[i+len-1]+dp[i][k]+dp[k][i+len-1]);
            dp[i][i+len-1] = max;
        }
    }
    return dp[0][numsSize+1];
}

int main()
{
    int nums[4] = {3,1,5,8};
    printf("%d", maxCoins(nums, 4));

    return 0;
}