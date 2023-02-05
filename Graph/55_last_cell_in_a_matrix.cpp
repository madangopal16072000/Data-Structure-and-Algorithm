#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    pair<int, int> endPoints(vector<vector<int>> matrix, int R, int C)
    {
        // code here
        int x, y;
        x = y = 0;
        int i = 0;
        int j = 1;
        queue<pair<char, pair<int, int>>> q;

        if (i < R && j < C && i >= 0 && j >= 0)
            q.push({'R', {x + i, y + j}});

        while (!q.empty())
        {
            char dir = q.front().first;
            x = q.front().second.first;
            y = q.front().second.second;

            q.pop();
            char toMove = dir;

            if (dir == 'T')
            {
                i = -1;
                j = 0;
            }
            else if (dir == 'R')
            {
                i = 0;
                j = 1;
            }
            else if (dir == 'D')
            {
                i = 1;
                j = 0;
            }
            else
            {
                i = 0;
                j = -1;
            }

            if (matrix[x][y] == 1)
            {
                if (dir == 'R')
                {
                    toMove = 'D';
                    i = 1;
                    j = 0;
                }
                else if (dir == 'T')
                {
                    toMove = 'R';
                    i = 0;
                    j = 1;
                }
                else if (dir == 'D')
                {
                    toMove = 'L';
                    i = 0;
                    j = -1;
                }
                else
                {
                    toMove = 'T';
                    i = -1;
                    j = 0;
                }
            }

            if (i + x < R && j + y < C && i + x >= 0 && j + y >= 0)
            {
                q.push({toMove, {i + x, j + y}});
            }
        }
        return {x, y};
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int R, C;
    cin >> R >> C;
    vector<vector<int>> matrix;
    for (int i = 0; i < R; i++)
    {
        vector<int> row;
        for (int j = 0; j < C; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        matrix.push_back(row);
    }

    Solution sln;
    pair<int, int> p = sln.endPoints(matrix, R, C);
    cout << p.first << " " << p.second << endl;
    return 0;
}