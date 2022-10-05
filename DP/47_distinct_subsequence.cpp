#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if(j < 0)
        return 1;
        if(i < 0)
        return 0;

        // recursive case
        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] == t[j])
        {
            return dp[i][j] = helper(i-1, j-1, s, t, dp) + helper(i-1, j, s, t, dp);
        }
        else
        {
            return dp[i][j] = helper(i-1, j, s, t, dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int> (t.length(), 0));
        return helper(s.length()-1, t.length()-1, s, t, dp);
    }
};
int main()
{
    string s, t;
    cin >> s >> t;
    Solution sl;
    cout << sl.numDistinct(s, t) << endl;
    return 0;
}