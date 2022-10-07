#include <bits/stdc++.h>
using namespace std;
class Graph
{
    private:
    bool dfs(int src, int col, vector<int> color, vector<int> adj[])
    {
        color[src] = col;
        for(int nbr : adj[src])
        {
            if(color[nbr] == -1)
            {
                if(dfs(nbr, !col, color, adj) == false)
                return false;
            }
            else if(color[nbr] == color[src])
            return false;
        }
        return true;
    }
    public:
    bool isBapartite(int V, vector<int> adj[])
    {
        vector<int> color(V+1, -1);
        for(int i = 1; i <= V; i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i, 0, color, adj) == false)
                return false;
            }
        }
        return true;
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
    vector<int> adj[V+1];
    for(int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    Graph g;
    cout << g.isBapartite(V, adj) << endl;
    return 0;
}