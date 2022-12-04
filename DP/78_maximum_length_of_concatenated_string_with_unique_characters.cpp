#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isUnique(string str, unordered_map<char, int> &mp)
    {
        int n = str.length();
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            mp[str[i]]++;
            if (mp[str[i]] > 1)
                ans = false;
        }
        return ans;
    }
    int helper(vector<string> arr, unordered_map<char, int> &mp, int i, int n, vector<int> &dp)
    {
        if (i == n)
        {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        int take, notake;
        take = notake = 0;

        if (isUnique(arr[i], mp))
        {
            take = arr[i].length() + helper(arr, mp, i + 1, n, dp);
        }
        int len = arr[i].size();
        for (int j = 0; j < len; j++)
        {
            mp[arr[i][j]]--;
        }

        notake = helper(arr, mp, i + 1, n, dp);
        return dp[i] = max(take, notake);
    }
    int maxLength(vector<string> &arr)
    {
        unordered_map<char, int> mp;
        int n = arr.size();
        vector<int> dp(n, -1);
        return helper(arr, mp, 0, n, dp);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    vector<string> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string d;
        cin >> d;
        arr.push_back(d);
    }
    Solution sln;
    cout << sln.maxLength(arr) << endl;
    return 0;
}