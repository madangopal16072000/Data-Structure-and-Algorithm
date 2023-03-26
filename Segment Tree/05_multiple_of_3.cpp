#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    int n;
    int k;
    vector<vector<int>> st;
    vector<int> lazy;

    vector<int> add(vector<int> &v1, vector<int> &v2)
    {
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(v1[i] + v2[i]);
        }
        return ans;
    }
    void shift(vector<int> &v, int cnt)
    {
        vector<int> temp = v;
        for (int i = 0; i < k; i++)
        {
            v[(i + 1) % k] = temp[i];
        }
    }

public:
    SegmentTree(int m, int l)
    {
        n = m;
        k = l;
        st.resize(4 * n, vector<int>(k, 0));
        lazy.resize(4 * n, 0);
    }

    void build(int s, int e, int node, vector<int> &v)
    {
        // base case
        if (s == e)
        {
            int idx = v[s] % k;
            st[node][idx]++;
            return;
        }

        int mid = s + (e - s) / 2;
        build(s, mid, 2 * node + 1, v);
        build(mid + 1, e, 2 * node + 2, v);

        st[node] = add(st[2 * node + 1], st[2 * node + 2]);
        return;
    }

    void update(int s, int e, int node, int l, int r)
    {

        // clear pending updates
        if (lazy[node] != 0)
        {
            shift(st[node], lazy[node]);
            if (s != e)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        // no overlap
        if (s > r || e < l)
            return;

        // complete overlap
        if (l <= s && e <= r)
        {
            shift(st[node], 1);
            if (s != e)
            {
                lazy[2 * node + 1] += 1;
                lazy[2 * node + 2] += 1;
            }
            return;
        }

        int mid = s + (e - s) / 2;
        update(s, mid, 2 * node + 1, l, r);
        update(mid + 1, e, 2 * node + 2, l, r);

        st[node] = add(st[2 * node + 1], st[2 * node + 2]);
        return;
    }

    vector<int> query(int s, int e, int node, int l, int r)
    {
        // no overlap
        if (e < l || s > r)
            return vector<int>(k, 0);

        // pending updates
        if (lazy[node] != 0)
        {
            shift(st[node], lazy[node]);
            if (s != e)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // complete overlap
        if (s >= l && e <= r)
        {
            return st[node];
        }

        // partial overlap
        int mid = s + (e - s) / 2;

        vector<int> v1 = query(s, mid, 2 * node + 1, l, r);
        vector<int> v2 = query(mid + 1, e, 2 * node + 2, l, r);

        return add(v1, v2);
    }

    void build(vector<int> v)
    {
        build(0, n - 1, 0, v);
    }

    void update(int l, int r)
    {
        update(0, n - 1, 0, l, r);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, 0, l, r)[0];
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
    int k;
    cin >> k;
    SegmentTree t(n, k);
    t.build(v);
    cout << t.query(0, 7) << endl;
    t.update(4, 7);
    cout << t.query(0, 7) << endl;
    t.update(5, 7);
    cout << t.query(0, 7) << endl;
    t.update(6, 7);
    cout << t.query(0, 7) << endl;
    t.update(7, 7);
    cout << t.query(0, 7) << endl;
    return 0;
}