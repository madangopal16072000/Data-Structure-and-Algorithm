#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<char> st;
        stack<int> cnt;

        int n = s.size();
        int i = 0;
        while (i < n)
        {
            if (st.empty())
            {
                st.push(s[i]);
                cnt.push(1);
            }
            else
            {
                if (st.top() == s[i])
                {
                    st.push(s[i]);
                    cnt.push(cnt.top() + 1);
                    if (cnt.top() == k)
                    {
                        int j = k;
                        while (j != 0)
                        {
                            st.pop();
                            cnt.pop();
                            j--;
                        }
                    }
                }
                else
                {
                    st.push(s[i]);
                    cnt.push(1);
                }
            }

            i++;
        }
        string ans = "";
        while (!st.empty())
        {
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
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
    int k;
    cin >> k;
    Solution sln;
    cout << sln.removeDuplicates(s, k) << endl;
    return 0;
}