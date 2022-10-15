#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string maxSum(string w, char x[], int b[], int n)
    {
        // code here
        unordered_map<char, int> mp;
        int len = w.length();
        for (int i = 0; i < n; i++)
        {
            mp[x[i]] = i;
        }
        int maxi = INT_MIN;
        int sum = 0;
        int sIdx, eIdx;
        sIdx = 0;
        int idx = 0;
        for (int i = 0; i < len; i++)
        {
            if (mp.count(w[i]))
                sum = sum + b[mp[w[i]]];
            else
                sum = sum + w[i];

            if (maxi < sum)
            {
                sIdx = idx;
                eIdx = i;
                maxi = sum;
            }

            if (sum < 0)
            {
                idx = i+1;
                sum = 0;
            }
        }
        return string(w.begin() + sIdx, w.begin() + eIdx + 1);
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
    // #endif
    string w = "oK";
    int n = 2;
    int b[] = {-880, 53};
    char x[] = {'K', 'o'};
    Solution sln;
    cout << sln.maxSum(w, x, b, n) << endl;
    return 0;
}