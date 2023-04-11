#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        int n = grid.size();
        vis[r][c] = true;
        grid[r][c] = -1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++)
        {
            int x = drow[k] + r;
            int y = dcol[k] + c;

            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 && vis[x][y] == false)
            {
                dfs(x, y, grid, vis);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {

        int n = grid.size();
        bool first = true;
        vector<vector<bool>> vis(n, vector<bool>(n, false)), visited(n, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    if (first)
                    {
                        dfs(i, j, grid, vis);
                        first = false;
                    }
                    else
                    {
                        q.push({0, {i, j}});
                        visited[i][j] = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        while (!q.empty())
        {
            int step = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;

            q.pop();

            if (grid[x][y] == -1)
                return step;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++)
            {
                int r = drow[k] + x;
                int c = drow[k] + y;

                if (r >= 0 && r < n && c >= 0 && c < n && !visited[r][c])
                {
                    visited[r][c] = true;
                    q.push({step + 1, {r, c}});
                }
            }
        }

        return -1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        grid.push_back(row);
    }

    Solution sln;
    cout << sln.shortestBridge(grid) << endl;
    return 0;
}