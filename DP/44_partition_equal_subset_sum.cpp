#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool targetSum2(vector<int> &nums, int target, int n, vector<vector<int>> &dp)
    {
        if(target == 0)
        return true;

        if(n < 0)
        return false;
        if(dp[n][target] != -1)
        return dp[n][target];
        // rec case
        bool inc = false, exc = false;
        if(nums[n] <= target)
        {
            inc = targetSum2(nums, target-nums[n], n-1, dp);
        }
        exc = targetSum2(nums, target, n-1, dp);
        return dp[n][target] = inc || exc;
    }
    bool targetSum(vector<int> &nums, int target)
    {
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
        for(int i = 0; i < nums.size(); i++)
        dp[i][0] = true;

        if(nums[0] <= target)
        dp[0][nums[0]] = true;
        
        for(int i = 1; i <= nums.size()-1; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                bool exc = dp[i-1][target];
                bool inc = false;
                if(nums[i] <= j)
                {
                    inc = dp[i-1][j-nums[i]];
                }
                dp[i][j] = inc || exc;
            }
        }
        return dp[nums.size()-1][target];

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i = 0; i < n; i++)
        {
            target += nums[i];
        }
        if(target % 2 != 0)
        return false;

        target = target/2;
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return targetSum2(nums, target, n-1, dp);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }

    Solution s;
    cout << s.canPartition(nums) << endl;
    return 0;
}