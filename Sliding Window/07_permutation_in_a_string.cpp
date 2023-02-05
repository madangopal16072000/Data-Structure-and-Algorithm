#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {

        int n = s1.size();
        int m = s2.size();

        if (m < n)
            return false;

        int i = 0, j = 0;
        unordered_map<char, int> mp;
        for (char ch : s1)
        {
            mp[ch]++;
        }
        int cnt = 0;
        while (j < m)
        {
            char ch = s2[j];
            if (mp.count(ch) > 0)
            {
                mp[ch]--;
                if (mp[ch] == 0)
                {
                    cnt++;
                }
            }

            if (j - i + 1 < n)
            {
                j++;
            }
            else if (cnt == mp.size())
                return true;
            else
            {
                if (mp.count(s2[i]) > 0)
                {
                    mp[s2[i]]++;
                    if (mp[s2[i]] == 1)
                    {
                        cnt--;
                    }
                }

                i++;
                j++;
            }
        }
        return false;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string s1, s2;
    cin >> s1 >> s2;

    Solution sln;
    cout << sln.checkInclusion(s1, s2) << endl;
    return 0;
}