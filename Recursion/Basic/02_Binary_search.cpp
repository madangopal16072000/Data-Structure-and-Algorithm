#include<iostream>
using namespace std;
int a[] = {1, 2, 3, 4, 5, 10, 20};
int binarySearch(int l, int h, int key)
{
    if(l <= h)
    {
        int mid = (l+h)/2;

        if(a[mid] == key)
        return mid;
        else if(a[mid] > key)
        binarySearch(l, mid - 1, key);
        else 
        binarySearch(mid+1, h, key);
    }
    else
    return -1;
}
int main()
{
    int l = 0;
    int h = sizeof(a)/sizeof(int) - 1;
    int key;
    cout << "Enter key : ";
    cin >> key;

    cout << binarySearch(l, h, key) << endl;
    return 0;
}