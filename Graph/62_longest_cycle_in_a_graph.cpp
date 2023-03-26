#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<int> &edges, vector<bool> &visited, vector<bool> &pathVis, vector<int> size, int &ans)
    {
        visited[node] = true;
        pathVis[node] = true;

        if (edges[node] != -1)
        {
            if (!visited[edges[node]])
            {
                size[edges[node]] = size[node] + 1;
                dfs(edges[node], edges, visited, pathVis, size, ans);
            }
            else if (pathVis[edges[node]])
            {
                ans = max(ans, size[node] - size[edges[node]] + 1);
            }
        }

        pathVis[node] = false;
    }
    int longestCycle(vector<int> &edges)
    {

        int n = edges.size();
        vector<bool> visited(n, false);
        vector<bool> pathVis(n, false);

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<int> size(n, 0);
                size[i] = 1;
                dfs(i, edges, visited, pathVis, size, ans);
            }
        }

        return ans == INT_MIN ? -1 : ans;
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
    vector<int> edges;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        edges.push_back(d);
    }

    Solution sln;
    cout << sln.longestCycle(edges) << endl;
    return 0;
}