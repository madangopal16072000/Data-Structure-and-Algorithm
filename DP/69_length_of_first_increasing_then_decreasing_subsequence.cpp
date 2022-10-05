#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &A)
{
    int n = A.size();
    vector<int> dp1(n, 1);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(A[j] < A[i])
            {
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    vector<int> dp2(n, 1);
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = n-1; j > i; j--)
        {
            if(A[j] < A[i])
            {
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        dp1[i] = dp1[i] + dp2[i];
        ans = max(ans, dp1[i]);
    }
    return ans-1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> A;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        A.push_back(d);
    }
    cout << f(A) << endl;
    return 0;
}