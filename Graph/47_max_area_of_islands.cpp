#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n+1, 0);
        for(int i = 0; i <= n; i++)
        parent[i] = i;

        size.resize(n+1, 1);
    }

    int find(int node)
    {
        if(node == parent[node])
        return node;
        
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int parentU = find(u);
        int parentV = find(v);

        if(parentU == parentV)
        return;

        if(size[parentU] < size[parentV])
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
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        DisjointSet ds(n*m);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    int drow[] = {-1, 0, 1, 0};
                    int dcol[] = {0, 1, 0, -1};
                    for(int k = 0; k < 4; k++)
                    {
                        int r = drow[k] + i;
                        int c = dcol[k] + j;
                        int node = i*m + j;
                        int adjNode = r*m + c;
                        if(r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == 1 && ds.find(node) != ds.find(adjNode))
                        {
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    int node = i*m + j;
                    ans = max(ans, ds.size[node]);
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid;
  for(int i = 0; i < n; i++)
  {
    vector<int> row;
    for(int j = 0; j < m; j++)
    {
        int d;
        cin >> d;
        row.push_back(d);
    }
    grid.push_back(row);
  }
  Solution sln;
  cout << sln.maxAreaOfIsland(grid) << endl;
  return 0;
}