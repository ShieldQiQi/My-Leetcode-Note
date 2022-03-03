#include <stdio.h>
#include "quick_sort.h"
#include <stdlib.h>

void dfs(int* candidates, int begin, int candidatesSize, int* combine, int* combineSize, int remain, int** ans, int* ansSize, int* returnColumnSizes)
{
    for(int i=begin; i<candidatesSize; i++)
    {
        if(remain-candidates[i] == 0)
        {
            *combineSize+=1;
            //combine = (int*)realloc(combine, *combineSize*sizeof(int));
            combine[*combineSize-1] = candidates[i];
            // store current combine array'
            int* temp = (int*)malloc(*combineSize*sizeof(int));
            for(int j=0; j<*combineSize; j++)
                temp[j] = combine[j];
            (*ansSize)++;
            //ans = (int**)realloc(ans, *ansSize*sizeof(int*));
            ans[*ansSize-1] = temp;
            //returnColumnSizes = (int**)realloc(returnColumnSizes, *ansSize*sizeof(int*));
            //returnColumnSizes[*ansSize-1] = (int*)malloc(sizeof(int));
            //returnColumnSizes[*ansSize-1][0] = *combineSize;
            returnColumnSizes[*ansSize-1] = *combineSize;
            *combineSize-=1;
            return;
        } else if(remain-candidates[i] > 0) {
            *combineSize+=1;
            //combine = (int*)realloc(combine, *combineSize*sizeof(int));
            combine[*combineSize-1] = candidates[i];
            dfs(candidates, i, candidatesSize, combine, combineSize, remain-candidates[i], ans, ansSize, returnColumnSizes);
            *combineSize-=1;
        } else {
            // current path is not valid
            break;
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    int** returnArray = (int**)malloc(1001*sizeof(int*));
    *returnColumnSizes = (int*)malloc(1001*sizeof(int));
    int combine[2001];
    *returnSize=0;
    int combineSize = 0;

    quick_sort(candidates, 0, candidatesSize-1);
    dfs(candidates, 0, candidatesSize, combine, &combineSize, target, returnArray, returnSize, *returnColumnSizes);
    
    return  returnArray;
}

int main()
{
    int candidates[4] = {2, 3, 6, 7};
    int candidatesSize = 4;
    int target = 7;
    int returnSize = 0;
    int *returnColumnSizes;
    
    int** returnArray = combinationSum(candidates, candidatesSize, target, &returnSize, &returnColumnSizes);
    printf("[ ");
    for(int i=0; i<returnSize; i++)
    {
        printf("[");
        for(int j=0; j<returnColumnSizes[i]; j++)
        {
            printf("%d ", returnArray[i][j]);
        }
        printf("], ");
    }
    printf(" ]");
    return 0;
}