#include <stdlib.h>
#include <stdio.h>

#define false 0
#define true 1

struct ListNode {
    int val;
    struct ListNode *next;
};

// 新建链表法 空间复杂度高

// bool hasCycle(struct ListNode *head)
// {
//     while(head != NULL)
//     {
//         if(head->val == INT_MAX || head->next == head)
//             return true;
//         head->val = INT_MAX;
//         head = head->next;
//     }
//     return false;
// }

// 快慢指针法

int hasCycle(struct ListNode *head)
{
    if(head == NULL)
        return false;
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(1)
    {
        if(fast == NULL || fast->next == NULL)
            break;
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }

    return false;
}

int main()
{
    struct ListNode list;
    list.next = &list;

    int ans = hasCycle(&list);
    printf("%d", ans);

    return 0;
}