#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int LPS(string s)
    {
        int n = s.size();
        vector<int> lps(n, 0);

        int i = 1;
        int len = 0;

        while (i < n)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len > 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[lps.size() - 1];
    }
    string shortestPalindrome(string s)
    {

        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        int lps = LPS(temp);

        int n = s.size();
        int len = n - lps;

        string ans = s.substr(lps, len);
        reverse(ans.begin(), ans.end());
        return ans + s;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    return 0;
}