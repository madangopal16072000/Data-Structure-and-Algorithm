#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool bfs(int i, int j, vector<vector<int>> &grid2, vector<vector<int>> grid1)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid2[i][j] = 2;
        int m = grid2.size();
        int n = grid2[0].size();
        bool ans = true;
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (grid1[r][c] == 0)
                ans = false;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int row = r + drow[i];
                int col = c + dcol[i];

                if (row >= 0 && row < m && col >= 0 && col < n && grid2[row][col] == 1)
                {
                    q.push({row, col});
                    grid2[row][col] = 2;
                }
            }
        }
        return ans;
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size();
        int n = grid1[0].size();

        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1 && grid1[i][j] == 1)
                {
                    bool ans = bfs(i, j, grid2, grid1);
                    if (ans)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid1;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        grid1.push_back(row);
    }

    vector<vector<int>> grid2;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        grid2.push_back(row);
    }
    Solution sln;
    cout << sln.countSubIslands(grid1, grid2) << endl;
    return 0;
}