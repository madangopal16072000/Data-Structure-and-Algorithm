#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    unordered_map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    void printList()
    {
        for(pair<T, list<T>> p : l)
        {
            T node = p.first;
            cout << node << " --> ";
            for(T nbr : l[node])
            {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
    void bfs(T src, T dest)
    {
        unordered_map<T, int> dist;
        queue<T> q;
        unordered_map<T, T> parent;
        for (pair<T, list<T>> p : l)
        {
            T node = p.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << "Distance of " << node << " From " << src << " is : " << dist[node] << endl;
            for (T nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                    parent[nbr] = node;
                }
            }
        }
        cout << "Distance : " << dist[dest] << endl;
        T temp = dest;
        while (parent[temp] != src)
        {
            cout << temp << " <-- ";
            temp = parent[temp];
        }
        cout << src << endl;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    Graph<int> g;
    vector<int> board;
    board.reserve(36);


    for (int i = 0; i < 36; i++)
    {
        int d;
        cin >> d;
        board.push_back(d);
    }

    for(int i = 0; i < 36; i++)
    {
        for(int dice = 1; dice <= 6; dice++)
        {
            int j = dice + i;
            j = j + board[j];

            if(j < 36)
            {
                g.addEdge(i, j);
            }
        }
    }
    g.printList();
    g.bfs(0, 35);
    return 0;
}