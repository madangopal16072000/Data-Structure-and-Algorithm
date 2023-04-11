#include <bits/stdc++.h>
using namespace std;
#define M 1000000
class Solution
{
public:
    int minimumVisitedCells(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0, 0}});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == m - 1 && y == n - 1)
            {
                return d;
            }

            for (int k = y + 1; k <= min(grid[x][y] + y, n - 1); k++)
            {
                if (dist[x][k] > d + 1)
                {
                    dist[x][k] = d + 1;
                    pq.push({dist[x][k], {x, k}});
                }
            }

            for (int k = x + 1; k <= min(grid[x][y] + x, m - 1); k++)
            {
                if (dist[k][y] > d + 1)
                {
                    dist[k][y] = d + 1;
                    pq.push({dist[k][y], {k, y}});
                }
            }
        }
        return -1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }

        grid.push_back(row);
    }

    Solution sln;
    cout << sln.minimumVisitedCells(grid) << endl;
    return 0;
}