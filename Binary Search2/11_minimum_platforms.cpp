#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    bool isValid(int mid, vector<vector<int>> &vec)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(vec[0][0]);
        int cnt = 1;
        int n = vec.size();
        int i = 1;
        while(i < n && !pq.empty())
        {
            if(pq.top() < vec[i][1])
            {
                pq.pop();
            }
            else
            {
                cnt++;
            }
            pq.push(vec[i][0]);
            
            if(cnt > mid)
            return false;
            i++;
        }
        return true;
    }
    int findPlatform(vector<int> arr, vector<int> dep, int n)
    {
    	// Your code here
    	int l = 1; 
    	int h = n;
    	vector<vector<int>> vec;
    	for(int i = 0; i < n; i++)
    	{
    	    vec.push_back({dep[i], arr[i]});
    	}
    	sort(vec.begin(), vec.end());
    	int ans = -1;
    	while(l <= h)
    	{
    	    int mid = l + (h-l)/2;
    	    
    	    if(isValid(mid, vec))
    	    {
    	        ans = mid;
    	        h = mid-1;
    	    }
    	    else
    	    {
    	        l = mid+1;
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
  int n;
  cin >> n;
  vector<int> arr, dep;
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  for(int i = 0; i < n; i++)
  {
    int d;
    cin >> d;
    dep.push_back(d);
  }

  Solution sln;
  cout << sln.findPlatform(arr, dep, n);
  return 0;
}