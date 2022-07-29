#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubarrayKSum(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int pre = 0, len = 0;
    for(int i=0; i<n; i++)
    {
        pre += arr[i];

        if(pre == k)
        len = max(len, i+1);

        if(m.find(pre-k) != m.end())
        len = max(len, i - m[pre-k]);
        else
        m[pre] = i;
    }
    return len;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
    cin >> arr[i];
    int k;
    cout << "Enter k : ";
    cin >> k;
    cout << "Longest Subarray with sum " << k << " : " << longestSubarrayKSum(arr, n, k) << endl;
    return 0;
}