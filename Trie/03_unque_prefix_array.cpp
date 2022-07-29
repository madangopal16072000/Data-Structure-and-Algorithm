#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

struct Node
{
    char data;
    unordered_map<char, Node*> children;
    bool terminal;

    Node(char data)
    : data(data), terminal(false) {}
};

class Trie
{
    Node *root;
    int cnt;

    public:
    Trie()
    {
        Node *root = new Node('\0');
        cnt = 0;
    }

    void insert(string w);
    bool find(string w);
};

void Trie::insert(string w)
{
    Node *temp = root;
    for(int i = 0; i < w.length(); i++)
    {
        char ch = w[i];

        if(temp->children.count(ch))
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
    cnt++;
}

bool Trie::find(string w)
{
    Node *temp = root;
    for(int i = 0; i < w.length(); i++)
    {
        char ch = w[i];
        if(temp->children.count(ch) == 0)
        return false;
        else
        temp = temp->children[ch];
    }
    return true;
}

int main()
{
    Trie t;
    vector<string> words = {"a", "hello", "not", "news", "apple"};
    for(string word : words)
    t.insert(word);

    string word;
    cout << "Enter word : ";
    cin >> word;

    if(t.find(word))
    cout << "Present" << endl;
    else
    cout << "Absent" << endl;
    return 0;
}