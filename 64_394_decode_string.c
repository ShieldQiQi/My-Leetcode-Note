#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <math.h>

char * decodeString(char * s)
{
    struct Stack *stack = initStack();
    int length = 500;
    char *string = (char*)malloc(sizeof(char)*(length+1));
    string[length] = 0;
    int i=0;
    int index = length-1;
    while(s[i]) {
        if(s[i] == ']') {
            while(1) {
                char temp = popStack(stack);
                if(temp != '[') {
                    string[index--] = temp;
                } else {
                    int repeat = 0;
                    int bit = 0;
                    while(stack->next != NULL && (char)(stack->next->value)-'9'<=0) {
                        repeat += pow(10, bit)*((char)popStack(stack)-'0');
                        bit++;
                    }
                    for(int m=0; m<repeat; m++)
                        for(int j=index+1; j<length; j++)
                            pushStack(stack, string[j]);
                    index = length-1;
                    break;
                }
            }
        } else {
            pushStack(stack, s[i]);
        }
        i++;
        if(!s[i])
            break;
    }
    char *ans = (char*)malloc(sizeof(char)*(stack->count+1));
    ans[stack->count] = 0;
    int size = stack->count;
    int k = 0;
    while(stack->count) {
        ans[k] = popStack(stack);
        k++;
    }
    int low = 0, high = size-1;
    while(low < high) {
        char swap = ans[low];
        ans[low] = ans[high];
        ans[high] = swap;
        low++;
        high--;
    }
    return ans;
}

int main()
{
    char *string = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    char *ans = decodeString(string);
    int i=0;
    while(ans[i]) {
        printf("%c", ans[i]);
        i++;
    }
    return 0;
}