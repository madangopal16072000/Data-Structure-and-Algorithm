#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool f(int i, int j, string s, string p, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0)
        return true;

        if(i >= 0 && j < 0)
        return false;

        if(i < 0 && j >= 0)
        {
            if(p[j] == '*')
            {
                for(int k = j-1; k >= 0; k=k-2)
                {
                    if(p[k] != '*')
                    return false;
                }
                return true;
            }
            else
            return false;
        }
        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] == p[j] || p[j] == '.')
        return dp[i][j] = f(i-1, j-1, s, p, dp);
        else if(p[j] == '*')
        {
            bool op1, op2;
            op1 = op2 = false;

            op1 = f(i, j-2, s, p, dp);
            if(s[i] == p[j-1] || p[j-1] == '.')
            {
                op2 = f(i-1, j, s, p, dp);
            }

            return dp[i][j] = op1 || op2;
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m-1, n-1, s, p, dp);
    }
    bool isMatch2(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        for(int j = 1; j <= n; j++)
        {
            if(p[j-1] == '*')
            {
                int k;
                for(k = j-1; k >= 0; k = k-2)
                {
                    if(p[k] != '*')
                    break;
                }
                if(k < 0)
                dp[0][j] = true;
            }
            else
            dp[0][j] = false;
        }
        dp[0][0] = true;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    bool op1, op2;
                    op1 = op2 = false;
                    op1 = dp[i][j-2];
                    if(s[i-1] == p[j-2] || p[j-2] == '.')
                    {
                        op2 = dp[i-1][j];
                    }
                    dp[i][j] = op1 || op2;
                }
                else
                dp[i][j] = false;
            }
            
        }
        return dp[m][n];
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string s, p;
    cin >> s >> p;
    Solution sln;
    cout << sln.isMatch2(s, p) << endl;
    return 0;
}