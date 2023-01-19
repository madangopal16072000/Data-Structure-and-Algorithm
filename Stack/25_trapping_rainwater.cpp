#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        
        stack<int> st;
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && height[st.top()] <= height[i])
            {
                int rMaxIdx = i;
                int curr = height[st.top()];
                st.pop();
                if(st.empty())
                break;

                int lMaxIdx = st.top();
                int width = rMaxIdx - lMaxIdx - 1;
                int h = min(height[rMaxIdx], height[lMaxIdx]) - curr;
                ans = ans + h*width;
            }
            st.push(i);
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