#include<iostream>
#include<unordered_map>
using namespace std;

int arr[100000];
int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    cin >> arr[i];

    int ans = 0;
    unordered_map<int, int> m;
    int j = 0;
    for(int i = 0; i < N; i++)
    {
        while(j < N && m[arr[j]] <= 0)
        {
            m[arr[j]]++;
            j++;
        }
        ans += ((j-i)*(j-i+1))/2;
        m.erase(arr[i]);
    }
    cout << ans << endl;
    return 0;
}