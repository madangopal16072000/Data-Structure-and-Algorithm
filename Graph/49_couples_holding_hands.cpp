#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        
        int m = row.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++)
        mp[row[i]] = i;

        queue<pair<int, int>> q;
        q.push({row[0], 0});
        int ans = 0;
        while(!q.empty())
        {
            int node = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(idx == m-1)
            break;
            
            if(idx % 2 == 1)
            {
                q.push({row[idx+1], idx+1});
                continue;
            }

            int step = 0;
            if(node % 2 == 0)
            {
                step = 1;
            }
            else
            {
                step = -1;
            }

            if(mp[node + step] != idx + 1)
            {
                int nbr = row[idx+1];
                swap(row[mp[node + step]], row[idx + 1]);
                int temp = mp[node+step];
                mp[node+step] = idx + 1;
                mp[nbr] = temp;
                ans++;
            }
            q.push({row[idx+1], idx+1});
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
  vector<int> row;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    row.push_back(d);
  }
  Solution sln;
  cout << sln.minSwapsCouples(row) << endl;
  return 0;
}