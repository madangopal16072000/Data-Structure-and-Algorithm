#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[] = {1, 3, 7, 9, 10};
    int n = sizeof(arr)/sizeof(int);

    auto it = find(arr, arr+n, 11);
    int index = it - arr;

    if(index != n)
    cout << "element is present at index " << index;
    else
    cout << "element is not present";
    return 0;


}