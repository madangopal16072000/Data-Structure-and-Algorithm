#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>> &a)
    {
        // code here
        vector<int> ans;
        int rowStart, colStart;
        int rowEnd, colEnd;
        rowStart = colStart = 0;
        rowEnd = R - 1;
        colEnd = C - 1;

        int cnt = 0;
        while (rowStart <= rowEnd && colStart <= colEnd)
        {
            int i, j;
            for (j = colStart; j <= colEnd && rowStart <= R; j++)
            {
                ans.push_back(a[rowStart][j]);
                cnt++;
            }
            rowStart = rowStart + 1;

            for (i = rowStart; i <= rowEnd && colEnd >= 0; i++)
            {
                ans.push_back(a[i][colEnd]);
                cnt++;
            }
            colEnd = colEnd - 1;
            if (rowStart <= rowEnd)
            {

                for (j = colEnd; j >= colStart && rowEnd >= 0; j--)
                {
                    ans.push_back(a[rowEnd][j]);
                    cnt++;
                }
                rowEnd = rowEnd - 1;
            }

            if (colStart <= colEnd)
            {
                for (i = rowEnd; i >= rowStart && colStart <= C; i--)
                {
                    ans.push_back(a[i][colStart]);
                    cnt++;
                }
                colStart = colStart + 1;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
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
    vector<vector<int>> a;
    for (int i = 0; i < R; i++)
    {
        vector<int> row;
        for (int j = 0; j < C; j++)
        {
            int d;
            cin >> d;
            row.push_back(d);
        }
        a.push_back(row);
    }

    Solution sln;
    vector<int> ans = sln.reverseSpiral(R, C, a);
    for (int x : ans)
        cout << x << " ";
    return 0;
}