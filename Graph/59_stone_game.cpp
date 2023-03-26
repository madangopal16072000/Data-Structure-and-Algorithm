#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis, int n)
    {
        vis[node] = true;
        pathVis[node] = true;
        for (int nbr : adj[node])
        {
            if (nbr >= n || nbr < 0)
                continue;

            if (!vis[nbr])
            {
                if (dfs(nbr, adj, vis, pathVis, n))
                    return true;
            }
            else if (pathVis[nbr] == true)
            {
                return true;
            }
        }
        pathVis[node] = false;
        return false;
    }
    int goodStones(int n, vector<int> &arr)
    {
        // Code here

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {
            adj[i].push_back(arr[i] + i);
        }

        vector<bool> vis(n, false);
        vector<bool> pathVis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, pathVis, n);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (pathVis[i] == false)
                cnt++;
        }
        return cnt;
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
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        arr.push_back(d);
    }
    Solution sln;
    cout << sln.goodStones(n, arr) << endl;
    return 0;
}