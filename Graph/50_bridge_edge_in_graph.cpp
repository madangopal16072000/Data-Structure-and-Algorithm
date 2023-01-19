#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
    public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n+1, 0);
        for(int i = 0; i <= n; i++)
        parent[i] = i;

        size.resize(n+1, 1);
    }

    int find(int node)
    {
        if(node == parent[node])
        return node;
        
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int parentU = find(u);
        int parentV = find(v);

        if(parentU == parentV)
        return;

        if(size[parentU] < size[parentV])
        {
            parent[parentU] = parentV;
            size[parentV] = size[parentV] + size[parentU];
        }
        else
        {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<vector<int>> adj, int c, int d) 
    {
        // Code here
        DisjointSet ds(V);
        
        for(int i = 0; i < V; i++)
        {
            for(int nbr : adj[i])
            {
                if(ds.find(nbr) != ds.find(i))
                {
                    ds.unionBySize(nbr, i);
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < V; i++)
        {
            if(ds.find(i) == i)
            cnt++;
        }
        
        DisjointSet ds1(V);
        int cnt2 = 0;
        for(int i = 0; i < V; i++)
        {
            for(int nbr : adj[i])
            {
                if((i == c || i == d) && (nbr == c || nbr == d))
                continue;
                
                if(ds.find(i) != ds.find(nbr))
                ds.unionBySize(nbr, i);
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(ds.find(i) == i)
            cnt2++;
        }
        
        return cnt2 == cnt+1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int V, E;
  cin >> V >> E;
  int c, d;
  cin >> c >> d;

  vector<vector<int>> adj(V);
  for(int i = 0; i < E; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  Solution sln;
  cout << sln.isBridge(V, adj, c, d);
  return 0;
}