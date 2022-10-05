#include<iostream>
using namespace std;

int maxProfit(int price[], int n)
{
    int *dp = new int[n+1];
    dp[0] = 0;

    for(int len = 1; len <= n; len++)
    {
        int ans = INT_MIN;

        for(int i = 0; i < len; i++)
        {
            int cut = i + 1;
            int currentAns = price[i] + dp[len - cut];
            ans = max(ans, currentAns);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main()
{
    int price[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price)/sizeof(int);

    cout << maxProfit(price, n) << endl;
    return 0;
}