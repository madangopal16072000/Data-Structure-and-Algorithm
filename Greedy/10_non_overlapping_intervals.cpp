#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int prev = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < prev && intervals[i][1] < prev)
            {
                prev = intervals[i][1];
                ans++;
            }
            else if (intervals[i][0] < prev)
            {
                ans++;
            }
            else
            {
                prev = intervals[i][1];
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
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        intervals.push_back({x, y});
    }

    Solution sln;
    cout << sln.eraseOverlapIntervals(intervals);
    return 0;
}