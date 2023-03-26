#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeReverse(string S)
    {
        // code here
        int n = S.size();
        unordered_map<char, int> mp, mp1;
        for (char ch : S)
            mp[ch]++;
        mp1 = mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            char ch = S[i];
            if (mp.count(ch) && mp[ch] > 1)
            {
                cnt++;
                mp[ch]--;
            }
        }

        cout << cnt << endl;
        for (auto p : mp1)
        {
            cout << p.first << " " << p.second << endl;
        }
        if (cnt % 2 == 1)
        {
            reverse(S.begin(), S.end());
        }

        string ans = "";
        int i = 0;
        while (i < n)
        {
            if (mp1[S[i]] > 1)
            {
                cnt--;
                mp1[S[i]]--;
            }
            else
            {
                ans = ans + S[i];
            }
            i++;
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
    cout << sln.removeReverse(s) << endl;
    return 0;
}