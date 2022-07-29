#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    Node *left;
    Node *right;
    bool terminal;
    Node()
    {
        left = nullptr;
        right = nullptr;
        terminal = false;
    }
};

class Trie
{
    Node *root;
    int cnt;

public:
    Trie()
    {
        root = new Node();
        cnt = 0;
    }
    void insert(int n);
    int maxXOR(vector<int> input);
    int maxXORHelper(int n);
};

void Trie::insert(int n)
{
    Node *temp = root;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit == 0)
        {
            if (temp->left == nullptr)
                temp->left = new Node();
            temp = temp->left;
        }
        else
        {
            if (temp->right == nullptr)
                temp->right = new Node();
            temp = temp->right;
        }
    }
    temp->terminal = true;
    cnt++;
}
int Trie::maxXORHelper(int n)
{
    Node *temp = root;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit == 0)
        {
            if (temp->right)
            {
                ans += 1 << i;
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            if (temp->left)
            {
                ans += (1 << i);
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    return ans;
}
int Trie::maxXOR(vector<int> input)
{
    vector<int> cumInput;
    cumInput.push_back(0);
    int cumxor = 0;
    for (int i = 0; i < input.size(); i++)
    {
        cumxor = cumxor ^ input[i];
        cumInput.push_back(cumxor);
    }
    int maxxor = INT_MIN;
    for (int i = 0; i < cumInput.size(); i++)
    {
        insert(cumInput[i]);
        int curr = maxXORHelper(cumInput[i]);
        maxxor = max(maxxor, curr);
    }
    return maxxor;
}
int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        input.push_back(d);
    }
    cout << t.maxXOR(input) << endl;
}
