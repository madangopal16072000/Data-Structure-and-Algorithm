#include <bits/stdc++.h>
using namespace std;
#define M 10000000007
class Solution
{
public:
  int sumSubarrayMins(vector<int> &arr)
  {
    int n = arr.size();
    stack<int> st;
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[st.top()] >= arr[i])
      {
        st.pop();
      }

      if (st.empty())
      {
        dp[i] = ((i + 1) * arr[i])%M;
      }
      else
      {
        dp[i] = (dp[st.top()] + (i - st.top()) * arr[i])%M;
      }
      st.push(i);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
      ans = (ans + dp[i])%M;
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
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    arr.push_back(d);
  }

  Solution sln;
  cout << sln.sumSubarrayMins(arr) << endl;
  return 0;
}