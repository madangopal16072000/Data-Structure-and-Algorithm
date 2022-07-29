#include<iostream>
#include<algorithm>

using namespace std;
bool compare(int a, int b)
{
    return a<=b;
}
int main()
{
    int coins[] = {1, 2, 5, 10, 50, 100, 200, 500, 1000};
    int n = sizeof(coins)/sizeof(int);
    int money;
    cin >> money;


    auto lb = lower_bound(coins, coins + n, compare) - coins - 1;
    cout << lb << " Money : " << coins[lb] << endl;

    return 0;
}