#include <stdio.h>

int countSubstrings(char * s)
{
    int ans = 0;
    for (int i=0; s[i]; i++) {
        for (int j=0; i-j>=0 && s[i+j]; j++) {
            if (s[i-j] == s[i+j]) {
                ans++;
            } else {
                break;
            }
        }
        for (int j=0; i-j>=0 && s[i+1] && s[i+1+j]; j++) {
            if (s[i-j] == s[i+1+j]) {
                ans++;
            } else {
                break;
            }
        }
    }

    return ans;
}

int main()
{
    char *string = "abs";
    printf("%d", countSubstrings(string));

    return 0;
}