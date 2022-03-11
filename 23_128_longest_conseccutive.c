#include <stdio.h>
#include <stdlib.h>
// #include "quick_sort.h"
#include "hash.h"

/* quick sort and O(n) travel */

// int longestConsecutive(int* nums, int numsSize)
// {
//     if(numsSize==0)
//         return 0;
//     quick_sort(nums, 0, numsSize-1);
//     int maxLength = 1;
//     int currentLength = 1;
//     for(int i=1; i<numsSize; i++)
//     {
//         if(nums[i] == nums[i-1]+1)
//         {
//             if(++currentLength > maxLength)
//                 maxLength = currentLength;
//         } else if(nums[i] == nums[i-1]) {
//             continue;
//         } else {
//             currentLength = 1;
//         }
//     }
//     return maxLength;
// }

/* use hashTable and O(n) travel */

int longestConsecutive(int* nums, int numsSize)
{
    if(numsSize == 0)
        return 0;
    int maxLength = 0;
    struct dataItem** hashArray = (struct dataItem**)malloc(sizeof(struct dataItem*)*numsSize);
    for(int i=0; i<numsSize; i++)
        hashArray[i] = NULL;
    int newNums[numsSize];
    int newNumsSize = 0;
    for(int i=0; i<numsSize; i++)
    {
        // kick out same value
        if(hash_sc_searchNode(nums[i], hashArray, numsSize) == NULL) {
            hash_sc_insertNode(nums[i], i, hashArray, numsSize);
            newNums[newNumsSize] = nums[i];
            newNumsSize++;
        }
    }

    int longestStreak = 0;

    for(int i=0; i<newNumsSize; i++)
    {
        if(hash_sc_searchNode(newNums[i]-1, hashArray, numsSize) == NULL)
        {
            int currentNum = newNums[i];
            int currentStreak = 1;
            while(hash_sc_searchNode(currentNum+1, hashArray, numsSize) != NULL) {
                currentNum += 1;
                currentStreak += 1;
            }
            if(longestStreak<currentStreak)
                longestStreak = currentStreak;
        }
    }

    return longestStreak;
}



int main()
{
    int nums[17] = {-7,-1,3,-9,-4,7,-3,2,4,9,4,-9,8,-7,5,-1,-7};
    int maxLength = longestConsecutive(nums, 17);
    printf("%d", maxLength);
    return 0;
}