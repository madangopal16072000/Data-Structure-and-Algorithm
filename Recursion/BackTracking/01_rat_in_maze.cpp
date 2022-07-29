#include <iostream>
using namespace std;

static int count = 0;
bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
    {
        soln[i][j] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    if (i >= m || j >= n)
        return false;

    if (maze[i][j] == 'X')
        return false;

    soln[i][j] = 1;

    bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
    bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);

    // Backtracking
    soln[i][j] = 0;
    if (rightSuccess || downSuccess)
    {
        return true;
    }
    return false;
}
int main()
{
    char maze[10][10] = {
        "OXOO",
        "OOOX",
        "OOXO",
        "XOOO",
        "XXOO"};

    int soln[10][10] = {0};
    int m = 5, n = 4;
    bool ans = ratInMaze(maze, soln, 0, 0, m, n);

    if (!ans)
        cout << "Path doesn't exists" << endl;
    return 0;
}