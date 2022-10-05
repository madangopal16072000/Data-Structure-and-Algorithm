#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int h(int x, vector<int> coins)
{
    int n = coins.size();
    vector<vector<int>> dp(x+1, vector<int>(n+1, 0));
    for(int j = 0; j < n; j++)
    dp[0][j] = 1;

    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i - coins[j] < 0)
            dp[i][j] = dp[i][j-1] % M;
            else
            dp[i][j] = (dp[i-coins[j]][j] + dp[i][j-1]) % M;
        }
        
    }
    return dp[x][n-1];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> coins;
    coins.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        coins.push_back(d);
    }
    cout << h(x, coins) << endl;
    return 0;
}