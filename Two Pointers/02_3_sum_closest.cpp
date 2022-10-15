#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int x, y, z;
        int mini = INT_MAX;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        mp[nums[i]] = i;

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                
            }
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    return 0;
}