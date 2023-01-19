#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<pair<int, pair<int, int>>> vec;
        for(int i = 0; i < tasks.size(); i++)
        {
          vec.push_back({tasks[i][1], {i, tasks[i][0]}});
        }
        sort(vec.begin(), vec.end());
        int n = vec.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({vec[0].first, {vec[0].second.first, vec[0].second.second}});
        int timer = vec[0].second.second;

        vector<int> ans;
        int i = 1;
        while(!pq.empty())
        {
            int idx = pq.top().second.first;
            int endtime = pq.top().first + pq.top().second.second;

            pq.pop();
            timer = endtime;
            ans.push_back(idx);

            while(pq.empty() && i < n && vec[i].second.second > timer)
            {
                timer++;
            }

            while(i < n && vec[i].second.second <= timer)
            {
                pq.push({vec[i].first, {vec[i].second.first, vec[i].second.second}});
                i++;
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
  
  vector<vector<int>> vec;

  int n;
  cin >> n;
  for(int i = 0;  i < n; i++)
  {
    vector<int> task;
    for(int j = 0; j < 2; j++)
    {
      int d;
      cin >> d;
      task.push_back(d);
    }
    vec.push_back(task);
  }

  Solution sln;
  
  vector<int> ans = sln.getOrder(vec);
  for(int x : ans)
  {
    cout << x << " ";
  }
  return 0;
}