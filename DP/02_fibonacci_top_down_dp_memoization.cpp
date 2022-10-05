#include<iostream>
using namespace std;

int fib(int n, int dp[])
{
    if(n == 1 || n == 0)
    return n;
    
    if(dp[n] != 0)
    return dp[n];

    int ans;
    ans = fib(n-1, dp) + fib(n-2, dp);
    return dp[n] = ans;
}

int main()
{
    int dp[10] = {0};
    cout << fib(6, dp) << endl;
    return 0;
}