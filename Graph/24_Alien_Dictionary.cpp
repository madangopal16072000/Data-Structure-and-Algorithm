#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void dfs(char src, unordered_map<char, bool> &vis, unordered_map<char, vector<char>> &mp, stack<char> &st)
    {
        vis[src] = true;
        
        for(char nbr : mp[src])
        {
            if(!vis[nbr])
            dfs(nbr, vis, mp, st);
        }
        st.push(src);
        return;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map<char, bool> vis;
        for(int i = 97; i < 97+K; i++)
        {
            vis[i] = false;
        }
        unordered_map<char, vector<char>> mp;
        for(int i = 1; i < N; i++)
        {
            if(dict[i][0] != dict[i-1][0])
            {
                mp[dict[i-1][0]].push_back(dict[i][0]);
            }
            else
            {
                int j = 1;
                while(dict[i][j] == dict[i-1][j])
                {
                    j++;
                }
                
                mp[dict[i-1][j]].push_back(dict[i][j]);
            }
        }
        
        stack<char> st;
        for(int i = 97; i < 97+K; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, mp, st);
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans = ans + st.top();
            st.pop();
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
    int N;
    cin >> N;
    string *dict = new string[N];
    int K;
    cin >> K;
    for(int i = 0; i < N; i++)
    {
        string d;
        cin >> d;
        dict[i] = d;
    }
    Solution sln;
    cout << sln.findOrder(dict, N, K) << endl;
    return 0;
}