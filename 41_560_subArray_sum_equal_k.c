#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int subarraySum(int* nums, int numsSize, int k)
{
    int count = 0;
    struct dataItem** hashTable = (struct dataItem**)malloc(sizeof(struct dataItem*)*numsSize);
    for(int i=0; i<numsSize; i++)
        hashTable[i] = NULL;
    
    int sum = 0;
    for(int i=0; i<numsSize; i++)
    {
        sum += nums[i];
        if(sum==k)
            count++;
        struct dataItem* temp = hash_sc_searchNode(sum-k, hashTable, numsSize);
        if(temp != NULL) {
            count += temp->value;
        }
        temp = hash_sc_searchNode(sum, hashTable, numsSize);
        if(temp != NULL) {
            temp->value += 1;
        } else {
            hash_sc_insertNode(sum, 1, hashTable, numsSize);
        }
    }

    return count;
}

int main()
{
    int nums[3] = {1, -1, 0};

    int count = subarraySum(nums, 3, 0);
    printf("%d", count);

    return 0;
}