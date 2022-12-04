#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> mp = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}, {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}};
        
        int n = s.length();
        int i = 0, j = n-1;
        string ans = s;
        while(i < j)
        {
            if(mp.count(ans[i]) > 0 && mp.count(ans[j]) > 0)
            {
                swap(ans[i], ans[j]);
                i++;
                j--;
            }
            if(mp.count(ans[i]) < 1)
                i++;
            if(mp.count(ans[j]) < 1)
                j--;
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
  string s;
  cin >> s;
  Solution sln;
  cout << sln.reverseVowels(s) << endl;
  return 0;
}