#include<bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> &dm)
{
    int n = dm.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n-1; i>=1; i--)
    {
        for(int j = i+1; j < n; j++)
        {
            int ans = 1e9;
            int steps;
            for(int k = i; k < j; k++)
            {
                steps = dm[i-1]*dm[k]*dm[j] + dp[i][k] + dp[k+1][j];
                ans = min(ans, steps);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][n-1];
}
int main()
{
    vector<int> dm {1, 2, 3, 4, 5};
    cout << matrixChainMultiplication(dm) << endl;
    return 0;
}