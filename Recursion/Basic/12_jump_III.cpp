#include <bits/stdc++.h>
using namespace std;
bool f(vector<int> &arr, int start, vector<int> &visited)
{
    // base case
    if(start < 0 || start >= arr.size())
    return false;

    if(arr[start] == 0)
    return true;

    if(visited[start] == 1)
    return false;

    visited[start] = 1;
    bool op1 = f(arr, start + arr[start], visited);
    bool op2 = f(arr, start - arr[start], visited);

    return op1 || op2;
}
bool canReach(vector<int> &arr, int start)
{
    int n = arr.size();
    vector<int> visited(n, 0);
    return f(arr, start, visited);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    int start;
    cin >> start;
    cout << canReach(nums, start);
    return 0;
}