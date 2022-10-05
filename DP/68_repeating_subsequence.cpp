#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string A, vector<vector<int>> dp)
{
    if(i == A.length() || j == A.length())
    return 0;

    if(dp[i][j] != -1)
    return dp[i][j];

    if(A[i] == A[j] && i != j)
    {
        return dp[i][j] = f(i+1, j+1, A, dp) + 1;
    }
    else
    {
        return dp[i][j] = max(f(i+1, j, A, dp), f(i, j+1, A, dp));
    }
}
int anytwo(string &A)
{
    int n = A.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(A[i-1] == A[j-1] && i != j)
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string A;
    cin >> A;
    int n = A.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    bool ans = anytwo(A) > 1;
    cout << ans;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int sub(int i, int j, string A, int l1, int l2, vector<vector<int>> dp)
// {
//     if(i == l1 || j == l2)
//     return 0;

//     if(dp[i][j] != -1)
//     return dp[i][j];

//     if(A[i] == A[j])
//     {
//         return dp[i][j] = sub(i+1, j+1, A, l1, l2, dp) + 1;
//     }
//     else
//     {
//         return dp[i][j] = max(sub(i+1, j, A, l1, l2, dp), sub(i, j+1, A, l1, l2, dp));
//     }
// }
// int anytwo(string A) {
//     int n = A.length();
//     int s = 0;
//     int e = n-1;
//     int mid = (s+e)/2;
//     int len1, len2;
//     int ans = INT_MIN;
//     len1 = mid - s + 1;
//     len2 = e - mid;
//     // cout << len1 << len2 << endl;
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     if(n%2==0)
//     {
//         ans = sub(s, mid+1, A, len1, n, dp);
//     }
//     else
//     {
//         int ans1 = sub(s, mid+1, A, len1, n, dp);
//         len1 = mid - s;
//         len2 = e - mid+1;
//         vector<vector<int>> dp2(n, vector<int>(n, -1));
//         int ans2 = sub(s, mid, A, len1, n, dp2);
//         ans = max(ans1, ans2);
//     }
//     return ans > 1 ? 1 : 0;
// }
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("./input.txt", "r", stdin);
//     freopen("./output.txt", "w", stdout);
// #endif
//     string A;
//     cin >> A;
//     cout << anytwo(A) << endl;
//     return 0;
// }