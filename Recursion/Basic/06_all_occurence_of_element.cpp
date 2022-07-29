#include<iostream>
using namespace std; 

void allOcc(int a[], int i, int n, int key)
{
    if(i == n)
    return;

    if(a[i] == key)
    cout << i << " ";

    allOcc(a, i+1, n, key);
}
int storeOcc(int input[], int i, int n, int out[], int j, int key)
{
    if( i==n )
    return j;

    if(input[i] == key)
    {
        out[j] = i;
        return storeOcc(input, i+1, n, out, j+1, key); 
    }
    else
    return storeOcc(input, i+1, n, out, j, key);
}
int main()
{
    int a[] = {1, 3, 7, 5, 2, 7, 9};
    int n = sizeof(a)/sizeof(int);
    int key;
    cout << "Enter key : ";
    cin >> key;
    // allOcc(a, 0, n, key);
    int *output = new int[n];
    int sizeOfOutput = storeOcc(a, 0, n, output, 0, key); 
    for(int i=0; i<sizeOfOutput; i++)
    cout << output[i] << " ";
    return 0;
}