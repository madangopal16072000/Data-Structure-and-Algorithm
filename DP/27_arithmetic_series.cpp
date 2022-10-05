#include <iostream>
#include <vector>
using namespace std;

bool isArithmetic(int s, int e, vector<int> &nums)
{
    int diff = nums[s+1] - nums[s];
    for(int i = s+2; i <= e; i++)
    {
        
        if(nums[i] - nums[i-1] != diff)
        return false;
    }
    return true;
}
int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    if(n < 3)
    return 0;

    vector<vector<int>> dp(n, vector<int>(n, -9999));
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int j = i + 2;
        
        if(isArithmetic(i, j, nums))
        {
            dp[i][j] = nums[i+1] - nums[i];
            ans++;
        }
    }

    for(int k = 4; k <= n; k++)
    {
        for(int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if(dp[i][j-1] != -9999 && nums[j]-nums[j-1] == dp[i][j-1])
            {
                dp[i][j] = dp[i][j-1];
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums {1,3,5,7,9};
    cout << numberOfArithmeticSlices(nums) << endl;
    return 0;
}