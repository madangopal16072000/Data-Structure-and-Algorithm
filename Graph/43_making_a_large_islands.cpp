#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.reserve(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        size.resize(n + 1, 1);
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int parentU = find(u);
        int parentV = find(v);

        if (parentU == parentV)
            return;

        if (rank[parentU] < rank[parentV])
        {
            parent[parentU] = parentV;
        }
        else if (rank[parentU] > rank[parentV])
        {
            parent[parentV] = parentU;
        }
        else
        {
            parent[parentU] = parentV;
            rank[parentV]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int parentU = find(u);
        int parentV = find(v);

        if (parentU == parentV)
            return;

        if (size[parentU] < size[parentV])
        {
            parent[parentU] = parentV;
            size[parentV] = size[parentV] + size[parentU];
        }
        else
        {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};
class Solution
{
public:
    // Function to find the number of islands.
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n * m);
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {

                    for (int k = 0; k < 4; k++)
                    {
                        int r = drow[k] + i;
                        int c = dcol[k] + j;
                        if (r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == 1)
                        {
                            int nodeNo = i * m + j;
                            int adjNodeNo = r * m + c;
                            if (ds.find(nodeNo) != ds.find(adjNodeNo))
                            {
                                ds.unionBySize(nodeNo, adjNodeNo);
                            }
                        }
                    }
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < n * m; i++)
        {
            ans = max(ans, ds.size[i]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    set<int> st;
                    for(int k = 0; k < 4; k++)
                    {
                        int r = drow[k] + i;
                        int c = dcol[k] + j;
                        if(r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == 1)
                        {
                            int p = ds.find(r*m + c);
                            st.insert(p);
                        }
                    }
                    int temp = 1;
                    for(auto x : st)
                    {
                        temp = temp + ds.size[x];
                    }
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
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
    vector<vector<int>> grid;
    for (int i = 0; i < R; i++)
    {
        vector<int> row;
        for (int j = 0; j < C; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        grid.push_back(row);
    }

    Solution sln;
    cout << sln.largestIsland(grid) << endl;
    return 0;
}