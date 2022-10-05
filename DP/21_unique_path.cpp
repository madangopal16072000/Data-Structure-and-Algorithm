#include<iostream>
#include<vector>

using namespace std;


// void helper(int i, int j, int m, int n, int &cnt)
// {
//     // base case
//     if(i == m-1 && j == n-1)
//     {
//         cnt++;
//         return;
//     }

//     if(i >= m || j >= n)
//     return;

//     // right;
//     helper(i, j+1, m, n, cnt);
//     // down
//     helper(i+1, j, m, n, cnt);
//     return;
// }
// int uniquePaths(int m, int n)
// {
//     int cnt = 0;
//     helper(0, 0, m, n, cnt);
//     return cnt;
// }

int helper2(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    // base case
    if(i == m-1 && j == n-1)
    return 1;
    if(i >= m || j >= n)
    return 0;

    // look up
    if(dp[i][j] != 0)
    return dp[i][j];


    int ans = helper2(i, j+1, m, n, dp) + helper2(i+1, j, m, n, dp);
    dp[i][j] = ans;
    return dp[i][j];
}
int uniquePaths2(int m, int n)
{
    vector<vector<int>> dp(m, vector<int> (n, 0));
    int ans = helper2(0, 0, m, n, dp);
    for(vector<int> row : dp)
    {
        for(int x : row)
        cout << x << " ";

        cout << endl;
    }
    return ans;
}
int main()
{
    int m, n;
    cin >> m >> n;
    cout << uniquePaths2(m, n) << endl;
    return 0;
}