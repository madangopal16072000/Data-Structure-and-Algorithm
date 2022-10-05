#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
class Solution
{
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

public:
    int f(string pressedKeys, int i, vector<int> &dp)
    {
        if (i < 1)
            return 1;

        if (dp[i] != -1)
            return dp[i];

        int j = i;
        while (j - 1 >= 0 && pressedKeys[j] == pressedKeys[j - 1])
        {
            j--;
        }

        int ans = 0;
        for (int k = 1; k <= mp[pressedKeys[i]].length() && k <= i - j + 1; k++)
        {
            ans = (ans + f(pressedKeys, i - k, dp)) % M;
        }
        return dp[i] = ans;
    }
    int countTexts(string pressedKeys)
    {
        int n = pressedKeys.size();
        vector<int> dp(n, -1);
        int ans = f(pressedKeys, n - 1, dp);
        for(int x : dp)
        cout << x << " ";
        cout << endl;
        return ans;
    }
    int countTexts2(string pressedKeys)
    {
        int n = pressedKeys.size();
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int j = i;
            while (j - 1 > 0 && pressedKeys[j-1] == pressedKeys[j - 2])
            {
                j--;
            }
            int ans = 0;
            for (int k = 1; k <= mp[pressedKeys[i-1]].length() && k <= i - j + 1; k++)
            {
                ans = (ans + dp[i-k]) % M;
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string pressedKeys;
    cin >> pressedKeys;
    Solution sln;
    cout << sln.countTexts2(pressedKeys) << endl;
    return 0;
}