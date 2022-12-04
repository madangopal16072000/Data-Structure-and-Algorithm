#include<bits/stdc++.h>
using namespace std;

void flowdWarshall(vector<vector<int>> matrix)
{
    int n = matrix.size();

    for(int via = 0; via < n; via++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }
    
    // to check cycle if self distance of any node became -ve
    for(int i = 0; i < n; i++)
    {
        if(matrix[i][i] < 0)
        {
            cout << "Cycle is Present" << endl;
        }
    }

    // printing matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<vector<int>> matrix;
  for(int i = 0; i < n; i++)
  {
    vector<int> vec;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        vec.push_back(d);
    }
    matrix.push_back(vec);
  } 
  flowdWarshall(matrix);
  return 0;
}