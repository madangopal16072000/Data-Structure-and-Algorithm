#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
void game(int maxSum, vector<int> a, vector<int> b, int sum, int cnt, int i, int j)
{
    // base case
    if (sum > maxSum)
    {
        return;
    }

    if (i == a.size() || j == b.size())
        return;
    // rec case
    game(maxSum, a, b, sum + a[i], cnt + 1, i + 1, j);

    game(maxSum, a, b, sum + b[j], cnt + 1, i, j + 1);
}
int main()
{
    vector<int> a;
    vector<int> b;
    int g;
    cin >> g;
    while (g--)
    {
        int n, m;
        int maxSum;
        cin >> n >> m >> maxSum;
        for (int i = 0; i < n; i++)
        {
            int d;
            cin >> d;
            a.push_back(d);
        }
        for (int i = 0; i < m; i++)
        {
            int d;
            cin >> d;
            b.push_back(d);
        }
        for (auto x : a)
            cout << x << " ";
        cout << endl;

        for (auto x : b)
            cout << x << " ";
        cout << endl;
        game(maxSum, a, b, 0, cnt, 0, 0);
        cout << cnt;
    }
}
