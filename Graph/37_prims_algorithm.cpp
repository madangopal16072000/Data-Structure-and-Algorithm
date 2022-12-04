#include<bits/stdc++.h>
using namespace std;


void prims(vector<vector<pair<int, int>>> adj, int V)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> vis(V, 0);

    int sum = 0;
    pq.push({0, {0, -1}});
    vector<vector<int>> mst;
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(vis[node] == 1)
        continue;

        vis[node] = 1;
        sum = sum + wt;
        if(node != 0)
        {
            mst.push_back({parent, node, wt});
        }


        for(auto vec : adj[node])
        {
            int adjNode = vec.first;
            int adjWt = vec.second;
            if(vis[adjNode] == 0)
            {
                pq.push({adjWt, {adjNode, node}});
            }
        }

    }

    cout << "Sum of MST : " << sum << endl;
    for(auto vec : mst)
    {
        for(int x : vec)
        cout << x << " ";
        cout << endl;
    }

}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int E;
  int V;
  cin >> V >> E;
  vector<vector<pair<int,int>>> adj(V, {{}});
  for(int i = 0; i < E; i++)
  {
    int x, y, wt;
    cin >> x >> y >> wt;
    adj[x].push_back({y, wt});
    adj[y].push_back({x, wt});
  }

  prims(adj, V);
  return 0;
}