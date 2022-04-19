#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quick_sort.h"
#include "hash.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    int tableSize = strsSize;
    struct dataItem2 **hashTable = initHashTable2(tableSize);
    int* columnSize = (int*)malloc(sizeof(int)*tableSize);
    memset(columnSize, 0, tableSize*4);
    *returnSize = 0;
    for(int i=0; i<strsSize; i++)
    {
        int count = 0;
        while(strs[i][count])
            count++;
        char *temp = (char*)malloc(sizeof(char)*(count+1));
        memcpy(temp, strs[i], count+1);
        quick_sort3(temp, 0, count-1);
        if(hash_sc_searchNode2(temp, hashTable, tableSize) == NULL)
            *returnSize += 1;
        hash_sc_insertNode2(temp, (char*)i, hashTable, tableSize);
        columnSize[hashCode2(temp, tableSize)] += 1;
    }
    char ***ans = (char***)malloc(sizeof(char**)*(*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0, index=0; i<tableSize; i++)
    {
        struct dataItem2 *temp, *preTemp;
        char **column;
       
        while(hashTable[i] != NULL)
        {
            temp = hashTable[i];
            preTemp = temp;
            column = (char**)malloc(sizeof(char*)*columnSize[i]);
            ans[index] = column;
            (*returnColumnSizes)[index] = 0;
            char* firstStr = temp->key;
            while(temp != NULL)
            {
                if(strcmp(firstStr, temp->key)==0)
                {
                    columnSize[i]--;
                    (*returnColumnSizes)[index] += 1;
                    *column = strs[(unsigned long long)(temp->value)];
                    column++;
                    if(preTemp == temp)
                    {
                        hashTable[i] = temp->next;
                        free(temp);
                        preTemp = hashTable[i];
                        temp = preTemp;
                    } else {
                        preTemp->next = temp->next;
                        free(temp);
                        temp = preTemp->next;
                    }
                } else {
                    preTemp = temp;
                    temp = temp->next;
                }
            }
            index++;
        }
    }
    return ans;
}

int main()
{
    char* strs[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int returnSize;
    int *returnColumnSizes;

    char ***ans = groupAnagrams(strs, 6, &returnSize, &returnColumnSizes);

    for(int i=0; i<returnSize; i++)
    {
        printf("[");
        for(int j=0; j<returnColumnSizes[i]; j++)
        {
            printf("%s, ", ans[i][j]);
        }
        printf("]");
    }

    return 0;
}