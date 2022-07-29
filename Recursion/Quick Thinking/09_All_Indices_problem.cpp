#include<iostream>
#include<vector>
using namespace std;
#define MAX 100001
int allIndices(int in[], int out[], int N, int M, int i, int j)
{
    if(i == N)
    return j;
    if(in[i] == M)
    {
        out[j] = i;
        return allIndices(in, out, N, M, i+1, j+1);
    }
    return allIndices(in, out, N, M, i+1, j);
}
int main()
{
    int N;
    cin >> N;
    int in[MAX];
    for(int i=0; i<N; i++)
    cin >> in[i];
    int M;
    cin >> M;
    int out[MAX];
    int size = allIndices(in, out, N, M, 0, 0);
    
    for(int i=0; i<size; i++)
    cout << out[i] << " ";
    return 0;

}