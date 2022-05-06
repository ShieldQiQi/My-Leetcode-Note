#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    int min;
    struct Node *next;
};

typedef struct {
    struct Node *head;
} MinStack;


MinStack* minStackCreate() {
    MinStack *stack = (MinStack*)malloc(sizeof(MinStack));
    stack->head = NULL;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    struct Node *New = (struct Node*)malloc(sizeof(struct Node));
    New->value = val;
    New->min = val;
    if (obj->head && obj->head->min<val)
        New->min = obj->head->min;
    New->next = obj->head;
    obj->head = New;
}

void minStackPop(MinStack* obj) {
    struct Node *tmp = obj->head;
    if (tmp) {
        obj->head = tmp->next;
        free(tmp);
    }
}

int minStackTop(MinStack* obj) {
    if (obj->head)
        return obj->head->value;
    else
        return -INT_MAX;
}

int minStackGetMin(MinStack* obj) {
    if (obj->head)
        return obj->head->min;
    else
        return -INT_MAX;
}

void minStackFree(MinStack* obj) {
    struct Node *tmp = obj->head, *pre_tmp;
    while(tmp) {
        pre_tmp = tmp;
        tmp = tmp->next;
        free(pre_tmp);
    }
}

int main()
{
    MinStack* obj = minStackCreate();
    minStackPush(obj, 5);
    minStackPush(obj, -3);
    minStackPush(obj, -2);
    minStackPop(obj);
    minStackPush(obj, -1);
    int param_3 = minStackTop(obj);
    int param_4 = minStackGetMin(obj);
    
    printf("%d %d", param_3, param_4);

    minStackFree(obj);

    return 0;
}
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/