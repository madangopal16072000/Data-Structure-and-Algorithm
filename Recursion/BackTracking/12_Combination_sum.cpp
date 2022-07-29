#include<iostream>
#include<vector>
#include<set>
using namespace std;

void combinationSum(vector<int> &A, int B, set<vector<int>> &s, int i, int sum, vector<int> &out)
{
    
    if(sum == B)
    {
        s.insert(out);
        return;
    }

    if(i == A.size())
    return;
    if(sum > B)
    return;

    sum = sum + A[i];
    out.push_back(A[i]);
    combinationSum(A, B, s, i, sum, out);
    sum = sum - A[i];
    out.pop_back();
    combinationSum(A, B, s, i+1, sum, out);

    return;
}
int main()
{
    vector<int> A;
    int N;
    cin >> N;
    A.reserve(N);
    for(int i=0; i<N; i++)
    {
        int d;
        cin >> d;
        A.push_back(d);
    }

    int B;
    cin >> B;
    set<vector<int>> s;
    vector<int> out;
    combinationSum(A, B, s, 0, 0, out);

    for(auto vec : s)
    {
        for(auto x : vec)
        cout << x << " ";
        cout << endl;
    }

    return 0;
}