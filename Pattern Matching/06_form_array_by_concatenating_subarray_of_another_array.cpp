#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
    {

        int n = nums.size();
        int lastIdx = -1;
        int cnt = 0;
        for (vector<int> vec : groups)
        {
            for (int i = lastIdx + 1; i <= n - vec.size(); i++)
            {
                bool flag = true;
                for (int j = i, k = 0; k < vec.size(); j++, k++)
                {
                    if (nums[j] != vec[k])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    lastIdx = i + vec.size() - 1;
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << " " << groups.size() << endl;
        return cnt == groups.size();
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    int m;
    cin >> m;
    vector<vector<int>> groups;
    for (int i = 0; i < m; i++)
    {
        int l;
        cin >> l;
        vector<int> vec;
        for (int j = 0; j < l; j++)
        {
            int d;
            cin >> d;
            vec.push_back(d);
        }
        groups.push_back(vec);
    }

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
    cout << sln.canChoose(groups, nums) << endl;
    return 0;
}