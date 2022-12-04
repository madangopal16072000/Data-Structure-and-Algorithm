#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj(n + 1);
        for (auto vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> freq(n + 1, 0);
        vector<int> dist(n + 1, 1e9);
        set<pair<int, int>> st;
        st.insert({0, 1});
        dist[1] = 0;
        freq[1] = 1;

        while (!st.empty())
        {
            auto it = *st.begin();
            int node = it.second;
            int ttime = it.first;
            st.erase(st.begin());
            bool flag = false;

            if ((ttime / change) % 2 == 1)
            {
                ttime = ttime + change;
            }

            for (int nbr : adj[node])
            {
                if (dist[nbr] != ttime + time && freq[nbr] < 2)
                {
                    if (nbr == n && flag)
                    {
                        return ttime + time;
                    }
                    if (nbr == n)
                    {
                        flag = !flag;
                    }
                    freq[nbr]++;
                    dist[nbr] = ttime + time;
                    st.insert({dist[nbr], nbr});
                }
            }
        }
        return -1;
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
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    int time, change;
    cin >> time >> change;

    Solution sln;
    cout << sln.secondMinimum(n, edges, time, change) << endl;
    return 0;
}