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

    void build(int start, int end, int node, vector<int> &v)
    {
        // base case
        if (start == end)
        {
            st[node] = v[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(start, mid, 2 * node + 1, v);
        build(mid + 1, end, 2 * node + 2, v);

        st[node] = st[2 * node + 1] ^ st[2 * node + 2];
        return;
    }

    int query(int start, int end, int l, int r, int node)
    {
        // no overlap
        if (end < l || start > r)
            return 0;
        // complete overlap
        if (start >= l && end <= r)
            return st[node];

        // partial overlap
        int mid = start + (end - start) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);

        return q1 ^ q2;
    }

    void build(vector<int> &v1)
    {
        build(0, n - 1, 0, v1);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l - 1, r - 1, 0);
    }
};
vector<int> solve(int n, vector<int> a, vector<vector<int>> queries)
{

    vector<int> ans;
    SegmentTree t(a.size());
    t.build(a);

    for (vector<int> vec : queries)
    {
        ans.push_back(t.query(vec[0], vec[1]));
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int m;
    cin >> m;
    vector<int> a;
    for (int i = 0; i < m; i++)
    {
        int d;
        cin >> d;
        a.push_back(d);
    }
    int n;
    cin >> n;
    vector<vector<int>> queries;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r});
    }

    vector<int> ans = solve(n, a, queries);
    return 0;
}