#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
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
  vector<vector<int>> stones;
  for(int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    stones.push_back({x, y});
  }

  Solution sln;
  cout << sln.removeStones(stones) << endl;
  return 0;
}