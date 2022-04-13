#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int isValid(char * s)
{
    struct Stack *stack = initStack();
    int i = 0;
    while(s[i] != NULL)
    {
        if(stack->next != NULL && (stack->next->value == '(' && s[i] == ')' ||
          stack->next->value == '[' && s[i] == ']' || stack->next->value == '{' && s[i] == '}'))
        {
            popStack(stack);
        } else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
            return 0;
        } else {
            pushStack(stack, s[i]);
        }
        i++;
    }
    if(stack->count)
        return 0;
    else
        return 1;
}

int main()
{
    char string[6] = {'(', ')', ']', '[', '{', '}'};
    printf("%d", isValid(string));
}
