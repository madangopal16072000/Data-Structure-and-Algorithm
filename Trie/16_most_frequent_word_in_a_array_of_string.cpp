#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    unordered_map<char, Node *> children;
    int cnt;
    int idx;
    Node(char data)
    {
        this->data = data;
        cnt = 0;
        idx = -1;
    }
};
class Solution
{
    Node *root;
    int maxfreq;
    string ans;
    int i;
    void insert(string &word, int idx)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->children.count(ch) == 0)
            {
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        if (temp->cnt = 0)
            temp->idx = idx;

        temp->cnt = temp->cnt + 1;

        if (temp->cnt > maxfreq)
        {
            maxfreq = temp->cnt;
            ans = word;
            i = temp->idx;
        }
        else if (temp->cnt == maxfreq)
        {
            if (i < temp->idx)
            {
                ans = word;
                i = temp->idx;
            }
        }
    }

public:
    // Function to find most frequent word in an array of strings.
    Solution()
    {
        root = new Node('\0');
        maxfreq = INT_MIN;
        ans = "";
        i = -1;
    }
    string mostFrequentWord(vector<string> &arr, int n)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            insert(arr[i], i);
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
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
    }
    Solution sln;
    cout << sln.mostFrequentWord(arr, n) << endl;
    return 0;
}