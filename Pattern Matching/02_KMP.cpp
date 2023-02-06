#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string s)
{
    int len = 0;
    int n = s.size();
    vector<int> lps(n, 0);
    int i = 1;

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
    return lps;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    vector<int> ans = LPS(s);
    return 0;
}