#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        set<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int s = i + 1;
            int e = n - 1;
            while (s < e)
            {
                if (nums[s] + nums[e] == -nums[i])
                {

                    vector<int> row;
                    row.push_back(nums[s]);
                    row.push_back(nums[e]);
                    row.push_back(nums[i]);
                    ans.insert(row);
                    s++;
                    e--;
                }
                else if (nums[s] + nums[e] < -nums[i])
                    s++;
                else
                    e--;
            }
        }

        vector<vector<int>> res;
        for (auto s : ans)
        {
            vector<int> row;
            for (int x : s)
            {
                row.push_back(x);
            }
            res.push_back(row);
        }
        return res;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    Solution sln;
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    vector<vector<int>> ans = sln.threeSum(nums);
    for (vector<int> row : ans)
    {
        for (int x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}