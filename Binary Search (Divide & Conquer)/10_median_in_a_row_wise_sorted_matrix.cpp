#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSmallerThanEqualToMid(vector<int> &row, int mid)
    {
        int l = 0;
        int h = row.size() - 1;

        while (l <= h)
        {
            int idx = (l + h) / 2;
            if (row[idx] <= mid)
            {
                l = idx + 1;
            }
            else
                h = idx - 1;
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here
        int l = INT_MAX;
        int h = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            l = min(l, matrix[i][0]);
            h = max(h, matrix[i][C - 1]);
        }

        while (l <= h)
        {
            int mid = (l + h) / 2;
            int cnt = 0;
            for (int i = 0; i < R; i++)
            {
                cnt += countSmallerThanEqualToMid(matrix[i], mid);
            }

            if (cnt <= (R * C) / 2)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int R, C;
    cin >> R >> C;
    vector<vector<int>> matrix;
    for (int i = 0; i < R; i++)
    {
        vector<int> row;
        for (int j = 0; j < C; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        matrix.push_back(row);
    }

    Solution sln;
    cout << sln.median(matrix, R, C) << endl;
    return 0;
}