#include<iostream>
using namespace std;

int minCoins(int N, int coins[], int T, int dp[])
{
    // base case
    if(N == 0)
    return 0;

    // lookup
    if(dp[N] != 0)
    return dp[N];

    // recursive case;
    int ans = INT_MAX;

    for(int i = 0; i < T; i++)
    {
        if(N - coins[i] >= 0)
        {
            int sub = minCoins(N-coins[i], coins, T, dp) + 1;
            ans = min(ans, sub);
        }
    }

    dp[N] = ans;
    return dp[N];
}

int main()
{
    int N;
    cin >> N;
    int coins[] = {1, 7, 10};
    int T = sizeof(coins)/sizeof(int);

    int dp[100] = {0};
    cout << minCoins(N, coins, T, dp) << endl;
    return 0;
}