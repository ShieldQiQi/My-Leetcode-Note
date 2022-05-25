#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

char * minWindow(char * s, char * t)
{
    // 65-90 97-122
    int *t_element = (int*)malloc(sizeof(int)*58);
    int *t_element_diff = (int*)malloc(sizeof(int)*58);
    int diff_count = 0;
    memset(t_element, 0, 58*4);
    memset(t_element_diff, 0, 58*4);
    for (int i = 0; t[i]; i++) {
        t_element[t[i]-65]++;
        t_element_diff[t[i]-65]++;
        diff_count++;
    }
    //
    char *removed_element = (char*)malloc(sizeof(char)*100000);
    memset(removed_element, 0, 100000);
    //
    struct Queue *ele_queue = initQueue(NULL, 0);
    struct Queue **char_queue = (struct Queue**)malloc(sizeof(struct Queue*)*58);
    for (int i = 0; i<58; i++)
        char_queue[i] = initQueue(NULL, 0);
    //
    int left = -1, right = INT_MAX, min_length = INT_MAX;
    int min_left, min_right;
    for (int i = 0; s[i]; i++) {
        if (t_element[s[i]-65]) {
            if (t_element_diff[s[i]-65] > 0) {
                t_element_diff[s[i]-65]--;
                diff_count--;
            }
            if (left == -1)
                left = i;
            if (char_queue[s[i]-65]->size >= t_element[s[i]-65]) {
                int index = popQueue(char_queue[s[i]-65]);
                removed_element[index] = 1;
                if (index == left) {
                    while (ele_queue->size && removed_element[ele_queue->head->next->value])
                        popQueue(ele_queue);
                    left = ele_queue->size?ele_queue->head->next->value:i;
                }
            }
            insertQueue(char_queue[s[i]-65], i);
            insertQueue(ele_queue, i);
            right = i;
            if (diff_count == 0 && right - left + 1 < min_length) {
                min_length = right - left + 1;
                min_left = left;
                min_right = right;
            }
        }
    }
    if (diff_count)
        return "";
    char *ans = (char*)malloc(sizeof(char)*(min_length+1));
    memcpy(ans, s+min_left, min_length);
    ans[min_length] = 0;
    return ans;
}

int main()
{
    char *s = "bba";//"ADOBECODEBANC";
    char *t = "ab";//"ABC";
    char *ans = minWindow(s, t);

    while(*ans) {
        printf("%c", *ans);
        ans++;
    }
    return 0;
}