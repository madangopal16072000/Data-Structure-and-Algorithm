#include<iostream>

using namespace std;

int linearSearch(int a[], int n, int key)
{
    if(n == 0)
    return -1;

    if(a[0] == key)
    return 0;

    int i = linearSearch(a+1, n-1, key);

    if( i == -1)
    return -1;
    else
    return i+1;
}
int linearSearch2(int a[], int i, int n, int key)
{
    if(i == n)
    return -1;
    
    if(a[i] == key)
    return i;
    else
    return linearSearch2(a, i+1, n, key);
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a)/sizeof(int);
    int key;
    cout << "Enter key : ";
    cin >> key;
    cout << linearSearch2(a, 0, n, key) << endl;
    return 0;
}