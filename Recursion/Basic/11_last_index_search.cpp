#include<iostream>
using namespace std;

int linearSearch(int a[], int N, int M)
{
    if(N == 0)
    return -1;
    
    if(a[N-1] == M)
    return N-1;
    
    return linearSearch(a, N-1, M);
}
int main()
{
    int N;
    cin >> N;
    
    int a[1001];
    for(int i=0; i<N; i++)
    cin >> a[i];
    
    int M;
    cin >> M;
    
    cout << linearSearch(a, N, M) << endl;
    return 0;
}