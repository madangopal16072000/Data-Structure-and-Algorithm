#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string str, int start, int end)
    {
        string sub = str.substr(start, end - start + 1);

        if (sub.length() > 3)
            return false;
        if (stoi(sub) > 255)
            return false;
        if (sub.length() > 1 && sub[0] == '0')
            return false;

        return true;
    }
    void f(int i, string s, vector<string> &ans, string temp, int k)
    {
        // base case
        if (i == s.size() && k == 0)
        {
            ans.push_back(temp);
        }

        if (i >= s.size() || k < 0)
        {
            return;
        }

        for (int j = i; j < s.size() && j < 3 + i; j++)
        {
            if (isValid(s, i, j))
            {
                f(j + 1, s, ans, temp + "." + s.substr(i, j), k--);
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s)
    {

        vector<string> ans;
        string temp = "";
        f(0, s, ans, temp, 3);

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
    vector<string> ans = sln.restoreIpAddresses(s);
    for (string str : ans)
        cout << str << " ";
    return 0;
}