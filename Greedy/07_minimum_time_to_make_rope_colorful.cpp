#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();
        int ans = 0;
        int i = 0;
        int j = 1;
        while (i < n - 1 && j < n)
        {
            if (colors[i] == colors[j])
            {
                while (colors[i] == colors[j])
                {
                    if (neededTime[i] < neededTime[j])
                    {
                        ans = ans + neededTime[i];
                        i = j;
                        j++;
                    }
                    else
                    {
                        ans = ans + neededTime[j];
                        j++;
                    }
                }
            }
            else
            {
                i = j; 
                j++;
            }
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
    string colors;
    cin >> colors;
    vector<int> neededTime;
    int n = colors.length();
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        neededTime.push_back(d);
    }
    Solution sln;
    cout << sln.minCost(colors, neededTime) << endl;
    return 0;
}