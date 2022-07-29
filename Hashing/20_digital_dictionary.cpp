#include<iostream>
#include<map>
using namespace std;

struct Node
{
    char data;
    map<char, Node*> children;
    bool terminal;
    Node(char ch)
    : data(ch), terminal(false) {}
};

class Trie
{
    Node *root;
    int cnt;

    public:
    Trie()
    {
        root = new Node('\0');
        cnt = 0;
    }

    void insert(string w);
    bool Search(string w);
    void print(Node *temp, string w);
};

void Trie::insert(string w)
{
    Node *temp = root;
    for(int i = 0; w[i] != '\0'; i++)
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
}
void Trie::print(Node *temp, string w)
{
    if(temp->terminal)
    cout << w << endl;

    string word;
    Node *t;
    for(auto it = temp->children.begin(); it != temp->children.end(); it++)
    {
        t = temp->children[it->first];
        word = w + it->first;
        print(t, word);
    }
    return;
}
bool Trie::Search(string w)
{
    Node *temp = root;
    for(int i = 0; w[i] != '\0'; i++)
    {
        char ch = w[i];
        if(temp->children.count(ch))
        temp = temp->children[ch];
        else
        return false;
    }
    print(temp, w);
    return true;
}
int main()
{
    Trie t;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        t.insert(s);
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        string q;
        cin >> q;
        if(!t.Search(q))
        {

        cout << "No suggestions" << endl;
        t.insert(q);
        }
    }
    return 0;
}