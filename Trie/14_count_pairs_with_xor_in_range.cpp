#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *children[2];
    bool terminal;

    Node(int data)
    {
        children[0] = children[1] = nullptr;
        this->data = data;
        terminal = false;
    }
};
class Solution
{
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

            if (temp->children[bit] == nullptr)
            {
                temp->children[bit] = new Node(bit);
            }
            temp = temp->children[bit];
        }
        temp->terminal = true;
    }
    void maxXOR(Node *temp, int num, int val, int k, int low, int high, int &cnt)
    {
        int bit = num >> k;
        if (bit != temp->data)
        {
            val = val + (1 << k);
            if (val > high)
                return;
        }

        if (temp->terminal)
        {
            if (val >= low)
                cnt++;
        }

        for (int i = 0; i < 2; i++)
        {
            if (temp->children[i] != nullptr)
                maxXOR(temp->children[i], num, val, k - 1, low, high, cnt);
        }
    }
    int countPairs(vector<int> &nums, int low, int high)
    {

        int cnt = 0;
        for (int x : nums)
        {
            Node *temp = root;

            for (int i = 0; i < 2; i++)
            {
                int val = 0;
                if (temp->children[i] != nullptr)
                    maxXOR(temp->children[i], x, val, 31, low, high, cnt);
            }
            insert(x);
        }
        return cnt;
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
    int low, high;
    cin >> low >> high;
    Solution sln;
    cout << sln.countPairs(nums, low, high) << endl;
    return 0;
}