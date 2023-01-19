#include<bits/stdc++.h>
using namespace std;
class MinStack {
    stack<long long> st;
    int mini = INT_MIN;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long value = val;
        if(st.empty())
        {
            st.push(value);
            mini = value;
        }
        else
        {
            if(val < mini)
            {
                st.push((long long)2*value-mini);
                mini = val;
            }
            else
            {
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty())
        return;

        long long el = st.top();
        st.pop();

        if(el < mini)
        {
            mini = 2*mini - el;
        }
    }
    
    int top() {
        if(st.empty())
        return -1;

        long long el = st.top();

        if(el < mini)
        {
            return mini;
        }
        
        return el;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("./input.txt", "r", stdin);
//   freopen("./output.txt", "w", stdout);
// #endif
  MinStack *obj = new MinStack();

  obj->push(-2);
  obj->push(0);
  obj->push(-3);

  cout << obj->getMin() << endl;
  obj->pop();
  cout << obj->top() << endl;
  cout << obj->getMin() << endl;
  return 0;
}