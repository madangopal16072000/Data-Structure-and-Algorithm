#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<long long int>> dp(m, vector<long long int>(n, 0));
        dp[0][0] = 1;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {

                if(i > 0)
                dp[i][j] += dp[i-1][j];
                if(j > 0)
                dp[i][j] += dp[i][j-1];
                
            }
        }
        return dp[m-1][n-1];
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int m, n;
    cin >> m >> n;
    Solution sln;
    cout << sln.numberOfPaths(m, n);
    return 0;
}