#include<iostream>
using namespace std;

int ladders(int N, int K, int dp[])
{
    // base case
    if(N == 0)
    return 1;

    // lookup
    if(dp[N] != 0)
    return dp[N];

    // recursive case
    int ways = 0;
    for(int i = 1; i<=K; i++)
    {
        if(N-i >= 0)
        {
            ways += ladders(N-i, K, dp);
        }
    }
    return dp[N] = ways;
}

int main()
{
    int N, K;
    cin >> N >> K;
    int dp[100] = {0};
    cout << ladders(N, K, dp) << endl;
    return 0;
}