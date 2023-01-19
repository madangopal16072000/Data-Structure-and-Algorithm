#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i, string temp, string s, vector<int> &dp)
    {
        if(i == s.size())
        return 0;

        if(dp[i] != -1)
        return dp[i];

        int op1, op2;
        op1 = op2 = INT_MAX;

        if(i > 0 && temp[i-1] == '1')
        {
            if(s[i] == '1')
            {
                op2 = f(i+1, temp + '1', s, dp);
            }
            else
            {
                op2 = 1 + f(i+1, temp + '1', s, dp);
            }
        }
        else
        {
            if(s[i] == '0')
            {
                op1 = f(i+1, temp + '0', s, dp);
            }
            else
            {
                op1 = 1 + f(i+1, temp + '0', s, dp);
            }

            if(s[i] == '1')
            {
                op2 = f(i+1, temp + '1', s, dp);
            }
            else
            {
                op2 = 1 + f(i+1, temp + '1', s, dp);
            }
        }


        return dp[i] = min(op1, op2);
    }
    int minFlipsMonoIncr(string s) {

        int n = s.size();
        int i = 0;
        string temp = "";
        while(i < n && s[i] == '0')
        {
            temp = temp + s[i];
            i++;
        }   

        vector<int> dp(n, -1);
        return f(i, temp, s, dp);
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
  cout << sln.minFlipsMonoIncr(s) << endl;
  return 0;
}