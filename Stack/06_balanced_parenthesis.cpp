#include<iostream>
#include<stack>
using namespace std;

char inp[100001];
bool isOpen(char ch)
{
    if (ch == '(' || ch == '[' || ch == '{')
        return true;
    return false;
}
bool isValid(char* s)
{
    int i = 0;
    stack<char> st;
    while (s[i] != '\0')
    {
        if (isOpen(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return false;

            switch (s[i])
            {
            case ')':
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
                break;
            case ']':
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
                break;
            case '}':
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
                break;
            }
        }
        i++;
    }
    if (st.empty())
        return true;
    else
        return false;
}
int main()
{
    cin >> inp;
    if(isValid(inp))
    cout << "Yes" << endl;
    else
    cout << "No" << endl;
}