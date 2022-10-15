#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        auto p = lower_bound(arr.begin(), arr.end(), x);
        int idx = p - arr.begin();
        multiset<int> ms;
        int i, j, cnt;
        i = idx - 1;
        j = idx;
        cnt = 0;
        while (i >= 0 && j < n && cnt < k)
        {
            if (abs(arr[i] - x) <= abs(arr[j] - x))
            {
                ms.insert(arr[i]);
                i--;
            }
            else
            {
                ms.insert(arr[j]);
                j++;
            }
            cnt++;
        }
        if (cnt != k)
        {
            while (i >= 0 && cnt < k)
            {
                ms.insert(arr[i]);
                i--;
                cnt++;
            }

            while (j < n && cnt < k)
            {
                ms.insert(arr[j]);
                j++;
                cnt++;
            }
        }
        return vector<int>(ms.begin(), ms.end());
    }
};
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
    int k, x;
    cin >> k >> x;
    Solution sln;
    vector<int> ans = sln.findClosestElements(nums, k, x);
    for (int x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}