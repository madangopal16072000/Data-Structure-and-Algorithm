#include<iostream>
using namespace std;

void primeSieve(int p[])
{
    for(long long int i=3; i<=100000; i+=2)
    p[i] = 1;

    for(long long int i=3; i<=100000; i+=2)
    {
        if(p[i] == 1)
        {
            for(long long int j=i*i; j<=100000; j = j+i)
            {
                p[j] = 0;
            }
        }
    }

    p[2] = 1;
    p[1] = p[0] = 0;
}
int main()
{
    int p[100000] = {0};

    primeSieve(p);
    int csum[100000] = {0};

    for(int i=1; i<=100000; i++)
    csum[i] = csum[i-1] + p[i];

    int N;
    cin >> N;
    while(N--)
    {
        int a, b;

        cin >> a >> b;

        cout << csum[b] - csum[a-1] << endl;
    }
    return 0;

}