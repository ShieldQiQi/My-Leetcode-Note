#include "stack.h"
#include <stdio.h>

int longestValidParentheses(char * s)
{
    struct Stack *stack = initStack();
    int index = 0;
    int longest_num = 0;
    while (s[index]) {
        if (stack->count && s[index] == ')' && s[stack->next->value] == '(') {
            popStack(stack);
        } else {
            pushStack(stack, index);
        }
        index++;
    }

    int pre = index;
    int tmp = 0;
    if (!stack->count)
        return index;
    while (stack->count) {
        tmp = popStack(stack);
        if (pre - tmp - 1> longest_num)
            longest_num = pre - tmp - 1;
        pre = tmp;
    }
    if (pre > longest_num)
        longest_num = pre;
    
    return longest_num;
}

int main()
{
    printf("%d", longestValidParentheses("(()"));
    return 0;
}