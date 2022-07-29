#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    v.push_back(10);
    for(int x : v)
    cout << x << " ";
    cout << endl;

    // using insert method
    vector<int> a {10, 20, 30, 40, 50};
    v.insert(v.begin() + 3, 100);
    v.insert(v.begin() + 4, 4, 100);
    v.insert(v.begin() + 3, a.begin(), a.end());
    for(int x : v)
    cout << x << " ";
    cout << endl;
    v.erase(v.begin() + 3);
    
    for(int x : v)
    cout << x << " ";
    cout << endl;
    v.erase(v.begin() + 4, v.begin() + 11);
    for(int x : v)
    cout << x << " ";
    cout << endl;

    v.clear();
    for(int x : v)
    cout << x  << " ";
    cout << endl;

    if(v.empty())
    cout << "is Empty " << endl;
    else
    cout << "not empty " << endl;

    cout << a.front() << endl;

    cout << a.back() << endl;
    return 0;
}