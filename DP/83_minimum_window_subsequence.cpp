#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int m = str1.size();
        int n = str2.size();

        vector<vector<pair<int, int>>> dp(m+1, vector<pair<int, int>>(n+1, {0, 0}));

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[];
                }
            }
        }
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