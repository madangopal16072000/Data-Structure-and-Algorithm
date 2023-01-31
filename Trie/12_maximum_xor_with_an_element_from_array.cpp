#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    unordered_map<int, Node *> children;
    bool terminal;

    Node(int data)
    {
        this->data = data;
        terminal = false;
    }
};

bool compare(vector<int> &a, vector<int> &b)
{
    if (a[1] < b[1])
        return true;
    else if (a[1] == b[1] && a[0] < b[0])
        return true;

    return false;
}
class Solution
{
private:
    Node *root;

public:
    Solution()
    {
        root = new Node(-1);
    }

    void insert(int num)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (temp->children.count(bit) == 0)
            {
                Node *newNode = new Node(bit);
                temp->children[bit] = newNode;
            }
            temp = temp->children[bit];
        }
        temp->terminal = true;
    }

    int maxXOR(int num)
    {
        Node *temp = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (temp->children.count(1 - bit))
            {
                ans = ans + (1 << i);
                temp = temp->children[1 - bit];
            }
            else
            {
                temp = temp->children[bit];
            }
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {

        sort(nums.begin(), nums.end());

        sort(queries.begin(), queries.end(), compare);

        int n = nums.size();
        int m = queries.size();
        vector<int> ans;
        Node *temp = root;
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            int first = queries[i][0];
            int second = queries[i][1];

            int idx = upper_bound(nums.begin(), nums.end(), second) - nums.begin();

            for (; j < idx && j < n; j++)
            {
                insert(nums[j]);
            }
            int curr;
            if (temp->children.size() > 0)
                curr = maxXOR(first);
            ans.push_back(curr);
        }
        return ans;
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
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        nums.push_back(d);
    }

    vector<vector<int>> queries;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        queries.push_back({x, y});
    }

    Solution sln;
    vector<int> ans = sln.maximizeXor(nums, queries);
    for (int x : ans)
        cout << x << " ";
    return 0;
}