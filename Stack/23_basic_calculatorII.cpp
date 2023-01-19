#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> infixToPostfix(string s)
    {
        unordered_map<char, int> pred{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
        stack<char> st;
        vector<string> exp;
        string temp = "";
        for (char ch : s)
        {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                exp.push_back(temp);
                temp = "";
                while (!st.empty() && pred[st.top()] >= pred[ch])
                {
                    temp = temp + st.top();
                    exp.push_back(temp);
                    temp = "";
                    st.pop();
                }
                st.push(ch);
                continue;
            }
            if (ch != ' ')
                temp = temp + ch;
        }
        exp.push_back(temp);
        temp = "";
        while (!st.empty())
        {
            temp = temp + st.top();
            exp.push_back(temp);
            temp = "";
            st.pop();
        }
        return exp;
    }
    int calculate(string s)
    {

        vector<string> exp = infixToPostfix(s);
        stack<int> st;
        for (string str : exp)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                int val = 0;
                if (str == "+")
                {
                    val = op1 + op2;
                }
                else if (str == "-")
                {
                    val = op1 - op2;
                }
                else if (str == "/")
                {
                    val = op1 / op2;
                }
                else
                {
                    val = op1 * op2;
                }
                st.push(val);
            }
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
int main()
{
    string s = "1*2-3/4+5*6-7*8+9/10";
    Solution sln;
    cout << sln.calculate(s) << endl;
    return 0;
}