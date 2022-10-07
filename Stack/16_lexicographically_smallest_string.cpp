#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string lexicographicallySmallest(string S, int k) {
        // code here

        int n = S.length();
        if(n & (n-1))
        k = k*2;
        else
        k = k/2;

        string ans = "";
        for(int i = 0; i < n; i++)
        {
            while(k && !ans.empty() && ans.back() > S[i])
            {
                k--;
                ans.pop_back();
            }
            ans = ans + S[i];
        }

        while(k--)
        ans.pop_back();

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
    int k;
    cin >> s >> k;
    Solution sln;
    cout << sln.lexicographicallySmallest(s, k) << endl;
    return 0;
}