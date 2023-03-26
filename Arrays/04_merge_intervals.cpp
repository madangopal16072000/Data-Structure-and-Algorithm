#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        while (i < n - 1)
        {
            if (intervals[i][1] >= intervals[i + 1][0])
            {
                int j = i;
                vector<int> last = intervals[i];
                while (j < n - 1 && last[1] >= intervals[j + 1][0])
                {
                    j++;
                    last[1] = max(last[1], intervals[j][1]);
                }

                ans.push_back({last[0], last[1]});
                i = j;
            }
            else
            {
                ans.push_back(intervals[i]);
            }
            i++;
        }

        if (i == n - 1)
        {
            ans.push_back(intervals[i]);
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
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        intervals.push_back({x, y});
    }
    Solution sln;

    vector<vector<int>> ans = sln.merge(intervals);
    for (vector<int> vec : ans)
        cout << vec[0] << " " << vec[1] << endl;
    return 0;
}