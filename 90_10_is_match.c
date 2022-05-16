#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int isMatch(char * s, char * p)
{
    int m = 0, n = 0;
    char *s_tmp = s,  *p_tmp = p;
    while (*s_tmp) {
        m++;
        s_tmp++;
    }
    while (*p_tmp) {
        n++;
        p_tmp++;
    }

    // 状态定义:dp[i][j]为考虑s[0,i-1]与p[0,j-1]是否能匹配上,能匹配上就为true
    int (*dp)[n+1] = (int(*)[n+1])malloc(sizeof(int)*(m+1)*(n+1));
    memset(dp, 0, 4*(m+1)*(n+1));
    dp[0][0] = 1;

    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                if (i && ((s[i-1] == p[j-2]) || (p[j-2] == '.'))) {
                    dp[i][j] |= dp[i - 1][j];
                }
                // s[i-1] != p[j-2]则舍去p的两项
                dp[i][j] = dp[i][j - 2];
            }
            else {
                if (i && ((s[i-1] == p[j-1]) || (p[j-1] == '.'))) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }
    return dp[m][n];
}

int main()
{
    char *s = "aa";
    char *p = "a*";
    printf("%d", isMatch(s, p));

    return 0;
}