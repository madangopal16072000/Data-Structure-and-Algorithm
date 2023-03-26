#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int unvisitedLeaves(int N, int leaves, vector<int> &frogs)
    {
        // Code here
        vector<bool> visited(leaves + 1, false);
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (frogs[i] <= leaves)
            {
                visited[frogs[i]] = true;
                cnt++;
            }
        }

        for (int i = 1; i <= leaves; i++)
        {
            if (visited[i] == true)
            {
                for (int j = i + i; j <= leaves; j = j + i)
                {
                    visited[j] = true;
                    if (!visited[j])
                        cnt++;
                }
            }
        }
        return leaves - cnt;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int N, leaves;
    cin >> N >> leaves;
    vector<int> frogs;
    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        frogs.push_back(d);
    }

    Solution sln;
    cout << sln.unvisitedLeaves(N, leaves, frogs) << endl;
    return 0;
}