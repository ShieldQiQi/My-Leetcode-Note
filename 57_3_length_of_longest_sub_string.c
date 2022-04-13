#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int lengthOfLongestSubstring(char * s)
{
    struct dataItem **hashTable = (struct dataItem**)malloc(sizeof(struct hashTable*)*128);
    for(int i=0; i<128; i++)
        hashTable[i] = NULL;
    int index = 0;
    int maxLength = 0;
    int startIndex = 0, endIndex = 0;
    while(s[index] != NULL)
    {
        struct dataItem *temp = hash_sc_searchNode(s[index], hashTable, 128);
        if(temp != NULL && temp->value != -1)
        {
            for(int i=startIndex; i<temp->value; i++)
            {
                struct dataItem *deleteNode = hash_sc_searchNode(s[i], hashTable, 128);
                deleteNode->value = -1;
            }
            startIndex = temp->value + 1;
            temp->value = index;
        } else if(temp == NULL) {
            hash_sc_insertNode(s[index], index, hashTable, 128);
        } else {
            temp->value = index;
        }
        endIndex = index;
        if(maxLength < endIndex-startIndex+1)
            maxLength = endIndex-startIndex+1;
        index++;
    }
    return maxLength;
}

int main()
{
    char string[9] = "absabsbb";
    printf("%d", lengthOfLongestSubstring(string));
    return 0;
}