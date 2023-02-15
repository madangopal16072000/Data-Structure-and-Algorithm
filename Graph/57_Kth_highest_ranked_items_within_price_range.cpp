#include <bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(vector<int> &v1, vector<int> &v2)
    {
        if (v1[0] == v2[0])
        {
            if (v1[1] == v2[1])
            {
                if (v1[2] == v2[2])
                {
                    return v1[3] < v2[3];
                }
                return v1[2] < v2[2];
            }
            return v1[1] < v2[1];
        }
        return v1[0] < v2[0];
    }
};
class Solution
{
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {

        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {start[0], start[1]}});
        vis[start[0]][start[1]] = true;
        while (!q.empty())
        {
            int step = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;

            q.pop();
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int r = drow[i] + x;
                int c = dcol[i] + y;

                if (r < m && r >= 0 && c < n && c >= 0 && vis[r][c] == 0 && grid[r][c] != 0)
                {
                    vis[r][c] = true;
                    q.push({step + 1, {r, c}});

                    if (grid[r][c] == 1 || grid[r][c] > pricing[1] || grid[r][c] < pricing[0])
                        continue;

                    pq.push({step + 1, grid[r][c], r, c});

                    if (pq.size() > k)
                    {
                        pq.pop();
                    }
                }
            }
        }
        vector<vector<int>> ans;
        while (pq.size() > 0)
        {
            vector<int> vec = pq.top();
            pq.pop();
            ans.push_back({vec[2], vec[3]});
        }
        reverse(ans.begin(), ans.end());
        return ans;
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

    vector<int> start;
    int s, e;
    cin >> s >> e;
    start.push_back(s);
    start.push_back(e);

    int l, h;
    cin >> l >> h;
    vector<int> pricing;
    pricing.push_back(l);
    pricing.push_back(h);

    int k;
    cin >> k;
    Solution sln;

    vector<vector<int>> ans = sln.highestRankedKItems(grid, pricing, start, k);
    return 0;
}