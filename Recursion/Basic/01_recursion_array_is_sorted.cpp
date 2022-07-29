#include<iostream>
using namespace std;

bool isSorted(int a[], int n)
{
    if(n == 1)
    return true;
    else
    return a[0] < a[1] && isSorted(a+1, n-1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    bool ans = isSorted(arr, sizeof(arr)/sizeof(int));
    cout << ans << endl;
    return 0;
}