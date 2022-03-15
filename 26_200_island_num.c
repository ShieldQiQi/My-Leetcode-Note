#include <stdio.h>
#include <stdlib.h>

void dfs(char grid[4][5], int gridSize, int* gridColSize, int i, int j)
{
    if(i<0 || i>=gridSize || j<0 || j>=gridColSize[0])
        return;
    if(grid[i][j]=='1')
    {
        grid[i][j] = '2';
        dfs(grid, gridSize, gridColSize, i-1, j);
        dfs(grid, gridSize, gridColSize, i+1, j);
        dfs(grid, gridSize, gridColSize, i, j-1);
        dfs(grid, gridSize, gridColSize, i, j+1);
    }
}

int numIslands(char grid[4][5], int gridSize, int* gridColSize)
{
    int islandNum = 0;
    for(int i=0; i<gridSize; i++)
    {
        for(int j=0; j<gridColSize[i]; j++)
        {
            if(grid[i][j]=='1')
            {
                islandNum++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return islandNum;
}

int main()
{
    const int gridSize = 4;
    const int colSize = 5;
    int gridColSize[gridSize];
    for(int i=0; i<gridSize; i++)
        gridColSize[i] = colSize;
    char grid[gridSize][colSize] =  {   {'1','1','1','1','0'},
                                        {'1','1','0','1','0'},
                                        {'1','1','0','0','0'},
                                        {'0','0','0','0','0'}   };
    int isLandNum = numIslands(grid, gridSize, gridColSize);
    printf("%d", isLandNum);

    return 0;
}