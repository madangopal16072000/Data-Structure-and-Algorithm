#include<iostream>
using namespace std;

void merge(int a[], int s, int e, int mid)
{
    // int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];
    while(i <= mid && j <= e)
    {
        if(a[i] < a[j])
        temp[k++] = a[i++];
        else
        temp[k++] = a[j++];
    }
    while(i <= mid)
    temp[k++] = a[i++];
    while(j <= e)
    temp[k++] = a[j++];

    for(int i=s; i<=e; i++)
    a[i] = temp[i];
}
void mergeSort(int a[], int s, int e)
{
    // Base Case
    if(s >= e)
    return;

    // Divide the array
    int mid = (s+e)/2;
    mergeSort(a, s, mid);
    mergeSort(a, mid+1, e);

    // Merge
    merge(a, s, e, mid);

}
int main()
{
    int a[] = {4, 5, 8, 2, 9, 1};
    int n = sizeof(a)/sizeof(int);

    mergeSort(a, 0, n-1);

    cout << "Sorted Array : ";
    for(int i=0; i<n; i++)
    cout << a[i] << " ";
    cout << endl;
    return 0;
}