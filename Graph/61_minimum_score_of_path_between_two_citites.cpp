#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<bool> &vis, vector<vector<pair<int, int>>> &adj)
    {
        vis[node] = true;

        for (pair<int, int> p : adj[node])
        {
            if (!vis[p.first])
            {
                dfs(p.first, vis, adj);
            }
        }
    }
    int minScore(int n, vector<vector<int>> &roads)
    {

        vector<vector<pair<int, int>>> adj(n + 1);
        for (vector<int> vec : roads)
        {
            adj[vec[0]].push_back({vec[1], vec[2]});
            adj[vec[1]].push_back({vec[0], vec[2]});
        }

        int mini = INT_MAX;
        vector<bool> vis(n + 1, false);

        dfs(1, vis, adj);

        for (int i = 1; i <= n; i++)
        {
            for (auto p : adj[i])
            {
                if (vis[p.first])
                {
                    mini = min(mini, p.second);
                }
            }
        }
        return mini;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n, e;
    cin >> n >> e;
    vector<vector<int>> roads;
    for (int i = 0; i < e; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        roads.push_back({x, y, d});
    }
    Solution sln;
    cout << sln.minScore(n, roads) << endl;
    return 0;
}