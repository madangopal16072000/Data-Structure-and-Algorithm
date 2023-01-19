#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    vector<int> size, parent;
    
    DisjointSet(int n)
    {
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++)
        {
            parent.push_back(i);
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
        for(int i = 0; i <= n; i++)
        {
            adj[i][i] = 1;
        }
        
        for(auto vec : dislikes)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        
        DisjointSet ds(n);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                int parI = ds.find(i);
                int parJ = ds.find(j);
                if(adj[i][j] == 0 && ds.find(i) != ds.find(j) && adj[parI][parJ] == 0)
                {
                    ds.unionBySize(i, j);
                }
            }
        }
        
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(ds.parent[i] == i)
            {
                cnt++;
            }
        }
        
        return cnt == 2;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dislikes;
  for(int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    dislikes.push_back({x, y});
  }

  Solution sln;
  cout << sln.possibleBipartition(n, dislikes) << endl;
  return 0;
}