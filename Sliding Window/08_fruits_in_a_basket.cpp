#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {

        unordered_map<int, int> mp;
        int n = fruits.size();
        int ans = INT_MIN;
        int i = 0;
        int j = 0;
        while (j < n)
        {
            mp[fruits[j]]++;

            while (i < j && mp.size() > 2)
            {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0)
                {
                    mp.erase(mp[fruits[i]]);
                }

                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
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
    int n;
    cin >> n;
    vector<int> fruits;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        fruits.push_back(d);
    }

    Solution sln;
    cout << sln.totalFruit(fruits) << endl;
    return 0;
}