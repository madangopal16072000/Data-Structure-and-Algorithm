#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int s, int e, string str)
    {
        while (s <= e)
        {
            if (str[s] != str[e])
                return false;
            s++;
            e--;
        }
        return true;
    }
    int minCut(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                    dp[i][j] = 0;
                else
                {
                    int mini = INT_MAX;
                    for (int k = i; k < j; k++)
                    {
                        int cuts = 1 + dp[i][k] + dp[k + 1][j];
                        mini = min(mini, cuts);
                    }
                    dp[i][j] = mini;
                }
            }
        }

        return dp[0][n - 1];
    }
};
int main()
{
    string str = "aabcc";
    Solution s;
    cout << s.minCut(str) << endl;
    return 0;
}