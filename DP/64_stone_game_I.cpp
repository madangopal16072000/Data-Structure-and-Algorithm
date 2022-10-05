#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i, int j, vector<int> &piles, vector<vector<int>> &dp)
    {
        // base case
        if(i > j)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int first = piles[i] + min(f(i+1, j-1, piles, dp), f(i+2,j, piles, dp));
        int last = piles[j] + min(f(i+1, j, piles, dp), f(i, j-2, piles, dp));

        return dp[i][j] = max(first, last);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int tot = accumulate(piles.begin(), piles.end(), 0);
        int fPlayer = f(0, n-1, piles, dp);
        cout << "Total : " << tot << " FPlayer : " << fPlayer << " SPlayer : " << tot - fPlayer << endl;
        return fPlayer > (tot - fPlayer);
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
  vector<int> piles;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    piles.push_back(d);
  }
  Solution sln;
  cout << sln.stoneGame(piles) << endl;
  return 0;
}