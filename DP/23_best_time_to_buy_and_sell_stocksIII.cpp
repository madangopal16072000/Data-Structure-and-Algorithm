#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> &prices, int i, int canBuy, int attempt, vector<vector<vector<int>>> &dp)
{
    // base case
    if(i == prices.size() || attempt >= 2)
    return 0;
    
    // memo
    if(dp[i][canBuy][attempt] != -1)
    return dp[i][canBuy][attempt];

    int profit = 0;
    if(canBuy)
    {
        profit = max(-prices[i] + helper(prices, i+1, 0, attempt, dp), helper(prices, i+1, 1, attempt, dp));
    }
    else
    {
        profit = max(prices[i] + helper(prices, i+1, 1, attempt + 1,dp), helper(prices, i+1, 0, attempt, dp));
    }

    return dp[i][canBuy][attempt] = profit;
}
int maxProfit(vector<int> &prices)
{
    int canBuy = 1;
    int attempt = 0;
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
    return helper(prices, 0, canBuy, attempt, dp);
}
int main()
{
    vector<int> prices {3,3,5,0,0,3,1,4};
    cout << maxProfit(prices) << endl;
}