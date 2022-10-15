#include <bits/stdc++.h>
using namespace std;
class compare
{
public:
    bool operator()(pair<int, int> const &p1, pair<int, int> const &p2)
    {
        return p1.second > p2.second;
    }
};
class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        int n = courses.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({courses[i][0], courses[i][1]});
        }

        int cnt = 0;
        int t = 0;
        while (!pq.empty())
        {

            if(pq.top().second - t >= pq.top().first)
            {
                cnt++;
                t = t + pq.top().first;
            }
            pq.pop();
        }
        return cnt;
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
    vector<vector<int>> courses;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vector<int> row;
        row.push_back(x);
        row.push_back(y);
        courses.push_back(row);
    }
    Solution sln;
    cout << sln.scheduleCourse(courses) << endl;
    return 0;
}