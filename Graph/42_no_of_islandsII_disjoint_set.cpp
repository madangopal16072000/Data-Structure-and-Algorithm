#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    vector<vector<int>> size;
    vector<vector<pair<int, int>>> parent;
    DisjointSet(int R, int C)
    {
        size.resize(R, vector<int>(C, 1));
        for(int i = 0; i < R; i++)
        {
            vector<pair<int, int>> row;
            for(int j = 0; j < C; j++)
            {
                row.push_back({i, j});
            }
            parent.push_back(row);
        }
    }
    
    pair<int, int> find(int r, int c)
    {
        if(r == parent[r][c].first && c == parent[r][c].second)
        return {r, c};
        
        return parent[r][c] = find(parent[r][c].first, parent[r][c].second);
    }
    
    void unionBySize(int r, int c, int x, int y)
    {
        pair<int, int> parR = find(r, c);
        pair<int, int> parX = find(x, y);
        
        if(parR == parX)
        return;
        
        if(size[parR.first][parR.second] < size[parX.first][parX.second])
        {
            parent[parR.first][parR.second] = parX;
            size[parX.first][parX.second] += size[parR.first][parR.second];
        }
        else
        {
            parent[parX.first][parX.second] = parR;
            size[parR.first][parR.second] += size[parX.first][parX.second];
        }
    }
};
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n, m);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
                    int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
                    
                    for(int k = 0; k < 8; k++)
                    {
                        int r = i + drow[k];
                        int c = j + dcol[k];
                        
                        if(r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == '1' && ds.find(r, c) != ds.find(i, j))
                        {
                            ds.unionBySize(r, c, i, j);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1' && ds.parent[i][j].first == i && ds.parent[i][j].second == j)
                {
                    ans++;
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
  vector<vector<char>> grid;
  for(int i = 0; i < R; i++)
  {
    vector<char> row;
    for(int j = 0; j < C; j++)
    {
        char d;
        cin >> d;
        row.push_back(d);
    }
    grid.push_back(row);
  }
  Solution sln;
  cout << sln.numIslands(grid) << endl;
  return 0;
}