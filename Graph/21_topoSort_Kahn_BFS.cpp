#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>> adj)
{
    int V = adj.size();
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++)
    {
        for(int nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
        q.push(i);
    }

    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int nbr : adj[node])
        {
            indegree[nbr]--;
            if(indegree[nbr] == 0)
            q.push(nbr);
        }
    }
    return topo;
}
int main()
{
    vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    vector<int> ans = topoSort(adj);
    for(int x : ans)
    cout << x << " ";
    return 0;
}