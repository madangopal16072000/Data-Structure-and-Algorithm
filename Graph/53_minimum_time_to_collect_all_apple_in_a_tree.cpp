#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        

        vector<vector<int>> adj(n);
        for(auto vec : edges)
        {
            int x = vec[0];
            int y = vec[1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> vis(n, 0);
        vector<int> dist(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int nbr : adj[node])
            {
                if(vis[nbr] == 0)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    vis[nbr] = 1;
                }
            }
        }

        cout << endl;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(hasApple[i])
            {
                ans = ans + dist[i];
            }
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
  
  int n;
  cin >> n;
  int e;
  cin >> e;
  vector<vector<int>> edges;
  for(int i = 0; i < e; i++)
  {
    int x, y;
    cin >> x >> y;
    edges.push_back({x, y});
  }
  vector<bool> hasApple = {false, false, true, false, true, true, false};

  Solution sln;
  cout << sln.minTime(n, edges, hasApple) << endl;
  return 0;
}