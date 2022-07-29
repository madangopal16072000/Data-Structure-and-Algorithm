#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int a, b;
    a = 10 ;
    b = 20 ;
    swap(a, b);
    cout << a << " and " << b << endl;

    cout << "Max : " << max(a, b) << endl;
    cout << "Min : " << min(a, b) << endl;

    int arr[] = {1, 2, 3, 4, 4, 5};
    reverse(arr, arr+4);
    for(int x : arr)
    cout << x << " ";
    cout << endl;
    int n = sizeof(arr)/sizeof(int);
    reverse(arr, arr+n);
    for(int x : arr)
    cout << x << " ";
    cout << endl;

    return 0;
}