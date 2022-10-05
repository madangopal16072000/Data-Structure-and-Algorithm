#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool f(int i, int j, string s, string p, vector<vector<int>> dp)
    {
        if(i < 0 && j < 0)
        return true;

        if(i >= 0 && j < 0)
        return false;

        if(i < 0 && j >= 0)
        {
            for(int k = 0; k <= j; k++)
            {
                if(p[k] != '*')
                return false;
            }
            return true;
        }

        // memo
        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] == p[j] || p[j] == '?')
        return dp[i][j] = f(i-1, j-1, s, p, dp);
        else if(p[j] == '*')
        {
            return dp[i][j] = f(i, j-1, s, p, dp) || f(i-1, j, s, p, dp);
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

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int j = 1; j <= n; j++)
        {
            int k;
            for(k = 1; k <= j; k++)
            {
                if(p[k-1] != '*')
                break;
            }
            if(k == j+1)
            dp[0][j] = 1;
        }
        dp[0][0] = 1;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else
                dp[i][j] = 0;
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