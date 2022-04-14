#include <stdio.h>
#include <stdlib.h>

char * longestPalindrome(char * s)
{
    int maxLength = 0;
    int startIndex=0;
    int stringLen = 0;
    while(s[stringLen])
        stringLen++;

    for(int i=0; i<stringLen; i++)
    {
        int left = 0, right = 0;
        while(i-left-1>=0 && i+right+1<stringLen && s[i-left-1]==s[i+right+1])
        {
            left++;
            right++;
        }
        if(right+left+1>maxLength)
        {
            startIndex = i-left;
            maxLength = right+left+1;
        }
    }

    for(int i=0; i<stringLen-1; i++)
    {
        int j=i+1;
        if(s[i] != s[j])
            continue;
        int left = 0, right = 0;
        while(i-left-1>=0 && j+right+1<stringLen && s[i-left-1]==s[j+right+1])
        {
            left++;
            right++;
        }
        if(right+left+2>maxLength)
        {
            startIndex = i-left;
            maxLength = right+left+2;
        }
    }

    char *ans = (char*)malloc(sizeof(char)*(maxLength+1));
    for(int i=0; i<maxLength; i++)
    {
        ans[i] = s[startIndex+i];
    }
    ans[maxLength] = NULL;
    return ans;
}

int main()
{
    char string[6] = "babad";
    char *ans = longestPalindrome(string);
    int i=0;
    while(ans[i] != NULL) {
        printf("%c", ans[i]);
        i++;
    }
    return 0;
}