#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;


class Solution {
public:
    int total;
    int helper(vector<int> &nums, int target, int n, int i, int sum, vector<vector<int>> &dp)
    {
        // base case
        if(i == n && sum == target)
        {
            return 1;
        }

        if(i >= n)
        return 0;

        if(dp[i][sum] != 10000)
        return dp[i][sum];

        int pos, neg;
        pos = neg = 0;
        neg = helper(nums, target, n, i+1, sum + ((-1)*nums[i]), dp);
        pos = helper(nums, target, n, i+1, sum + (nums[i]), dp);
        return dp[i][sum] = pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int x : nums)
        total += x;

        vector<vector<int>> dp(n, vector<int>(2*total + 1, 10000));

        return helper(nums, target, n, 0, 0, dp);
    }
};
int main()
{
    int target = 1;
    // cin >> target;
    vector<int> nums {1};
    Solution s;
    cout << s.findTargetSumWays(nums, target) << endl;
    return 0;
}