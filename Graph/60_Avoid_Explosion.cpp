#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent.push_back(i);
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int parU = find(u);
        int parV = find(v);

        if (parU == parV)
            return;

        if (size[parU] < size[parV])
        {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else
        {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
};
class Solution
{
public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m)
    {

        DisjointSet ds(max(n, m));
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            ds.unionBySize(mix[i][0], mix[i][1]);
            int j = 0;
            for (; j < m; j++)
            {
                int x = danger[j][0];
                int y = danger[j][1];

                if (ds.find(x) == ds.find(y))
                {
                    ans.push_back("No");
                    break;
                }
            }

            if (j == m)
            {
                ans.push_back("Yes");
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mix, danger;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mix.push_back({x, y});
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        danger.push_back({x, y});
    }
    Solution sln;
    vector<string> ans = sln.avoidExplosion(mix, n, danger, m);
    for (string s : ans)
        cout << s << endl;
    return 0;
}