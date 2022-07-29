#include<iostream>
using namespace std;
bool isSafe(int board[][10], int i, int j, int n)
{
    // row check
    for(int row = 0; row <i; row++)
    {
        if(board[row][j] == 1)
        return false;
    }

    // left diagonal check
    int x = i;
    int y = j;
    while(x >= 0 && y >= 0)
    {
        if(board[x][y] == 1)
        return false;

        x--;
        y--;
    }

    // right diagonal check

    x = i;
    y = j;
    while(x >= 0 && y <n)
    {
        if(board[x][y] == 1)
        return false;

        x--;
        y++;
    }
    return true;

}
bool solveNQueen(int board[][10], int n, int i)
{
    if(i == n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 1)
                cout << "Q ";
                else
                cout << "X ";
            }
            cout << endl;
        }
        return true;
    }

    for(int j=0; j<n; j++)
    {
        if(isSafe(board, i, j, n))
        {
            board[i][j] = 1;
            bool result = solveNQueen(board, n, i+1);
            if(result)
            return true;
        }
        board[i][j] = 0;
    }
    return false;
}
int main()
{
    int board[10][10] = {0};
    int N;
    cin >> N;
    solveNQueen(board, N, 0);
    return 0;
}