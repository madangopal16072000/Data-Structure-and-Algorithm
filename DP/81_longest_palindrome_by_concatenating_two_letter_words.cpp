#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
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
  vector<string> words;
  for(int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    words.push_back(s);
  }
  Solution sln;
  cout << sln.longestPalindrome(words) << endl;
  return 0;
}