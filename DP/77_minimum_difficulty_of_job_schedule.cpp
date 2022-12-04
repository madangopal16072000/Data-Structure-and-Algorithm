#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxi(int i, int j, vector<int> jobDifficulty)
    {
        int m = INT_MIN;
        for(int s = i; s >= j; s--)
        {
            m = max(jobDifficulty[s], m);
        }
        return m;
    }
    int f(int i, int j, vector<int> jobDifficulty, vector<vector<int>> dp)
    {
        // base case
        if(i == 0)
        {
            return jobDifficulty[i];
        }
        if(j == 0)
        {
            return maxi(i, 0, jobDifficulty);
        }

        // memo
        if(dp[i][j] != -1)
        return dp[i][j];

        int mini = INT_MAX;
        for(int k = i; k > 0; k--)
        {
            int m = maxi(i, k, jobDifficulty);
            mini = min(mini, m + f(k-1, j-1, jobDifficulty, dp));
        }

        return dp[i][j] = mini;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        vector<vector<int>> dp(n, vector<int>(d, -1));
        return f(n-1, d-1, jobDifficulty, dp);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    vector<int> jobDifficulty;
    int n, d;
    cin >> n >> d;

    for(int i = 0; i < n; i++)
    {
        int x; 
        cin >> x;
        jobDifficulty.push_back(x);
    }

    Solution sln;
    cout << sln.minDifficulty(jobDifficulty, d) << endl;
    return 0;
}