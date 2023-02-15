#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int n;
    vector<int> st;

public:
    SegmentTree(int m)
    {
        n = m;
        st.resize(4 * n, 0);
    }
    void build(int start, int ending, int node, vector<int> &v)
    {
        // base case
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }

        int mid = start + (ending - start) / 2;

        // left tree
        build(start, mid, 2 * node + 1, v);
        // right tree
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    int query(int start, int ending, int l, int r, int node)
    {
        // no overlap
        if (ending < l || start > r)
            return 0;

        // complete overlap
        if (l <= start && r >= ending)
        {
            return st[node];
        }

        // partial overlapping
        int mid = start + (ending - start) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return q1 + q2;
    }

    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] = value;
            return;
        }

        int mid = start + (ending - start) / 2;

        if (index <= mid)
            update(start, mid, 2 * node + 1, index, value);
        else
            update(mid + 1, ending, 2 * node + 2, index, value);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
        return;
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int index, int value)
    {
        update(0, n - 1, 0, index, value);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    SegmentTree t(n);
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        vec.push_back(d);
    }

    t.build(vec);
    cout << t.query(4, 5) << endl;
    cout << t.query(2, 5) << endl;

    t.update(3, 10);
    cout << t.query(1, 5) << endl;
    return 0;
}