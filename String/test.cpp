#include<bits/stdc++.h>
using namespace std;
#define M 1000000000
class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        // code here
        sort(capacity.begin(), capacity.end());
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            ans = (ans*(capacity[i] - i))%M;
        }
        return ans;
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
  vector<int> capacity;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    capacity.push_back(d);
  }

  Solution soln;
  cout << soln.totalWays(n, capacity) << endl;
  return 0;
}