#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long> arr, long long n)
    {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        long long ans = 0;
        while (pq.size() > 1)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            ans = ans + x + y;
            pq.push(x + y);
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
    long long n;
    cin >> n;
    vector<long long> arr;
    for (long long i = 0; i < n; i++)
    {
        long long d;
        cin >> d;
        arr.push_back(d);
    }

    Solution sln;
    cout << sln.minCost(arr, n) << endl;
    return 0;
}