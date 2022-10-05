#include<iostream>
#include<vector>
using namespace std;

int optimalStrategy(int i, int j, int arr[], vector<vector<int>> &dp)
{
    // base case
    if(i > j)
    return 0;

    // look up
    if(dp[i][j] != -1)
    return dp[i][j];
    // recursive case
    int first = arr[i] + min(optimalStrategy(i+1, j-1, arr, dp), optimalStrategy(i+2, j, arr, dp));
    int last = arr[j] + min(optimalStrategy(i+1, j-1, arr, dp), optimalStrategy(i, j-2, arr, dp));

    return dp[i][j] = max(first, last);
}
int main()
{
    // int arr[] = {7, 3, 1, 6, 2, 8, 10, 11};
    int arr[] = {5, 3, 7, 10};
    int n = sizeof(arr)/sizeof(int);

    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i > j)
            dp[i][j] = 0;
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << optimalStrategy(0, n-1, arr, dp) << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        cout << dp[i][j] << " ";

        cout << endl;
    }
    return 0;
}