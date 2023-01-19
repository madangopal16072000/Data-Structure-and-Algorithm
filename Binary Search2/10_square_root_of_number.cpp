#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long l = 1;
        long long h = x;
        int ans = 1;
        while(l <= h)
        {
            long long mid = l + (h-l)/2;
            if(mid*mid <= x)
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
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