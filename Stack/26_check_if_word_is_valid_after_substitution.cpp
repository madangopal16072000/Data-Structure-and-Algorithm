#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s)
        {
            if(ch == 'c')
            {
                if(!st.empty() && st.top() == ch-1)
                {
                    ch = st.top();
                    st.pop();

                    if(!st.empty() && st.top() == ch-1)
                    {
                        ch = st.top();
                        st.pop();
                    }
                    else
                    {
                        st.push(ch);
                    }
                }
                else
                {
                    st.push(ch);
                }
            }
            else
            st.push(ch);
        }

        return st.empty();
    }
};
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  string s = "abacbcabcc";
  Solution sln;
  cout << sln.isValid(s) << endl;
  return 0;
}