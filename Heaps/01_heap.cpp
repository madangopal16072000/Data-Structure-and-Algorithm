#include<iostream>
#include<vector>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;
    bool compare(int a, int b)
    {
        if(minHeap)
        return a < b;
        else
        return a > b;
    }
    public:
    Heap(int defaultSize = 10, bool type = true)
    {
        v.reserve(defaultSize);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx/2;

        while(idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        int last = v.size()-1;
        swap(v[last], v[1]);
        v.pop_back();
        heapify(1);
    }

    void heapify(int idx)
    {
        int left = 2*idx;
        int right = 2*idx + 1;
        int minIdx = idx;
        int last = v.size() - 1;

        if(left <= last && compare(v[left], v[minIdx]))
        {
            minIdx = left;
        }

        if(right <= last && compare(v[right], v[minIdx]))
        {
            minIdx = right;
        }

        if(minIdx != idx)
        {
            swap(v[idx], v[minIdx]);
            heapify(minIdx);
        }
    }

    bool empty()
    {
        return v.size() == 1;
    }
};
int main()
{
    Heap h;
    for(int i=0; i<5; i++)
    {
        int d;
        cin >> d;
        h.push(d);
    }

    while(!h.empty())
    {
        int val = h.top();
        h.pop();
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
