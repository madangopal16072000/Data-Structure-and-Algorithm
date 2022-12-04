#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void topoSort(int src, vector<bool> &vis, vector<pair<int,int>> adj[], stack<int> &st)
    {
        vis[src] = true;

        for(pair<int, int> p : adj[src])
        {
            int v = p.first;
            if(!vis[v])
            {
                topoSort(v, vis, adj, st);
            }
        }
        st.push(src);
        return;
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here

        vector<pair<int, int>> *adj = new vector<pair<int, int>>[N];
        for(int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        vector<bool> vis(N, false);
        stack<int> st;
        for(int i = 0; i < N; i++)
        {
            if(!vis[i])
            {
                topoSort(i, vis, adj, st);
            }
        }

        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();

            for(pair<int, int> p : adj[node])
            {
                int wt = p.second;
                int v = p.first;
                if(wt + dist[node] < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }

        }

        return dist;
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
    vector<vector<int>> edges;

    for(int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    Solution sln;
    vector<int> ans = sln.shortestPath(n, m, edges);

    for(int x : ans)
    cout << x << " ";
    return 0;
}