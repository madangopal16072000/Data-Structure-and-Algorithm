#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
    public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
    }
    bool dfs(int src, int vis[], int pathVis[])
    {
        vis[src] = 1;
        pathVis[src] = 1;

        for(int nbr : adj[src])
        {
            if(!vis[nbr])
            {
                if(dfs(nbr,vis, pathVis))
                return true;
            }
            else if(pathVis[nbr])
            {
                return true;
            }
        }
        pathVis[src] = 0;
        return false;
    }
    bool isCycle()
    {
        int vis[V] = {0};
        int pathVis[V] = {0};

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, vis, pathVis))
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
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for(int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }

    cout << g.isCycle() << endl;
    return 0;
}