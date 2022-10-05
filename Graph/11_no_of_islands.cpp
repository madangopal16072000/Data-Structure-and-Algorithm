#include <bits/stdc++.h>
using namespace std;
class Solution {
    int m, n;
  public:
    void dfs_helper(int i, int j, vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = '2';
        
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++)
        {
            int r = i + drow[k];
            int c = j + dcol[k];
            if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
            {
                dfs_helper(r, c, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    cnt++;
                    dfs_helper(i, j, grid);
                }
            }
        }
        return cnt;
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
    vector<vector<char>> grid;
    for(int i = 0; i < m; i++)
    {
        vector<char> vec;
        for(int j = 0; j < n; j++)
        {
            char d;
            cin >> d;
            vec.push_back(d);

        }
        grid.push_back(vec);
    }

    Solution sln;
    cout << sln.numIslands(grid) << endl;
    return 0;
}