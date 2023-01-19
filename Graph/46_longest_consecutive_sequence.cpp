#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    unordered_map<int, int> size, parent;
    
    DisjointSet(vector<int> nums)
    {
        for(int x : nums)
        {
            parent[x] = x;
            size[x] = 1;
        }
    }
    int find(int node)
    {
        if(node == parent[node])
            return node;
        
        return parent[node] = find(parent[node]);
    }
    
    void unionBySize(int u, int v)
    {
        int parU = find(u);
        int parV = find(v);
        
        if(parU == parV)
            return;
        
        if(size[parU] < size[parV])
        {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else
        {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]] = 1;
        }
        DisjointSet ds(nums);
        for(int i = 0; i < n; i++)
        {
            if(mp.count(nums[i] + 1) == 1)
            {
                if(ds.find(nums[i]) != ds.find(nums[i] + 1))
                {
                    ds.unionBySize(nums[i], nums[i] + 1);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, ds.size[nums[i]]);
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
  vector<int> nums;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    nums.push_back(d);
  }
  Solution sln;
  cout << sln.longestConsecutive(nums) << endl;
  return 0;
}