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

bool compare(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), compare);
        sort(queries.begin(), queries.end(), compare);

        DisjointSet ds(n);
        vector<bool> ans;

        int e = edgeList.size();
        int q = queries.size();
        int j = 0;
        for(int i = 0; i < q; i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            int lmt = queries[i][2];

            
            while(j < e)
            {
                int u = edgeList[j][0];
                int v = edgeList[j][1];
                int wt = edgeList[j][2];

                if(wt < lmt)
                {
                    j++;
                    ds.unionBySize(u, v);
                }
                else
                {
                    break;
                }
            }

            if(ds.find(x) == ds.find(y))
            {
                ans.push_back(true);
            }
            else
            ans.push_back(false);
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
  int n;
  cin >> n;
  int e;
  cin >> e;
  vector<vector<int>> edgeList;
  for(int i = 0; i < e; i++)
  {
    int x, y, wt;
    cin >> x >> y >> wt;
    edgeList.push_back({x, y, wt});
  }

  int q;
  cin >> q;
  vector<vector<int>> queries;
  for(int i = 0; i < q; i++)
  {
    int x, y, wt;
    cin >> x >> y >> wt;
    queries.push_back({x, y, wt});
  }

  Solution sln;
  vector<bool> ans = sln.distanceLimitedPathsExist(n, edgeList, queries);
  for(bool x : ans)
  cout << x << " ";

  return 0;
}