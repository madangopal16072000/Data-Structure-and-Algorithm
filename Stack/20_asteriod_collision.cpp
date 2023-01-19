#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for(int i = 0; i < n; i++)
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
            }
            else
            {
                bool dirA = asteroids[i] >= 0;

                while(!st.empty() &&  st.top() >= 0 != dirA && abs(st.top()) < abs(asteroids[i]))
                {
                    st.pop();
                }

                if(st.empty() || st.top() >= 0 == dirA)
                {
                    st.push(asteroids[i]);
                }
                else if(dirA != st.top() >= 0 && abs(st.top()) == abs(asteroids[i]))
                {
                    st.pop();
                }
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
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
  vector<int> asteroids;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    asteroids.push_back(d);
  }
  Solution sln;
  vector<int> ans = sln.asteroidCollision(asteroids);

  for(int x : ans)
  cout << x << " ";
  return 0;
}