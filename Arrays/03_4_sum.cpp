#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            if (i == 0 || nums[i - 1] != nums[i])
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (flag || nums[j - 1] != nums[j])
                    {
                        flag = false;
                        int k = j + 1, l = n - 1;
                        while (k < l)
                        {
                            int sum = nums[i] + nums[j] + nums[k] + nums[l];
                            if (sum == target)
                            {
                                ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                                k++;
                                l--;
                            }
                            else if (sum > target)
                            {
                                l--;
                            }
                            else
                            {
                                k++;
                            }

                            while (k < l && nums[k] == nums[k + 1])
                                k++;
                            while (k < l && nums[l] == nums[l - 1])
                                l--;
                        }
                    }
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
    int n, target;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    cin >> target;

    Solution sln;
    vector<vector<int>> ans = sln.fourSum(nums, target);
    for (vector<int> vec : ans)
    {
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}