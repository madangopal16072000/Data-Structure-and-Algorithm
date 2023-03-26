#include <bits/stdc++.h>
using namespace std;

bool isValid(int mid, int A, vector<int> &vec)
{
  int cnt = 0;
  for (int x : vec)
  {
    if (x >= mid)
    {
      cnt++;
    }

    if (cnt >= A)
      return true;
  }

  return false;
}
int f(int A, int B, vector<int> &nums)
{
  unordered_map<int, int> mp;
  for (int x : nums)
  {
    mp[x]++;
  }

  vector<int> vec;
  int maxi = 1;
  for (auto p : mp)
  {
    maxi = max(maxi, p.second);
    vec.push_back(p.second);
  }

  int s = 0;
  int e = maxi;

  int ans = -1;
  while (s <= e)
  {
    int mid = s + (e - s) / 2;

    if (isValid(mid, A, vec))
    {
      ans = mid;
      s = mid + 1;
    }
    else
    {
      e = mid - 1;
    }
  }

  return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int A, B;
  cin >> A >> B;
  vector<int> nums;
  for (int i = 0; i < B; i++)
  {
    int d;
    cin >> d;
    nums.push_back(d);
  }

  cout << f(A, B, nums) << endl;
  return 0;
}