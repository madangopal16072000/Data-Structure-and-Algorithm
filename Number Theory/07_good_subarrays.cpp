#include<iostream>
#include<unordered_map>
using namespace std;
long long int cumArray(long long cum[], long long A[],  long long N)
{
    cum[0] = A[0];
    for(long long int i = 1; i<N; i++)
    {
        cum[i] = cum[i-1] + A[i];
    }
    long long int *modArray = new long long[N+1];
    for(long long int i = 0, j = 0; i<N; i++, j++)
    {
        modArray[j] = cum[i]%N;
    }
    unordered_map<long long int, long long int> H;
    H[0] = 1;
    for(long long int i = 0; i<N; i++)
    {
        H[modArray[i]]++;
    }
    long long int count = 0;
    for(long long int i=0; i<H.size(); i++)
    {
        if(H[i] > 0)
        count = count + H[i]*(H[i] - 1)/2;

    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        long long int N;
        cin >> N;
        long long *A = new long long[N+1];
        for(int i=0; i<N; i++)
        cin >> A[i];
        long long *cum = new long long[N+1];
        cout << cumArray(cum, A, N) << endl;
    }
    return 0;
}