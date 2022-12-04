#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char ch)
        : data(ch), terminal(false) {}
};

class Solution
{
    Node *root;

public:
    void insert(string s)
    {
        Node *temp = root;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            char ch = s[i];
            if (temp->children.count(ch) > 0)
            {
                temp = temp->children[ch];
            }
            else
            {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }
    void dfs(Node *temp, vector<string> &vec, string n)
    {
        n = n + temp->data;

        for (auto p : temp->children)
        {
            dfs(p.second, vec, n);
        }
        if (temp->terminal)
        {
            vec.push_back(n);
        }
        return;
    }
    vector<string> find(int i, int j, string s)
    {
        Node *temp = root;
        for (int k = i; k <= j; k++)
        {
            char ch = s[k];
            if (temp->children.count(ch) == 0)
            {
                return {"0"};
            }
            else
                temp = temp->children[ch];
        }
        vector<string> vec;
        dfs(temp, vec, s.substr(0, j-i));
        return vec;
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        root = new Node('\0');
        for (int i = 0; i < n; i++)
        {
            insert(contact[i]);
        }

        int len = s.length();
        vector<vector<string>> ans;

        for (int i = 0; i < len; i++)
        {
            vector<string> row = find(0, i, s);
            sort(row.begin(), row.end());
            ans.push_back(row);
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
    string *contact = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> contact[i];
    }
    string s;
    cin >> s;
    Solution sln;
    vector<vector<string>> ans = sln.displayContacts(n, contact, s);
    for (vector<string> vec : ans)
    {
        for (string s : vec)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}