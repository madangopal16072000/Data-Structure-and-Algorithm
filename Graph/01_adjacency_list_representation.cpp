#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
        int V;
        list<int> *l;

    public:
        Graph(int V)
        {
            this->V = V;
            l = new list<int>[V];
        }
        void addEdge(int x, int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void display()
        {
            for(int i = 0; i < V; i++)
            {
                cout << "Vertex " << i << "-->";
                for(int nbr : l[i])
                {
                    cout << nbr << " ";
                }
                cout << endl;
            }
        }
};
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
  #endif
  
  int V;
  cin >> V;
  Graph g(V);
  int E;
  cin >> E;
  for(int i = 0; i < E; i++)
  {
    int x, y;
    cin >> x >> y;
    g.addEdge(x, y);
  }

  g.display();
  return 0;
}