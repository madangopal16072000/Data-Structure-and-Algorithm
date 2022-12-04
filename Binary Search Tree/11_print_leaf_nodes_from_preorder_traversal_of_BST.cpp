#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void f(int i, int j, int arr[], vector<int> &ans)
    {
        // base case
        if(i > j)
        return;

        if(i == j)
        {
            ans.push_back(arr[i]);
            return;
        }

        int k = i+1;
        while(arr[i] > arr[k] && k <= j)
        {
            k++;
        }
        f(i+1, k-1, arr, ans);
        f(k, j, arr, ans);
        return;
    }
public:
    vector<int> leafNodes(int arr[], int N)
    {
        // code here
        vector<int> ans;
        f(0, N - 1, arr, ans);
        return ans;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    Solution sln;
    vector<int> ans = sln.leafNodes(arr, N);
    for (int x : ans)
        cout << x << " ";

    return 0;
}