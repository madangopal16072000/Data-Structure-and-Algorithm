#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here

        long long nsum = (n * (n + 1)) / 2;
        long long sum = 0;
        long long ssum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            ssum = ssum + arr[i] * arr[i];
        }

        long long nssum = (n * (n + 1) * (2 * n + 1)) / 6;

        long long temp1 = sum - nsum;
        long long temp2 = ssum - nssum;
        long long temp3 = temp2 / temp1;

        int rp = (temp3 + temp1) / 2;
        int ms = rp - temp1;

        int *ans = new int[2];
        ans[0] = rp;
        ans[1] = ms;
        return ans;
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
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sln;
    int *ans = sln.findTwoElement(arr, n);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}