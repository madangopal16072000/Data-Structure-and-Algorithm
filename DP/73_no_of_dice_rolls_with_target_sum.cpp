#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

class Solution {
public:
    int f(int n, int k, int target, vector<vector<int>> &dp)
    {
        if(n < 0 && target == 0)
        return 1;

        if(target < 0 || n < 0)
        return 0;

        if(dp[n][target] != -1)
        return dp[n][target];

        int ans = 0;
        for(int i = 1; i <= k; i++)
        {
            ans = (ans + f(n-1, k, target-i, dp))%M;
        }
        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, k, target, dp);
    }
    int numRollsToTarget2(int n, int k, int target)
    {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
        for(int j = 0; j <= target; j++)
        dp[0][j] = 0;

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                int ans = 0;
                for(int l = 1; l <= k; l++)
                {
                    if(j-l >= 0 && i-1>=0)
                    {
                        ans = (ans + dp[i-1][j-l])%M;
                    }
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][target];
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    int n, k, target;
    Solution sln;
    while(t--)
    {
        cin >> n >> k >> target;
        cout << sln.numRollsToTarget2(n, k, target) << endl;
    }
    return 0;
}