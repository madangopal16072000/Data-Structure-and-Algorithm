#include<bits/stdc++.h>
using namespace std;

int lcs(int N, int M, int K, vector<int> &s1, vector<int> &s2, int i, int j, vector<vector<int>> &dp)
{
    if(i == N || j == M)
    return 0;

    if(dp[i][j] != -1)
    return dp[i][j];

    if(s1[i] == s2[j])
    return 1 + lcs(N, M, K, s1, s2, i+1, j+1, dp);

    int op1 = lcs(N, M, K, s1, s2, i+1, j, dp);
    int op2 = lcs(N, M, K, s1, s2, i, j+1, dp);

    return dp[i][j] = max(op1, op2);

}
int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> s1, s2;
    for(int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        s1.push_back(d);
    }

    for(int i = 0; i < M; i++)
    {
        int d;
        cin >> d;
        s2.push_back(d);
    }

    vector<vector<int>> dp(N, vector<int>(M, -1));
    int ans = lcs(N, M, K, s1, s2, 0, 0, dp);

    if(N - ans >= K && M-ans >= K)
    {
        cout << K + ans;
    }
    else if(N - ans < K)
    {
        cout <<  N;
    }
    else if(M - ans < K)
    cout << M;
    else
    {
        cout << min(N-ans, M-ans) + ans;
    }

    cout << endl;
    return 0;
}