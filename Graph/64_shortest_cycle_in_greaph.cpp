#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ans;
    void dfs(int node, int parent, vector<bool> &vis, vector<int> dist, vector<vector<int>> &adj)
    {
        vis[node] = true;
        for (int nbr : adj[node])
        {
            if (!vis[nbr])
            {
                dist[nbr] = dist[node] + 1;
                dfs(nbr, node, vis, dist, adj);
            }
            else if (nbr != parent && dist[nbr] > 0)
            {
                ans = min(ans, dist[node] - dist[nbr] + 1);
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        ans = INT_MAX;
        vector<vector<int>> adj(n);
        for (vector<int> vec : edges)
        {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        vector<bool> vis(n, false);
        vector<int> dist(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dist[i] = 1;
                dfs(i, -1, vis, dist, adj);
            }
        }
        return ans == INT_MAX ? -1 : ans;
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
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    Solution sln;
    cout << sln.findShortestCycle(n, edges) << endl;
    return 0;
}