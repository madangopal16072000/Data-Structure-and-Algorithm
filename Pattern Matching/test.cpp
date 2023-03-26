#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
    {

        int n = s.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                mp[0] = {i, i};
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int num = 0;
            int cnt = 0;
            for (int j = i; j >= 0 && cnt >= 30; j--)
            {
                if (s[j] == '0')
                {
                    cnt++;
                    continue;
                }

                num = num + (1 << cnt);
                mp[num] = {j, i};
                cnt++;
            }
        }
        // for (auto p : mp)
        // {
        //     cout << p.first << " " << p.second[0] << " " << p.second[1] << endl;
        // }

        vector<vector<int>> ans;
        for (vector<int> vec : queries)
        {
            int l = vec[0];
            int h = vec[1];
            int val = l ^ h;
            if (mp.count(val) > 0)
            {
                ans.push_back(mp[val]);
            }
            else
            {
                ans.push_back({-1, -1});
            }
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
        int x, y;
        cin >> x >> y;
        queries.push_back({x, y});
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