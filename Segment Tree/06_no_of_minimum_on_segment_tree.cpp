#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    int n;
    vector<pair<int, int>> st;

public:
    SegmentTree(int m)
    {
        n = m;
        st.resize(4 * n, {0, 0});
    }

    void build(int s, int e, int node, vector<int> &v)
    {
        // base case
        if (s == e)
        {
            st[node] = {v[s], 1};
            return;
        }

        int mid = s + (e - s) / 2;
        build(s, mid, 2 * node + 1, v);
        build(mid + 1, e, 2 * node + 2, v);

        pair<int, int> p1, p2;
        p1 = st[2 * node + 1];
        p2 = st[2 * node + 2];

        if (p1.first == p2.first)
        {
            st[node] = {p1.first, p1.second + p2.second};
        }
        else if (p1.first < p2.first)
        {
            st[node] = {p1.first, p1.second};
        }
        else
        {
            st[node] = {p2.first, p2.second};
        }
    }

    pair<int, int> query(int s, int e, int node, int l, int r)
    {
        // no overlap
        if (e < l || s > r)
            return {INT_MAX, 0};

        // complete overlap
        if (l <= s && e <= r)
        {
            return st[node];
        }

        // partial overlap
        int mid = s + (e - s) / 2;

        pair<int, int> p1 = query(s, mid, 2 * node + 1, l, r);
        pair<int, int> p2 = query(mid + 1, e, 2 * node + 2, l, r);

        if (p1.first == p2.first)
        {
            return {p1.first, p1.second + p2.second};
        }
        else if (p1.first < p2.first)
        {
            return {p1.first, p1.second};
        }
        else
        {
            return {p2.first, p2.second};
        }
    }

    void update(int s, int e, int node, int idx, int val)
    {
        // base case
        if (s == e)
        {
            st[node] = {val, 1};
            return;
        }

        int mid = s + (e - s) / 2;

        if (idx <= mid)
        {
            update(s, mid, 2 * node + 1, idx, val);
        }
        else
        {
            update(mid + 1, e, 2 * node + 2, idx, val);
        }

        pair<int, int> p1, p2;
        p1 = st[2 * node + 1];
        p2 = st[2 * node + 2];

        if (p1.first == p2.first)
        {
            st[node] = {p1.first, p1.second + p2.second};
        }
        else if (p1.first < p2.first)
        {
            st[node] = {p1.first, p1.second};
        }
        else
        {
            st[node] = {p2.first, p2.second};
        }
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    pair<int, int> query(int l, int r)
    {
        return query(0, n - 1, 0, l, r - 1);
    }

    void update(int idx, int val)
    {
        update(0, n - 1, 0, idx, val);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    SegmentTree t(n);
    t.build(v);
    while (m--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int idx, val;
            cin >> idx >> val;
            t.update(idx, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            pair<int, int> p = t.query(l, r);
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}