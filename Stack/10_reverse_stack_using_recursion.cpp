#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(top);
}
void reverseStack(stack<int> &s)
{
    if(s.empty())
    return;

    int top = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, top);
}
int main()
{
    int N;
    cin >> N;
    stack<int> s;
    for(int i=0; i<N; i++)
    {
        int data;
        cin >> data;
        s.push(data);
    }
    reverseStack(s);
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}