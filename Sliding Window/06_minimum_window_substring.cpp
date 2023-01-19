#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        
        int k = t.size();

        unordered_map<char, int> mp;
        for(char ch : t)
        {
            mp[ch]++;
        }
        int i = 0, j = 0;
        int n = s.size();
        int low, high, len;
        low = high = -1;
        len = INT_MAX;

        while(j < n)
        {
            if(mp.count(s[j]))
            {
                mp[s[j]]--;
                if(mp[s[j]] >= 0)
                {
                    k--;
                }
            }

            while(i < n && k == 0)
            {
                if(len > j-i+1)
                {
                    low = i;
                    high = j;
                    len = j-i+1;
                }

                if(mp.count(s[i]))
                {
                    mp[s[i]]++;
                    if(mp[s[i]] > 0)
                    {
                        k++;
                    }
                }
                i++;
            }
            j++;
        }

        if(low == -1)
        {
            return "";
        }
        string temp = "";
        for(int i = low; i <= high; i++)
        {
            temp = temp + s[i];
        }
        return temp;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  string s;
  string t;
  cin >> s >> t;

  Solution sln;
  cout << sln.minWindow(s, t) << endl;
  return 0;
}