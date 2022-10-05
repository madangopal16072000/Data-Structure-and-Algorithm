#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int j, int k, vector<int> nums, vector<int> multipliers, vector<vector<vector<int>>> &dp)
    {
        // base case
        if (i > j || k == multipliers.size())
            return 0;

        if(dp[i][j][k] != -1)
        return dp[i][j][k];

        int start = multipliers[k] * nums[i] + f(i + 1, j, k+1, nums, multipliers, dp);
        int end = multipliers[k] * nums[j] + f(i, j-1, k+1, nums, multipliers, dp);
        return dp[i][j][k] = max(start, end);
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(m, -1)));
        return f(0, n - 1, 0, nums, multipliers, dp);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }

    int m;
    cin >> m;
    vector<int> multipliers;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        multipliers.push_back(d);
    }

    Solution sln;
    cout << sln.maximumScore(nums, multipliers) << endl;
    return 0;
}
