#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int dichotomy(int** matrix, int left_x, int left_y, int right_x, int right_y, int* x, int* y, int target, int flag)
{
    if(matrix[right_x][right_y]==target)
    {
        *x = right_x;
        *y = right_y;
        return true;
    }

    if(matrix[left_x][left_y]>target && flag==1)
    {
        *x = left_x;
        *y = left_y;
        return false;
    }

    int middle_x, middle_y;
    while(!(left_x==right_x && left_y==right_y))
    {
        middle_x = (left_x+right_x)/2;
        middle_y = (left_y+right_y)/2;
        if(matrix[middle_x][middle_y]>target)
        {
            right_x = middle_x;
            right_y = middle_y;
        } else if(matrix[middle_x][middle_y]<target){
            if(left_x==middle_x && left_y==middle_y) {
                if(flag==1) {
                    *x = right_x;
                    *y = right_y;
                } else {
                    *x = left_x;
                    *y = left_y;
                }
                break;
            }
            left_x = middle_x;
            left_y = middle_y;
        } else {
            *x = middle_x;
            *y = middle_y;
            return true;
        }
    }
    return false;
}

int searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int flag = 1;
    int left_x = 0, right_x = matrixSize-1;
    int left_y = matrixColSize[0]-1, right_y = matrixColSize[0]-1;
    int x, y;
    while(!(left_x==right_x && left_y==right_y))
    {
        if(matrix[right_x][right_y] < target && flag==1)
            return false;
        if(matrix[left_x][left_y] > target && flag==0)
            return false;

        if(dichotomy(matrix, left_x, left_y, right_x, right_y, &x, &y, target, flag))
            return true;
        printf("%d %d flag:%d\n", x, y, flag);
        if(flag) {
            left_x = right_x = x;
            left_y = 0;
            right_y = y;
            flag = 0;
        } else {
            left_x = x;
            right_x = matrixSize-1;
            left_y = right_y = y;
            flag = 1;
        }
    }

    return false;
}


int main()
{
    int matrix0[5] = {1,4,7,11,15};
    int matrix1[5] = {2,5,8,12,19};
    int matrix2[5] = {3,6,9,16,22};
    int matrix3[5] = {10,13,14,17,24};
    int matrix4[5] = {18,21,23,26,30};
    int* matrix[5] = {matrix0, matrix1, matrix2, matrix3, matrix4};
    int matrixColSize[5] = {5, 5, 5, 5, 5};

    int target  = 5;
    if(searchMatrix(matrix, 5, matrixColSize, target))
    {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}