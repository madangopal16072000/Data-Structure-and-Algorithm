#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        // for(int x : nums)
        // cout << x << " ";
        // cout << endl;
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int n = nums.size();
        int ans = 0;
        int k = 0;
        int i, j;
        i = idx - 1;
        j = idx;
        while (i >= 0 && j < n && k < 3)
        {
            if (target - nums[i] < nums[j] - target)
            {
                ans = ans + nums[i];
                i--;
            }
            else
            {
                ans = ans + nums[j];
                j++;
            }
            k++;
        }
        while (k < 3 && i >= 0)
        {
            ans = ans + nums[i];
            k++;
            i--;
        }

        while (k < 3 && j < n)
        {
            ans = ans + nums[j];
            k++;
            j++;
        }
        return ans;
    }
    int f(int i, int j, vector<int> nums, int target)
    {
        if (j == 0)
            return 0;
        if (i < 0)
            return INT_MAX;

        int take = f(i-1, j-1, nums, target) + nums[i];
        int notTake = f(i-1, j, nums, target);
        return min( abs(take-target), abs(notTake-target));
    }
    int threeSumClosest1(vector<int> nums, int target)
    {
        return f(nums.size() - 1, 3, nums, target);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    int target;
    cin >> target;
    Solution sln;
    cout << sln.threeSumClosest1(nums, target) << endl;
    return 0;
}