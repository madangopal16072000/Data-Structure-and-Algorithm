#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    cin >> n >> sum;

    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        arr.push_back(d);
    }

    vector<vector<int>> dp((n+1), vector<int> (sum+1, false));
    for(int i = 0; i <= n; i++)
    dp[i][0] = 1;

    for(int i = 0; i <= n; i++)
    dp[0][i] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(arr[i-1] > j)
            dp[i][j] = dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }
    if(dp[n][sum])
    cout << "Yes" << endl;
    else
    cout << "No" << endl;
    return 0;



}