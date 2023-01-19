#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        unordered_map<int, int> mpl, mph;

        int n = nums.size();
        int il = 0, ih = 0, j = 0;

        int cntl, cnth;
        cntl = cnth = 0;
        int ans = 0;
        while(j < n)
        {
            if(mpl[nums[j]] == 0)
            {
                cntl++;
            }

            mpl[nums[j]]++;

            while(il < j && cntl > k)
            {
                mpl[nums[il]]--;
                if(mpl[nums[il]] == 0)
                {
                    cntl--;
                }
                il++;
            }

            if(mph[nums[j]] == 0)
            {
                cnth++;
            }
            mph[nums[j]]++;

            while(ih < j && cnth > k || (cnth == k && mph[nums[ih]] > 1))
            {
                mph[nums[ih]]--;
                if(mph[nums[ih]] == 0)
                {
                    cnth--;
                }
                ih++;
            }

            if(cntl == k)
            {
                ans = ans + ih-il+1;
            }
            j++;
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
  
  return 0;
}