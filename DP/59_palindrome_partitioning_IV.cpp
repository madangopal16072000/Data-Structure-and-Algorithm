#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int i, int j, string s)
    {
        while(i < j)
        {
            if(s[i] != s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    bool f(int i, int n, string s, int cnt, vector<vector<int>> dp)
    {
        // base case
        if(i > s.size()-1)
        return false;
        if(dp[i][cnt] != -1)
        return 0;

        if(cnt == 0)
        {
            if(isPalindrome(i, n, s))
            return dp[i][cnt] = true;
            else 
            return dp[i][cnt] = false;
        }


        // recursive case
        bool val = false;
        for(int k = i; k <= n; k++)
        {
            if(isPalindrome(i, k, s))
            {
                val = val || f(k+1, n, s, cnt-1, dp);
            }
        }
        return dp[i][cnt] = val;
    }
    bool checkPartitioning(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return f(0, n-1, s, 2, dp);      
    }
};
int main()
{
    string s = "abcbdd";
    Solution sln;
    cout << sln.checkPartitioning(s) << endl;
    return 0;
}