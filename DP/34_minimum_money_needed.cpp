#include<bits/stdc++.h>
using namespace std;
#define INF 9999
int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> wt;
    for(int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        wt.push_back(d);
    }
    vector<int> val;
    for(int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        val.push_back(d);
    }
    vector<vector<int>> dp(N+1, vector<int>(W+1));

    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
            else if(wt[i-1] <= j)
            {
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    cout << dp[N][W] << endl;
}