#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>> preMaxRow(n, vector<int>(m));
        vector<vector<int>> postMaxRow(n, vector<int>(m));
        vector<vector<int>> preMaxCol(n, vector<int>(m));
        vector<vector<int>> postMaxCol(n, vector<int>(m));

        for(int i = 0; i < n; i++)
        {
            preMaxRow[i][0] = heightMap[i][0];
            for(int j = 1; j < m; j++)
            {
                preMaxRow[i][j] = max(heightMap[i][j], preMaxRow[i][j-1]);
            }
            postMaxRow[i][m-1] = heightMap[i][m-1];
            for(int j = m-2; j >= 0; j--)
            {
                postMaxRow[i][j] = max(heightMap[i][j], postMaxRow[i][j+1]);
            }
        }

        for(int j = 0; j < m; j++)
        {
            preMaxCol[0][j] = heightMap[0][j];
            for(int i = 1; i < n; i++)
            {
                preMaxCol[i][j] = max(heightMap[i][j], preMaxCol[i-1][j]);
            }

            postMaxCol[n-1][j] = heightMap[n-1][j];
            for(int i = n-2; i >= 0; i--)
            {
                postMaxCol[i][j] = max(postMaxCol[i+1][j], heightMap[i][j]);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans = ans + (min(preMaxRow[i][j], min(postMaxRow[i][j], min(preMaxCol[i][j], postMaxCol[i][j])))-heightMap[i][j]);
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
  vector<vector<int>> heightMap;
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    vector<int> row;
    for(int j = 0; j < m; j++)
    {
        int d;
        cin >> d;
        row.push_back(d);
    }
    heightMap.push_back(row);
  }

  Solution sln;
  cout << sln.trapRainWater(heightMap) << endl;
  return 0;
}