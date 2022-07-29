#include<iostream>
#include<set>

using namespace std;
int main()
{
    int arr[] = {10, 30, 50, 20, 10, 10, 30, 80};
    int n = sizeof(arr)/sizeof(int);

    multiset<int> s(arr, arr+n);

    for(multiset<int>::iterator it = s.begin(); it!=s.end(); it++)
    cout << *it << " ";
    cout << endl;
    s.erase(s.find(10));
    for(auto x : s)
    cout << x << " ";
    cout << endl;

    pair<multiset<int>::iterator, multiset<int>::iterator> range = s.equal_range(10);
    for(auto it = range.first; it!=range.second; it++)
    cout << *it << " ";

    cout << *s.lower_bound(40) << endl;
    cout << *s.upper_bound(30) << endl;

}