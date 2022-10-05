#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;

        int freshOrg = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({0, {i, j}});
                    visited[i][j] = 2;
                }
                if(grid[i][j] == 1)
                {
                    freshOrg++;
                }
            }
        }

        int tm = 0;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        int cnt = 0;
        while(!q.empty())
        {
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            tm = max(t, tm);

            for(int i = 0; i < 4; i++)
            {
                int row = r + drow[i];
                int col = c + dcol[i];

                if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1 && visited[row][col] == 0)
                {
                    q.push({t+1, {row, col}});
                    visited[row][col] = 2;
                    cnt++;
                }
            }
        }
        if(cnt != freshOrg)
        return -1;
        else
        return tm;
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
    vector<vector<int>> grid;
    for(int i = 0; i < m; i++)
    {
        vector<int> row;
        for(int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        grid.push_back(row);
    }
    Solution sln;
    cout << sln.orangesRotting(grid) << endl;
    return 0;
}