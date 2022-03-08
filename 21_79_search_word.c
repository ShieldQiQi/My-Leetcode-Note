#include <stdio.h>
#include <stdlib.h>

int dfs(char** board, int boardSize, int* boardColSize, char * word, int* index, int i, int j)
{
    if(word[*index]=='\0')
    {
        return 1;
    }
    if(board[i][j] == word[*index])
    {
        (*index)++;
        char temp = board[i][j];
        board[i][j] = '\0';
        if(i+1<boardSize && dfs(board, boardSize, boardColSize, word, index, i+1, j))
        {
            return 1;
        }
        if(j+1<boardColSize[0] && dfs(board, boardSize, boardColSize, word, index, i, j+1))
        {
            return 1;
        }
        if(i-1>=0 && dfs(board, boardSize, boardColSize, word, index, i-1, j))
        {
            return 1;
        }
        if(j-1>=0 && dfs(board, boardSize, boardColSize, word, index, i, j-1))
        {
            return 1;
        }
        if(word[*index]=='\0')
        {
            return 1;
        }
        (*index)--;
        board[i][j] = temp;
    }
    return 0;
}

int exist(char** board, int boardSize, int* boardColSize, char * word)
{
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardColSize[i]; j++)
        {
            // get the first char
            if(board[i][j] == word[0])
            {
                int index = 0;
                if(dfs(board, boardSize, boardColSize, word, &index, i, j))
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    char char1[3] = {'C', 'A', 'A'};
    char char2[3] = {'A', 'A', 'A'};
    char char3[3] = {'B', 'C', 'D'};
    char* board[3] = {char1, char2, char3};
    int boardColSize[3] = {3, 3, 3};
    char word[4] = "AAB";
    // char char_[1] = {'a'};
    // int boardColSize[1] = {1};
    // char* board[1] = {char_};
    // char word[2] = "a";
    if(exist(board, 3, boardColSize, word))
        printf("true");
    else
        printf("false");

    return 0;
}