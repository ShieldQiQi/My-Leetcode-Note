/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

// 双指针解法-----------------------------------------------

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    quick_sort(nums, 0, numsSize-1);
    int** returnArray = (int **)malloc(sizeof(int *));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int));

    for(int i=0; i<numsSize; i++)
    {
        if(i>0 && nums[i] == nums[i-1])
            continue;
        int k = numsSize-1;
        int target = -nums[i];
        for(int j=i+1; j<numsSize; j++)
        {
            if(j>i+1 && nums[j]==nums[j-1])
                continue;
            while(j<k && nums[j]+nums[k]>target)
                k--;
            
            if(j==k)
                break;
            if(nums[j]+nums[k]==target)
            {
                (*returnSize)++;
                returnArray = (int**)realloc(returnArray, (*returnSize)*sizeof(int*));
                returnArray[*returnSize-1] = (int*)malloc(3*sizeof(int));
                returnArray[*returnSize-1][0] = nums[i];
                returnArray[*returnSize-1][1] = nums[j];
                returnArray[*returnSize-1][2] = nums[k];
                *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize)*sizeof(int));
                (*returnColumnSizes)[*returnSize-1] = 3;
            }
        }
    }

    return returnArray;
}

int main()
{
    int nums[11] = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    int numsSize = 11;
    int returnSize = 0;
    int *returnColumnSizes;

    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    for(int i=0; i<returnSize; i++)
    {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0;
}

// 哈希-两数之和解法----------------------------------------

// // hash node struct
// struct hashTable {
//     int key;
//     int value;
//     struct hashTable* next;
// };

// inline int hashCode(int key, int size) {return abs(key)%size;}

// // insert hash node
// void insert(int key, int value, struct hashTable** table, int size)
// {
//     int index = hashCode(key, size);
//     if(table[index] == NULL)
//     {
//         table[index] = (struct hashTable*)malloc(sizeof(struct hashTable));
//         table[index]->key = key;
//         table[index]->value = value;
//         table[index]->next = NULL;
//         return;    
//     }
//     struct hashTable* temp = table[index];
//     while(temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = (struct hashTable*)malloc(sizeof(struct hashTable));
//     temp->next->key = key;
//     temp->next->value = value;
//     temp->next->next = NULL;
// }

// // search hash node
// struct hashTable* search(int key, int value, int flag, struct hashTable** table, int size)
// {
//     int index = hashCode(key, size);
//     struct hashTable* temp = table[index];
//     while(temp != NULL)
//     {
//         if(temp->key == key)
//         {
//             if(flag==0 || (flag==1 && temp->value == value))
//                 return temp;
//         }
//         temp = temp->next;
//     }
//     return NULL;
// }

// int** twoSum(int* nums, int numsSize, int target, int* returnSize)
// {
//     struct hashTable** hashArray = (struct hashTable**)malloc(numsSize*sizeof(struct hashTable*));
//     *returnSize = 0;
//     int** indexArray = (int **)malloc(sizeof(int *));

//     for(int i=0; i<numsSize; i++)
//     {
//         hashArray[i] = NULL;
//     }

//     for(int index0=0; index0<numsSize; index0++)
//     {
//         struct hashTable*  matchedItem= search(target - nums[index0], 0, 0, hashArray, numsSize);
//         if(matchedItem != NULL && matchedItem->value != index0)
//         {
//             // found the result index1
//             int* temp = (int*)malloc(2*sizeof(int));
//             temp[1] = index0;
//             temp[0] = matchedItem->value;
//             (*returnSize) += 1;
//             indexArray = (int **)realloc(indexArray, (*returnSize)*sizeof(int*));
//             indexArray[*returnSize-1] = temp;
//         }
//         insert(nums[index0], index0, hashArray, numsSize);
//     }
//     if(*returnSize != 0)
//         return indexArray;
//     return NULL;
// }

// void bubbleSort(int* array, int size)
// {
//     for(int i=0; i<size; i++)
//     {
//         for(int j=i; j<size; j++)
//         {
//             if(array[j]<array[i])
//             {
//                 int temp = array[i];
//                 array[i] = array[j];
//                 array[j] = temp;
//             }
//         }
//     }
// }

// int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
// {
//     *returnSize = 0;
//     int** returnArray = (int **)malloc(sizeof(int *));

//     for(int i=numsSize-1; i>1; i--)
//     {
//         int currentSize = 0;
//         int** temp = twoSum(nums, i, -nums[i], &currentSize);
//         if(temp != NULL)
//         {
//             for(int j=0; j<currentSize; j++)
//             {
//                 int* threeNums = (int*)malloc(3*sizeof(int));
//                 threeNums[0] = nums[temp[j][0]];
//                 threeNums[1] = nums[temp[j][1]];
//                 threeNums[2] = nums[i];
//                 bubbleSort(threeNums, 3);

//                 (*returnSize)+=1;
//                 returnArray = (int**)realloc(returnArray, (*returnSize)*sizeof(int*));
//                 returnArray[(*returnSize)-1] = threeNums;
//             }
//         }
//     }

//     int** trueArray = (int **)malloc(sizeof(int *));
//     int trueSize = 0;
//     struct hashTable** hashArray = (struct hashTable**)malloc((*returnSize)*sizeof(struct hashTable*));
//     for(int i=0; i<(*returnSize); i++)
//     {
//         hashArray[i] = NULL;
//     }
//     for(int i=0; i< (*returnSize); i++)
//     {
//         struct hashTable* tempNode = search(returnArray[i][0], returnArray[i][1], 1, hashArray, *returnSize);
//         if(tempNode == NULL)
//         {
//             trueSize++;
//             insert(returnArray[i][0], returnArray[i][1], hashArray, *returnSize);
//             trueArray = (int**)realloc(trueArray, trueSize*sizeof(int*));
//             trueArray[trueSize-1] = returnArray[i];
//         }
//     }

//     *returnSize = trueSize;
//     *returnColumnSizes = (int*)malloc(trueSize*sizeof(int));
//     for(int i=0; i<trueSize; i++)
//         (*returnColumnSizes)[i] = 3;
//     return trueArray;
// }
