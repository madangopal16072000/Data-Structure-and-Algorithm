#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int getPalindromeCount(string s)
{
    string p(s.rbegin(), s.rend());

    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i-1] == p[j-1])
            {
                dp[i][j] = (1 + dp[i-1][j-1])%M;
            }
            else
            {
                dp[i][j] = (max(dp[i-1][j], dp[i][j-1]))%M;
            }

            if(dp[i][j] == 5)
            {
                ans = (ans + 1)%M;
            }
        }
    }

    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  string s;
  cin >> s;
  cout << getPalindromeCount(s) << endl;
  return 0;
}