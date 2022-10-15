#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int f(int i, int a[], unordered_map<int, int> &mp)
    {
        if (i <= 0)
        {
            int sum = 0;
            for (auto p : mp)
            {
                if (p.second > 0)
                    sum = sum + p.first;
            }
            return sum;
        }
        int take, noTake;
        take = noTake = 0;
        cout << a[i] << endl;
        if (mp[a[i]] > 0 && mp.count(a[i] - 1) && mp[a[i]-1] > 0)
        {
            mp[a[i] - 1]--;
            mp[a[i]]--;
            take = a[i] + f(i - 1, a, mp);
            
        }
        noTake = f(i - 1, a, mp);

        return max(take, noTake);
    }
    int maximizeSum(int a[], int n)
    {
        // Complete the function
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
        }

        return f(n - 1, a, mp);
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
    int *a = new int[n];
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        a[i] = d;
    }
    Solution sln;
    cout << sln.maximizeSum(a, n) << endl;
    return 0;
}