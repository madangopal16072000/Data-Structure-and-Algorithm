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
    }

    void update(int s, int e, int node, int idx)
    {
        // base case
        if (s == e)
        {
            st[node] = !st[node];
            return;
        }

        int mid = s + (e - s) / 2;
        if (idx <= mid)
        {
            update(s, mid, 2 * node + 1, idx);
        }
        else
        {
            update(mid + 1, e, 2 * node + 2, idx);
        }

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    int query(int s, int e, int node, int k)
    {
        // base case
        if (s == e)
        {
            return s;
        }

        int mid = s + (e - s) / 2;
        if (k <= st[2 * node + 1])
        {
            return query(s, mid, 2 * node + 1, k);
        }
        else
        {
            return query(mid + 1, e, 2 * node + 2, k - st[2 * node + 1]);
        }
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    void update(int idx)
    {
        update(0, n - 1, 0, idx);
    }

    int query(int k)
    {
        return query(0, n - 1, 0, k + 1);
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
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx;
            cin >> idx;
            t.update(idx);
        }
        else
        {
            int k;
            cin >> k;
            cout << t.query(k) << endl;
        }
    }
    return 0;
}