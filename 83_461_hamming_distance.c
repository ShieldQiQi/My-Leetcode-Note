#include <stdio.h>
#include <stdlib.h>

int hammingDistance(int x, int y)
{
    int ans = 0;
    for (int i=0; i<31; i++) {
        int mask = 1 << i;
        if ((x & mask) != (y & mask))
            ans++;
    }
    return ans;
}

int main()
{

    printf("%d ", hammingDistance(1, 4));

    return 0;
}
