#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int> (n, 0));
    int start = 0;
    int maxLength = 1;
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for(int i = 0; i < n-1; i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of subsing from
            // starting index i and length k
            int j = i + k - 1;
 
            // checking for sub-sing from ith index to
            // jth index iff s[i+1] to s[j-1] is a
            // palindrome
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
 
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    return s.substr(start, maxLength);
}
int main()
{
    string s;
    s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;
}