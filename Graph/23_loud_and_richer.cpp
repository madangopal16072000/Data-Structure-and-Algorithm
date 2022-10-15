#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int src, vector<int> adj[], vector<int> quiet, vector<int> &ans, vector<int>& vis, int mini, int idx)
    {
        vis[src] = true;
        if(mini > quiet[src])
        {
            mini = quiet[src];
            idx = src;
        }
        for(int nbr : adj[src])
        {
            if(!vis[nbr])
            {
                dfs(nbr, adj, quiet, ans, vis, mini, idx);
            }
        }
        if(quiet[ans[src]] > quiet[idx])
        ans[src] = idx;

        return;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
        int V =  quiet.size();
        int n = richer.size();
        vector<int> *adj = new vector<int>[V];
        for(vector<int> row : richer)
        {
            adj[row[0]].push_back(row[1]);
        }
        vector<int> ans;
        for(int i = 0; i < V; i++)
        {
            ans.push_back(i);
        }
        for(int i = 0; i < V; i++)
        {
            vector<int> vis(V, false);
            int mini = quiet[i];
            int idx = i;
            dfs(i, adj, quiet, ans, vis, mini, idx);
        }
        return ans;
        
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  vector<vector<int>> richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
  vector<int> quiet = {3,2,5,4,6,1,7,0};
  Solution sln;
  vector<int> ans = sln.loudAndRich(richer, quiet);
  for(int x : ans)
  cout << x << " ";
  return 0;
}