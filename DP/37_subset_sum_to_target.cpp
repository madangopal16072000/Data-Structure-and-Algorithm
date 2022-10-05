#include<bits/stdc++.h>
using namespace std;


int subsetSum(int n, int sum, vector<int> &inp, vector<vector<int>> &dp)
{
    if(sum == 0)
    return 1;

    if(n <= 0)
    return 0;

    if(dp[n][sum] != -1)
    return dp[n][sum];
    
    if(inp[n-1] > sum)
    return dp[n][sum] = subsetSum(n-1, sum, inp, dp);
    else
    return dp[n][sum] = subsetSum(n-1, sum, inp, dp) || subsetSum(n-1, sum - inp[n-1], inp, dp);

}
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> inp;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        inp.push_back(d);
    }

    vector<vector<int>> dp(n+1, vector<int>(sum + 1, -1));
    if(subsetSum(n, sum, inp, dp))
    cout << "Yes" << endl;
    else
    cout << "No" << endl;
    return 0;
}