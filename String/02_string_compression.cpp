#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        if (n == 1)
        {
            return 1;
        }
        int i = 0;
        int cnt = 1;
        vector<char> ans;
        while (i < n)
        {
            if (i + 1 < n && chars[i] == chars[i + 1])
            {
                cnt++;
            }
            else
            {
                if (cnt == 1)
                {
                    ans.push_back(chars[i]);
                }
                else
                {
                    ans.push_back(chars[i]);
                    if (cnt >= 10)
                    {
                        int x = cnt;
                        int y = 0;
                        int r;
                        while (x != 0)
                        {
                            r = x % 10;
                            y = y * 10 + r;
                            x = x / 10;
                        }

                        while (y != 0)
                        {
                            r = y % 10;
                            ans.push_back(r + 48);
                            y = y / 10;
                        }
                    }
                    else
                    ans.push_back(char(cnt + 48));
                }
                cnt = 1;
            }

            i++;
        }
        chars.clear();
        int len = ans.size();
        for (int i = 0; i < len; i++)
        {
            chars.push_back(ans[i]);
        }
        ans.clear();
        return chars.size();
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<char> chars;
    for(int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        chars.push_back(ch);
    }

    Solution sln;
    cout << sln.compress(chars) << endl;
    cout << endl;
    for(char ch : chars)
    cout << ch << " ";
    cout << endl;
    return 0;
}