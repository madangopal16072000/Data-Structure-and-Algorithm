#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &dp, vector<vector<int>> &matrix)
    {
        vis[i][j] = true;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int m = matrix.size();
        int n = matrix[0].size();

        for (int k = 0; k < 4; k++)
        {
            int r = drow[k] + i;
            int c = dcol[k] + j;

            if (r >= 0 && r < m && c >= 0 && c < n && matrix[r][c] > matrix[i][j])
            {
                if (!vis[r][c])
                {
                    dp[i][j] = max(dp[i][j], 1 + dfs(r, c, vis, dp, matrix));
                }
                else
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[r][c]);
                }
            }
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dp(m, vector<int>(n, 1));

        int ans = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j])
                {
                    ans = max(ans, dfs(i, j, vis, dp, matrix));
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
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        matrix.push_back(row);
    }

    Solution sln;
    cout << sln.longestIncreasingPath(matrix) << endl;
    return 0;
}