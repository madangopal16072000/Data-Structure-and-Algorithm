#include<iostream>
#include<vector>
using namespace std;

void primeSieve(int p[])
{
    for(int i=3; i<1000; i+=2)
    p[i] = 1;

    for(int i=3; i<1000; i+=2)
    {
        if(p[i] == 1)
        {
            for(int j = i*i; j<1000; j = j + i)
            p[j] = 0;
        }
    }

    p[2] = 1;
    p[1] = p[0] = 0;
}
vector<int> primeList(int p[], int n)
{
    vector<int> primes(n);
    primeSieve(p);
    int j=0;
    for(int i=0; i<1000 && j < n; i++)
    {
        if(p[i] == 1)
        primes[j++] = i;
    }
    return primes;
}
vector<int> factorize(vector<int> primes, int n)
{

    vector<int> factors;

    int j = 0;
    int i = primes[0];

    while(i*i <= n)
    {
        if(n % i == 0)
        {
            factors.push_back(i);
            while(n % i == 0)
            {
                n = n / i;
            }
        }
        j++;
        i = primes[j];
    }
    if(n!=1)
    factors.push_back(n);

    return factors;
}
int main()
{
    int p[1000] = {0};
    vector<int> primes = primeList(p, 100);
    
    int T;
    cout << "Enter number of Test Case : ";
    cin >> T;
    while(T--)
    {
        int num;
        cout << "Enter num : ";
        cin >> num;

        vector<int> factors = factorize(primes, num);

        for(auto x : factors)
        cout << x << " ";
        cout << endl;
    }
}