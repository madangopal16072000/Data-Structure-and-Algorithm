#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

bool isOperand(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
    return false;
    else
    return true;
}

int pre(char ch)
{
    switch(ch)
    {
        case '+' : return 1;
        case '-' : return 1;
        case '*' : return 2;
        case '/' : return 2;
        case '(' : return 3;
        case ')' : return 3;
        default : break;
    }
    return 0;
}

void infixToPostfix(char *str,char *postfix)
{
    

    stack<char> st;

    int i = 0, j = 0;
    while(str[i] != '\0')
    {
        if(isOperand(str[i]))
        {
            postfix[j++] = str[i++];
        }
        else
        {
            if(st.empty() || pre(str[i]) > pre(st.top()))
            {
                st.push(str[i++]);
            }
            else
            {
                postfix[j++] = st.top();
                st.pop();
            }
        }
    }
    while(!st.empty())
    {
        postfix[j++] = st.top();
        st.pop();
    }
    postfix[j] = '\0';

}

int main()
{
    char str[] = "a+b*(c^d-e)^(f+g*h)-i";
    char *postfix = new char[50];
    infixToPostfix(str, postfix);
    cout << postfix << endl;
    return 0;
}