#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {

        int n = nums.size();
        multiset<int> ms;
        ms.insert(2 * nums[n - 1]);
        int ans = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            auto it = ms.lower_bound(nums[i]);
            int idx = distance(ms.begin(), it);

            ans = ans + idx;
            ms.insert(2 * nums[i]);
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
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }

    Solution sln;
    cout << sln.reversePairs(nums) << endl;
    return 0;
}