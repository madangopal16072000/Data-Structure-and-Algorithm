#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, vector<int> &temp, vector<int> &ans, int l, int mid, int h, unordered_map<int, int> mp)
{
    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= h)
    {
        if (nums[i] <= nums[j])
        {
            temp[k++] = nums[j++];
        }
        else
        {
            ans[mp[nums[i]]] += h-j+1;
            temp[k++] = nums[i++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }
    while (j <= h)
    {
        temp[k++] = nums[j++];
    }

    for(int i = l; i <= h; i++)
    {
        nums[i] = temp[i];
    }
}
void mergeSort(vector<int> &nums, vector<int> &temp, vector<int> &ans, int l, int h, unordered_map<int, int> mp)
{
    if(l >= h)
    return;

    int mid = 0;

    mid = l + (h - l) / 2;
    mergeSort(nums, temp, ans, l, mid, mp);
    mergeSort(nums, temp, ans, mid + 1, h, mp);
    merge(nums, temp, ans, l, mid, h, mp);
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

    vector<int> ans(n, 0);
    vector<int> temp(n, 0);
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = i;
    }
    mergeSort(nums, temp, ans, 0, n - 1, mp);
    for (int x : ans)
        cout << x << " ";

    return 0;
}