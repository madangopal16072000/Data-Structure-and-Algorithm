#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int beautySum(string s)
    {

        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> mp;
            int maxVal = 0;
            int minVal = INT_MAX;
            char maxChar, minChar;
            for (int j = i; j < n; j++)
            {
                mp[s[j]]++;
                if (maxVal < mp[s[j]])
                {
                    maxVal = mp[s[j]];
                    maxChar = s[j];
                }

                if (minVal >= mp[s[j]] || minChar == s[j])
                {
                    minVal = mp[s[j]];
                    minChar = s[j];
                }
                if (maxVal - minVal != 0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //   freopen("./input.txt", "r", stdin);
    //   freopen("./output.txt", "w", stdout);
    // #endif
    string s = "aabcb";
    Solution sln;
    cout << sln.beautySum(s) << endl;
    return 0;
}