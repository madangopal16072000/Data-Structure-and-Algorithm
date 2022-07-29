#include<iostream>
#include<vector>

using namespace std;

bool compare(int a, int b)
{
    return a > b ? true : false;
}

void heapify(vector<int> &v, int i)
{
    int left = 2*i;
    int right = 2*i + 1;
    int last = v.size() - 1;
    int maxIdx = i;

    if(left <= last && compare(v[left], v[maxIdx]))
    maxIdx = left;

    if(right <= last && compare(v[right], v[maxIdx]))
    maxIdx = right;

    if(i != maxIdx)
    {
        swap(v[i], v[maxIdx]);
        heapify(v, maxIdx);
    }
}
ostream& operator<<(ostream &os, vector<int> v)
{
    for(auto x : v)
    os << x << " ";
    return os;
}

void buildHeap(vector<int> &v)
{
    for(int i=v.size()/2; i>=1; i--)
    {
        heapify(v, i);
    }
}
int main()
{
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    cout << v << endl;
    buildHeap(v);
    cout << v << endl;
    return 0;
}