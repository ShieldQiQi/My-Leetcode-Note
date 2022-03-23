#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int quick_sort_(int (*array)[2], int low, int high, int k);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    int* ans = (int*)malloc(sizeof(int)*k);
    *returnSize = k;
    struct dataItem** hashTable = (struct dataItem**)malloc(sizeof(struct dataItem*)*numsSize);
    for(int i=0; i<numsSize; i++)
        hashTable[i] = NULL;
    
    int count = 0;
    for(int i=0; i<numsSize; i++)
    {
        struct dataItem* temp = hash_sc_searchNode(nums[i], hashTable, numsSize);
        if(temp == NULL) {
            hash_sc_insertNode(nums[i], 1, hashTable, numsSize);
            count++;
        } else
            temp->value += 1; 
    }
    int (*tempArr)[2] = (int (*)[2])malloc(sizeof(int)*count*2);
    hash_sc_travel(tempArr, hashTable, numsSize);

    for(int i=0; i<count; i++)
        //printf("Freq:%d Value:%d\n", tempArr[i][0], tempArr[i][1]);

    // quick sort
    quick_sort_(tempArr, 0, count-1, count-k);

    for(int i=0; i<k; i++)
    {
        ans[i] = tempArr[count-i-1][1];
    }

    return ans;
}

int main()
{
    int nums[20] = {5,-3,9,1,7,7,9,10,2,2,10,10,3,-1,3,7,-9,-1,3,3};
    int returnSize = 0;
    int* ans = topKFrequent(nums, 20, 3, &returnSize);

    for(int i=0; i<returnSize; i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}

int quick_sort_(int (*array)[2], int low, int high, int k)
{
    if(low >= high) // sort ended
        return 1;
    int i= low;
    int j= high;
    int key = array[low][0];
    int keyValue = array[low][1];

    while(low < high)
    {
        while(array[high][0]>=key && low<high)
        {
            high--;
        }
        if(key > array[high][0])
        {
            array[low][0] = array[high][0];
            array[low][1] = array[high][1];
            low++;
        }
        while(array[low][0]<=key && low<high)
        {
            low++;
        }
        if(key < array[low][0])
        {
            array[high][0] = array[low][0];
            array[high][1] = array[low][1];
            high--;
        }
    }
    array[low][0] = key;
    array[low][1] = keyValue;
    quick_sort_(array, i, low-1, k);
    quick_sort_(array, low+1, j, k);
    // if(low == k)
    //     return 0;
    // if(quick_sort(array, i, low-1, k))
    //     return 1;
    // if(quick_sort(array, low+1, j, k))
    //     return 1;
    return 1;
}