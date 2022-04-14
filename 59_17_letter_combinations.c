#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char **ans, char *digits, int combineSize, int currentLayer, int *index, char *temp)
{
    if(currentLayer == 0)
        temp = (char*)malloc(sizeof(char)*combineSize);
    if(currentLayer == combineSize)
    {
        memcpy(ans[*index], temp, sizeof(char)*combineSize);
        ans[*index][combineSize] = NULL;
        *index += 1;
        return;
    }
    if(digits[currentLayer]-'0' <= 6)
    {
        for(int i=0; i<3; i++)
        {
            temp[currentLayer] = (digits[currentLayer]-'2')*3+i+'a';
            dfs(ans, digits, combineSize, currentLayer+1, index, temp);
        }
    } else if (digits[currentLayer]-'0' >= 7) {
        for(int i=0; i<(digits[currentLayer]-'0'==8?3:4); i++)
        {
            if(digits[currentLayer]-'0' == 7)
                temp[currentLayer] = 15+i+'a';
            else if(digits[currentLayer]-'0' == 8)
                temp[currentLayer] = 19+i+'a';
            else
                temp[currentLayer] = 22+i+'a';

            dfs(ans, digits, combineSize, currentLayer+1, index, temp);
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize)
{
    char **ans_;
    if(digits[0] == NULL) {
        *returnSize = 0;
        return ans_;
    }
    int combineSize = 0;
    *returnSize = 1;
    while(digits[combineSize] != NULL) {
        if(digits[combineSize] == '7' || digits[combineSize] == '9')
            *returnSize *= 4;
        else
            *returnSize *= 3;
        combineSize++;
    }
    char **ans = (char**)malloc(sizeof(char*)*(*returnSize));
    for(int i=0; i<*returnSize; i++)
        ans[i] = (char*)malloc(sizeof(char)*(combineSize+1));
    
    int index = 0;
    char *temp;
    dfs(ans, digits, combineSize, 0, &index, temp);

    return ans;
}

int main()
{
    char digits[3] = "29";
    int returnSize;
    char **ans = letterCombinations(digits, &returnSize);
    for(int i=0; i<returnSize; i++)
    {
        int j=0;
        while (ans[i][j] != NULL)
        {
            printf("%c", ans[i][j]);
            j++;
        }
        printf(", ");
    }
    for(int i=0; i<returnSize; i++)
        free(ans[i]);
    free(ans);
    return 0;
}