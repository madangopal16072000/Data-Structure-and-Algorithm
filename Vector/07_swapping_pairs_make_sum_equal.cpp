#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    long long findSwapValues(long long A[], long long n, long long B[], long long m)
    {
        // Your code goes here
        sort(A, A + n);
        sort(B, B + n);

        long long sumA = 0, sumB = 0;
        for (long long i = 0; i < n; i++)
            sumA += A[i];
        for (long long j = 0; j < m; j++)
            sumB += B[j];

        long long temp = (sumB - sumA);
        if (temp % 2 == 1)
            return -1;

        cout << sumA << " " << sumB << endl;
        temp = temp / 2;

        for (long long i = 0; i < n; i++)
        {
            long long y = A[i];
            long long x = y + temp;
            cout << temp << " " << x << " " << y << endl;
            // long long s = 0, e = m - 1;
            // while (s <= e)
            // {
            //     long long mid = s + (e - s) / 2;

            //     if (B[mid] == x)
            //     {
            //         return 1;
            //     }
            //     else if (B[mid] > x)
            //         e = mid - 1;
            //     else
            //         s = mid + 1;
            // }
            if (binary_search(B, B + n, x))
                return 1;
        }

        return -1;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    long long n, m;
    cin >> n >> m;
    long long *A = new long long[n];
    long long *B = new long long[m];

    for (long long i = 0; i < n; i++)
        cin >> A[i];

    for (long long j = 0; j < m; j++)
        cin >> B[j];

    Solution sln;
    cout << sln.findSwapValues(A, n, B, m) << endl;
    return 0;
}