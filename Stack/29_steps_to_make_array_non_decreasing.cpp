#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {

        int n = nums.size();
        int i = n - 1;
        stack<int> st;
        int ans = 0;
        while (i >= 0)
        {
            if (st.empty() || nums[i] <= nums[st.top()])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && nums[i] > nums[st.top()])
                {
                    ans = max(ans, (st.top() - i));
                    st.pop();
                }
            }
            i--;
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
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }

    Solution sln;
    cout << sln.totalSteps(nums) << endl;
    return 0;
}