#include <stdio.h>
#include <stdlib.h>

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

// 自顶向下 空间O(log n) 栈空间
struct ListNode* sortList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode *slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode *behindHalf = sortList(slow->next);
    slow->next = NULL;
    struct ListNode *frontHalf = sortList(head);
    // merge LinkedList
    return mergeTwoLists(frontHalf, behindHalf);
}

// 自顶向下 空间O(1)
struct ListNode* sortList2(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    int length = 0;
    struct ListNode* node = head;
    while (node != NULL) {
        length++;
        node = node->next;
    }
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    for (int subLength = 1; subLength < length; subLength <<= 1) {
        struct ListNode *prev = dummyHead, *curr = dummyHead->next;
        while (curr != NULL) {
            struct ListNode* head1 = curr;
            for (int i = 1; i < subLength && curr->next != NULL; i++) {
                curr = curr->next;
            }
            struct ListNode* head2 = curr->next;
            curr->next = NULL;
            curr = head2;
            for (int i = 1; i < subLength && curr != NULL && curr->next != NULL;
                 i++) {
                curr = curr->next;
            }
            struct ListNode* next = NULL;
            if (curr != NULL) {
                next = curr->next;
                curr->next = NULL;
            }
            struct ListNode* merged = mergeTwoLists(head1, head2);
            prev->next = merged;
            while (prev->next != NULL) {
                prev = prev->next;
            }
            curr = next;
        }
    }
    return dummyHead->next;
}

int main()
{
    struct ListNode tail = {1, NULL};
    struct ListNode middle = {3, &tail};
    struct ListNode head = {2, &middle};
    struct ListNode *ans = sortList2(&head);
    while(ans != NULL)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    return 0;
}