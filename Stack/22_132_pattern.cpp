#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pge(n, -1);
        vector<int> pse(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            st.pop();

            if(!st.empty())
            pge[i] = st.top();

            st.push(i);
        }
        while(!st.empty())
        st.pop();
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

            if(!st.empty())
            pse[i] = st.top();

            st.push(i);
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[pge[i]] > nums[i] && nums[pse[i]] < nums[i] && pse[i] < pge[i])
            return true;
        }
        return false;
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  vector<int> nums{-1, 3, 2, 0};
  Solution sln;
  cout << sln.find132pattern(nums) << endl;
  return 0;
}