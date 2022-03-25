#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataItem {
    int key;
    int valueRow;
    int valueCol;
    struct dataItem* next;
};
int hash_sc_insertNode_(int key, int valueRow, int valueCol, struct dataItem** hashArray, int size);
inline int hashCode_(int key, int size) {return abs(key) % size;};

double dfs(struct dataItem** hashTable, char* sourceStr, char* targetStr, char* (*equations)[2], double* values, int size, int* equationsVisitFlag)
{
    int hashIndex = hashCode_(sourceStr[0]-'0', size);
    struct dataItem* temp = hashTable[hashIndex];
    while(temp != NULL)
    {
        if(strcmp(equations[temp->valueRow][temp->valueCol], sourceStr)==0 && !(equationsVisitFlag[temp->valueRow]))
        {
            if(strcmp(sourceStr, targetStr)==0)
                return 1.0;
            if(strcmp(equations[temp->valueRow][!(temp->valueCol)], targetStr)==0)
            {
                return temp->valueCol==0 ? values[temp->valueRow] : 1/values[temp->valueRow];
            } else {
                equationsVisitFlag[temp->valueRow] = 1;
                double result = dfs(hashTable, equations[temp->valueRow][!(temp->valueCol)], targetStr, equations, values, size, equationsVisitFlag);
                equationsVisitFlag[temp->valueRow] = 0;
                if(result != -1.0)
                {
                    return result*(temp->valueCol==0 ? values[temp->valueRow] : 1/values[temp->valueRow]);
                }
            }
        }
        temp = temp->next;
    }
    return -1.0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* calcEquation(char* (*equations)[2], int equationsSize, int* equationsColSize, double* values, int valuesSize, 
                        char* (*queries)[2], int queriesSize, int* queriesColSize, int* returnSize)
{
    *returnSize = queriesSize;
    double* ans = (double*)malloc(sizeof(double)*queriesSize);
    int* equationsVisitFlag = (int*)malloc(sizeof(int)*equationsSize);
    int hashTableSize = 75;
    // define a hashTable to store equations elements
    // '0'-'9' 'a'-'z' 48-122 == 75
    struct dataItem** hashTable = (struct dataItem**)malloc(sizeof(struct dataItem*)*hashTableSize);
    for(int i=0; i<hashTableSize; i++)
        hashTable[i] = NULL;
    for(int i=0; i<equationsSize; i++)
    {
        equationsVisitFlag[i] = 0;
        hash_sc_insertNode_(equations[i][0][0]-'0', i, 0, hashTable, hashTableSize);
        hash_sc_insertNode_(equations[i][1][0]-'0', i, 1, hashTable, hashTableSize);
    }

    // use dfs get answer
    for(int i=0; i<queriesSize; i++)
    {
        ans[i] = dfs(hashTable, queries[i][0], queries[i][1], equations, values, hashTableSize, equationsVisitFlag);
    }
    free(hashTable);
    return ans;
}

int main()
{
    char* equations[2][2] = {{"a","b"},{"b","c"}};
    double values[2] = {2.0,3.0};
    char* queries[5][2] = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    int returnSize = 5;
    int equationsColSize[2];
    int queriesColSize[5];
    double* ans  = calcEquation(equations, 2, equationsColSize, values, 2, queries, 5, queriesColSize, &returnSize);
    for(int i=0; i<returnSize; i++)
    {
        printf("%f ", ans[i]);
    }

    return 0;
}


// insert Item operation
int hash_sc_insertNode_(int key, int valueRow, int valueCol, struct dataItem** hashArray, int size)
{
    int hashIndex = hashCode_(key, size);
    if(hashArray[hashIndex]==NULL)
    {
        hashArray[hashIndex] = (struct dataItem*)malloc(sizeof(struct dataItem));
        hashArray[hashIndex]->key = key;
        hashArray[hashIndex]->valueRow = valueRow;
        hashArray[hashIndex]->valueCol = valueCol;
        hashArray[hashIndex]->next = NULL;
        return 1;
    }

    struct dataItem* temp = hashArray[hashIndex];
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (struct dataItem*)malloc(sizeof(struct dataItem));
    temp->next->key = key;
    temp->next->valueRow = valueRow;
    temp->next->valueCol = valueCol;
    temp->next->next = NULL;
    return 1;

}