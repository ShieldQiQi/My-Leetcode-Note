#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode *indexNode = head;
    int nextAdd = 0;

    while(l1 != NULL && l2 != NULL)
    {
        struct ListNode *tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        tempNode->val = (l1->val + l2->val + nextAdd)%10;
        tempNode->next = NULL;
        nextAdd = (l1->val + l2->val + nextAdd)/10;
        indexNode->next = tempNode;
        indexNode = tempNode;
        l1 = l1->next;
        l2 = l2->next;
    }
    struct ListNode *remain = NULL;
    if(l1 != NULL)
        remain = l1;
    else if(l2 != NULL)
        remain = l2;
    
    while(remain != NULL)
    {
        struct ListNode *tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        tempNode->val = (remain->val + nextAdd)%10;
        tempNode->next = NULL;
        nextAdd = (remain->val + nextAdd)/10;
        indexNode->next = tempNode;
        indexNode = tempNode;
        remain = remain->next;
    }
    if(nextAdd)
    {
        struct ListNode *tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        tempNode->val = nextAdd;
        tempNode->next = NULL;
        indexNode->next = tempNode;
        indexNode = tempNode;
    }

    return head->next;
}

int main()
{
    struct ListNode head1 = {6, NULL};
    struct ListNode middle = {2, NULL};
    struct ListNode head2 = {1, NULL};
    head1.next = &middle;

    struct ListNode* ans = addTwoNumbers(&head1, &head2);

    while(ans)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }

    return 0;
}