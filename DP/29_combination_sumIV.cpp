#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int target, int sum, int i)
{
    // base case
    if (sum == target)
    {
        return 1;
    }

    if (i >= nums.size())
    {
        return 0;
    }

    int inc, exc;
    inc = exc = 0;

    for (int j = 0; j <= i; j++)
    {
        if (sum + nums[j] <= target)
            inc = helper(nums, target, sum + nums[j], i);

        exc = helper(nums, target, sum, i + 1);
    }

    return inc + exc;
}
int combinationSum4(vector<int> &nums, int target)
{
    int sum = 0;
    return helper(nums, target, sum, 0);
}

int main()
{
    vector<int> nums{1, 2, 3};
    int target = 4;

    cout << combinationSum4(nums, target);
    return 0;
}