#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
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
                if (nums[i] > 2 * nums[j])
                    cnt++;

                temp[k++] = nums[i];
                i++;
            }
            else
            {
                int l = i;
                while (l <= mid && nums[l] <= 2 * nums[j])
                    l++;
                cnt = cnt + (mid - l + 1);
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
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        cnt = 0;
        vector<int> temp(n, 0);
        mergeSort(0, n - 1, nums, temp);
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
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }

    Solution sln;
    cout << sln.reversePairs(nums) << endl;
    return 0;
}