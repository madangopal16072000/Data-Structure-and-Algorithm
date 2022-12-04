#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for(int i = 0; i < V; i++)
        {
            for(auto vec : edges)
            {
                int u = vec[0];
                int v = vec[1];
                int w = vec[2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        for(auto vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            if(dist[u] != 1e8 && dist[u] + w < dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  
  return 0;
}