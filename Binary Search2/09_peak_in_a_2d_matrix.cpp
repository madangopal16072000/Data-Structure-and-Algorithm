#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    pair<int, int> peakElement(int i, int n, vector<vector<int>> mat)
    {
        int s = 0, e = n - 1;
        int mid = 0;

        while (s < e)
        {
            mid = s + (e - s) / 2;
            if (mat[i][mid] < mat[i][mid + 1])
                s = mid + 1;
            else
                e = mid;
        }
        return {i, s};
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {

        int m = mat.size();
        int n = mat[0].size();
        int x, y;
        for (int i = 0; i < m; i++)
        {
            pair<int, int> p = peakElement(i, n, mat);
            int r = p.first;
            int c = p.second;
            if (r > 0 && r < m - 1)
            {
                if (mat[r][c] > mat[r - 1][c] && mat[r][c] > mat[r + 1][c])
                {
                    x = r;
                    y = c;
                    break;
                }
            }
            else if (r > 0)
            {
                if (mat[r][c] > mat[r - 1][c])
                {
                    x = r;
                    y = c;
                }
                else
                {
                    x = r - 1;
                    y = c;
                }
            }
            else if (r < m - 1)
            {
                if (mat[r][c] > mat[r + 1][c])
                {
                    x = r;
                    y = c;
                }
                else
                {
                    x = r + 1;
                    y = c;
                }
            }
        }
        return {x, y};
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat;
    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        mat.push_back(row);
    }
    Solution sln;
    vector<int> ans = sln.findPeakGrid(mat);
    for (int x : ans)
        cout << x << " ";
    return 0;
}