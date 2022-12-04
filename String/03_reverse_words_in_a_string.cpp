#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> vec;
        int i = 0;
        string res = "";
        while(i < n)
        {
            
            if(s[i] != ' ')
            {
                string ans = "";
                while(i < n && s[i] != ' ')
                {
                    ans = ans + s[i];
                    i++;
                }
                vec.push_back(ans);
            }
            else
            {
                i++;
            }
        }
        int m = vec.size();
        for(int i = m-1; i > 0; i--)
        {
            res = res + vec[i] + " ";
        }
        res = res + vec[0];
        return res;
        
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
  cout << sln.reverseWords("the sky is blue") << endl;
  return 0;
}