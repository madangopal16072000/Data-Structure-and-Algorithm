#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    private:
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        parent.reserve(n+1);
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

    void unionByRank(int u, int v)
    {
        int parentU = find(u);
        int parentV = find(v);

        if(parentU == parentV)
        return;

        if(rank[parentU] < rank[parentV])
        {
            parent[parentU] = parentV;
        }
        else if(rank[parentU] > rank[parentV])
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        vector<int> ans;

        for(vector<int> vec : operators)
        {
            int row = vec[0];
            int col = vec[1];

            if(vis[row][col])
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = true;
            cnt++;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++)
            {
                int r = drow[k] + row;
                int c = dcol[k] + col;

                if(r < n && r >= 0 && c < m && c >= 0 && vis[r][c] == true && ds.find(r*m + c) != ds.find(row*m + col))
                {
                    cnt--;
                    ds.unionBySize(r*m+c, row*m+col);
                }
            }
            ans.push_back(cnt);
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
  int k;
  cin >> k;
  vector<vector<int>> operators;
  for(int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x >> y;
    operators.push_back({x, y});
  }

  Solution sln;
  vector<int> ans = sln.numOfIslands(R, C, operators);
  for(int x : ans)
  cout << x << " ";

  return 0;
}