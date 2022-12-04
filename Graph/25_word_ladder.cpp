#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();

        bool bP, eP;
        bP = eP = false;
        for (int i = 0; i < n; i++)
        {
            if (beginWord == wordList[i])
                bP = true;
            if (endWord == wordList[i])
                eP = true;
        }
        if (eP == false)
            return 0;

        if (bP == false)
        {
            n = n + 1;
            wordList.push_back(beginWord);
        }

        int m;
        unordered_map<string, vector<string>> adj;
        for (int i = 0; i < n; i++)
        {
            multimap<char, int> mp;
            m = wordList[i].size();
            for (int j = 0; j < m; j++)
            {
                mp.insert({wordList[i][j], j});
            }
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    m = wordList[j].size();
                    cnt = 0;
                    for (int k = 0; k < m; k++)
                    {
                        char ch = wordList[j][k];
                        if (!mp.count(ch) || mp.find(ch)->second != k)
                        {
                            cnt++;
                        }
                    }
                    if (cnt == 1)
                    {
                        adj[wordList[i]].push_back(wordList[j]);
                    }
                }
            }
        }

        for (auto p : adj)
        {
            cout << p.first << "-->";
            for (string x : p.second)
            {
                cout << x << ", ";
            }
            cout << endl;
        }
        // return 0;

        unordered_map<string, bool> vis;
        unordered_map<string, int> dist;
        for (int i = 0; i < n; i++)
        {
            vis[wordList[i]] = false;
            dist[wordList[i]] = INT_MAX;
        }

        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = true;
        dist[beginWord] = 0;

        while (!q.empty())
        {
            string node = q.front();
            q.pop();

            for (string nbr : adj[node])
            {
                if (!vis[nbr])
                {
                    vis[nbr] = true;
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }

        if (dist[endWord] != INT_MAX)
            return dist[endWord] + 1;
        else
            return 0;
    }
    int ladderLength2(string beginWord, string endWord, vector<string> wordList)
    {
        int n = wordList.size();
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string, string> parent;
        st.erase(beginWord);
        int ans = INT_MAX;
        parent[beginWord] = beginWord;
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord)
            {
                ans = steps;
                break;
            }

            int m = word.size();
            string node = word;
            for (int i = 0; i < m; i++)
            {
                char orgChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        parent[word] = node;
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = orgChar;
            }
        }

        string node = endWord;
        while (parent[node] != node)
        {
            cout << node << " ";
            node = parent[node];
        }
        cout << node << endl;
        return ans != INT_MAX ? ans : 0;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    vector<string> wordList;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        wordList.push_back(s);
    }

    Solution sln;
    cout << sln.ladderLength2(beginWord, endWord, wordList) << endl;
    return 0;
}