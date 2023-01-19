#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s = 0, e = nums.size()-1;
        int mid = 0;

        while(s <= e)
        {
            mid = s + (e-s)/2;

            if(nums[mid] == target)
            return mid;
            else if(nums[mid] <= nums[e])
            {
                if(nums[mid] < target && target <= nums[e])
                s = mid+1;
                else
                e = mid-1;
            }
            else if(nums[s] <= nums[mid])
            {
                if(nums[s] <= target && target < nums[mid])
                e = mid-1;
                else
                s = mid+1;
            }
        }
        return -1;
    }
};
class Solution2 {
public:
    int findMin(vector<int> &nums)
    {
        int s = 0, e = nums.size()-1;
        int N = nums.size();
        int mid = 0;
        while(s <= e)
        {
            mid = s + (e-s)/2;

            if(nums[mid] >= nums[(mid+1)%N])
            return (mid+1)%N;
            else if(nums[mid] <= nums[(mid+N-1)%N])
            return mid;
            else if(nums[s] <= nums[mid])
            s = mid+1;
            else if(nums[mid] <= nums[e])
            e = mid-1;
        }
        return -1;
    }
    int bs(vector<int> &nums, int s, int e, int target)
    {
        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid] == target)
            return mid;
            else if(nums[mid] < target)
            s = mid+1;
            else 
            e = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int s = 0, e = nums.size()-1;
        int mid = findMin(nums);
        int left = bs(nums, mid, e, target);
        int right = bs(nums, s, mid-1, target);

        if(left != -1)
        return left;
        else if(right != -1)
        return right;
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