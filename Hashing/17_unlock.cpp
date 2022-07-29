#include<iostream>
using namespace std;

int input[100000];

int idxSearch(int key, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(key == input[i])
        break;
    }
    return i == size ? -1 : i;
}
int main()
{
    int N;
    long long K;
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    long long cnt = 1;
    for(int i = N; i >= 1 && cnt <= K; i--)
    {
        int bestPos = N - i;
        int currPos = idxSearch(i, N);
        if(bestPos != currPos)
        {
            swap(input[bestPos], input[currPos]);
            cnt++;
        }
    }

    for(int i = 0; i < N; i++)
    cout << input[i] << " ";
    return 0;
}