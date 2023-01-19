#include <bits/stdc++.h>
using namespace std;

int binarySearch(int s, int e, vector<int> &nums, int k)
{
    int mid = 0;

    while(s <= e)
    {
        mid = s + (e-s)/2;
        if(nums[mid] == k)
        return mid;
        else if(nums[mid] < k)
        s = mid+1;
        else 
        e = mid-1;
    }
    return -1;
}
int infSort(vector<int> &nums, int k)
{
    int s = 0, e = 1;

    while(k > nums[e])
    {
        s = e;
        e = 2*e;
    }

    return binarySearch(s, e, nums, k);
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
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }
    int k;
    cin >> k;

    cout << infSort(nums, k) << endl;
    return 0;
}