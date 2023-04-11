#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int k, vector<int> &reward1, vector<int> &reward2, vector<vector<int>> &dp, int n)
    {
        // base case
        if (i == n && k == 0)
            return 0;

        if (i >= n)
            return INT_MIN;

        if (dp[i][k] != -1)
            return dp[i][k];

        int take, nottake;
        take = nottake = INT_MIN;
        if (k > 0)
        {
            take = reward1[i] + f(i + 1, k - 1, reward1, reward2, dp, n);
        }
        nottake = reward2[i] + f(i + 1, k, reward1, reward2, dp, n);

        return dp[i][k] = max(take, nottake);
    }
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {

        int n = reward1.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return f(0, k, reward1, reward2, dp, n);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    vector<int> reward1, reward2;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        reward1.push_back(d);
    }

    for (int j = 0; j < n; j++)
    {
        int d;
        cin >> d;
        reward2.push_back(d);
    }

    Solution sln;
    cout << sln.miceAndCheese(reward1, reward2, k);
    return 0;
}