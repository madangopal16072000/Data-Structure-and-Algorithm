#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, int n, vector<int> &piles, vector<vector<int>> &dp, int turn, int M)
    {
        // base case
        if(i >= n)
        return 0;

        if(dp[i][turn] != -1)
        return dp[i][turn];

        int ans = 0;
        if(turn == 0)
        {
            for(int X = 1; X <= 2*M && i + X < n; X++)
            {
                int sum = 0;
                int j;
                for(j = i; j < i + X; j++)
                {
                    sum = sum + piles[j];
                }

                ans = max(ans, sum + f(i + X, n, piles, dp, 1, max(X, M)));
            }
        }
        else
        {
            for(int X = 1; X <= 2*M && i + X < n; X++)
            {
                int sum = 0;
                int j;
                for(j = i; j < i+X; j++)
                {
                    sum = sum + piles[j];
                }
                
                ans = max(ans, sum + f(i + X, n, piles, dp, 0, max(X, M)));
            }
        }
        return dp[i][turn] = ans;

    }
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, n, piles, dp, 0, 1);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> piles;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        piles.push_back(d);
    }
    Solution sln;
    cout << sln.stoneGameII(piles) << endl;
    return 0;
}