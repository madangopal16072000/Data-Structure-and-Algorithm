#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool helper(int i, int j, string s1, string s2)
    {
        // base case
        if(i == j)
        {
            return s1[i] == s2[j];
        }

        // recursive case
        for(int k = i; k < j; k++)
        {
            string swapStr = s1.substr(k+1, j-(k+1) + 1) + s1.substr(i, k-i+1); 
            bool swap = helper(k+1, j, s1, s2) + helper(i, k, s1, s2);
            string noSwapStr = s1.substr(i, k-i+1) + s1.substr(k+1, j-(k+1)+1);
            bool noSwap = helper(i, k, s1, s2) + helper(k+1, j, s1, s2);
            string str = s2.substr(i, j-i+1);
            if(swap)
            {
                
            }
            else if(noSwap)
            {

            }
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 != len2)
        return false;

        return helper(0, len1-1, s1, s2);


    }
};
int main()
{
    string s1 = "great";
    string s2 = "rgeat";
    Solution s;
    cout << s.isScramble(s1, s2) << endl;
    return 0;
}