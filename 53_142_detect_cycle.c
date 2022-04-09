#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *fast = head, *slow = head;
    if(fast==NULL || fast->next==NULL)
        return NULL;
    fast = fast->next->next;
    slow = slow->next;
    
    while(fast != slow)
    {
        if(fast==NULL || fast->next==NULL)
            return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }

    slow = head;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;

}

int main()
{
    
    struct ListNode tail;
    struct ListNode middle = {2, &tail};
    tail.val = 3;
    tail.next = &middle;
    struct ListNode head = {1, &middle};

    struct ListNode *ans = detectCycle(&head);

    printf("%d", ans->val);
    return 0;
}