#include <iostream>
#include<cmath>
using namespace std;

bool isPossible(int Mat[][9], int N, int i, int j, int number)
{
    for(int x = 0; x<N; x++)
    {
        if(Mat[x][j] == number || Mat[i][x] == number)
        return false;
    }

    int rn = sqrt(N);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x = sx; x < sx+rn; x++)
    {
        for(int y = sy; y < sy+rn; y++)
        {
            if(Mat[x][y] == number)
            return false;
        }
    }
    return true;
}
bool sudokuSolver(int Mat[][9], int N, int i, int j)
{
    // Base case
    if (i == N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << Mat[i][j] << " ";

            cout << endl;
        }
        return true;
    }
    
    // end of any row
    if(j == N)
    {
        return sudokuSolver(Mat, N, i+1, 0);
    }
    // pre filled cells

    if(Mat[i][j] != 0 )
    {
        return sudokuSolver(Mat, N, i, j+1);
    }

    // Rec case
    for(int number = 1; number <= 9; number++)
    {
        if(isPossible(Mat, N, i, j, number))
        {
            Mat[i][j] = number;
            bool result = sudokuSolver(Mat, N, i, j+1);
            if(result)
            return true;
        }
    }
    Mat[i][j] = 0;
    return false;
}
int main()
{
    int Mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    int N = 9;
    // int N;
    // cin >> N;
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //         cin >> Mat[i][j];
    // }
    cout << sudokuSolver(Mat, N, 0, 0);
    return 0;
}