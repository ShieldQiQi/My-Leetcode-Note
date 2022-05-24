#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int minDistance(char * word1, char * word2)
{
    int dp[502][502];

    int length1 = 0, length2 = 0;
    for (length1 = 1; word1[length1-1]; length1++)
        dp[length1][0] = length1;
    for (length2 = 1; word2[length2-1]; length2++)
        dp[0][length2] = length2;
    dp[0][0] = 0;

    for (int i = 1; word1[i-1]; i++) {
        for (int j = 1; word2[j-1]; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = fmin(fmin(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
            }
        }
    }

    return dp[length1-1][length2-1];
}

int main()
{
    char *word1 = "horse";
    char *word2 = "ros";

    printf("%d", minDistance(word1, word2));

    return 0;
}