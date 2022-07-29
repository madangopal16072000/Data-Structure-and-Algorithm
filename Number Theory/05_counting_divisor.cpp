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
            for(int j = i*i; j<1000; j+=i)
            p[j] = 0;
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
}
vector<int> primeList(int p[], int n)
{
    vector<int> primes;
    // primeSieve(p);
    int j = 0;
    for(int i=0; i<1000 && j < n; i++, j++)
    {
        if(p[i] == 1)
        primes.push_back(i);
    }
    return primes;
}
int countNoDivisor(vector<int> primes, int n)
{
    int ans = 1;
    int i = 0;
    int pm = primes[0];

    while(pm*pm <= n)
    {
        if(n % pm == 0)
        {
            int count = 0;
            while(n % pm == 0)
            {
                count++;
                n = n / pm;
            }
            ans = ans*(count + 1);
        }
        i++;
        pm = primes[i];

    }
    if(n != 1)
    ans = ans*(2);
    return ans;
}
int main()
{
    int p[1000] = {0};
    primeSieve(p);
    vector<int> primes = primeList(p, 100);

    int T;
    cout << "Enter number of Test Cases : ";
    cin >> T;
    while(T--)
    {
        int n;
        cout << "Enter number : ";
        cin >> n;
        int result = countNoDivisor(primes, n);
        cout << result << endl;
    }
}