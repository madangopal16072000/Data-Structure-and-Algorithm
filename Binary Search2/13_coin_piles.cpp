#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSteps(vector<int> &A, int N, int K)
    {
        // code here
        sort(A.begin(), A.end());
        int i = 0;
        int j = N - 1;
        int ans = 0;
        while (i < j && A[j] - A[i] > K)
        {
            if (A[i] < A[j] - A[i] - K)
            {
                ans = ans + A[i];
                i++;
            }
            else
            {
                ans = ans + A[j] - A[i] - K;
                i++;
                j--;
            }
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
    int N, K;
    cin >> N >> K;
    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        A.push_back(d);
    }

    Solution sln;
    cout << sln.minSteps(A, N, K);
    return 0;
}