#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubarraywithSum0(int arr[], int n)
{
    int pre = 0;
    int len = 0;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++)
    {
        pre += arr[i];

        if(pre == 0)
        len = max(len, i+1);

        if(m.find(pre) != m.end())
        len = max(len, i - m[pre]);
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
    for(int i = 0; i<n; i++)
    cin >> arr[i];

    cout << "Length of Longest Subarray with sum 0 : " << longestSubarraywithSum0(arr, n) << endl;
    return 0;
}