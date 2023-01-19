#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int f(int i, int n, string s, int k, unordered_map<char, int> &dp)
    {
        return -1;
    }
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> dp;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(!dp.count(s[i]))
            {
                dp[s[i]] = 1;
            }
        }

        return f(0, n, s, k, dp);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  
  return 0;
}