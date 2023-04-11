#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {

        int res = INT_MAX;
        for (int x : position)
        {
            int ans = 0;
            for (int y : position)
            {
                if (x == y)
                    continue;

                cout << y << " ";
                if (abs(x - y) % 2 == 1)
                {
                    ans = ans + y;
                }
            }
            res = min(res, ans);
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
    int n;
    cin >> n;
    vector<int> position;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        position.push_back(d);
    }

    Solution sln;
    cout << sln.minCostToMoveChips(position) << endl;
    return 0;
}