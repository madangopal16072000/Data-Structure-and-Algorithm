#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int *leftSmall = new int[n];
        int *rightSmall = new int[n];
        // generating left small
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();


            if(st.empty())
            leftSmall[i] = 0;
            else
            leftSmall[i] = st.top() + 1;

            st.push(i);
        }

        // clearing st for right small 
        while(!st.empty())
        st.pop();

        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

            if(st.empty())
            rightSmall[i] = n-1;
            else
            rightSmall[i] = st.top() - 1;

            st.push(i);
        }
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int area = heights[i]*(rightSmall[i] - leftSmall[i] + 1);
            maxi = max(maxi, area);
        }

        return maxi;
    }
};
int main()
{
    vector<int> heights {2,1,5,6,2,3};
    Solution s;
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}