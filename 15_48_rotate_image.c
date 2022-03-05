#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int layer = matrixSize%2==0?matrixSize/2:matrixSize/2+1;

    for(int i=matrixSize%2; i<layer; i++)
    {
        for(int j=0; j<2*i+1-matrixSize%2; j++)
        {
            int x = j-i-(matrixSize+1)%2;
            if(x>=0 && matrixSize%2==0)
                x+=1;
            int y = i+(matrixSize+1)%2;
            int realX = (matrixSize%2==0 && x>0)?(x+matrixSize/2-1):(x+matrixSize/2);
            int realY = (matrixSize%2==0 && y<0)?(matrixSize/2-y-1):(matrixSize/2-y);
            int temp = matrix[realY][realX];
            for(int k=0; k<3; k++)
            {
                // anti-clock rotate
                int swap = x;
                x = -y;
                y = swap;
                int realX_ = (matrixSize%2==0 && x>0)?(x+matrixSize/2-1):(x+matrixSize/2);
                int realY_ = (matrixSize%2==0 && y<0)?(matrixSize/2-y-1):(matrixSize/2-y);
                matrix[realY][realX] = matrix[realY_][realX_];
                realX = realX_;
                realY = realY_;
            }
            matrix[realY][realX] = temp;
        }
    }
}

int main()
{
    int matrix1[4] = {5,1,9,11};
    int matrix2[4] = {2,4,8,10};
    int matrix3[4] = {13,3,6,7};
    int matrix4[4] = {15,14,12,16};
    int* matrix[4] = {matrix1, matrix2, matrix3, matrix4};
    int matrixSize = 4;
    int matrixColSize[4] = {4,4,4,4};

    rotate((int**)matrix, matrixSize, matrixColSize);
    printf("result is:\n");
    for(int i=0; i<matrixSize; i++)
    {
        for(int j=0; j<matrixColSize[i]; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}