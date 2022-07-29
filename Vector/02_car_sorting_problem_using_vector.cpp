#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    int d1 = p1.first*p1.first + p1.second*p1.second;
    int d2 = p2.first*p2.first + p2.second*p2.second;

    if(d1 == d2)
    return p1.first < p2.first;
    else
    return d1 < d2;
}
int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> vec;
    vec.reserve(N);
    int x, y;
    for(int i=0; i<N; i++)
    {
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end(), compare);

    // for(auto x : vec)
    // cout << x.first << ", " << x.second << endl;

    for(int i=0; i<N; i++)
    {
        cout << vec[i].first << ", " << vec[i].second << endl;
    }

    return 0;
}