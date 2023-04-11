#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool detectCycle(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &pathVis)
    {
        visited[node] = true;
        pathVis[node] = true;

        for (int nbr : adj[node])
        {
            if (!visited[nbr])
            {
                if (detectCycle(nbr, adj, visited, pathVis))
                    return true;
            }
            else if (pathVis[nbr])
            {
                return true;
            }
        }
        pathVis[node] = false;
        return false;
    }
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &mp, string &colors, int &ans)
    {
        vis[node] = true;
        mp[colors[node] - 'a']++;
        ans = max(ans, mp[colors[node] - 'a']);

        for (int nbr : adj[node])
        {
            if (!vis[nbr])
            {
                dfs(nbr, adj, vis, mp, colors, ans);
            }
        }

        mp[colors[node] - 'a']--;
    }

public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {

        int n = colors.size();
        vector<vector<int>> adj(n);
        for (vector<int> row : edges)
        {
            adj[row[0]].push_back(row[1]);
        }

        vector<bool> visited(n, false);
        vector<bool> pathVis(n, false);

        if (detectCycle(0, adj, visited, pathVis))
        {
            return -1;
        }

        vector<int> mp(26, 0);
        vector<bool> vis(n, false);
        int ans = 0;
        dfs(0, adj, vis, mp, colors, ans);
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    string colors;
    cin >> colors;
    int m;
    cin >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    Solution sln;
    cout << sln.largestPathValue(colors, edges) << endl;
    return 0;
}