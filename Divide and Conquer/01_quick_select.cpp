#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int partition(vector<int> &nums, int s, int e)
    {
        int pivot = nums[e];
        int i = s - 1;
        for (int j = s; j < e; j++)
        {
            if (nums[j] < pivot)
            {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[++i], nums[e]);
        return i;
    }
    int quickSelect(vector<int> &nums, int s, int e, int k)
    {
        int p = partition(nums, s, e);

        if (p == k)
            return nums[p];
        else if (p < k)
        {
            return quickSelect(nums, p + 1, e, k);
        }
        else
            return quickSelect(nums, s, p - 1, k);
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {

        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
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

    int k;
    cin >> k;
    Solution sln;
    cout << sln.findKthLargest(nums, k) << endl;
    return 0;
}