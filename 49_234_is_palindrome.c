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

int isPalindrome(struct ListNode* head)
{
    int ans = 1;
    struct ListNode *slow, *fast;
    slow = fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* halfList = reverseList(slow->next);
    struct ListNode* halfListTemp = halfList;
    while(halfList != NULL)
    {
        if(halfList->val != head->val) {
            ans = 0;
            break;
        }
        halfList = halfList->next;
        head = head->next;
    }
    slow->next = reverseList(halfListTemp);

    return ans;

}

int main()
{
    struct ListNode head = {1, NULL};
    struct ListNode middle = {2, NULL};
    struct ListNode tail = {1, NULL};
    head.next = &middle;
    middle.next = &tail;

    int ans = isPalindrome(&head);

    printf("%d ", ans);

    return 0;
}