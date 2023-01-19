#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0, j = n-1;
        while(i >= 0 && i < m && j >= 0 && j < n)
        {
            if(matrix[i][j] == target)
            return true;
            else if(matrix[i][j] > target)
            j = j-1;
            else
            i = i+1;
        }
        return false;
    }
};
class Solution2 {
public:
    bool binarySearch(int i, int n, vector<vector<int>> matrix, int target)
    {
        int s = 0, e = n-1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(matrix[i][mid] == target )
            return true;
            else if(matrix[i][mid] > target)
            e = mid-1;
            else
            s = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++)
        {
            if(binarySearch(i, n, matrix, target))
            return true;
        }
        return false;
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
  vector<vector<int>> matrix;
  for(int i = 0; i < m; i++)
  {
    vector<int> row;
    for(int j = 0; j < n; j++)
    {
        int d;
        cin >> d;
        row.push_back(d);
    }
    matrix.push_back(row);
  }
  int target;
  cin >> target;
  Solution2 sln;
  cout << sln.searchMatrix(matrix, target);
  return 0;
}