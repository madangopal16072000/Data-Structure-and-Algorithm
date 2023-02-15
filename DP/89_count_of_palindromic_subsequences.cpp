#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
class Solution
{
public:
    /*You are required to complete below method */
    long long int countPS(string str)
    {
        // Your code here

        int n = str.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = 1;
                }
                else if (gap == 1)
                {
                    if (str[i] == str[j])
                    {
                        dp[i][j] = 3;
                    }
                    else
                    {
                        dp[i][j] = 2;
                    }
                }
                else
                {
                    if (str[i] == str[j])
                    {
                        dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) % MOD;
                    }
                    else
                    {
                        dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) % MOD;
                    }
                }
            }
        }

        return (dp[0][n - 1] + MOD) % MOD;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string str;
    cin >> str;
    Solution sln;
    cout << sln.countPS(str) << endl;
    return 0;
}