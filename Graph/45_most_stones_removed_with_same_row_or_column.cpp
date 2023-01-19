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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = INT_MIN;
        int maxCol = INT_MIN;
        for(auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);


        unordered_map<int, int> mp;
        for(auto vec : stones)
        {
            int nodeRowNo = vec[0];
            int nodeColNo = maxRow + 1 + vec[1];
            mp[nodeRowNo] = 1;
            mp[nodeColNo] = 1;
            ds.unionBySize(nodeRowNo, nodeColNo);
        }

        int cnt = 0;
        for(auto p : mp)
        {
            if(ds.find(p.first) == p.first)
            {
                cnt++;
            }
        }

        return stones.size() - cnt;
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
  vector<vector<int>> stones;
  for(int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    stones.push_back({x, y});
  }

  Solution sln;
  cout << sln.removeStones(stones) << endl;
  return 0;
}