#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool redundantParenthesis(string s)
{
    stack<char> st;
    for(int i=0; s[i] != '\0'; i++)
    {
        if(s[i] == ')')
        {
            if(st.top() == '(')
            return true;

            // poping all operands and operator
            while(st.top() != '(')
            st.pop();

            // poping 1 operning brace for 1 closing brace
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {

    string s;
    cin >> s;
    
    if(redundantParenthesis(s))
    cout << "Dupliate" << endl;
    else
    cout << "Not Duplicates" << endl;
    }
}