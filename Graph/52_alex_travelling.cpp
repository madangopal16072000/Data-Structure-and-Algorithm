#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int, int>> adj[n+1];
        for(auto vec : flights)
        {
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(n+1, INT_MAX);
        
        pq.push({0, k});
        dist[k] = 0;
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            
            pq.pop();
            
            for(auto p : adj[node])
            {
                int nbr = p.first;
                int wt = p.second;
                
                if(d + wt < dist[nbr])
                {
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            ans += dist[i];
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
  vector<vector<int>> flights;
  int e, n, k;
  cin >> n >> k >> e;
  for(int i = 0; i < e; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> vec{x, y, z};
    flights.push_back(vec);
  }
  Solution sln;
  cout << sln.minimumCost(flights, n, k) << endl;
  return 0;
}