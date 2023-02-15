#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        unordered_map<char, int> mp;
        int cnt = 0;
        int i = 0, j = 0;
        int ans = 0;
        int n = s.size();
        while (j < n)
        {
            char ch = s[j];
            if (mp.count(ch) && mp[ch] > 0)
            {
                cnt++;
            }
            mp[ch]++;

            if (cnt == 0)
            {
                ans = max(ans, j - i + 1);
            }
            else
            {
                mp[s[i]]--;

                if (mp[s[i]] >= 1)
                {
                    cnt--;
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};
int main()
{
    string s;
    cin >> s;
    Solution sln;
    cout << sln.lengthOfLongestSubstring(s) << endl;
    return 0;
}