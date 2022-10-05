#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        unordered_map<int, int> nge;
        stack<int> st;
        for(int i = len2-1; i >= 0; i--)
        {
            while(!st.empty() && nums2[st.top()] <= nums2[i])
            st.pop();

            if(st.empty())
            nge[nums2[i]] = -1;
            else
            nge[nums2[i]] = nums2[st.top()];
            
            st.push(i);
        }
        vector<int> ans; 
        for(int i = 0; i < len1; i++)
        {
            ans.push_back(nge[nums1[i]]);   
        }
        return ans;
    }
};
int main()
{
    vector<int> nums1 {4, 1, 2};
    vector<int> nums2 {1, 3, 4, 2};
    Solution s;
    vector<int> ans = s.nextGreaterElement(nums1, nums2);
    for(int x : ans)
    cout << x << " ";
    cout << endl;
    return 0;
}