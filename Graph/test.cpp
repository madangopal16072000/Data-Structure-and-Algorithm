#include <bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<int, list<int>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }
    int bfs(int src, int dest)
    {
        unordered_map<int, int> dist;
        queue<int> q;

        for (auto nodePair : l)
        {
            int node = nodePair.first;
            for (int nbr : l[node])
                dist[nbr] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int nbr : l[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }
        return dist[dest];
    }
};
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> temp(n * n+1, 0);
        int k = 1;
        bool isOdd = true;

        for (int i = n - 1; i >= 0; i--)
        {
            if (isOdd)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] != -1)
                    {
                        temp[k] = board[i][j] - k;
                    }
                    k++;
                }
            }

            if (!isOdd)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (board[i][j] != -1)
                    {
                        temp[k] = board[i][j] - k;
                    }
                    k++;
                }
            }
            isOdd = !isOdd;
        }
        Graph g;
        for (int i = 1; i <= n * n; i++)
        {
            for (int dice = 1; dice <= 6; dice++)
            {
                int j = i + dice;
                if(j > n*n)
                break;
                
                j = j + temp[j];
                if (j <= n*n)
                {
                    g.addEdge(i, j);
                }
            }
        }
        g.addEdge(n*n, n*n);
        return g.bfs(1, n * n);
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
    vector<vector<int>> board;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        board.push_back(row);
    }

    Solution sln;
    cout << sln.snakesAndLadders(board);
    return 0;
    return 0;
}