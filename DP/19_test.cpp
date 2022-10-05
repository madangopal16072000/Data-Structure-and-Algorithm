#include <iostream>
using namespace std;

void countStrings(int i, int n, int lastDigit, int &ans)
{
    // base case
    if (i == n)
    {
        ans++;
        return;
    }

    // recursive case
    if (lastDigit == 0)
    {
        countStrings(i + 1, n, 0, ans);
        countStrings(i + 1, n, 1, ans);
    }

    else
        countStrings(i + 1, n, 0, ans);
}
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    countStrings(0, n, 0, ans);
    // countStrings(0, n, 1, ans);
    cout << ans << endl;
    return 0;
}