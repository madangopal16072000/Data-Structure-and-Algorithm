#include<bits/stdc++.h>
using namespace std;
#define LM 99999
class Solution {
public:
    int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        // base case
        if(i == 0)
        return matrix[i][j];
        if(j < 0 || j == matrix.size())
        return LM;

        // recursive case
        if(dp[i][j] != LM)
        return dp[i][j];

        int  op1 = matrix[i][j] + f(i-1, j, matrix, dp);
        int  op2 = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int  op3 = matrix[i][j] + f(i-1, j+1, matrix, dp);

        return dp[i][j] = min(op1, min(op2, op3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, LM));
        int minPath = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            minPath = min(minPath, f(n-1, i, matrix, dp));
        }
        return minPath;
    }
    int minFallingPathSum1(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int j = 0; j < n; j++)
        dp[0][j] = matrix[0][j];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int op1, op2, op3;
                op1 = op2 = op3 = LM;
                op1 = dp[i-1][j];
                if(j > 0)
                op2 = dp[i-1][j-1];
                if(j < n-1)
                op3 = dp[i-1][j+1];
                
                dp[i][j] = matrix[i][j] + min(op1, min(op2, op3));
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j < n; j++)
        {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
    int minFallingPathSum2(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prevRow(n, 0);
        for(int j = 0; j < n; j++)
        prevRow[j] = matrix[0][j];

        for(int i = 1; i < n; i++)
        {
            vector<int> curr(n, 0);
            for(int j = 0; j< n; j++)
            {
                int op1, op2, op3;
                op1 = op2 = op3 = LM;
                op1 = prevRow[j];
                if(j > 0)
                op2 = prevRow[j-1];
                if(j < n-1)
                op3 = prevRow[j+1];

                curr[j] = matrix[i][j] + min(op1, min(op2, op3));
            }
            prevRow = curr;
        }
        int ans = INT_MAX;
        for(int j = 0; j<n; j++)
        {
            ans = min(ans, prevRow[j]);
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> matrix {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    // vector<vector<int>> matrix {
    //     {-19, 57},
    //     {-40, 5}
    // };

    Solution s;
    cout << s.minFallingPathSum2(matrix) << endl;
    return 0;
}