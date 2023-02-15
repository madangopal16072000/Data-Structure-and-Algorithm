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
            st[node] = {v[s], v[s]};
            return;
        }

        int mid = s + (e - s) / 2;
        build(s, mid, 2 * node + 1, v);
        build(mid + 1, e, 2 * node + 2, v);

        st[node].first = max(st[2 * node + 1].first, max(st[2 * node + 2].first, st[2 * node + 1].second + st[2 * node + 2].second));
        st[node].second = max(st[2 * node + 1].second, st[2 * node + 2].second);
        return;
    }

    void update(int s, int e, int node, int idx, int val)
    {
        // base case
        if (s == e)
        {
            st[node] = {val, val};
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

        st[node].first = max(st[2 * node + 1].second + st[2 * node + 2].second, max(st[2 * node + 1].first, st[2 * node + 2].first));
        st[node].second = max(st[2 * node + 1].second, st[2 * node + 2].second);
        return;
    }

    pair<int, int> query(int s, int e, int node, int l, int r)
    {
        // no overlap
        if (e < l || s > r)
            return {0, 0};

        // complete overlap
        if (s >= l && e <= r)
        {
            return st[node];
        }

        // partial ovelap
        int mid = s + (e - s) / 2;

        pair<int, int> q1 = query(s, mid, 2 * node + 1, l, r);
        pair<int, int> q2 = query(mid + 1, e, 2 * node + 2, l, r);

        int sum = max(q1.second + q2.second, max(q1.first, q2.first));
        int maxi = max(q1.second, q2.second);
        return {sum, maxi};
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    void update(int idx, int val)
    {
        update(0, n - 1, 0, idx, val);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, 0, l, r).first;
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
    cout << t.query(2, 5) << endl;
    t.update(3, 9);
    cout << t.query(2, 5) << endl;
    return 0;
}