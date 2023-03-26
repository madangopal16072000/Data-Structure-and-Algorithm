#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, int arr[], int n, vector<int> &dp)
    {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;
        for (int j = 1; j <= arr[i]; j++)
        {
            ans = min(ans, 1 + f(i + j, arr, n, dp));
        }

        return dp[i] = ans;
    }
    int minJumps(int arr[], int n)
    {
        // Your code here

        vector<int> dp(n, -1);
        return f(0, arr, n, dp);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int n = 10;

    Solution sln;
    cout << sln.minJumps(arr, n) << endl;
    return 0;
}