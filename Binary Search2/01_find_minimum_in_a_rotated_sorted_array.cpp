#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int s = 0, e = nums.size()-1;
        int N = nums.size();
        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid] <= nums[(mid+N-1)%N])
            {
                return nums[mid];
            }
            else if(nums[mid] >= nums[(mid+1)%N])
            {
                return nums[(mid+1)%N];
            }
            else if(nums[s] <= nums[mid])
            s = mid+1;
            else if(nums[mid] <= nums[e])
            e = mid-1;
        }
        return -1;
    }
    int findMin(vector<int> &nums)
    {
        int s = 0, e = nums.size()-1;

        if(s == e || nums[s] < nums[e])
        return nums[s];

        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid] > nums[mid+1])
            return nums[mid+1];
            else if(nums[mid] < nums[mid-1])
            return nums[mid];
            else if(nums[s] < nums[mid])
            s = mid+1;
            else if(nums[mid] < nums[e])
            e = mid-1;
        }
        return -1;
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