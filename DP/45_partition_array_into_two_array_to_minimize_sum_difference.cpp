#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i = 0; i < n; i++)
        {
            target += nums[i];
        }

        vector<vector<bool>> dp(n, vector<bool> (target+1, false));
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if(nums[0] == target)
        dp[0][nums[0]] = true;

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= target; j++)
            {
                bool inc = false;
                if(nums[i] <= j)
                {
                    inc = dp[i-1][j-nums[i]];
                }
                bool exc = dp[i-1][j];
                dp[i][j] = inc || exc;
            }
        }

        int minDiff = INT_MAX;
        for(int i = 0; i <= target; i++)
        {
            if(dp[n-1][i] == true)
            {
                int diff = abs(i - (target-i));
                minDiff = min(diff, minDiff);
            }
        }
        return minDiff;
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
    cout << s.minimumDifference(nums) << endl;
    return 0;
}