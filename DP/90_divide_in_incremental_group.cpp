#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, int j, int prev, vector<vector<vector<int>>> &dp)
    {
        // base case
        if (i == 0 && j == 0)
            return 1;
        else if (i <= 0 || j == 0)
            return 0;

        if (dp[i][j][prev] != -1)
            return dp[i][j][prev];

        int ans = 0;
        for (int k = prev; k <= i; k++)
        {
            ans = ans + f(i - k, j - 1, k, dp);
        }

        return dp[i][j][prev] = ans;
    }
    int countWaystoDivide(int N, int K)
    {
        // Code here
        int ans = 0;
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(N + 1, -1)));
        for (int k = 1; k <= N; k++)
        {
            ans = ans + f(N - k, K - 1, k, dp);
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
    int N, K;
    cin >> N >> K;
    Solution sln;
    cout << sln.countWaystoDivide(N, K) << endl;
    return 0;
}