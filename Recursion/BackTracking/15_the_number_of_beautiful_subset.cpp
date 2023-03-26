#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, int n, vector<int> &nums, int k, unordered_map<int, int> &mp)
    {
        // base case
        if (i == n)
        {
            return 1;
        }

        int take, notTake;
        take = notTake = 0;
        if (mp.count(abs(k - nums[i])) == 0)
        {
            mp[nums[i]]++;
            take = f(i + 1, n, nums, k, mp);
            mp.erase(nums[i]);
        }
        notTake = f(i + 1, n, nums, k, mp);

        return take + notTake;
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {

        int n = nums.size();
        unordered_map<int, int> mp;
        return f(0, n, nums, k, mp) - 1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    cin >> k;
    Solution sln;
    cout << sln.beautifulSubsets(nums, k) << endl;
    return 0;
}