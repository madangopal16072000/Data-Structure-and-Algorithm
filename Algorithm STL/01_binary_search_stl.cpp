#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {10, 20, 33, 40, 40, 40, 50, 100};
    int n = sizeof(arr)/sizeof(int);
    int key;
    // cin >> key;
    // bool present = binary_search(arr, arr+n, key);

    // if(present)
    // cout << "present" << endl;
    // else
    // cout << "absent"<< endl;
    // return 0;
    // 
    // lower bound return iterator to element greater than equal to key;
    // lower and upper bound works on sorted and time complexity is logn
    int *it1 = lower_bound(arr, arr+n, 40);

    cout << "Lower bound index : " << (it1 - arr) << endl;

    // upper bound givers element greater than key

    int *it2 = upper_bound(arr, arr+n, 40);
    
    cout << "Upper bound index : " << (it2 - arr) << endl;

    cout << "no of " << key << "present : " << (it2 - it1) << endl;
    return 0;
}