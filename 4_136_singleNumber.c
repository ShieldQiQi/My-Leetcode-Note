#include <stdio.h>
#include <stdlib.h>

struct dataItem
{
    int key;
    int value;
    struct dataItem* next;
};

inline int hashCode(int key, int size) {return abs(key)%size;}

void hashInsert(int key, struct dataItem** hashTable, int size)
{
    int index = hashCode(key, size);
    if(hashTable[index]==NULL)
    {
        hashTable[index] = (struct dataItem*)malloc(sizeof(struct dataItem));
        hashTable[index]->key = key;
        hashTable[index]->next = NULL;
        hashTable[index]->value = 0;
        return;
    }
    struct dataItem* temp = hashTable[index];
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (struct dataItem*)malloc(sizeof(struct dataItem));
    temp->next->key = key;
    temp->next->value = 0;
    temp->next->next = NULL;
}

struct dataItem* hashSearch(int key, struct dataItem** hashTable, int size)
{
    int index = hashCode(key, size);
    struct dataItem* temp = hashTable[index];
    while(temp != NULL)
    {
        if(temp->key == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}


int singleNumber(int* nums, int numsSize)
{
    // 每个元素最多有一个重复元素，故可由异或运算的特性得到成单的元素

    int singleNum = nums[0];
    for(int i=1; i<numsSize; i++)
    {
        singleNum ^= nums[i];
    }
    return singleNum;

    // // 最大有(n+1)/2个不相同元素
    // struct dataItem** hashTable = (struct dataItem**)malloc((numsSize+1)/2*sizeof(struct dataItem));
    // for(int i=0; i<(numsSize+1)/2; i++)
    // {
    //     hashTable[i] = NULL;
    // }
    // int singleNum;
    // for(int i=0; i<numsSize; i++)
    // {
    //     struct dataItem* temp = hashSearch(nums[i], hashTable, (numsSize+1)/2);
    //     if(temp == NULL)
    //     {
    //         hashInsert(nums[i], hashTable, (numsSize+1)/2);
    //     } else {
    //         temp->value+=1;
    //     }
    // }

    // for(int i=0; i<numsSize; i++)
    // {
    //     struct dataItem* temp = hashSearch(nums[i], hashTable, (numsSize+1)/2);
    //     if(temp->value==0)
    //         return nums[i];
    // }
    // return 0;
}

int main()
{
    int nums[5] = {4,1,2,1,2};

    int singleNum = singleNumber(nums, 5);
    printf("Single Number is %d\n", singleNum);

    return 0;
}