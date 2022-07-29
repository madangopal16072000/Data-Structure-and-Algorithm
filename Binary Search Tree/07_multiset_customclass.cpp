#include<iostream>
#include<set>

using namespace std;
class person_compare
{
    public:
    bool operator()(pair<string, int> p1, pair<string, int> p2)
    {
        return p1.second < p2.second;
    }
};
int main()
{
    pair<string, int> p1 = make_pair("B", 120);
    pair<string, int> p2 = make_pair("A", 100);
    pair<string, int> p3 = make_pair("C", 50);
    pair<string, int> p4 = make_pair("D", 30);

    multiset<pair<string, int>, person_compare> m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);

    for(auto p : m)
    cout << p.first << " and " << p.second << endl;
}