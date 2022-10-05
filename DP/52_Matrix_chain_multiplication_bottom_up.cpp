#include<bits/stdc++.h>
using namespace std;

int matrixChain(int i, int j, vector<int> dim, vector<vector<int>> &dp)
{
    // base case 
    if(i == j)
    return 0;

    // recursive case
    if(dp[i][j] != -1)
    return dp[i][j];
    
    int ans = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int steps = dim[i-1]*dim[k]*dim[j] + matrixChain(i, k, dim, dp) + matrixChain(k+1, j, dim, dp);
        ans = min(ans, steps);
    }
    return dp[i][j] = ans;
}
int main()
{
    vector<int> dim {1, 2, 3, 4, 5};
    vector<vector<int>> dp(dim.size(), vector<int> (dim.size(), -1));
    cout << matrixChain(1, dim.size()-1, dim, dp) << endl;
    return 0;
}