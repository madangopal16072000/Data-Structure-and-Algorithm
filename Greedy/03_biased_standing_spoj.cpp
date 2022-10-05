#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int arr[100000];
int main()
{
    int t, n;
    cin >> t;
    cout << endl;
    while(t--)
    {
        cin >> n;
        string name;
        int rank;
        for(int i = 0; i < n; i++)
        {
            cin >> name >> rank;
            arr[rank]++;
        }
        int ans = 0;
        int actualRank = 1;
        for(int i = 1; i <= n; i++)
        {
            while(arr[i])
            {
                ans += abs(actualRank - i);
                actualRank++;
                arr[i]--;
            }
        }
        cout << ans << endl;
    }
}