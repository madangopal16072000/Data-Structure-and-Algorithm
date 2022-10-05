#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    {
        // base case
        if(i == 0)
        return j;
        if(j == 0)
        return i;

        // recursive case
        if(dp[i][j] != -1)
        return dp[i][j];
        if(word1[i-1] == word2[j-1])
        {
            return dp[i][j] = helper(i-1, j-1, word1, word2, dp);
        }
        else
        {
            int op1 = helper(i, j-1, word1, word2, dp) + 1;
            int op2 = helper(i-1, j, word1, word2, dp) + 1;
            int op3 = helper(i-1, j-1, word1, word2, dp) + 1;
            return dp[i][j] = min(op1, min(op2, op3));
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return helper(m, n, word1, word2, dp);
    }
    int minDistance2(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; i++)
        dp[i][0] = i;
        for(int j = 0; j <= n; j++)
        dp[0][j] = j;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
                else
                {
                    int op1 = 1+dp[i][j-1];
                    int op2 = 1+dp[i-1][j];
                    int op3 = 1+dp[i-1][j-1];
                    dp[i][j] = min(op1, min(op3, op2));
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    Solution s;
    cout << s.minDistance2(word1, word2) << endl;
    return 0;
}