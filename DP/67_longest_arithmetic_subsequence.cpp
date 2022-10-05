#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
        }
        vector<vector<int>> dp(n, vector<int>(2*maxi + 1, 1));
        // vector<unordered_map<int, int>> dp;
        dp.reserve(n);
        int M = maxi;
        int ans = INT_MIN;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                dp[i][diff + M] = dp[j][diff + M] + 1;
                ans = max(ans, dp[i][diff + M]);
            }
        }
        return ans;
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
    nums.reserve(n);
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    Solution sln;
    cout << sln.longestArithSeqLength(nums) << endl;
    return 0;
}