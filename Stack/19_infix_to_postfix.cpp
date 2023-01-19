#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        unordered_map<char, bool> op;
        op['+'] = true;
        op['-'] = true;
        op['*'] = true;
        op['/'] = true;
        op['^'] = true;
        op['('] = true;
        op[')'] = true;

        unordered_map<char, int> in, out;
        in['+'] = in['-'] = 2;
        in['*'] = in['/'] = 4;
        in['^'] = 5;
        in['('] = 0;
        out['+'] = out['-'] = 1;
        out['*'] = out['/'] = 3;
        out['^'] = 6;
        out['('] = 7;
        out[')'] = 0;

        string ans = "";
        stack<char> st;
        int i = 0;
        int n = s.size();
        while (i < n)
        {
            char ch = s[i];
            if (op.count(ch))
            {
                if (st.empty() || out[ch] > in[st.top()])
                {
                    st.push(ch);
                    i++;
                }
                else
                {
                    if (ch == ')')
                    {
                        while (st.top() != '(')
                        {
                            ans.push_back(st.top());
                            st.pop();
                        }
                        i++;
                    }
                    else
                    {
                        ans.push_back(st.top());
                    }
                    st.pop();
                }
            }
            else
            {
                ans.push_back(ch);
                i++;
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    string infixToPostfix1(string s)
    {
        unordered_map<char, bool> op;
        op['+'] = true;
        op['-'] = true;
        op['*'] = true;
        op['/'] = true;
        op['^'] = true;
        op['('] = true;
        op[')'] = true;
        unordered_map<char, int> pre;
        pre['+'] = pre['-'] = 1;
        pre['*'] = pre['/'] = 2;
        pre['^'] = 3;

        int i = 0;
        string ans;
        int n = s.size();
        stack<char> st;
        while (i < n)
        {
            char ch = s[i];
            if (op.count(ch) == 0)
            {
                ans.push_back(ch);
                i++;
            }
            else if (ch == '(')
            {
                st.push(ch);
                i++;
            }
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
                i++;
            }
            else
            {
                if (st.empty())
                {
                    st.push(ch);
                    i++;
                }
                else
                {
                    if (pre[ch] > pre[st.top()])
                    {
                        st.push(ch);
                        i++;
                    }
                    else if (pre[ch] < pre[st.top()])
                    {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    else
                    {
                        if (ch == '^' && st.top() == '^')
                        {
                            st.push(ch);
                            i++;
                        }
                        else
                        {
                            ans.push_back(st.top());
                            st.pop();
                        }
                    }
                }
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
class Solution1
{

    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        stack<char> st; // For stack operations, we are using
                        // C++ built in stack
        string result;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            // If the scanned character is
            // an operand, add it to output string.
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                result += c;

            // If the scanned character is an
            // ‘(‘, push it to the stack.
            else if (c == '(')
                st.push('(');

            // If the scanned character is an ‘)’,
            // pop and to output string from the stack
            // until an ‘(‘ is encountered.
            else if (c == ')')
            {
                while (st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }

            // If an operator is scanned
            else
            {
                while (!st.empty() && prec(s[i]) <= prec(st.top()))
                {
                    if (c == '^' && st.top() != '^')
                        break;
                    else
                    {
                        result += st.top();
                        st.pop();
                    }
                }
                st.push(c);
            }
        }

        // Pop all the remaining elements from the stack
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    Solution sln;
    cout << sln.infixToPostfix1(s) << endl;
    return 0;
}