#include<iostream>
using namespace std;

int partition(int a[], int s, int e)
{

    // inplace sorting won't take extra space
    int i = s-1;
    int j = s;
    int pivot = a[e];

    for(; j<e; j++)
    {
        if(a[j] < pivot)
        {
            i = i+1;
            swap(a[j], a[i]);
        }
    }

    // swap the pivot with i+1 position element
    swap(a[i+1], a[e]);
    return i+1;
}
void quickSort(int a[], int s, int e)
{
    if(s >= e)
    return;

    int p = partition(a, s, e);

    quickSort(a, s, p-1);
    quickSort(a, p+1, e);
}
int main()
{
    int a[] = {2, 7, 8, 6, 1, 5, 4};
    int n = sizeof(a)/sizeof(int);

    quickSort(a, 0, n-1);
    for(int i=0; i<n; i++)
    cout << a[i] << " ";
    return 0;
}