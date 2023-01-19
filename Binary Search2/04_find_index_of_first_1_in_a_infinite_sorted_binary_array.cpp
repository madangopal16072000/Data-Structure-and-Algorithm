#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int s, int e, vector<int> &nums)
{
    int mid = 0;
    int ans = -1;
    while(s <= e)
    {
        mid = s + (e-s)/2;

        if(nums[mid] == 1)
        {
            ans = mid;
            e = mid-1;
        }
        else if(nums[mid] < 1)
        {
            s = mid+1;
        }
        else
        e = mid-1;
    }
    return ans;
}
int f(vector<int> &nums)
{
    int s = 0, e = 1;
    while(1 > nums[e])
    {
        s = e;
        e = 2*e;
    }

    return firstOccurrence(s, e, nums);
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

    cout << f(nums) << endl;
    return 0;
}