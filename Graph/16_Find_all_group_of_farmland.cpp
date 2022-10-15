#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bfs(int i, int j, vector<vector<int>> &land)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        land[i][j] = 2;
        int xmin, ymin, xmax, ymax;
        xmin = ymin = INT_MAX;
        xmax = ymax = INT_MIN;
        int m = land.size();
        int n = land[0].size();

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            xmin = min(xmin, r);
            ymin = min(ymin, c);
            xmax = max(xmax, r);
            ymax = max(ymax, c);
            q.pop();
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int row = r + drow[i];
                int col = c + dcol[i];

                if (col >= 0 && col < n && row >= 0 && row < m && land[row][col] == 1)
                {
                    q.push({row, col});
                    land[row][col] = 2;
                }
            }
            
        }
        return {xmin, ymin, xmax, ymax};
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == 1)
                {
                    vector<int> row = bfs(i, j, land);
                    ans.push_back(row);
                }
            }
        }
        return ans;
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
    vector<vector<int>> land;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        land.push_back(row);
    }

    Solution sln;
    vector<vector<int>> ans = sln.findFarmland(land);
    for(vector<int> vec : ans)
    {
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}