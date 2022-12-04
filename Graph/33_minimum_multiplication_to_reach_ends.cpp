#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        queue<pair<int, int>> q;
        q.push({0, start});
        int n = arr.size();
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        while (!q.empty())
        {
            int node = q.front().second;
            int step = q.front().first;
            q.pop();

            if (node == end)
            {
                return step;
            }
            // else if(node < end)
            // {
            for (int i = 0; i < n; i++)
            {
                int next = (node * arr[i]) % 100000;
                if (step + 1 < dist[next])
                {
                    dist[next] = step + 1;
                    q.push({dist[next], next});
                }
            }
            // }
        }
        return -1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        arr.push_back(d);
    }
    int start, end;
    cin >> start >> end;
    Solution sln;
    cout << sln.minimumMultiplications(arr, start, end) << endl;
    return 0;
}