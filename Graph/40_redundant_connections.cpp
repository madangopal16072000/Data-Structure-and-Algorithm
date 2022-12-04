#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    vector<int> parent, size;
    DisjointSet(int V)
    {
        parent.reserve(V+1);
        for(int i = 0; i <= V; i++)
            parent.push_back(i);
        size.resize(V+1, 1);
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        DisjointSet ds(n);
        int x, y;
        for(int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(ds.find(u) == ds.find(v))
            {
                x = u;
                y = v;
            }
            else
            ds.unionBySize(u, v);
        }
        vector<int> ans;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  vector<vector<int>> edges;
  int E;
  cin >> E;
  for(int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    vector<int> row;
    row.push_back(u);
    row.push_back(v);
    edges.push_back(row);
  }

  Solution sln;
  vector<int> ans = sln.findRedundantConnection(edges);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}