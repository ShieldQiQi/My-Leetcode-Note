#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* tempHead = head;
    while(head != NULL && head->next != NULL)
    {
        struct ListNode* tempNode = head->next->next;
        head->next->next = tempHead;
        tempHead = head->next;
        head->next = tempNode;
    }

    return tempHead;
}

int main()
{
    struct ListNode head = {1, NULL};
    struct ListNode tail = {2, NULL};
    head.next = &tail;

    struct ListNode *ans = reverseList(&head);

    while(ans)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }

    return 0;
}