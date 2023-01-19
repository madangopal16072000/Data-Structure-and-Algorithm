#include<bits/stdc++.h>
using namespace std;

int binarySearch(int s, int e, vector<int> A, int B)
{
    int mid = 0;
    
    while(s <= e)
    {
        mid = s + (e-s)/2;
        
        if(A[mid] == B)
        return mid;
        else if(A[mid] < B)
        {
            s = mid+1;
        }
        else
        e = mid-1;
    }
    return -1;
}

int binarySearchR(int s, int e, vector<int> A, int B)
{
    int mid = 0;
    while(s <= e)
    {
        mid = s + (e-s)/2;
        if(A[mid] == B)
        return mid;
        else if(A[mid] < B)
        {
            e = mid-1;
        }
        else
        s = mid+1;
    }
    return -1;
}
int solve(vector<int> &A, int B) {
    
    
    
    int s = 0, e = A.size()-1;
    int mid = 0;
    
    while(s < e)
    {
        mid = s + (e-s)/2;
        if(A[mid] < A[mid+1])
        s = mid+1;
        else 
        e = mid;
    }
    
    int ans = binarySearch(0, s, A, B);
    int ansR = binarySearchR(s+1, A.size()-1, A, B);
    if(ans != -1)
    return ans;
    else
    return ansR;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> nums;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    nums.push_back(d);
  }
  int k;
  cin >> k;
  cout << solve(nums, k) << endl;
  return 0;
}