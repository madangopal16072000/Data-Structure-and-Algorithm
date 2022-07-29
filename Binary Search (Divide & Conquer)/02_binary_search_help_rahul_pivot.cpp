#include<iostream>
#include<algorithm>
using namespace std;
int find_index(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid;
    while(s <= e)
    {
        mid = (s+e)/2;

        if(arr[mid] == key)
        return mid;
        else if(arr[s] <= arr[mid])
        {
            if(key >= arr[s] && key <= arr[mid])
            e = mid - -1;
            else
            s = mid+1;
        }
        else
        {
            if(key >= arr[mid] && key <= arr[e])
            s = mid + 1;
            else
            e = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {4, 5, 1, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin >> key;
    int index = find_index(arr, n, key);
    cout << "Index of " << key << " : " << index << endl;
    return 0;
}