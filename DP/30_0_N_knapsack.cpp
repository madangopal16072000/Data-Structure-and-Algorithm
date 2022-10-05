#include<bits/stdc++.h>
using namespace std;


int knapsack(int i, int n, int W, vector<int> &wt, vector<int> &val, int sum, vector<vector<int>> &dp)
{
    if(i >= n)
    return 0;

    if(dp[i][sum] != -1)
    return dp[i][sum];

    int inc, exc;
    inc = exc = 0;

    if(sum + wt[i] <= W)
    inc = val[i] + knapsack(i, n, W, wt, val, sum + wt[i], dp);

    exc = knapsack(i+1, n, W, wt, val, sum, dp);
    return dp[i][sum] = max(inc, exc);
}
int main()
{
    int n, W;
    cin >> n >> W;
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    vector<int> wt;
    vector<int> val;

    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        wt.push_back(d);
    }

    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        val.push_back(d);
    }

    cout << knapsack(0, n, W, wt, val, 0, dp) << endl;
    return 0;
}
// int main()
// {
//     int n, W;
//     // cin >> n >> W;
//     n = 5, W = 11;
//     vector<int> wt {3, 2, 4, 5, 1};
//     vector<int> val {4, 3, 5, 6, 1};
//     vector<vector<int>> dp(n, vector<int>(W+1, -1));
//     cout << knapsack(0, n, W, wt, val, 0, dp) << endl;
//     return 0;
// }