#include <stdio.h>
#include <stdlib.h>

int maximalSquare(char matrix[4][5], int matrixSize, int matrixColSize)
{
    int maxLength = 0;

    for(int i=0; i<matrixSize; i++)
    {
        for(int j=0; j<matrixColSize; j++)
        {
            if(matrix[i][j]=='1' && i-1>=0 && j-1>=0)
            {
                int min = matrix[i-1][j-1];
                if(min>matrix[i][j-1])
                    min = matrix[i][j-1];
                if(min>matrix[i-1][j])
                    min = matrix[i-1][j];
                matrix[i][j] = min+1;
                if(maxLength<matrix[i][j])
                    maxLength = matrix[i][j];
            }
        }
    }

    return (maxLength-'0')*(maxLength-'0');
}

int main()
{
    char matrix[4][5] = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

    int maxSquare = maximalSquare(matrix, 4, 5);
    printf("%d", maxSquare);

    return 0;
}