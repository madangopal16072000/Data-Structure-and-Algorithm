#include<iostream>
using namespace std;


void bracket(char out[], int i, int op, int cl, int N)
{
    // base case
    if(op == 2 && cl == 2)
    {
        out[i] = '\0';
        cout << out << endl;
        return;
    }
    // rec case
    if(op <= N)
    {
        out[i] = '(';
        bracket(out, i+1, op+1, cl, N);
    }

    if(cl < op)
    {
        out[i] = ')';
        bracket(out, i+1, op, cl+1, N);
    }
    return;


}
int main()
{
    int N;
    cin >> N;
    char out[12];
    bracket(out, 0, 0, 0, N);
    return 0;
}