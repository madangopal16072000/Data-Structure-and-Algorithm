#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
class Solution {
public:
    long long fact(int n)
    {
        if(n == 1)
            return 1;
        
        return n*fact(n-1);
    }
    long long f(string temp)
    {
        unordered_map<char, int> mp;
        int n = temp.size();
        long long ans = 1;
        for(char ch : temp)
        {
            mp[ch]++;
        }
        
        ans = fact(n)%M;
        for(auto p : mp)
        {
            ans = (ans/fact(p.second))%M;
        }
        return ans;
    }
    int countAnagrams(string s) {
        
        int n = s.size();
        string temp = "";
        long long ans = 1;
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            if(ch == ' ')
            {
                if(temp.size() > 0)
                {
                    ans = (ans*f(temp))%M;
                }
                
                temp = "";
            }
            else
            {
                temp = temp + ch;
            }
        }
        if(temp.size() > 0)
        {
            ans = (ans*f(temp))%M;
        }
        return ans;
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  Solution sln;
  string s = "b okzojaporykbmq tybq zrztwlolvcyumcsq jjuowpp";
  cout << sln.countAnagrams(s) << endl;
  return 0;
}