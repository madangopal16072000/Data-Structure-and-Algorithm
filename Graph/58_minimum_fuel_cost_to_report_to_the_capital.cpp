#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    pair<int, long long> dfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &vis, int seats)
    {
        vis[node] = true;
        pair<int, long long> p = {0, 0};

        for (int nbr : adj[node])
        {
            if (!vis[nbr])
            {
                pair<int, long long> t = dfs(nbr, adj, vis, seats);
                p = {p.first + t.first, p.second + t.second};
            }
        }
        p = {p.first + 1, p.second + p.first / seats + 1};
        return p;
    }
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {

        if (roads.size() == 0)
            return 0;

        unordered_map<int, vector<int>> adj;
        for (vector<int> vec : roads)
        {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        vector<bool> vis(adj.size(), false);

        pair<int, long long> p = {0, 0};
        vis[0] = true;
        for (int nbr : adj[0])
        {
            if (!vis[nbr])
            {
                pair<int, long long> t = dfs(nbr, adj, vis, seats);
                p = {p.first + t.first, p.second + t.second};
            }
        }
        return p.second;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> roads;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        roads.push_back({x, y});
    }
    int seats;
    cin >> seats;
    Solution sln;
    cout << sln.minimumFuelCost(roads, seats) << endl;
    return 0;
}