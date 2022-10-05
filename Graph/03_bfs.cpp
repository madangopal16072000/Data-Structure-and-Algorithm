#include<bits/stdc++.h>
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

    void bfs(T src)
    {
        queue<T> q;
        unordered_map<T, bool> visited;
        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";

            for(T nbr : l[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
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
  for(int i = 0; i < E; i++)
  {
    int x, y;
    cin >> x >> y;
    g.addEdge(x, y);
  }

  g.bfs(0);
  return 0;
}