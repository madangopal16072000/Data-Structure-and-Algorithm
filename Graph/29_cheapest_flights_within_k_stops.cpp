#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < m; i++)
        {
            int x = flights[i][0];
            int y = flights[i][1];
            int d = flights[i][2];

            adj[x].push_back({y, d});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        q.push({0, {src, 0}});
        dist[src] = 0;

        while(!q.empty())
        {
            int step = q.front().first;
            int node = q.front().second.first;
            int d = q.front().second.second;
            q.pop();

            if(step > k)
            continue;

            for(pair<int, int> p : adj[node])
            {
                if(d + p.second < dist[p.first] && step <= k)
                {
                    dist[p.first] = d + p.second;
                    q.push({step + 1, {p.first, dist[p.first]}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
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
  int m;
  cin >> m;
  vector<vector<int>> flights;
  for(int i = 0; i < m; i++)
  {
    int x, y, d;
    cin >> x >> y >> d;
    flights.push_back({x, y, d});
  }
  int src, dst, k;
  cin >> src >> dst >> k;
  Solution sln;
  cout << sln.findCheapestPrice(n, flights, src, dst, k) << endl;

  return 0;
}