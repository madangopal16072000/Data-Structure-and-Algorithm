#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {

        map<int, int> mp;
        for (int x : hand)
        {
            mp[x]++;
        }

        int cnt = 0;
        int lastUsed = -1;

        map<int, int>::iterator it = mp.begin();

        while (it != mp.end())
        {
            pair<int, int> p = *it;
            int val = p.first;
            if (cnt == 0 || lastUsed + 1 == val)
            {
                lastUsed = val;
                cnt++;
                mp[val]--;
                it++;
                if (mp[val] == 0)
                {
                    mp.erase(val);
                }
            }
            else
            {
                return false;
            }

            if (cnt == groupSize)
            {
                lastUsed = -1;
                cnt = 0;
                it = mp.begin();
            }
        }

        if (cnt != 0)
            return false;

        return true;
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
    vector<int> hand;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        hand.push_back(d);
    }
    int groupSize;
    cin >> groupSize;

    Solution sln;
    cout << sln.isNStraightHand(hand, groupSize) << endl;
    return 0;
}