#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int s, int e)
{
    int pivot = nums[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (nums[j] < pivot)
        {
            swap(nums[++i], nums[j]);
        }
    }

    swap(nums[++i], nums[e]);
    return i;
}

void quickSort(vector<int> &nums, int s, int e)
{
    // base case
    if (s >= e)
        return;

    int p = partition(nums, s, e);
    quickSort(nums, s, p - 1);
    quickSort(nums, p + 1, e);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }

    quickSort(nums, 0, n - 1);
    for (int x : nums)
        cout << x << " ";

    return 0;
}