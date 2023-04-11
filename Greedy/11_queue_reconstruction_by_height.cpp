#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int n = people.size();
        sort(people.begin(), people.end());
        vector<vector<int>> ans(n, {-1, -1});

        for (vector<int> p : people)
            cout << p[0] << " " << p[1] << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = people[i][1]; j < n; j++)
            {
                if (ans[j][0] == -1 && ans[j][1] == -1)
                {
                    ans[j] = {people[i][0], people[i][1]};
                    break;
                }
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

    int n;
    cin >> n;
    vector<vector<int>> people;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        people.push_back({x, y});
    }

    Solution sln;
    vector<vector<int>> ans = sln.reconstructQueue(people);
    for (vector<int> vec : ans)
        cout << vec[0] << " " << vec[1] << endl;
    return 0;
}