#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

int largestRectangleArea(int* heights, int heightsSize)
{
    int *left = (int*)malloc(sizeof(int)*heightsSize);
    int *right = (int*)malloc(sizeof(int)*heightsSize);
    for (int i = 0; i<heightsSize; i++)
        right[i] = heightsSize;
    struct Stack *stack = initStack();

    for (int i = 0; i < heightsSize; i++) {
        while (stack->count && heights[stack->next->value] >= heights[i]) {
            right[stack->next->value] = i;
            popStack(stack);
        }
        left[i] = (stack->count == 0)?-1:stack->next->value;
        pushStack(stack, i);
    }

    int ans = 0;
    for (int i = 0; i<heightsSize; i++) {
        ans = fmax(ans, (heights[i])*(right[i]-left[i]-1));
    }
    return ans;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize)
{
    int max_area = 0;
    int *tmp = (int*)malloc(sizeof(int)*matrixColSize[0]);
    for (int j = 0; j < matrixColSize[0]; ++j)
        tmp[j] = matrix[0][j] - '0';
    int maxRec = largestRectangleArea(tmp, matrixColSize[0]);
    if (maxRec > max_area)
        max_area = maxRec;

    for (int i = 1; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[i]; ++j) {
            tmp[j] = (matrix[i][j]=='1' ? tmp[j] + 1: 0);
        }
        int maxRec = largestRectangleArea(tmp, matrixColSize[i]);
        if (maxRec > max_area)
            max_area = maxRec;
    }

    return max_area;
}

int main()
{
    char matrix1[1] = {'1'};
    char *maxtrix[1] = {matrix1};
    int matrixColSize[1] = {1};

    printf("%d", maximalRectangle(maxtrix, 1, matrixColSize));

    return 0;
}