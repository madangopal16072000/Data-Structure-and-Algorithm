#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i = 0; i < m; i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        set<pair<int, int>> st;
        vector<int> dist(n+1, 1e9);
        st.insert({k, 0});
        dist[k] = 0;

        while(!st.empty())
        {
            auto it = *st.begin();
            int node = it.first;
            int d = it.second;
            st.erase(st.begin());

            for(auto p : adj[node])
            {
                int nbr = p.first;
                int w = p.second;
                if(d + w < dist[nbr])
                {
                    if(dist[nbr] != 1e9);
                    st.erase({nbr, dist[nbr]});

                    dist[nbr] = d + w;
                    st.insert({nbr, dist[nbr]});
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            ans = max(ans, dist[i]);
        }
        return ans == 1e9 ? -1 : ans;
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