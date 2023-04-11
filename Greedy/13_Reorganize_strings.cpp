#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reorganizeString(string s)
    {

        int n = s.size();
        int cnt = 0;
        int unique = 0;
        vector<pair<int, char>> mp(26, {0, ' '});
        for (char ch : s)
        {
            mp[ch - 'a'] = {mp[ch - 'a'].first + 1, ch};
            cnt++;
            if (mp[ch - 'a'].first == 1)
                unique++;
        }

        sort(mp.begin(), mp.end(), greater<pair<int, char>>());

        int i = 0;
        int j = 1;
        string ans = "";

        int k = 0;
        while (k < cnt)
        {
            if (k % 2 == 0)
            {
                if (i != j && mp[i].first)
                {
                    ans = ans + mp[i].second;
                    mp[i] = {mp[i].first - 1, mp[i].second};
                    k++;
                }
                else if (i >= unique)
                    return "";
                else
                {

                    i++;
                }
            }
            else
            {
                if (j != i && mp[j].first)
                {
                    ans = ans + mp[j].second;
                    mp[j] = {mp[j].first - 1, mp[j].second};
                    k++;
                }
                else if (j >= unique)
                    return "";
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
    string s;
    cin >> s;
    Solution sln;
    cout << sln.reorganizeString(s) << endl;
    return 0;
}