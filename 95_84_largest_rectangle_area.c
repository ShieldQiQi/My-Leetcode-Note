#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <math.h>

int largestRectangleArea(int* heights, int heightsSize)
{
    int *left = (int*)malloc(sizeof(int)*heightsSize);
    int *right = (int*)malloc(sizeof(int)*heightsSize);
    // 最后栈内剩下的为递增元素，故右侧边界为heightsSize位置
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

    // stack = initStack();
    // for (int i = heightsSize-1; i >= 0; i--) {
    //     while (stack->count && heights[stack->next->value] >= heights[i]) {
    //         popStack(stack);
    //     }
    //     right[i] = (stack->count == 0)?heightsSize:stack->next->value;
    //     pushStack(stack, i);
    // }

    int ans = 0;
    for (int i = 0; i<heightsSize ;i++) {
        ans = fmax(ans, heights[i]*(right[i]-left[i]-1));
    }
    return ans;

}

int main()
{
    int heights[6] = {2,1,5,6,2,3};
    printf("%d", largestRectangleArea(heights, 6));

    return 0;
}