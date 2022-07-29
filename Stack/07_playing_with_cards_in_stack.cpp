#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define M 1000000
int sieve[M] = {0};

void primeSieve(int *prime, int Q)
{
    for(long long i=3; i<=M; i+=2)
    sieve[i] = 1;

    for(long long i=3; i<=M; i+=2)
    {
        if(sieve[i] == 1)
        {
            for(long long j=i*i; j<=M; j+=i)
            sieve[j] = 0;
        }
    }
    sieve[0] = 0;
    sieve[1] = 0;
    sieve[2] = 1;

    for(long long i = 0, j = 0; i<=M && j<=Q; i++)
    {
        if(sieve[i] == 1)
        {
            prime[j] = i;
            j++;
        }
    }
}
int main()
{
    int N, Q;
    cin >> N >> Q;
    int *prime = new int[Q+1];
    primeSieve(prime, Q);

    for(int i=0; i<5; i++)
    cout << prime[i] << " ";

    vector<stack<int>> A(Q+1);
    vector<stack<int>> B(Q);
    for(int i=0; i<N; i++)
    {
        int data;
        cin >> data;
        A[0].push(data);
    }

    for(int i=1; i<=Q; i++)
    {
        while(!A[i-1].empty())
        {
        int card = A[i-1].top();
        A[i-1].pop();
        if(card % prime[i-1] == 0)
        {
            B[i-1].push(card);
        }
        else
        A[i].push(card);
        }
    }

    for(int i=0; i<B.size(); i++)
    {
        while(!B[i].empty())
        {
            cout << B[i].top() << endl;
            B[i].pop();
        }
    }
    for(int i=1; i<A.size(); i++)
    {
        while(!A[i].empty())
        {
            cout << A[i].top() << endl;
            A[i].pop();
        }
    }

}