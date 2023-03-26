#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {

        vector<vector<int>> ans;
        for (vector<int> vec : firstList)
        {
            for (vector<int> row : secondList)
            {
                if (row[0] <= vec[0] && vec[0] <= row[1])
                {
                    ans.push_back({vec[0], row[1]});
                }

                if (row[0] <= vec[1] && vec[1] <= row[1])
                {

                    ans.push_back({row[0], vec[1]});
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

    int n, m;
    cin >> n;
    vector<vector<int>> firstList;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        firstList.push_back({x, y});
    }

    cin >> m;
    vector<vector<int>> secondList;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        secondList.push_back({x, y});
    }

    Solution sln;

    vector<vector<int>> ans = sln.intervalIntersection(firstList, secondList);
    for (vector<int> vec : ans)
        cout << vec[0] << " " << vec[1] << endl;
    return 0;
}