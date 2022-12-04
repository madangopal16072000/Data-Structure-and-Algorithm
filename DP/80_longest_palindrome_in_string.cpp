#include<bits/stdc++.h>
using namespace std;

int f(string s)
{
    int n = s.length();
    int len = 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    for(int i = 0; i < n-1; i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            len = 2;
        }
    }

    for(int i = n-3; i >= 0; i--)
    {
        for(int j = i+2; j < n; j++)
        {
            if(s[i] == s[j])
            {
                if(dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                    len = max(len, j-i+1);
                }
            }
        }
    }
    return len;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
 string s;
 cin >> s;
 cout << f(s) << endl;
 return 0;
}