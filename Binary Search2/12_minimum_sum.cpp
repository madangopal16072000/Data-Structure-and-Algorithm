#include<bits/stdc++.h>
using namespace std;
class Solution{   
public:
    string f(string num1, string num2)
    {
        string ans = "";
        int m = num1.size();
        int n = num2.size();
        
        int i = m-1;
        int j = n-1;
        
        int r = 0;
        while(i>= 0 && j >= 0)
        {
            int x = num1[i]-'0';
            int y = num2[j]-'0';
            
            int val = (r+x+y)%10;
            r = (r+x+y)/10;
            char ch = val + '0';
            ans = ch + ans;
            i--;
            j--;
        }
        
        while(i >= 0)
        {
            int x = num1[i]-'0';
            int val = (r+x)%10;
            r = (r+x)/10;
            char ch = val + '0';
            
            ans = ch + ans;
        }
        
        while(j >= 0)
        {
            int y = num2[j]-'0';
            int val = (r+y)%10;
            r = (r+y)/10;
            char ch = val + '0';
            ans = ch + ans;
        }
        
        int k = 0;
        int len = ans.size();
        string temp = "";
        while(k < len && ans[k] == '0')
        {
            k++;
        }
        for(; k < len; k++)
        {
            temp = temp + ans[k];
        }
        ans = temp;
        return ans;
    }
    string solve(vector<int> arr, int n) {
        // code here
        sort(arr.begin(), arr.end());
        int i = 0;
        string num1 = "";
        
        while(i < n)
        {
            char ch = arr[i] + '0';
            num1 = num1 + ch;
            i = i+2;
        }
        
        string num2 = "";
        int j = 1;
        while(j < n)
        {
            char ch = arr[j] + '0';
            num2 = num2 + ch;
            j = j + 2;
        }
        cout << num1 << " " << num2 << endl;
        string ans = f(num1, num2);
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
  vector<int> arr;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  Solution sln;
  cout << sln.solve(arr, n) << endl;
  return 0;
}