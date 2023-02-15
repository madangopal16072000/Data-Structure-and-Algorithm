#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool LPS(string s, int m)
    {
        bool flag = false;
        int i = 1;
        int len = 0;
        int n = s.size();
        vector<int> lps(n, 0);
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

            if (len == m)
            {
                flag = true;
            }
        }

        return flag;
    }
    int repeatedStringMatch(string a, string b)
    {
        string s = a;
        int c = 1;
        while (s.size() < b.size())
        {
            s += a;
            c++;
        }
        int m = b.size();
        s = b + "#" + s;
        if (LPS(s, m))
            return c;
        c++;
        s = s + a;
        if (LPS(s, m))
            return c;

        return -1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;

    Solution sln;
    cout << sln.repeatedStringMatch(a, b) << endl;
    return 0;
}