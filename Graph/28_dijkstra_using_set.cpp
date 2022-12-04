#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int src)
{
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, src});
    dist[src] = 0;

    while(!st.empty())
    {
        auto it = *st.begin();
        int d = it.first;
        int node = it.second;
        st.erase(it);

        for(pair<int, int> p : adj[node])
        {
            int w = p.second;
            int nbr = p.first;

            if(d + w < dist[nbr])
            {
                if(dist[nbr] != 1e9)
                st.erase({dist[nbr], nbr});

                dist[nbr] = d + w;
                st.insert({dist[nbr], nbr});
            }
        }

    }
    return dist;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int V;
  cin >> V;
  vector<pair<int, int>> *adj = new vector<pair<int, int>>[V];
  int E;
  cin >> E;
  for(int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int src;
  cin >> src;
  
  vector<int> ans = dijkstra(V, adj, src);
  for(int i = 0; i < V; i++)
  {
    cout << i << "-->" << ans[i] << endl;
  }
  return 0;
}