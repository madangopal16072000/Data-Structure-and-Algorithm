#include<iostream>
#include<stack>
using namespace std;

void display(stack<int> s1)
{
    while(!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    for(int i=0; i<n; i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void reverseStack(stack<int> &s1)
{
    // helper stack
    stack<int> s2;
    int n = s1.size();

    for(int i=0; i<n; i++)
    {
        int x = s1.top();
        s1.pop();

        // transfer n - i -1 elements from stack s1 to s2;
        transfer(s1, s2, n-i-1);

        // insert x into stack s1;
        s1.push(x);

        // transfer n - i -1 elements from stack s2 to s1;
        transfer(s2, s1, n-i-1);
    }
}
// Recursive Method

void insertAtBottom(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
    return;
}
void reverseStackR(stack<int> &s)
{
    if(s.empty())
    return;

    int x = s.top();
    s.pop();
    reverseStackR(s);
    insertAtBottom(s, x);
    return;
}
int main()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    cout << "Initial Stack : ";
    display(s1);
    cout << endl;
    reverseStackR(s1);
    cout << "Reversed Stack : ";
    display(s1);
    return 0;
}