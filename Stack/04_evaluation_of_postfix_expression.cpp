#include<iostream>
#include<string>
#include<stack>

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

string infixToPostfix(string infix)
{
    string postfix;
    int i = 0;
    stack<char> st;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        {
            postfix.push_back(infix[i++]);
        }
        else
        {
            if(st.empty() || pre(infix[i]) > pre(st.top()))
            {
                st.push(infix[i++]);
            }
            else
            {
                postfix.push_back(st.top());
                st.pop();
            }
        }
    }
    while(!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}
int evaluate(string postfix)
{
    int i = 0;
    stack<int> st;
    while(postfix[i] != '\0')
    {
        if(isOperand(postfix[i]))
        {
            st.push(postfix[i++] - '0');
        }
        else
        {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();
            int result = 0;
            switch(postfix[i])
            {
                case '+' :
                result = operand1 + operand2;
                break;
                case '-' :
                result = operand2 - operand1;
                break;
                case '*' : 
                result = operand1*operand2;
                break;
                case '/' : 
                result = operand2/operand1;
            }
            st.push(result);
            i++;
        }
    }
    return st.top();
}
int main()
{
    string infix = "6+5+3*4";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
    int result = evaluate(postfix);
    cout << result << endl;
    return 0;
}