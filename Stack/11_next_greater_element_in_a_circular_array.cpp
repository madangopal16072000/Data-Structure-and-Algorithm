#include<iostream>
#include<stack>

using namespace std;
int a[1000000];
int nge[1000000];
void nextGreaterElement(int a[], int n)
{
    stack<int> st;
    for(int i = 2*n-1; i>=0; i--)
    {
        while(!st.empty() && a[i%n] >= a[st.top()])
        st.pop();

        if(i < n)
        {
            if(!st.empty())
            {
                nge[i] = a[st.top()];
            }
            else
            nge[i] = -1;
        }
        st.push(i%n);
    }
    for(int i = 0; i<n; i++)
    cout << nge[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    nextGreaterElement(a, n);
    return 0;
}