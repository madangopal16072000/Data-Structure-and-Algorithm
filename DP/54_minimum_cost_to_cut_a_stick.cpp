#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        // base case 
        if(i > j)
        return 0;
        // recursvie case
        if(dp[i][j] != -1)
        return dp[i][j];

        int ans = 1e9;
        int cost;
        for(int k = i;  k <= j; k++)
        {
            cost = cuts[j+1] - cuts[i-1] + helper(i, k-1, cuts, dp) + helper(k+1, j, cuts, dp);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return helper(1, c, cuts, dp);
    }
    // bottom up approach
    int minCost1(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));
        for(int i = c; i >= 1; i--)
        {
            for(int j = 1; j <= c; j++)
            {
                if(i > j)
                continue;

                int mini = INT_MAX;
                for(int k = i; k <= j; k++)
                {
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};

int main()
{
    int n = 7;
    vector<int> cuts {1, 3, 4, 5};
    Solution s;
    cout << s.minCost1(n, cuts) << endl;
    return 0;
}