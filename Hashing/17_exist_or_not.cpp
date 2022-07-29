#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int L;
        cin >> L;
        unordered_map<int, bool> m;
        for (int i = 0; i < L; i++)
        {
            int d;
            cin >> d;
            m[d] = true;
        }

        int Q;
        cin >> Q;
        while (Q--)
        {
            int key;
            cin >> key;
            if (m[key])
                cout << "Yes";
            else
                cout << "No";
            cout << endl;
        }
    }
    return 0;
}