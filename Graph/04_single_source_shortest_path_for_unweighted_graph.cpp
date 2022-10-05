#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    unordered_map<T, list<T>>l;
    public:
        void addEdge(int x, int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void bfs(T src)
        {
            unordered_map<T, int> dist;
            queue<T> q;



            for(pair<T, list<T>> p : l)
            {
                T node = p.first;
                dist[node] = INT_MAX;
            }

            q.push(src);
            dist[src] = 0;

            while(!q.empty())
            {
                T node = q.front();
                q.pop();

                for(T nbr : l[node])
                {
                    if(dist[nbr] == INT_MAX)
                    {
                        q.push(nbr);
                        dist[nbr] = dist[node] + 1;
                    }
                }
            }

            for(auto node_pair : l)
            {
                T node = node_pair.first;
                cout << "Distance of node " << node << " From Source " << src << " : " << dist[node] << endl;
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