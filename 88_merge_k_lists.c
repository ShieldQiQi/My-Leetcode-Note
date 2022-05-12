#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* returnList = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* indexPtr = returnList;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val < list2->val) {
            indexPtr->next = list1;
            list1 = list1->next;
        } else {
            indexPtr->next = list2;
            list2 = list2->next;
        }
        indexPtr = indexPtr->next;
    }
    if(list1 != NULL)
        indexPtr->next = list1;
    else
        indexPtr->next = list2;

    return returnList->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if (!listsSize)
        return NULL;
    int pair_nums = listsSize/2;
    int layer = 1;
    while (pair_nums > 0) {
        for (int i=0; i<pair_nums; i++) {
            lists[(int)(i*pow(2, layer))] = mergeTwoLists(lists[(int)(i*pow(2, layer))], 
            lists[(int)(i*pow(2, layer)+pow(2, layer-1))]);
        }
        layer++;
        listsSize = pair_nums + listsSize % 2;
        pair_nums = listsSize/2;
    }
    return lists[0];
}

int main()
{
    struct ListNode tail = {1, NULL};
    struct ListNode middle = {3, NULL};
    struct ListNode head = {2, NULL};
    struct ListNode **lists = (struct ListNode**)malloc(sizeof(struct ListNode*)*3);
    lists[0] = &head;
    lists[1] = &middle;
    lists[2] = &tail;

    struct ListNode *ans = mergeKLists(lists, 3);
    while(ans != NULL)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}