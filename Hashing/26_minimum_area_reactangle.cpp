#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        int n = points.size();

        unordered_map<int, vector<int>> mp;

        for(auto vec : points)
        {
            mp[vec[0]].push_back(vec[1]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if(x1 == x2 || y1 == y2)
                continue;

                bool first = false, second = false;
                for(int x : mp[x1])
                {
                    if(x == y2)
                    {
                        first = true;
                    }
                }

                for(int x : mp[x2])
                {
                    if(x == y1)
                    {
                        second = true;
                    }
                }

                if(first && second)
                {
                    ans = min(ans, abs(x1-x2)*abs(y1-y2));
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
  
  int n;
  cin >> n;
  vector<vector<int>> points;
  for(int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    points.push_back({x, y});
  }

  Solution sln;
  cout << sln.minAreaRect(points) << endl;
  return 0;
}