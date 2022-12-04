#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        
        bool odd = true;
        int n = mat.size();
        for(int i = 0; i < n; i++)
        {
            int j = i;
            int k = 0;
            vector<int> temp;
            while(j >= 0 && k < n)
            {
                temp.push_back(mat[j][k]);
                j--;
                k++;
            }
            if(!odd)
            {
                reverse(temp.begin(), temp.end());
            }
            odd = !odd;
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        
        for(int i = 1; i < n; i++)
        {
            int j = n-1;
            int k = i;
            vector<int> temp;
            while(j >= 0 && k < n)
            {
                temp.push_back(mat[j][k]);
                j--;
                k++;
            }
            
            if(!odd)
            {
                reverse(temp.begin(), temp.end());
            }
            odd = !odd;
            ans.insert(ans.end(), temp.begin(), temp.end());
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
  
  int n;
  cin >> n;
  vector<vector<int>> mat;
  for(int i = 0; i < n; i++)
  {
    vector<int> row;
    for(int j = 0; j < n; j++)
    {
        int d;
        cin >> d;
        row.push_back(d);
    }
    mat.push_back(row);
  }

  Solution sln;
  vector<int> ans = sln.findDiagonalOrder(mat);
  for(int x : ans)
  cout << x << " ";
  return 0;
}