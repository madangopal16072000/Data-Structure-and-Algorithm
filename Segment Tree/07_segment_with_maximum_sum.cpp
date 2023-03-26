#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
    int n;
    vector<vector<int>> st;
    vector<int> add(vector<int> v1, vector<int> v2)
    {
        vector<int> temp;
        temp.push_back(v1[0] + v2[0]);
        temp.push_back(max(v2[1], v2[0] + v1[1]));
        temp.push_back(max(v1[2], v1[0] + v2[2]));
        temp.push_back(max(max(v1[3], v2[3]), v1[1] + v2[2]));
        return temp;
    }

public:
    SegmentTree(int m)
    {
        n = m;
        st.resize(4 * n, vector<int>(4, 0));
    }

    void build(int s, int e, int node, vector<int> &v)
    {
        // base case
        if (s == e)
        {
            st[node] = {v[s], max(0, v[s]), max(0, v[s]), max(0, v[s])};
            return;
        }

        int mid = s + (e - s) / 2;
        build(s, mid, 2 * node + 1, v);
        build(mid + 1, e, 2 * node + 2, v);

        vector<int> v1, v2;
        v1 = st[2 * node + 1];
        v2 = st[2 * node + 2];

        st[node] = add(v1, v2);
    }
    void update(int s, int e, int node, int idx, int val)
    {
        // base case
        if (s == e)
        {
            st[node] = {val, val, val, val};
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

        vector<int> v1, v2;
        v1 = st[2 * node + 1];
        v2 = st[2 * node + 2];

        st[node] = add(v1, v2);
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    int query()
    {
        return st[0][3];
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
    cout << t.query() << endl;
    while (m--)
    {
        int idx, val;
        cin >> idx >> val;
        t.update(idx, val);
        cout << t.query() << endl;
    }
    return 0;
}