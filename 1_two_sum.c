/*
 * 
 * Author: XiaoFang Qi
 * Date: 2022/2/25
 */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

//extern struct dataItem* hashArray[SIZE];

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

int* twoSum_2(int* nums, int numsSize, int target, int* returnSize)
{
    struct dataItem* hashArray[SIZE] = {NULL};
    for(int index0=0; index0<numsSize; index0++)
    {
        struct dataItem*  matchedItem= hash_sc_searchNode(target - nums[index0], hashArray);
        if(matchedItem != NULL && matchedItem->value != index0)
        {
            // found the result index1
            *returnSize = 2;
            int* temp = (int*)malloc(2*sizeof(int));
            temp[1] = index0;
            temp[0] = matchedItem->value;
            return temp;
        }
        struct dataItem node = {nums[index0], index0, NULL};
        hash_sc_insertNode(&node, hashArray);
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int returnSize;
    for(int j=0;j<1;j++)
    {
        int nums2[3] = {3, -4, 1};
        int * result2 = twoSum_2(nums2, 3, -1, &returnSize);
        printf("%d, %d, returned size is %d\n", result2[0], result2[1], returnSize);
    }
    return 0;
}