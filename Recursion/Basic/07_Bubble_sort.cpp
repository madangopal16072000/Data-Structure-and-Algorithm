#include<iostream>
using namespace std;

void bubbleSortIterative(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(a[j] > a[j+1])
            swap(a[j], a[j+1]);
        }
    }
}
void bubbleSortRecursive(int a[], int n)
{
    if(n == 1)
    return;

    for(int i=0; i<n-1; i++)
    {
        if(a[i] < a[i+1])
        swap(a[i], a[i+1]);
    }

    bubbleSortRecursive(a, n-1);
}
int main()
{
    int a[] = {9, 1, 5, 3, 2};
    int n = sizeof(a)/sizeof(int);

    bubbleSortRecursive(a, n);
    for(int i=0; i<n; i++)
    cout << a[i] << " ";
    return 0;
}