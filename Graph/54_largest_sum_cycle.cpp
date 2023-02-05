#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, int parent, vector<bool> &vis, vector<int> Edge, long long sum, long long &maxi)
    {
        vis[node] = true;

        sum = sum + node;
        int nbr = Edge[node];

        if (nbr != -1 && !vis[nbr])
        {
            dfs(nbr, node, vis, Edge, sum, maxi);
        }
        else if (nbr != -1 && nbr != parent)
        {
            maxi = max(maxi, sum);
        }

        vis[node] = false;
    }
    long long largestSumCycle(int N, vector<int> Edge)
    {
        // code here

        vector<bool> vis(N, false);
        long long maxi = INT_MIN;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i] && Edge[i] != -1)
            {
                long long sum = 0;
                dfs(i, -1, vis, Edge, sum, maxi);
            }
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int N;
    cin >> N;
    vector<int> Edge;
    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        Edge.push_back(d);
    }
    Solution sln;
    cout << sln.largestSumCycle(N, Edge) << endl;
    return 0;
}