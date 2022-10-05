#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>> &dp)
{
    if(i == s1.length() || j == s2.length() || k == s3.length())
    return 0;

    if(dp[i][j][k] != -1)
    return dp[i][j][k];

    if(s1[i] == s2[j] && s2[j] == s3[k])
    {
        return 1 + lcs(s1, s2, s3, i+1, j+1, k+1, dp);
    }

    int op1 = lcs(s1, s2, s3, i+1, j, k, dp);
    int op2 = lcs(s1, s2, s3, i, j+1, k, dp);
    int op3 = lcs(s1, s2, s3, i, j, k+1, dp);

    return dp[i][j][k] = max(max(op1, op2), op3);
}
int main()
{
    string s1, s2, s3;
    // s1 = "GHQWNV";
    // s2 = "SJNSDGH";
    // s3 = "CPGMAH";

    cin >> s1;
    cin >> s2;
    cin >> s3;
    vector<vector<vector<int>>> dp(s1.length(), vector<vector<int>>(s2.length(), vector<int>(s3.length(), -1)));
    cout << lcs(s1, s2, s3, 0, 0, 0, dp) << endl;
    return 0;
}