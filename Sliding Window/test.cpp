#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        long long ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        while(j < n)
        {
            if(mp.count(nums[j]))
            {
                cnt = cnt + mp[nums[j]];
            }
            mp[nums[j]]++;
            
            
            while(i < n && cnt >= k)
            {
                ans = ans + n-j;
                if(mp[nums[i]] > 1)
                {
                    mp[nums[i]]--;
                    cnt = cnt - mp[nums[i]];
                }
                i++;
            }
            
            j++;
        }
        return ans;
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  vector<int> nums = {1, 1, 1, 1, 1};
  int k = 10;
  Solution sln;
  cout << sln.countGood(nums, k) << endl;
  return 0;
}