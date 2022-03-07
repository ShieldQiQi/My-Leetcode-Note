#include <stdio.h>
#include <stdlib.h>

// void addNext(int** grid, int gridSize, int gridColSize, int i, int j, int sum, int* minPath)
// {
//     // update the sum
//     sum+=grid[i][j];

//     // add down
//     if(i+1<gridSize)
//         addNext(grid, gridSize, gridColSize, i+1, j, sum, minPath);
//     // add right
//     if(j+1<gridColSize)
//         addNext(grid, gridSize, gridColSize, i, j+1, sum, minPath);

//     if(/**minPath>sum && */i==gridSize-1 && j==gridColSize-1){
//         //*minPath = sum;
//         //printf("%d\n", sum);
//         static int count=0;
//         printf("%d\n", count++);
//     }
//     return;
// }

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    for(int i=0; i<gridSize; i++)
    {
        for(int j=0; j<*gridColSize; j++)
        {
            if(i==j && j==0)
            {
                continue;
            } else if(i==0) {
                grid[i][j] += grid[i][j-1];
            } else if(j==0) {
                grid[i][j] += grid[i-1][j];
            } else {
                grid[i][j] += grid[i][j-1]>grid[i-1][j]?grid[i-1][j]:grid[i][j-1];
            }
        }
    }
    return grid[gridSize-1][*gridColSize-1];
}

int main()
{
    int grid1[8] = {1,4,8,6,2,2,1,7};
    int grid2[8] = {4,7,3,1,4,5,5,1};
    int grid3[8] = {8,8,2,1,1,8,0,1};
    int grid4[8] = {8,9,2,9,8,0,8,9};
    int grid5[8] = {5,7,5,7,1,8,5,5};
    int grid6[8] = {7,0,9,4,5,6,5,6};
    int grid7[8] = {4,9,9,7,9,1,9,0};
    int *grid[7] = {grid1, grid2, grid3, grid4, grid5, grid6, grid7};
    int gridSize = 7;
    int gridColSize = 8;

    int minPath = minPathSum(grid, gridSize, &gridColSize);

    printf("%d", minPath);

    return 0;
}
