#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    unordered_map<char, Node *> children;
    bool terminal;

    Node(char data)
    {
        this->data = data;
        terminal = false;
    }
};
class StreamChecker
{
    Node *root;

public:
    void insert(string &word)
    {
        Node *temp = root;

        int n = word.size();
        for (int i = n - 1; i >= 0; i--)
        {
            char ch = word[i];

            if (temp->children.count(ch) == 0)
            {
                Node *newNode = new Node(ch);
                temp->children[ch] = newNode;
            }
            temp = temp->children[ch];
        }
        temp->terminal = true;
    }
    StreamChecker(vector<string> &words)
    {
        root = new Node('\0');
        for (string word : words)
        {
            insert(word);
        }
    }

    bool query(char letter)
    {

        Node *temp = root;

        if (temp->children.count(letter) == 0)
            return false;

        return true;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    vector<string> words;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }
    StreamChecker *obj = new StreamChecker(words);

    int q = 6;
    for (int i = 0; i < q; i++)
    {
        char ch;
        cin >> ch;
        cout << obj->query(ch) << endl;
    }
    return 0;
}