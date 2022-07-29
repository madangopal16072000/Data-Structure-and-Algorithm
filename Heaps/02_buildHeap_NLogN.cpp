#include<iostream>
#include<vector>
using namespace std;

bool compare(int a, int b)
{
    return a > b ? true : false;
}
void buildHeap(vector<int> &v)
{
    for(int i=2; i<v.size(); i++)
    {
        int idx = i;
        int parent = idx/2;

        while(idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

ostream& operator<<(ostream &os, vector<int> v)
{
    for(auto x : v)
    os << x << " ";
    return os;
}
int main()
{
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    cout << v << endl;
    buildHeap(v);
    cout << v << endl;
    return 0;

}