#include<iostream>
#include<stack>
using namespace std;

int price[1000000];
int span[1000000] = {0};

void stockSpan(int N)
{
    stack<int> st;
    st.push(0);
    span[0] = 1;
    for(int i=1; i<N; i++)
    {
        int currentPrice = price[i];
        while(!st.empty() && currentPrice > price[st.top()])
        st.pop();

        if(!st.empty())
        {
            int prevHeight = st.top();
            span[i] = i - st.top();
        }
        else
        {
            span[i] = i+1;
        }

        st.push(i);
    }
}
int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    cin >> price[i];

    stockSpan(N);

    for(int i=0; i<N; i++)
    {
        cout << span[i] << " ";
    }
    cout << "END" << endl;
}