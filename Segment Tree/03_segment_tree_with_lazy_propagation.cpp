#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int n;
    vector<int> st, lazy;

public:
    SegmentTree(int m)
    {
        n = m;
        st.resize(4 * n, 0);
        lazy.resize(4 * m, 0);
    }

    void build(int s, int e, int node, vector<int> &v)
    {
        // base case
        if (s == e)
        {
            st[node] = v[s];
            return;
        }

        int mid = s + (e - s) / 2;

        build(s, mid, 2 * node + 1, v);
        build(mid + 1, e, 2 * node + 2, v);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
        return;
    }

    void update(int s, int e, int node, int l, int r, int val)
    {
        // no overlapping
        if (e < l || s > r)
            return;

        // lazy propagation
        if (lazy[node] != 0)
        {
            // pending updates
            st[node] = st[node] + lazy[node] * (e - s + 1);
            if (s != e)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // complete overlap
        if (l <= s && r >= e)
        {
            st[node] = st[node] + val * (e - s + 1);
            if (s != e)
            {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        // partial overlap
        int mid = s + (e - s) / 2;
        update(s, mid, 2 * node + 1, l, r, val);
        update(mid + 1, e, 2 * node + 2, l, r, val);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
        return;
    }

    int query(int s, int e, int node, int l, int r)
    {
        // no overlap
        if (e < l || s > r)
            return 0;

        // lazy propagation
        if (lazy[node] != 0)
        {
            st[node] += lazy[node] * (e - s + 1);
            if (s != e)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // complete ovelap
        if (s >= l && e <= r)
        {
            return st[node];
        }

        // partial overlap
        int mid = s + (e - s) / 2;

        int q1 = query(s, mid, 2 * node + 1, l, r);
        int q2 = query(mid + 1, e, 2 * node + 2, l, r);

        return q1 + q2;
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    void update(int l, int r, int val)
    {
        update(0, n - 1, 0, l, r, val);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, 0, l, r);
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
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }

    SegmentTree t(n);
    t.build(v);

    cout << t.query(2, 4) << endl;
    t.update(0, 7, 5);
    cout << t.query(2, 4) << endl;
    return 0;
}