#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

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

int main()
{
    struct ListNode list1 = {1, NULL};
    struct ListNode list2 = {2, NULL};

    struct ListNode* returnList = mergeTwoLists(&list1, &list2);
    while(returnList != NULL)
    {
        printf("%d ", returnList->val);
        returnList = returnList->next;
    }

    return 0;

}