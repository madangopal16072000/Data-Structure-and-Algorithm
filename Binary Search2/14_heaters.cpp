#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    pair<int, int> binarySearch(vector<int> &houses, int k)
    {
        int l = -1;
        int h = -1;

        int i = 0;
        int j = houses.size() - 1;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;

            if (houses[mid] == k)
            {
                l = mid;
                h = mid;
                return {l, h};
            }
            else if (houses[mid] < k)
            {
                l = mid;
                i = mid + 1;
            }
            else
            {
                h = mid;
                j = mid - 1;
            }
        }

        return {l, h};
    }
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {

        int n = houses.size();
        sort(heaters.begin(), heaters.end());

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int h = houses[i];

            pair<int, int> p = binarySearch(heaters, h);

            int d1 = p.first == -1 ? INT_MIN : h - heaters[p.first];
            int d2 = p.second == -1 ? INT_MIN : heaters[p.second] - h;
            int minD = min(d1, d2);

            ans = max(ans, minD);
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
    vector<int> houses;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        houses.push_back(d);
    }
    vector<int> heaters;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int d;
        cin >> d;
        heaters.push_back(d);
    }
    Solution sln;
    cout << sln.findRadius(houses, heaters) << endl;

    return 0;
}