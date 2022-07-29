#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(int);

    for(int x : arr)
    cout << x << " ";
    cout << endl;

    rotate(arr, arr+2, arr+n);

    for(int x: arr)
    cout << x << " ";
    cout << endl;

    vector<int> v{10, 20, 30, 40, 50};
    rotate(v.begin(), v.begin()+3, v.end());

    for(int i=0; i<v.size(); i++)
    cout << v[i] << " ";
    cout << endl;

    // next permutation

    vector<int> vec {1, 2, 3};
    next_permutation(vec.begin(), vec.end());
    next_permutation(vec.begin(), vec.end());

    for(int x : vec)
    cout << x << " "; 
    cout << endl;
}