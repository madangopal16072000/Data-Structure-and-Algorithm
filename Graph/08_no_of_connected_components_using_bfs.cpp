#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;

        visited[src] = true;
        q.push(src);

        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            for (T nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    int connectedComponents()
    {
        unordered_map<T, bool> visited;
        for (auto p : l)
        {
            visited[p.first] = false;
        }
        int cnt = 0;
        for (auto p : l)
        {
            if (!visited[p.first])
            {
                cnt++;
                bfs(p.first, visited);
            }
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
    int E;
    cin >> E;
    Graph<int> g;
    for(int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }

    cout << g.connectedComponents() << endl;
    return 0;
}