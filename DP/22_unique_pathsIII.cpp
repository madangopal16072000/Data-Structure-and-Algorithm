#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, int m, int n, vector<vector<int>> &grid)
{
    if (i >= m || j >= n || i < 0 || j < 0)
        return 0;

    if (grid[i][j] == 2)
        return 1;

    if (grid[i][j] == -1)
        return 0;




    if(grid[i][j] == 0)
    grid[i][j] = -1;

    int left = helper(i, j - 1, m, n, grid);
    int down = helper(i + 1, j, m, n, grid);
    int right = helper(i, j + 1, m, n, grid);
    int top = helper(i - 1, j, m, n, grid);
    grid[i][j] = 0;

    return left + down + right + top;
}
int uniquePathsIII(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int i, j;
    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                cout << i << " " << j << endl;
                break;
            }
        }
        if(j != n)
        break;
    }
    int ans = helper(i, j, m, n, grid);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        cout << grid[i][j] << " ";


        cout << endl;
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid{{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    cout << uniquePathsIII(grid) << endl;
    return 0;
}