#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a, int b)
{
    cout << "comparing " << a << " and " << b << endl;
    return a<b;
}
int main()
{
    int arr[] = {5, 4, 2, 1, 3};
    int n = sizeof(arr)/sizeof(int);

    sort(arr, arr+n, compare);

    for(int x : arr)
    cout << x << " ";
    cout << endl;
}
