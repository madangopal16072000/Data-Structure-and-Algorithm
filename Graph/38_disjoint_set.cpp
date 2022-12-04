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
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  
  DisjointSet ds(7);
  ds.unionBySize(1, 2);
  ds.unionBySize(2, 3);
  ds.unionBySize(4, 5);
  ds.unionBySize(6, 7);
  ds.unionBySize(5, 6);

  if(ds.find(3) == ds.find(7))
  cout << "same" << endl;
  else
  cout << "different" << endl;

  ds.unionBySize(3, 7);
  if(ds.find(3) == ds.find(7))
  cout << "same" << endl;
  else
  cout << "different" << endl;
  return 0;
}

// TC : O(4alfa)