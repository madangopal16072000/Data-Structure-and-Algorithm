#include<iostream>
#include<algorithm>
using namespace std;

int makeChange(int *coins, int n, int money)
{
    int ans = 0;
    while(money > 0)
    {
        int idx = upper_bound(coins, coins + n, money) - coins - 1;
        cout << coins[idx] << endl;
        money = money - coins[idx];
        ans++;
    }
    return ans;
}
int main()
{
    int money;
    cout << "Enter money : ";
    cin >> money;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    cout << makeChange(coins, sizeof(coins)/sizeof(int), money);
    return 0;
}