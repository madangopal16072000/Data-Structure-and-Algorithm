#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // unordered_map<string, char> mp = {{"1", 'A'}, {"2", 'B'}, {"3", 'C'}, {"4", 'D'}, {"5", 'E'}, {"6", 'F'}, {"7", 'G'}
    // ,{"8", 'H'}, {"9", 'I'}, {"10", 'J'}, {"11", 'K'}, {"12", 'L'}, {"13", 'M'}, {"14", 'N'}, {"15", 'O'}, {"16", 'P'},
    // {"17", 'Q'}, {"18", 'R'}, {"19", 'S'}, {"20", 'T'}, {"21", 'U'}, {"22", 'V'}, {"23", 'W'}, {"24", 'X'}, {"25", 'Y'}, {"26", 'Z'}};
public:
    int toInt(string s)
    {
        int num = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int c = s[i] - '0';
            num = num * 10 + c;
        }
        return num;
    }
    int f(int i, string s, vector<int> dp)
    {
        if (i == s.length())
            return 1;

        int op1, op2;
        op1 = op2 = 0;

        string sub1 = s.substr(i, 1);
        if (sub1.front() != '0' && toInt(sub1) <= 26)
        {
            op1 = f(i + 1, s, dp);
        }

        string sub2 = s.substr(i, 2);
        if (sub2.front() != '0' && toInt(sub2) <= 26)
        {
            op2 = f(i + 2, s, dp);
        }
        return dp[i] = 1 + op1 + op2;
    }
    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> dp(n, -1);
        return f(0, s, dp);
    }
    int f1(string s, int i, vector<int> dp, int n)
    {
        // base case
        if (i == n)
            return 1;
        if (dp[i] != -1)
            return dp[i];

        int op1, op2;
        op1 = op2 = 0;
        if (s[i] != '0')
        {
            op1 = f1(s, i + 1, dp, n);

            if ((i + 1 < n) && ((s[i] == '1') || (s[i] == '2' && (s[i + 1] - '0' >= 0 && s[i + 1] - '0' <= 6))))
            {
                op2 = f1(s, i + 2, dp, n);
            }
        }
        return dp[i] = op1 + op2;
    }
    int numDecodings1(string s)
    {
        int n = s.length();
        vector<int> dp(n, -1);
        return f1(s, 0, dp, n);
    }
    int f3(string s, int i, vector<int> dp)
    {
        if (i < 0)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        int op1, op2;
        op1 = op2 = 0;

        if (s[i] != '0')
            op1 = f3(s, i - 1, dp);
        if (i - 1 >= 0)
        {
            if (s[i - 1] == '1' || s[i - 1] == '2' && (s[i] - '0' >= 0 && s[i] - '0' <= 6))
            {
                op2 = f3(s, i - 2, dp);
            }
        }

        return dp[i] = op1 + op2;
    }
    int numDecodings3(string s)
    {
        int n = s.length();
        vector<int> dp(n, -1);
        return f3(s, n - 1, dp);
    }
    int numDecodings4(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            int op1, op2;
            op1 = op2 = 0;
            if (s[i - 1] != '0')
            {
                op1 = dp[i - 1];
            }
            if (i - 1 > 0)
            {
                if (s[i - 2] == '1' || s[i - 2] == '2' && (s[i - 1] >= 48 && s[i - 1] <= 54))
                {
                    op2 = dp[i - 2];
                }
            }
            dp[i] = op1 + op2;
        }

        return dp[n];
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
    cout << sln.numDecodings4(s) << endl;
    return 0;
}