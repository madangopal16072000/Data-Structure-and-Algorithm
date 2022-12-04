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
        parent[i] = i;

        size.resize(V+1, 1);
    }
    int find(int node)
    {
        while(node != parent[node])
        {
            node = parent[node];
        }
        return node;
    }

    void unionBySize(int u, int v)
    {
        int parentU = find(u);
        int parentV = find(v);

        if(parentU == parentV)
        return;

        if(size[parentU] < size[parentV])
        {
            parent[parentU] = v;
            size[parentV] += size[parentU];
        }
        else
        {
            parent[parentV] = u;
            size[parentU] += size[parentV];
        }
    }
};
void Krushkal(vector<pair<int, int>> adj[], int V)
{
    vector<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < V; i++)
    {
        for(pair<int, int> p : adj[i])
        {
            int u = i;
            int v = p.first;
            int wt = p.second;
            edges.push_back({wt, {u, v}});
        }
    }

    DisjointSet ds(V);
    sort(edges.begin(), edges.end());
    int sum = 0;
    for(auto p : edges)
    {
        int weight = p.first;
        int u = p.second.first;
        int v = p.second.second;

        if(ds.find(u) != ds.find(v))
        {
            sum = sum + weight;
            ds.unionBySize(u, v);
        }
    }

    cout << "sum : " << sum << endl;
    for(int i = 0; i <= V; i++)
    {
        if(i != ds.parent[i])
        cout << i << " " << ds.parent[i] << endl;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int V;
  cin >> V;
  vector<pair<int, int>> *adj = new vector<pair<int, int>>[V+1];
  int E;
  cin >> E;
  for(int i = 0; i < E; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }

  Krushkal(adj, V);
  return 0;
}