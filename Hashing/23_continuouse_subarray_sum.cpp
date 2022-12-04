#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int cumsum = 0;

        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            cumsum = cumsum + nums[i];

            if(cumsum%k == 0 && i > 0)
            {
                return true;
            }

            if(mp.count(cumsum%k) > 1 && i - mp[cumsum%k] >= 2)
            return true;

            if(mp.count(cumsum%k) == 0)
            mp[cumsum%k] = i;
        }
        return false;
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
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    nums.push_back(d);
  }

  int k;
  cin >> k;
  Solution sln;
  cout << sln.checkSubarraySum(nums, k) << endl;
  return 0;
}