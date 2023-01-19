#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
        sort(nums.begin(), nums.end());
        unordered_map<int, list<int>> mp;
        multiset<int> st;
        for(int x : nums)
        {
            st.insert(x);
            mp[x%k].push_back(x);
        }
        
        for(int x : st)
        {
            st.erase(x);
            mp[x%k].pop_front();
            
            if(x % k == 0)
            {
                if(mp[0].size() == 0)
                return false;

                st.erase(mp[0].back());
                mp[0].pop_back();
            }
            else
            {
                if(mp[k-x%k].size() == 0)
                return false;
                
                int cnt = st.erase(mp[k-x%k].back());
                cnt--;
                while(cnt--)
                {
                    st.insert(mp[k-x%k].back());
                }
                mp[k-x%k].pop_back();
            }
        }
        
        return true;
        
        
    }
};
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int n, k;
  cin >> n >> k;
  vector<int> nums;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    nums.push_back(d);
  }

  Solution sln;
  cout << sln.canPair(nums, k) << endl;
  return 0;
}