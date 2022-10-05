#include<bits/stdc++.h>
using namespace std;

int exchangeCoins(int n, vector<int> &dp)
{
    // base case
    if(n <= 0)
    return 0;

    if(dp[n] != -1)
    return dp[n];
    int op1, op2, op3, op4;
    op1 = op2 = op3 = op4 = 0;

    if(n%4 == 0)
    {
        op1 = exchangeCoins(n/4, dp);
    }
    if(n%3 == 0)
    {
        op2 = exchangeCoins(n/3, dp);
    }
    if(n%2 == 0)
    {
        op3 = exchangeCoins(n/2, dp);
    }
    op4 = n;
    return dp[n] = max(op1 + op2 + op3, op4);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    cout << exchangeCoins(n, dp) << endl;
    for(int x : dp)
    cout << x << " ";
    return 0;
}