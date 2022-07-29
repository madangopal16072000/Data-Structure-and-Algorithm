#include<iostream>
#include<unordered_map>
#include<math.h>
using namespace std;

int main()
{
    unordered_map<int, int> factors{0};
    int num;
    cout << "Enter number : ";
    cin >> num;
    int i;
    for(i=2; i<=sqrt(num); i++)
    {
        if(num % i == 0)
        {
            while(num%i == 0)
            num = num/i;
            factors[i]++;
        }
    }
    if(i!=1)
    factors[num]++;

    for(auto i : factors)
    cout << i.first << " " << i.second << endl;
    return 0;
}