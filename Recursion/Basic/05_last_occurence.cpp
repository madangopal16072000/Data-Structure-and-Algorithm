#include<iostream>
using namespace std;

int lastOcc(int a[], int n, int key)
{
    if(n == 0)
    return -1;

    int i = lastOcc(a+1, n-1, key);

    if(i == -1)
    {
        if(a[0] == key)
        return 0;
        else
        return -1;
    }
    else
    return i+1;
}
int main()
{
    int a[] = {1, 3, 7, 5, 4, 7, 9};
    int n = sizeof(a)/sizeof(int);
    int key;
    cout << "Enter key : ";
    cin >> key;
    int index = lastOcc(a, n, key);
    cout << index << endl;
    return 0;
}