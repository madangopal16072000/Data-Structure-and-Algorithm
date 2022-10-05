#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, int n, vector<int> &arr, int k, vector<int> &dp)
    {
        // base case
        if (i == n)
            return 0;

        // recursive case

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MIN;
        int len = 0;
        int maxi = INT_MIN;
        for (int j = i; j < min(i + k, n); j++)
        {
            len++;
            maxi = max(maxi, arr[j]);
            int cost = len * maxi + f(j + 1, n, arr, k, dp);
            ans = max(ans, cost);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = f(0, n, arr, k, dp);
        for (int x : dp)
            cout << x << " ";
        cout << endl;
        return ans;
    }
    int maxSumAfterPartitioning1(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int ans = INT_MIN;
            int len = 0;
            int maxi = INT_MIN;
            for (int j = i; j < min(i + k, n); j++)
            {
                len++;
                maxi = max(maxi, arr[j]);
                int cost = len * maxi + f(j + 1, n, arr, k, dp);
                ans = max(ans, cost);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
int main()
{
    vector<int> arr{1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k = 4;
    Solution s;
    cout << s.maxSumAfterPartitioning1(arr, k) << endl;
    return 0;
}