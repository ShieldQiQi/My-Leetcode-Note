#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void dfs(struct ListNode* head, int n, int* index)
{
    if(head != NULL)
    {
        dfs(head->next, n, index);
        *index += 1;
        if(*index == n+1)
        {
            struct ListNode* temp = head->next;
            head->next = head->next->next;
            // free(temp);
        }
    }
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int index = 0;
    dfs(head, n, &index);
    if(index == n)
    {
        struct ListNode* temp = head->next;
        // free(head);
        return temp;
    }
    return head;
}

int main()
{
    struct ListNode head1 = {6, NULL};
    struct ListNode middle = {2, NULL};
    head1.next = &middle;

    struct ListNode* ans = removeNthFromEnd(&head1, 1);

    while(ans)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }

    return 0;
}