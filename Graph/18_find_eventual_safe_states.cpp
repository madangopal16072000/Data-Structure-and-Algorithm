#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int src, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> graph, int safeNode[])
    {
        vis[src] = 1;
        pathVis[src] = 1;
        safeNode[src] = 0;

        for(int nbr : graph[src])
        {
            if(vis[nbr] == 0)
            {
                if(dfs(nbr, vis, pathVis, graph, safeNode)==true)
                return true;
            }
            else if(pathVis[nbr] == 1)
            return true;
        }
        pathVis[src] = 0;
        safeNode[src] = 1;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        int safeNode[V];
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, vis, pathVis, graph, safeNode);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++)
        {
            if(safeNode[i] == 1)
            ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    vector<vector<int>> graph = {{1,2},{2, 3}, {5}, {0}, {5}, {}, {}};

    Solution sln;
    vector<int> ans = sln.eventualSafeNodes(graph);
    for(int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}