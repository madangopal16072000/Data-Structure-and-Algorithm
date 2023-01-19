#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {

        int sum = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        mp[0]++;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + nums[i];

            int temp = sum;
            temp = temp % k;
            if (sum < 0)
            {
                temp = k + temp;
            }

            if (mp.count(temp))
            {
                ans = ans + mp[temp];
            }

            mp[temp]++;
        }
        return ans;
    }
};
int main()
{
    vector<int> nums{2, -2, 2, -4};
    int k = 6;
    cout << (-17) % 6 << endl;
    Solution sln;
    cout << sln.subarraysDivByK(nums, k) << endl;
    return 0;
}