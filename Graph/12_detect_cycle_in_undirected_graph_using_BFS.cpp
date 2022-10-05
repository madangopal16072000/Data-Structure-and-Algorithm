#include <bits/stdc++.h>
using namespace std;

class Graph
{
    bool bfs(int src, vector<int> adj[], int vis[])
    {
        queue<pair<int, int>> q;
        q.push({src, -1});

        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(int nbr : adj[node])
            {
                if(!vis[nbr])
                {
                    vis[nbr] = 1;
                    q.push({nbr, node});
                }
                else
                {
                    if(nbr != parent)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public:
    bool detectCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(bfs(i, adj, vis))
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
    vector<int> *adj = new vector<int>[V];
    int E;
    cin >> E;
    for(int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    Graph g;
    cout << g.detectCycle(V, adj) << endl;
    return 0;
}