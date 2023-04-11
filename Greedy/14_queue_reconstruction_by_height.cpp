#include <bits/stdc++.h>
using namespace std;
class compare
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
        {
            return a[0] <= b[0];
        }
        else
        {
            return a[1] < b[1];
        }
    }
};
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {

        sort(people.begin(), people.end(), compare());

        int n = people.size();
        list<pair<int, int>> lst;
        ;
        for (int i = 0; i < n; i++)
        {
            auto it = lst.begin();
            int h = people[i][0];
            int k = people[i][1];

            while (it != lst.end() && (k || it->first <= h))
            {
                advance(it, 1);
                k--;
            }
            lst.insert(it, {people[i][0], people[i][1]});
        }

        vector<vector<int>> ans;
        for (pair<int, int> p : lst)
        {
            ans.push_back({p.first, p.second});
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