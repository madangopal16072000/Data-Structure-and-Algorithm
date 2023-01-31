#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool f(string s1, string s2, unordered_map<string, bool> &dp)
    {
        // base case
        if (s1.compare(s2) == 0)
            return true;

        if (s1.size() <= 1)
            return false;

        string temp = s1;
        temp = temp + " " + s2;
        if (dp.count(temp))
        {
            return dp[temp];
        }
        bool flag = false;
        int n = s1.size();
        for (int i = 1; i < n; i++)
        {

            bool withSwap = f(s1.substr(0, i), s2.substr(n - i, i), dp) && f(s1.substr(i, n - i), s2.substr(0, n - i), dp);
            bool withoutSwap = f(s1.substr(0, i), s2.substr(0, i), dp) && f(s1.substr(i, n - i), s2.substr(i, n - i), dp);

            if (withSwap || withoutSwap)
            {
                flag = true;
                break;
            }
        }

        return dp[temp] = flag;
    }
    bool isScramble(string s1, string s2)
    {
        // code here

        if (s1.size() != s2.size())
            return false;

        if (s1.size() == 0)
            return true;

        unordered_map<string, bool> dp;
        return f(s1, s2, dp);
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
    cout << sln.isScramble(s1, s2);
    return 0;
}