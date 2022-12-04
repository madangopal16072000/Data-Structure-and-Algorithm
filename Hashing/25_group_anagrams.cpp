#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        vector<vector<string>> ans;
        set<set<string>> st;
        for (int i = 0; i < n; i++)
        {
            int m = strs[i].size();
            set<string> row;
            row.insert(strs[i]);
            unordered_map<char, int> mp;
            for (int j = 0; j < m; j++)
            {
                mp[strs[i][j]]++;
            }

            for (int k = 0; k < n; k++)
            {
                if(i == k)
                continue;

                m = strs[k].size();
                int j;
                for (j = 0; j < m; j++)
                {
                    if (mp.count(strs[k][j]) > 0)
                    {
                        mp[strs[k][j]]--;
                    }
                    else
                        break;
                }
                if (j == m)
                {
                    row.insert(strs[k]);
                }
            }

            st.insert(row);
        }
        for(set<string> row : st)
        {
            vector<string> vec;
            for(string s : row)
            {
                vec.push_back(s);
            }
            ans.push_back(vec);
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams2(vector<string> strs)
    {
        int n = strs.size();
        set<string> st;
        for(int i = 0; i < n; i++)
        {
            st.insert(strs[i]);
        }

        vector<vector<string>> ans;
        while(!st.empty())
        {
            vector<string> row;
            auto it = st.begin();
            string s = *it;
            row.push_back(s);
            st.erase(it);

            unordered_map<char, int> mp;
            int m = s.size();
            for(int i = 0; i < m; i++)
            {
                mp[s[i]]++;
            }

            for(string str : st)
            {
                m = str.size();
                int j ;
                for(j = 0; j < m; j++)
                {
                    if(mp.count(str[j]) > 0)
                    {
                        mp[str[j]]--;
                    }
                    else
                    break;
                }
                if(j == m)
                {
                    row.push_back(str);
                    st.erase(str);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams3(vector<string> strs)
    {
        int n = strs.size();
        unordered_multimap<string, int> mp;
        for(int i = 0; i < n; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp.insert({s, i});
        }

        vector<vector<string>> ans;
        set<multiset<string>> st;
        for(pair p : mp)
        {

            multiset<string> row;
            row.insert(strs[p.second]);
            for(pair q : mp)
            {
                if(p == q)
                continue;

                if(p.first == q.first)
                {
                    row.insert(strs[q.second]);
                }
            }
            st.insert(row);
        }

        for(multiset<string> row : st)
        {
            vector<string> vec;
            for(string s : row)
            {
                vec.push_back(s);
            }
            ans.push_back(vec);
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
    int n;
    cin >> n;
    vector<string> strs;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    Solution sln;
    vector<vector<string>> ans = sln.groupAnagrams3(strs);
    for (vector<string> row : ans)
    {
        for (string s : row)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}