#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        unordered_map<char, int> mp;
        for(int i = 2; i <= n; i++)
        {
            string temp = "";
            int m = ans.size();
            
            int j = 0;
            while(j < m)
            {
                int cnt = 1;
                while(j+1 < m && ans[j] == ans[j+1])
                {
                    cnt++;
                    j++;
                }
                char ch = char(cnt+48);
                char c = ans[j];
                temp = temp + ch + c;
                j++;
            }
            ans = temp;
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
  Solution sln;
  cout << sln.countAndSay(n) << endl;
  return 0;
}