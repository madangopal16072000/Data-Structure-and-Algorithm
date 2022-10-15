#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>> mat)
    {
        unordered_map<int, vector<int>> graph;
        int n = mat.size();
        for(int i = 0; i < n; i++)
        {
            graph[mat[i][1]].push_back(mat[i][0]);
        }
        
        unordered_map<int, int> indegree;
        for(auto p : graph)
        {
            indegree[p.first] = 0;
            for(int x : p.second)
            {
                indegree[x]++;
            }
        }
        
        queue<int> q;
        for(auto p : indegree)
        {
            if(p.second == 0)
                q.push(p.first);
        }
        
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(int x : graph[node])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
            return topo;

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> row = topoSort(k, rowConditions);
        vector<int> col = topoSort(k, colConditions);
        
        vector<vector<int>> ans(k, vector<int>(k, 0));
        
        int rSize = row.size();
        int cSize = col.size();
        if(rSize != k || cSize != k)
        return {};

        vector<int> idx(k+1, 0);
        for(int i = 0; i < cSize; i++)
        {
            idx[col[i]] = i;
        }

        for(int i = 0; i < k; i++)
        {
            ans[i][idx[row[i]]] = row[i];
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
    int k;
    cin >> k;
    int r, c;
    cin >> r;
    vector<vector<int>> rowConditions;
    for(int i = 0; i < r; i++)
    {
        int x, y;
        cin >> x >> y;
        rowConditions.push_back({x, y});
    }
    cin >> c;
    vector<vector<int>> colConditions;
    for(int i = 0; i < c; i++)
    {
        int x, y;
        cin >> x >> y;
        colConditions.push_back({x, y});
    }

    Solution sln;
    vector<vector<int>> ans = sln.buildMatrix(k, rowConditions, colConditions);
    for(auto v : ans)
    {
        for(int x : v)
        cout << x << " ";
        cout << endl;
    }
    return 0;
}