#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    int load = 0;
    int maxLoad = 0;
    int diff = 0;
    for(int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        vec.push_back(d);
        load += d;
    }

    if(load%n)
    {
        cout << -1 << endl;
        return 0;
    }
    load = load/n;

    for(int i = 0; i < n; i++)
    {
        diff += load - vec[i];
        int ans = max(diff, -1*diff);
        maxLoad = max(maxLoad, ans);
    }

    cout << maxLoad << endl;
    
}