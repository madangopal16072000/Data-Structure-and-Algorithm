#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int Q;
    cin >> Q;
    stack<int> st;
    int ch, cost;
    while (Q--)
    {
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            if (!st.empty())
            {
                cout << st.top() << endl;
                st.pop();
            }
            else
                cout << "No Code" << endl;

            break;
        }
        case 2:
        {
            cin >> cost;
            st.push(cost);
            break;
        }
        }
    }
}