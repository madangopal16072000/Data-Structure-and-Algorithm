#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    vector<pair<int, int>> vec = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    sort(vec.begin(), vec.end(), compare);

    // for(int i=0; i<vec.size(); i++)
    // {
    //     cout << "( " << vec[i].first << ", " << vec[i].second << " )" << endl;
    // }
    int i = 0;
    cout << "( " << vec[i].first << ", " << vec[i].second << " )" << endl;

    for(int j=1; j<vec.size(); j++)
    {
        if(vec[j].first > vec[i].second)
        {
            cout << "( " << vec[j].first << ", " << vec[j].second << " )" << endl;
            i = j;
        }
    }
    

}