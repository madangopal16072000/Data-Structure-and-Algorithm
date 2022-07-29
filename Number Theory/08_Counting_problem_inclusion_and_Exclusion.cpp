#include<iostream>
using namespace std;

int main()
{
    int T;
    cout << "Enter number of Test Cases : ";
    cin >> T;
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int primeSize = sizeof(primes)/sizeof(int);
    int subsets = (1 << primeSize);
    while(T--)
    {
        int num;
        cout << "Enter number : ";
        cin >> num;
        int ans = 0;
        for(int i=1; i<subsets; i++)
        {
            int den = 1;
            int setBits = __builtin_popcount(i);
            for(int j=0; j<primeSize; j++)
            {
                if( i & (1 << j))
                den = den*primes[j];
            }
            if(setBits & 1)
            ans = ans + num/den;
            else
            ans = ans - num/den;
            

        }
        cout << "Answer : " << ans << endl;

    }
}