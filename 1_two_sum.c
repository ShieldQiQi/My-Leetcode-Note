/*
 * 
 * Author: XiaoFang Qi
 * Date: 2022/2/25
 */

#include <stdio.h>
#include <stdlib.h>

// 暴力破解法
int* twoSum_1(int* nums, int numsSize, int target, int* returnSize){
    int index0, index1;
    for(index0=0; index0<numsSize-1; index0++)
    {
        for(index1=index0+1; index1<numsSize; index1++)
        {
            if(nums[index0]+nums[index1]==target)
            {
                *returnSize = 2;
                int* temp = (int*)malloc(2*sizeof(int));
                temp[0] = index0;
                temp[1] = index1;
                return temp;
            }
        }
    }
    return NULL;
}

// 使用哈希

int main()
{
    int nums[4] = {2, 7, 11, 15};
    int returnSize;
    int * result = twoSum_1(nums, 4, 18, &returnSize);
    printf("%d, %d, returned size is %d\n", result[0], result[1], returnSize);
    return 0;
}