#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    unordered_map<char, Node*> children;
    bool terminal;
    int num;
    Node(char data)
    : data(data), terminal(false), num(1){}
};
class Solution{
    Node *root;
    int cnt;
public:
    void insert(string s)
    {
        Node *temp = root;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            if(temp->children.count(ch))
            {
                
                temp = temp->children[ch];
                temp->num++;
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
    int find(string s)
    {
        int n = s.length();
        Node *temp = root;
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            if(temp->children.count(ch))
            temp = temp->children[ch];
            else
            return 0;
        }
        return temp->num;
    }
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        root = new Node('\0');
        cnt = 0;

        for(int i = 0; i < N; i++)
        {
            insert(li[i]);
        }
        vector<int> dp(Q, 0);
        for(int i = 0; i < Q; i++)
        {
            dp[i] = find(query[i]);
        }

        return dp;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int N, Q;
    cin >> N >> Q;
    string li[N];
    for(int i = 0; i < N; i++)
    {
        cin >> li[i];
    }

    string query[Q];
    for(int i = 0; i < Q; i++)
    {
        cin >> query[i];
    }

    Solution sln;
    vector<int> ans = sln.prefixCount(N, Q, li, query);
    for(int x : ans)
    cout << x << " ";
    cout << endl;
    return 0;
}