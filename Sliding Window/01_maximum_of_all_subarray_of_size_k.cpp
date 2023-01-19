#include<bits/stdc++.h>
using namespace std;

vector<int> maxSub(vector<int> &nums, int k)
{
    deque<int> dq;
    int i = 0, j = 0;
    int n = nums.size();
    vector<int> ans;
    while(j < n)
    {
        while(!dq.empty() && dq.back() < nums[j])
        {
            dq.pop_back();
        }
        dq.push_back(nums[j]);

        if(j-i+1 < k)
        j++;
        else
        {
            ans.push_back(dq.front());
            if(nums[i] == dq.front())
            {
                dq.pop_front();
            }
            i++;
            j++;
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
  int n;
  cin >> n;
  vector<int> nums;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    nums.push_back(d);
  }
  int k;
  cin >> k;
  vector<int> ans = maxSub(nums, k);
  for(int x : ans)
  cout << x << " ";
  return 0;
}