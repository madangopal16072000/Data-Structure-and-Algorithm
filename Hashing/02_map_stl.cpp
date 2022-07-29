#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string, int> m;
    m["Banana"] = 5;
    m["Mango"] = 10;
    m["Apple"] = 7;

    string fruit;
    cin >> fruit;
    auto f = m.find(fruit);
    if(f != m.end())
    {
        cout << fruit << " : " << m[fruit] << endl;
    }
    else
    cout << "Not Found" << endl;

    m.erase(fruit);

    if(m.count(fruit))
    cout << "Price of " << fruit << " : " << m[fruit] << endl;
    else
    cout << "Not Found" << endl;

    m["Pineapple"] = 10;
    m["Grapes"] = 8;

    for(map<string, int>::iterator it = m.begin(); it!=m.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }

    cout << endl;
    // for each loo
    for(pair p : m)
    cout << p.first << " : " << p.second << endl;
    return 0;
}