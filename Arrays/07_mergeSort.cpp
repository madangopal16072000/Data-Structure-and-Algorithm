#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void merge(int s, int mid, int e, vector<int> &nums, vector<int> &temp)
{
    int n = nums.size();
    int k = s;
    int i = s, j = mid + 1;
    while (i <= mid && j <= e)
    {
        if (nums[i] <= nums[j])
        {
            temp[k++] = nums[i];
            i++;
        }
        else
        {
            cnt = cnt + mid - i + 1;
            temp[k++] = nums[j];
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }

    while (j <= e)
    {
        temp[k++] = nums[j++];
    }

    for (int i = s; i <= e; i++)
    {
        nums[i] = temp[i];
    }
}
void mergeSort(int i, int j, vector<int> &nums, vector<int> &temp)
{
    if (i == j)
        return;

    int mid = i + (j - i) / 2;
    mergeSort(i, mid, nums, temp);
    mergeSort(mid + 1, j, nums, temp);
    merge(i, mid, j, nums, temp);
}
void f(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp(n, 0);
    mergeSort(0, n - 1, nums, temp);
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

    f(nums);
    for (int x : nums)
        cout << x << " ";

    cout << endl
         << cnt << endl;
    return 0;
}