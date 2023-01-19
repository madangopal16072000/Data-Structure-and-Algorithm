#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int il = 0, ih = 0;
        int cntl, cnth;
        cntl = cnth = 0;
        int n = nums.size();
        int ans = 0;
        int j = 0;

        while(j < n)
        {
            if(nums[j] % 2 == 1)
            {
                cntl = cntl+1;
                cnth = cnth+1;
            }

            while(il < j && cntl > k)
            {
                if(nums[il]%2 == 1)
                {
                    cntl--;
                }
                il++;
            }

            while(ih < j && (cnth > k || cnth == k && nums[ih]%2 == 0))
            {
                if(nums[ih]%2 == 1)
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
class Solution2 {
public:
    int f(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        int n = nums.size();
        int cnt = 0;

        while(j < n)
        {
            k = k - nums[j]%2;

            while(k < 0)
            {
                k = k + nums[i]%2;
                i++;
            }

            cnt = cnt + j-i+1;
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k)-f(nums, k-1);
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