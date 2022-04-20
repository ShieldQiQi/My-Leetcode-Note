#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int wordBreak(char * s, char ** wordDict, int wordDictSize)
{
    int stringLen = 0;
    while(s[stringLen])
        stringLen++;
    char *tempString = (char*)malloc(sizeof(char)*(stringLen+1));
    memcpy(tempString, s, stringLen+1);
    int* dp = (int*)malloc(sizeof(int)*stringLen);
    struct dataItem2 **hashTable = initHashTable2(wordDictSize);
    for(int i=0; i<wordDictSize; i++) {
        hash_sc_insertNode2(wordDict[i], NULL, hashTable, wordDictSize);
    }
    for(int i=0; i<stringLen; i++)
    {
        dp[i] = 0;
        for(int j=0; i-j>=0; j++)
        {
            char temp = s[i+1];
            s[i+1] = 0;
            if(hash_sc_searchNode2(s+i-j, hashTable, wordDictSize) != NULL && (i-j==0 || dp[i-j-1])) {
                dp[i] = 1;
                s[i+1] = temp;
                break;
            }
            s[i+1] = temp;
        }
    }
    return dp[stringLen-1];
}

int main()
{
    char string[9] = "leetcode";
    char *wordDict[2] = {"leet", "code"};
    int ans = wordBreak(string, wordDict, 2);
    printf("%d", ans);
    
    return 0;
}