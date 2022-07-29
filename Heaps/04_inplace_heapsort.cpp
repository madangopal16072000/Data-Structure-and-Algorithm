#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int> &v, int idx, int size)
{
    int left = 2*idx;
    int right = 2*idx + 1;
    int last = size-1;
    int maxIdx = idx;

    if(left <= last && v[left] < v[maxIdx])
    maxIdx = left;

    if(right <= last && v[right] < v[maxIdx])
    maxIdx = right;

    if(idx != maxIdx)
    {
        swap(v[idx], v[maxIdx]);
        heapify(v, maxIdx, size);
    }
}
void buildHeap(vector<int> &v)
{
    int size = v.size();
    for(int i = size/2; i >= 1; i--)
    {
        heapify(v, i, size);
    }
}
void heapsort(vector<int> &v)
{
    buildHeap(v);
    for(auto x : v)
    cout << x << " ";
    cout << endl;
    int n = v.size();
    while(n > 1)
    {
        swap(v[1], v[n-1]);
        n--;
        heapify(v, 1, n);
    }
}
int main()
{
    vector<int> v;
    int size;
    cout << "Enter size : ";
    cin >> size;
    v.push_back(-1);
    for(int i=1; i<=size; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }

    heapsort(v);
    for(auto x : v)
    cout << x << " ";
    cout << endl;
    return 0;
}