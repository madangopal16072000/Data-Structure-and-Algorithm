#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int amount, vector<int> &coins, int n, vector<vector<int>> &dp)
    {
        // base case
        if(amount == 0)
        return 1;

        if(n < 0)
        return 0;

        if(dp[n][amount] != -1)
        return dp[n][amount];

        // rec case
        if(amount - coins[n] < 0)
        {
            return dp[n][amount] = helper(amount, coins, n-1, dp);
        }
        else
        {
            return dp[n][amount]=helper(amount, coins, n-1, dp) + helper(amount - coins[n], coins, n, dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        int ans = helper(amount, coins, coins.size()-1, dp);
        for(vector<int> row : dp)
        {
            for(int x : row)
            cout << x << " ";
            cout << endl;
        }
        return ans;
    }
};

int main()
{
    int amount, n;
    cin >> amount >> n;
    vector<int> coins;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        coins.push_back(d);
    }

    Solution s;
    cout << s.change(amount, coins) << endl;
    return 0;
}