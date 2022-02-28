#include <stdio.h>

int maxArea_(int* height, int heightSize)
{
    int max_area = 0;
    int minHeight = 0;
    int bound = heightSize-1;
    for(int i=0; i<heightSize-1; i++)
    {
        if(height[i]>minHeight)
        {
            for(int j=bound; j>i; j--)
            {
                if(height[j]>minHeight)
                {
                    if(height[j]<height[i]){
                        minHeight = height[j];
                        int area = (j-i)*minHeight;
                        if(area > max_area)
                            max_area = area;
                    }else{
                        minHeight = height[i];
                        int area = (j-i)*minHeight;
                        bound = j;
                        if(area > max_area)
                            max_area = area;
                        break;
                    }
                }
            }
        }
    }
    return max_area;
}

int maxArea(int* height, int heightSize)
{
    int max_area = 0;

    for(int i=0, j=heightSize-1; i<j;)
    {
        if(height[i]<height[j])
        {
            max_area = max_area<(j-i)*height[i]?(j-i)*height[i]:max_area;
            i++;
        } else {
            max_area = max_area<(j-i)*height[j]?(j-i)*height[j]:max_area;
            j--;
        }
    }

    return max_area;
}

int main()
{
    int height[9] = {1,8,6,2,5,4,8,3,7};
    int heightSize = 9;

    int max_area = maxArea(height, heightSize);

    printf("%d\n", max_area);

    return 0;
}