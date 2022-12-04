#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximum69Number (int num) {
        int r;
        vector<int> vec;
        int temp = num;
        while(num)
        {
            r = num%10;
            vec.push_back(r);
            num = num/10;
        }
        int n = vec.size();
        int i = n-1;
        while(vec[i] == 9 && i >= 0)
        {
            i--;
        }
        if(i >= 0)
        {
            vec[i] = 9;
        }
        else
        {
            return temp;
        }
        int ans = 0;
        for(int i = n-1; i >= 0; i--)
        {
            ans = ans*10 + vec[i];
        }
        return ans;
        
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  int n = 9999;

  Solution sln;
  cout << sln.maximum69Number(n) << endl;
  return 0;
}