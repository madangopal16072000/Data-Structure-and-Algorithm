#include<iostream>
using namespace std;


int lis(int arr[], int n)
{
    int dp[100] = {1};
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }

    for(int i = 0; i < n; i++)
    cout << dp[i] << " ";
    return ans;
}
int main()
{
    int arr[] = {10,9,2,5,3,7,101,18};
    int n = sizeof(arr)/sizeof(int);

    cout << lis(arr, n) << endl;
    return 0;
}