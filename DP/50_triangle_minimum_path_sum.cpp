#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        // base case
        if(i == triangle.size()-1)
        {
            dp[i][j] = triangle[i][j];
        }

        // recursive case
        if(dp[i][j] != -1)
        return dp[i][j];

        int down = helper(i+1, j, triangle, dp);
        int diag = helper(i+1, j+1, triangle, dp);
        return dp[i][j] = triangle[i][j] + min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(), -1));
        return helper(0, 0, triangle, dp);
    }
    int minimumTotal1(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (triangle[n-1].size(), 0));
        for(int j = 0; j < triangle[n-1].size(); j++)
        dp[n-1][j] = triangle[n-1][j];


        for(int i = n-2; i >= 0; i--)
        {
            for(int j = i; j >= 0; j--)
            {
                int down = dp[i+1][j];
                int dg = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down, dg);
            }
        }
        return dp[0][0];
    }
};
int main()
{
    vector<vector<int>> triangle {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    Solution s;
    cout << s.minimumTotal1(triangle) << endl;
    return 0;
}