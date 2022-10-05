#include <iostream>
#include <vector>
using namespace std;
    int helper(vector<int> &prices, int i, int canBuy,vector<vector<int>> &dp, int fee)
    {
        // base case
        if(i == prices.size())
            return 0;
        
        // memo
        if(dp[i][canBuy] != -1)
            return dp[i][canBuy];
        
        int profit = 0;
        if(canBuy)
        {
            profit = max(-prices[i] + helper(prices, i+1, 0,dp, fee), helper(prices, i+1, 1,dp, fee));
        }
        else
        {
            int inc = prices[i] + helper(prices, i+1, 1,dp, fee) - fee;

            int exc = helper(prices, i+1, 0,dp, fee);
            profit = max(inc, exc);
        }
        
        return dp[i][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int canBuy = 1;
        int cnt = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        int amt = helper(prices, 0, canBuy, dp, fee);
        return amt - fee*cnt;
    }
int main()
{
    int fee = 2;
    vector<int> prices{1, 3, 2, 8, 4, 9};
    cout << maxProfit(prices, fee) << endl;
    return 0;
}