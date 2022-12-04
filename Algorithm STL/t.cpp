#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        if(m != n)
            return false;
        
        
        map<char, int> mp1, mp2;
        for(int i = 0; i < m; i++)
        {
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        
        if(mp1.size() != mp2.size())
            return false;
        
        multimap<int, char> mp3, mp4;
        for(auto p : mp1)
        {
            mp3.insert({p.second, p.first});
        }
        for(auto p : mp2)
        {
            mp4.insert({p.second, p.first});
        }
        
        auto it1 = mp1.begin();
        for(auto p : mp2)
        {
            auto p2 = *it1;
            if(p.first != p2.first)
            {
                return false;
            }
        }
        auto it = mp3.begin();
        for(auto p : mp4)
        {
            auto p2 = *it;
            if(p.first != p2.first)
                return false;

            it++;
        }
        
        return true;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  string word1, word2;
  cin >> word1 >> word2;
  Solution sln;
  cout << sln.closeStrings(word1, word2) << endl;
  return 0;
}