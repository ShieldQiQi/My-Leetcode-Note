#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// 拼接法 AB与BA
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode* path1 = headA;
    struct ListNode* path2 = headB;
    while(path1 != path2)
    {
        path1 = path1?path1->next:headB;
        path2 = path2?path2->next:headA;
    }

    return path1;
    
}

// 末端对齐法

// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
// {
//     int countA = 0, countB = 0;
//     struct ListNode* tempA = headA;
//     struct ListNode* tempB = headB;
//     while(tempA != NULL)
//     {
//         tempA = tempA->next;
//         countA++;
//     }
//     while(tempB != NULL)
//     {
//         tempB = tempB->next;
//         countB++;
//     }

//     if(countA>countB) {
//         int sub = countA-countB;
//         while(sub--)
//         {
//             headA = headA->next;
//         }
//     } else {
//         int sub = countB-countA;
//         while(sub--)
//         {
//             headB = headB->next;
//         }
//     }

//     while(headA != NULL)
//     {
//         if(headA == headB)
//             return headA;
//         headB = headB->next;
//         headA = headA->next;
//     }

//     return NULL;
// }

int main()
{
    struct ListNode headA = {1, NULL};
    struct ListNode* headB = &headA;

    struct ListNode* ans  = getIntersectionNode(&headA, headB);
    if(ans != NULL)
        printf("intersected at %d", ans->val);
    else
        printf("No intersection");

    return 0;
}