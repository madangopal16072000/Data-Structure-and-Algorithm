#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int src, vector<bool> &vis, vector<int> adj[], stack<int> &st, vector<bool> &pathVis)
    {
        vis[src] = true;
        pathVis[src] = true;

        for(int nbr : adj[src])
        {
            if(!vis[nbr])
            {
                if(dfs(nbr, vis, adj, st, pathVis))
                return true;

            }
            else if(pathVis[nbr])
            return true;
        }
        pathVis[src] = false;
        st.push(src);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> *adj = new vector<int>[numCourses];

        int n = prerequisites.size();
        for(int i = 0; i < n; i++)
        {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];

            adj[y].push_back(x);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        stack<int> st;

        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, adj, st, pathVis);
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        if(ans.size() == numCourses)
        return ans;
        else
        return {};
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
    int len;
    cin >> len;
    vector<vector<int>> pre;
    for(int i = 0; i < len; i++)
    {
        vector<int> row;
        int x, y;
        cin >> x >> y;
        row.push_back(x);
        row.push_back(y);
        pre.push_back(row);

    }
    Solution sln;
    vector<int> ans = sln.findOrder(n, pre);
    for(int x : ans)
    cout << x << " ";
    cout << endl;
    return 0;
}