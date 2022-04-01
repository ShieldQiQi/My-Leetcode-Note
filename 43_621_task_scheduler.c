#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int leastInterval(char* tasks, int tasksSize, int n)
{
    int tasksFreq[26];
    memset(tasksFreq, 0, sizeof(tasksFreq));
    for(int i=0; i<tasksSize; i++)
        tasksFreq[tasks[i]-'A']++;

    // 最多的执行次数
    int maxExec = 0;
    for (int i = 0; i < 26; i++) {
        maxExec = fmax(maxExec, tasksFreq[i]);
    }
    // 具有最多执行次数的任务数量
    int maxCount = 0;
    for (int i = 0; i < 26; i++) {
        if (maxExec == tasksFreq[i]) {
            maxCount++;
        }
    }

    return fmax((maxExec - 1) * (n + 1) + maxCount, tasksSize);

}


int main()
{
    char tasks[6] = {'A','A','A','B','B','B'};

    printf("%d", leastInterval(tasks, 6, 2));
    return 0;
}