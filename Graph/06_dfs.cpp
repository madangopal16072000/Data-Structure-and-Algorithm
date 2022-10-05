#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<T>> l;
    void dfs_helper(T src, unordered_map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs(T src)
    {
        unordered_map<T, bool> visited;

        for (auto p : l)
        {
            visited[p.first] = false;
        }

        dfs_helper(src, visited);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    Graph<int> g;
    int E;
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    g.dfs(0);
    return 0;
}