#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;
        set<string> st(wordList.begin(), wordList.end());

        int level = 0;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        vector<vector<string>> ans;
        q.push({beginWord});

        while(!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            
            if(vec.size() > level)
            {
                level++;
                for(string s : usedOnLevel)
                {
                    st.erase(s);
                }
            }

            string word = vec.back();

            if(word == endWord)
            {
                if(ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }

            int m = word.size();

            for(int i = 0; i < m; i++)
            {
                char ch = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(st.count(word) > 0)
                    {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = ch;
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
    string beginWord;
    string endWord;
    cin >> beginWord >> endWord;
    
    vector<string> wordList;
    int n;
    cin >> n; 
    for(int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        wordList.push_back(word);
    }

    Solution sln;
    vector<vector<string>> ans = sln.findLadders(beginWord, endWord, wordList);

    for(vector<string> row : ans)
    {
        for(string s : row)
        cout << s << " ";
        cout << endl;
    }
    return 0;
}