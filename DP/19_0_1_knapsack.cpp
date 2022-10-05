#include<iostream>
#include<vector>
using namespace std;

int knapsack(int N, int S, int wt[], int val[], vector<vector<int>> dp)
{
    // base case
    if(N == 0 || S == 0)
    return 0;

    if(dp[N][S] != -1)
    return dp[N][S];
    // rec case
    int inc = INT_MIN;
    int exc = INT_MIN;
    if(wt[N-1] < S)
    inc = val[N-1] + knapsack(N-1, S - wt[N-1], wt, val, dp);

    exc = knapsack(N-1, S, wt, val, dp);
    return dp[N][S] = max(inc, exc);
}
int main()
{
    int N, S;
    cin >> N >> S;
    int *wt = new int[N];
    int *val = new int[N];

    for(int i = 0; i < N; i++)
    cin >> wt[i];

    for(int i = 0; i < N; i++)
    cin >> val[i];

    vector<vector<int>> dp(N+1, vector<int>(S+1, -1));
    cout << knapsack(N, S, wt, val, dp) << endl;
    return 0;
}