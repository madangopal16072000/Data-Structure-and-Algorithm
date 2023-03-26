#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> KMP(string s, int k)
    {
        int i = 1;
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0;
        vector<int> ans = {-1, -1};
        while (i < n)
        {
            if (s[len] == s[i])
            {
                len++;
                lps[i] = len;

                if (len == k)
                {
                    ans[0] = i - 2 * k;
                    ans[1] = i - k - 1;
                    return ans;
                }
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
        return ans;
    }
    string decToBin(int n)
    {
        string temp = "";
        while (n > 0)
        {
            int bit = n & 1;
            n = n >> 1;
            char ch = bit + '0';
            temp = temp + ch;
        }
        reverse(temp.begin(), temp.end());
        if (temp.size() == 0)
        {
            return "0";
        }
        return temp;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
    {
        vector<vector<int>> ans;
        for (vector<int> vec : queries)
        {
            int l = vec[0];
            int h = vec[1];
            int val = l ^ h;
            string bin = decToBin(val);
            string temp = bin + "#" + s;

            vector<int> res = KMP(temp, bin.size());
            ans.push_back(res);
        }
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
    int n;
    cin >> n;
    vector<vector<int>> queries;
    for (int i = 0; i < n; i++)
    {
        int l, h;
        cin >> l >> h;
        queries.push_back({l, h});
    }
    Solution sln;
    vector<vector<int>> ans = sln.substringXorQueries(s, queries);
    for (vector<int> vec : ans)
    {
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}