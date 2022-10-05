#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
    string s1 = "ABCD";
    string s2 = "ABEDC";

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])
            dp[i][j] = 1 + dp[i-1][j-1];
            else
            {
                int op1 = dp[i-1][j];
                int op2 = dp[i][j-1];
                dp[i][j] = max(op1, op2);
            }
        }
    }

    // cout << dp[n][m] << endl;

    string ans;
    int i = n, j = m;
    while(i != 0 && j != 0)
    {
        if(dp[i][j] == dp[i][j-1])
        j--;
        else if(dp[i][j] == dp[i-1][j])
        i--;
        else
        {
            ans += s1[i-1];
            i--;
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}