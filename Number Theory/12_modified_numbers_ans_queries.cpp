#include <bits/stdc++.h>
using namespace std;
#define N 10004
class Solution
{
public:
    void sieve(int p[], int M)
    {
        for (int i = 3; i <= M; i = i + 2)
        {
            p[i] = 1;
        }

        for (int i = 3; i <= M; i = i + 2)
        {
            if (p[i] == 1)
            {
                for (int j = i * i; j <= M; j = j + i)
                {
                    p[j] = 0;
                }
            }
        }
        p[2] = 1;
        p[1] = p[0] = 0;
    }
    int prime(int n, int p[])
    {
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            if (p[i] == 1 && n%i == 0)
            {
                while(n%i == 0)
                {
                    n = n / i;
                }
                ans = ans + i;
            }
        }
        return ans;
    }
    int sumOfAll(int l, int r)
    {
        // code here
        int p[N];
        sieve(p, r+1);
        int ans = 0;
        if (l == 1)
        {
            ans = 1;
            l++;
        }
        for (int i = l; i <= r; i++)
        {
            ans = ans + prime(i, p);
        }
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int l, r;
    cin >> l >> r;
    Solution sln;
    cout << sln.sumOfAll(l, r) << endl;
    return 0;
}