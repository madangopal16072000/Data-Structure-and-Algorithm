#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int divide(string num, int m)
    {
        int i = 0;
        int n = num.size();
        int carry = 0;
        while (i < n)
        {
            long long x = carry;
            if (x < m)
            {
                while (i < n && x < m)
                {
                    x = x * 10 + (num[i] - '0');
                    i++;
                }
            }
            else
            {
                x = x * 10 + (num[i] - '0');
                i++;
            }

            carry = x % m;
        }
        return carry == 0 ? 1 : 0;
    }
    vector<int> divisibilityArray(string word, int m)
    {

        vector<int> div;
        int n = word.size();
        long long num = 0;
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            temp = temp + word[i];
            int ans = divide(temp, m);
            div.push_back(ans);
        }
        return div;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string word;
    cin >> word;
    int m;
    cin >> m;
    Solution sln;
    vector<int> ans = sln.divisibilityArray(word, m);
    for (int x : ans)
        cout << x << " ";

    return 0;
}