#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}
int main()
{
    int n;
    cin >> n;
    int d, f;
    int ans = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> f;
        v.push_back(make_pair(d, f));
    }

    sort(v.begin(), v.end(), compare);

    int L, P;
    cin >> L >> P;
    for (int i = 0; i < n; i++)
    {
        v[i].first = L - v[i].first;
    }

    int prev = 0;
    int x = 0;
    priority_queue<int> pq;
    int flag = 0;
    while (x < n)
    {
        if (P >= (v[x].first - prev))
        {
            P = P - (v[x].first - prev);
            pq.push(v[x].second);
            prev = v[x].first;
        }
        else
        {
            if (pq.empty())
            {
                flag = 1;
                break;
            }
            P += pq.top();
            pq.pop();
            ans += 1;
            continue;
        }
        x++;
    }

    if (flag == 1)
    {
        cout << -1 << endl;
    }

    L = L - v[n - 1].first;
    if (P >= L)
    {
        cout << ans << endl;
    }
    else
    {
        while (P < L)
        {
            if (pq.empty())
            {
                flag = 1;
                break;
            }
            P += pq.top();
            pq.pop();
            ans = ans + 1;
        }

        if (flag == 1)
        {
            cout << -1 << endl;
        }

        cout << ans << endl;
    }

    return 0;
}