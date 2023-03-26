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

        // left tree
        build(s, mid, 2 * node + 1, v);
        // right tree
        build(mid + 1, e, 2 * node + 2, v);

        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
    }

    int query(int s, int e, int l, int r, int node)
    {
        // no overlap
        if (e < l || s > r)
            return 0;

        // complete overlap
        if (l <= s && r >= e)
        {
            return st[node];
        }

        // partial overlapping
        int mid = s + (e - s) / 2;

        int q1 = query(s, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, e, l, r, 2 * node + 2);

        return max(q1, q2);
    }

    void update(int s, int e, int node, int index, int value)
    {
        // base case
        if (s == e)
        {
            st[node] = value;
            return;
        }

        int mid = s + (e - s) / 2;

        if (index <= mid)
            update(s, mid, 2 * node + 1, index, value);
        else
            update(mid + 1, e, 2 * node + 2, index, value);

        st[node] = max(st[2 * node + 1], st[2 * node + 2]);
        return;
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    int query(int x)
    {
        int l = 0;
        int h = n - 1;
        int ans = -1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (query(0, n - 1, l, mid, 0) >= x)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
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
            int val;
            cin >> idx >> val;
            t.update(idx, val);
        }
        else
        {
            int x;
            cin >> x;
            cout << t.query(x) << endl;
        }
    }
    return 0;
}