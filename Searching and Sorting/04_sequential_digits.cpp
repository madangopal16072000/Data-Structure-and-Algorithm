#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int low, int high, vector<int> &ans, int i, int num)
    {
        if (num > high || i > 10)
            return;

        if (num >= low && num <= high)
            ans.push_back(num);

        return;
    }
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        for (int i = 1; i < 10; i++)
        {
            dfs(low, high, ans, i, 0);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    return 0;
}