#include<bits/stdc++.h>
using namespace std;

int uniquePaths1(int i, int j, vector<vector<int>> &dp)
{
    if(i == 0 && j == 0)
    return 1;

    if(i < 0 || j < 0)
    return 0;

    // recursive case
    if(dp[i][j] != -1)
    return dp[i][j];

    int top = uniquePaths1(i-1, j, dp);
    int left = uniquePaths1(i, j-1, dp);
    return top + left;
}
int uniquePaths2(int m, int n)
{
    vector<vector<int>> dp(m, vector<int> (n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
            dp[i][j] = 1;
            else
            {
                int top = 0, left = 0;
                if(i > 0)
                {
                    top = dp[i-1][j];
                }
                if(j > 0)
                {
                    left = dp[i][j-1];
                }
                dp[i][j] = top + left;
            }
        }
    }
    return dp[m-1][n-1];
}

int uniquePaths3(int m, int n)
{
    vector<int> preRow(n, 0);

    for(int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
            curr[j] = 1;
            else
            {
                int top = 0, left = 0;
                if(i > 0)
                {
                    top = preRow[j];
                }
                if(j > 0)
                {
                    left = curr[j-1];
                }
                curr[j] = top + left;
            }
        }
        preRow = curr;
    }
    return preRow[n-1];
}
int main()
{
    int m, n;
    cin >> m >> n;
    // vector<vector<int>> dp(m, vector<int> (n, -1));
    // cout << uniquePaths1(m-1, n-1, dp) << endl;
    // cout << uniquePaths2(m, n) << endl;

    cout << uniquePaths3(m, n) << endl;
    return 0;
}