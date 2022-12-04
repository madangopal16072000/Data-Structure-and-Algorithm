#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> *adj = new vector<int>[n];

        int m = edges.size();
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++)
        {
            for(int nbr : adj[i])
            {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        vector<int> vis(n, false);
        vector<set<int>> parent(n, set<int>());
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int nbr : adj[node])
            {
                indegree[nbr]--;
                
                for(auto e : parent[node])
                {
                    parent[nbr].insert(e);
                }
                parent[nbr].insert(node);
                if(indegree[nbr] == 0)
                q.push(nbr);
            }
        }
        vector<vector<int>> res;
        for(int i = 0; i < n; i++)
        {
            vector<int> row;
            for(int x : parent[i])
            {
                row.push_back(x);
            }
            res.push_back(row);
        }
        return res;

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
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    Solution sln;
    vector<vector<int>> ans = sln.getAncestors(n, edges);

    for(vector<int> row : ans)
    {
        for(int x : row)
        cout << x << " ";
        cout << endl;
    }
    return 0;
}