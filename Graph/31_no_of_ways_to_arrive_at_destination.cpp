#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
class Solution {
public:
    long long countPaths(long long n, vector<vector<long long>>& roads) {
        vector<vector<pair<long long, long long>>> adj(n);
        long long m = roads.size();
        for(long long i = 0; i < m; i++)
        {
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<long long> dp(n, 0);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, 1e18);
        pq.push({0, 0});
        dist[0] = 0;
        dp[0] = 1;
        while(!pq.empty())
        {
            long long d = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for(pair<long long, long long> p : adj[node])
            {
                long long nbr = p.first;
                long long w = p.second;
                if(d + w < dist[nbr])
                {
                    dist[nbr] = d + w;
                    pq.push({dist[nbr], nbr});
                    dp[nbr] = dp[node]%M;
                }
                else if(d + w == dist[nbr])
                {
                    dp[nbr] = (dp[nbr] + dp[node])%M;
                }
            }
        }
        return dp[n-1]%M;
    }
};
long long main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  vector<vector<long long>> roads;
  for(long long i = 0; i < m; i++)
  {
    long long u, v, w;
    cin >> u >> v >> w;
    roads.push_back({u, v, w});
  }
  Solution sln;
  cout << sln.countPaths(n, roads) << endl;
  return 0;
}