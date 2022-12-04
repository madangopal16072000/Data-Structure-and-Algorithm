#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void prims(vector<int> &vis, unordered_map<int, int> &mst, int src, vector<vector<int>> adj)
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            if(vis[node] == 1 && mst[node] != -1)
                continue;
            
            vis[node] = 1;
            mst[node] = par;
            
            for(int nbr : adj[node])
            {
                if(vis[nbr] == 0 || mst[nbr] == -1)
                {
                    q.push({nbr, node});
                }
            }
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<int> vis(n+1, 0);
        unordered_map<int, int> mst;
        
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                prims(vis, mst, i, adj);
            }
        }
        
        int x, y;
        for(int i = 0; i < n; i++)
        {
            if(mst.count(edges[i][0])==0 && mst.count(edges[i][1])==0)
            {
                x = edges[i][0];
                y = edges[i][1];
            }
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
  vector<int> ans = sln.findRedundantDirectedConnection(edges);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}