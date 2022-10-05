#include<iostream>
using namespace std;

int maxSum(int arr[], int n)
{
    int currentSum = 0;
    int max_so_far = arr[0];

    for(int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        max_so_far = max(max_so_far, currentSum);
        if(currentSum < 0)
        currentSum = 0;
    }

    return max_so_far;
}

int main()
{
    int arr[] = {-2, -1};
    int n = sizeof(arr)/sizeof(int);

    cout << maxSum(arr, n) << endl;
    return 0;
}