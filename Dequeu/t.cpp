#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void parse(string expression, stack<char> &st, stack<char> &op)
    {
        if(op.top() == '&')
        {
            op.pop();
            bool val = true;
            while(st.top() != '(')
            {
                if(st.top() == 'f')
                {
                    val = false;
                }
                st.pop();
            }
            st.pop();
            if(val)
            st.push('t');
            else
            st.push('f');
        }
        else if(op.top() == '|')
        {
            bool val = false;
            op.pop();
            while(st.top() != '(')
            {
                if(st.top() == 't')
                val = true;
                st.pop();
            }
            st.pop();
            if(val)
            st.push('t');
            else
            st.push('f');

        }
        else if(op.top() == '!')
        {
            op.pop();
            if(st.top() == 't')
            {
                st.pop();
                st.pop();
                st.push('f');
            }
            else
            {
                st.pop();
                st.pop();
                st.push('t');
            }
        }
    }
    bool parseBoolExpr(string expression) {
        stack<char> st, op;
        for(int i = 0; i < expression.size(); i++)
        {
            if(expression[i] == '!' || expression[i] == '&' || expression[i] == '|')
            {
                op.push(expression[i]);
            }
            else if(expression[i] == '(' || expression[i] == 't' || expression[i] == 'f')
            {
                st.push(expression[i]);
            }
            else if(expression[i] == ')')
            {
                parse(expression, st, op);
            }
        }

        if(st.top() == 't')
        return true;
        else
        return false;
    }
};
int main()
{
    string exp = "!(f)";

    Solution s;
    cout << s.parseBoolExpr(exp) << endl;
    return 0;
}