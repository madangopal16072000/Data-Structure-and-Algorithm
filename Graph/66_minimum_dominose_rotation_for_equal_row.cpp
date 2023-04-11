#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {

        vector<int> mp1(7, 0), mp2(7, 0);
        for (int x : tops)
            mp1[x]++;
        for (int x : bottoms)
            mp2[x]++;

        vector<int> possible;
        for (int i = 1; i <= 6; i++)
        {
            if (mp1[i] + mp2[i] >= 6)
            {
                possible.push_back(i);
            }
        }

        if (possible.size() == 0)
            return -1;

        int ans = INT_MAX;
        for (int x : possible)
        {
            int cnt = 0;
            int i;
            for (i = 0; i < 6; i++)
            {
                if (tops[i] == x)
                {
                    continue;
                }

                if (bottoms[i] == x)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }

            if (i == 6)
            {
                ans = min(ans, cnt);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    vector<int> tops, bottoms;
    for (int i = 0; i < 6; i++)
    {
        int x;
        cin >> x;
        tops.push_back(x);
    }

    for (int i = 0; i < 6; i++)
    {
        int x;
        cin >> x;
        bottoms.push_back(x);
    }

    Solution sln;
    cout << sln.minDominoRotations(tops, bottoms) << endl;
    return 0;
}