#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int Q, k;
    cin >> Q >> k;
    priority_queue<long long> pq;
    while (Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            cin >> x >> y;
            int dist = x * x + y * y;
            pq.push(dist);
            while(pq.size() > k)
            {
                pq.pop();
            }
        }
        else if (type == 2)
        {
            cout << pq.top() << endl;
        }
    }
}