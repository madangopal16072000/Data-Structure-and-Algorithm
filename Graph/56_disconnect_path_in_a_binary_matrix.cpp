#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cnt;
    bool dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        // base case
        if (i == n - 1 && j == m - 1)
        {
            cnt++;
            return true;
        }

        vis[i][j] = true;

        if (i + 1 < n && vis[i + 1][j] == false && grid[i + 1][j] == 1)
        {
            if (dfs(i + 1, j, n, m, grid, vis))
                return true;
        }

        if (j + 1 < m && vis[i][j + 1] == false && grid[i][j + 1] == 1)
        {
            if (dfs(i, j + 1, n, m, grid, vis))
                return true;
        }

        return false;
    }
    bool isPossibleToCutPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        cnt = 0;
        dfs(0, 0, n, m, grid, vis);
        cout << cnt << endl;
        if (cnt > 1)
            return false;

        return true;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        grid.push_back(row);
    }
    Solution sln;
    cout << sln.isPossibleToCutPath(grid) << endl;
    return 0;
}