#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int f(int i, int j, vector<int> arr, int k, vector<vector<int>> &dp)
    {
        if(i > j)
        return INT_MAX;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(arr[j]-arr[i] <= k)
        return 0;

        int op1 = 1 + f(i+1, j, arr, k, dp);
        int op2 = 1 + f(i, j-1, arr, k, dp);
        return dp[i][j] = min(op1, op2);
    }
    int removals(vector<int>& arr, int k){
        //Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, arr, k, dp);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> arr;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  int k;
  cin >> k;
  Solution sln;
  cout << sln.removals(arr, k) << endl;
  return 0;
}