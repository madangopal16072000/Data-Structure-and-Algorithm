#include <bits/stdc++.h>
using namespace std;

int minDiff(vector<int> nums, int k)
{
    int s = 0, e = nums.size()-1;
    int mid = 0;

    while(s <= e)
    {
        mid = s + (e-s)/2;

        if(nums[mid] == k)
        return nums[mid];
        else if(nums[mid] > k)
        e = mid-1;
        else
        s = mid+1;
    }

    if(s < nums.size() && nums[s]-k < nums[e]-k)
    return nums[s];
    else 
    return nums[e];
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

    int k;
    cin >> k;
    cout << minDiff(nums, k) << endl;
    return 0;
}