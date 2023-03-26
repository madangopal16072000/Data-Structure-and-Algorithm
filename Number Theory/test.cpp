#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = 1;
        while (j < n && nums[j] < 2 * nums[i])
        {
            j++;
        }
        int ans = 0;
        if (j == n)
            return 0;
        vector<bool> marked(n, false);
        while (j < n)
        {
            if (marked[i] == true)
            {
                i++;
            }
            else if (marked[j] == true)
            {
                j++;
            }
            else
            {
                if (2 * nums[i] <= nums[j])
                {
                    ans = ans + 2;
                    marked[i] = marked[j] = true;
                    i++;
                    j++;
                }
                else
                {
                    j++;
                }
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
    cout << sln.maxNumOfMarkedIndices(nums) << endl;
    return 0;
}