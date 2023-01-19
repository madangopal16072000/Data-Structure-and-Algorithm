#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1;
    int mid = 0;

    while (s <= e)
    {
        if (mid > 0 && mid < nums.size() - 1)
        {

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return nums[mid];

            else if (nums[mid] < nums[mid + 1])
                e = mid + 1;
            else if (nums[mid] < nums[mid - 1])
                s = mid - 1;
        }
        else if (mid == 0)
        {
            if (nums[mid] > nums[mid + 1])
                return nums[mid];
            else
                return nums[mid + 1];
        }
        else if (mid == nums.size() - 1)
        {
            if (nums[mid] > nums[mid - 1])
                return nums[mid];
            else
                return nums[mid - 1];
        }
    }

    return -1;
}
int peakElement2(vector<int> &nums)
{
    int s = 0, e = nums.size();
    int mid = 0;

    while(s < e)
    {
        mid = s + (e-s)/2;
        if(nums[mid] < nums[mid+1])
        s = mid+1;
        else
        e = mid;
    }
    return s;
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

    cout << peakElement(nums) << endl;
    return 0;
}