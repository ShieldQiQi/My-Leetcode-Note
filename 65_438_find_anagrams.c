#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize)
{
    int bucket[26], tmp[26];
    memset(bucket, 0, 26*4);
    memset(tmp, 0, 26*4);
    int p_length = 0;
    int diff_count = 0;
    int *ans = (int*)malloc(sizeof(int)*50000);
    *returnSize = 0;

    while(*p) {
        bucket[*p - 'a']++;
        if(!s[p_length])
            return ans;
        tmp[s[p_length]-'a']++;
        p++;
        p_length++;
    }

    for(int i=0; i<26; i++) {
        diff_count += abs(tmp[i]-bucket[i]);
    }

    for(int i=p_length-1; s[i]; i++) {
        if(diff_count == 0) {
            ans[*returnSize] = i-p_length+1;
            *returnSize += 1;
        }
        if(s[i+1]) {
            if(++tmp[s[i+1]-'a'] <= bucket[s[i+1]-'a'])
                diff_count--;
            else
                diff_count++;
            if(--tmp[s[i-p_length+1]-'a'] < bucket[s[i-p_length+1]-'a'])
                diff_count++;
            else
                diff_count--;
        }
    }
    return ans;
}

int main()
{
    char *s = "cbaebabacd", *p = "abc";
    int returnSize;
    int *ans = findAnagrams(s, p, &returnSize);
    for(int i=0; i<returnSize; i++)
        printf("%d ", ans[i]);
    return 0;
}
