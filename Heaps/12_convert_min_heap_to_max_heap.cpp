#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void heapify(vector<int> &arr, int idx)
    {
        int left = 2 * idx;
        int right = 2 * idx + 1;
        int n = arr.size();
        int maxIdx = idx;
        if (left <= n && arr[left - 1] > arr[idx - 1])
            maxIdx = left;

        if (right <= n && arr[right - 1] > arr[maxIdx - 1])
            maxIdx = right;

        if (maxIdx != idx)
        {
            swap(arr[maxIdx - 1], arr[idx - 1]);
            heapify(arr, maxIdx);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N)
    {

        for (int i = N; i >= 1; i--)
        {
            heapify(arr, i);
        }
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
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        arr.push_back(d);
    }
    Solution sln;
    sln.convertMinToMaxHeap(arr, n);
    for (int x : arr)
        cout << x << " ";
    return 0;
}