#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, vector<int>> adj;
    int V;
    bool dfs(int src, int parent, int *vis)
    {
        vis[src] = 1;
        for (int x : adj[src])
        {
            if (!vis[x])
            {
                if (dfs(x, src, vis))
                    return true;
            }
            else if (parent != x)
                return true;
        }
        return false;
    }

    Graph(int V)
    {
        this->V = V;
    }
    bool isCycle()
    {
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int V;
    cin >> V;
    Graph g(V);

    int E;
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        g.adj[x].push_back(y);
        g.adj[y].push_back(x);
    }

    cout << g.isCycle() << endl;
    return 0;
}