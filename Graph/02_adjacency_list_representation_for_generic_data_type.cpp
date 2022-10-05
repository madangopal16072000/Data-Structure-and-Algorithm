#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
        unordered_map<string, list<pair<string, int>>> l;
    public:
        void addEdge(string x, string y, bool bidir, int wt)
        {
            l[x].push_back(make_pair(y, wt));
            if(bidir)
            {
                l[y].push_back(make_pair(x, wt));
            }
        }

        void printList()
        {
            for(pair<string, list<pair<string, int>>> p: l)
            {
                string city = p.first;
                cout << city << " --> ";
                list<pair<string, int>> nbrs = p.second;
                for(pair<string, int> nbr : nbrs)
                {
                    string dest = nbr.first;
                    int dist = nbr.second;
                    cout << "( " << dest << ", " << dist << " )";
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
  Graph g;
  int E;
  cin >> E;
  for(int i = 0; i < E; i++)
  {
    string x, y;
    bool bidir;
    int wt;
    cin >> x >> y >> bidir >> wt;
    g.addEdge(x, y, bidir, wt);
  }
  g.printList();
  return 0;
}