#include<iostream>
#include<algorithm>
using namespace std;

int first_occurence(int a[], int n, int key)
{
    int s = 0;
    int e = n-1;
    int ans = -1;
    int mid;
    while(s <= e)
    {
        mid = (s+e)/2;
        if(a[mid] == key)
        {
            ans = mid;
            e = mid-1;
        }
        else if(a[mid] > key)
        {
            e = mid -1;
        }
        else
        s = mid+1;
    }
    return ans;
}
int last_occurence(int a[], int n, int key)
{
    int s = 0;
    int e = n-1;
    int mid;
    int ans = -1;
    while(s <= e)
    {
        mid = (s+e)/2;
        if(a[mid] == key)
        {
            ans = mid;
            s = mid+1;
        }
        else if(a[mid] > key)
        e = mid -1;
        else 
        s = mid + 1;
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10, 12, 15, 20};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin >> key;
    int index = first_occurence(arr, n, key);
    cout << "First occurence of " << key << " : " << index << endl;
    cout << "Last occurence of " << key << " : " << last_occurence(arr, n, key) << endl;
    
    return 0;
}