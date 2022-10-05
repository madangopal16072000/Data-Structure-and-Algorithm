#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({0, {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        vector<vector<int>> dist = mat;
        while (!q.empty())
        {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            int drow[4] = {-1, 0, 1, 0};
            int dcol[4] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int row = r + drow[i];
                int col = c + dcol[i];

                if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col])
                {
                    dist[row][col] = d + 1;
                    q.push({dist[row][col], {row, col}});
                    visited[row][col] = true;
                }
            }
        }
        return dist;
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
    vector<vector<int>> mat;
    for (int i = 0; i < m; i++)
    {
        vector<int> vec;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            vec.push_back(d);
        }
        mat.push_back(vec);
    }
    Solution sln;
    vector<vector<int>> ans = sln.updateMatrix(mat);
    for(vector<int> row : ans)
    {
        for(int x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}