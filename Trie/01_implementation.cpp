#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node
{
    char data;
    unordered_map<char, Node *> children;
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
        root = new Node('\0');
        cnt = 0;
    }

    void insert(char *w);
    bool find(char *w);
    void uniquePrefix(char *w);
};

void Trie::insert(char *w)
{
    Node *temp = root;
    for (int i = 0; w[i] != '\0'; i++)
    {
        char ch = w[i];
        if (temp->children.count(ch))
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

bool Trie::find(char *w)
{
    Node *temp = root;
    for (int i = 0; w[i] != '\0'; i++)
    {
        char ch = w[i];
        if (temp->children.count(ch) == 0)
            return false;
        else
            temp = temp->children[ch];
    }
    return temp->terminal;
}

void Trie::uniquePrefix(char *w)
{
    Node *temp = root;
    char pre[10];
    int j = 0;
    for (int i = 0; w[i] != '\0'; i++)
    {
        char ch = w[i];
        pre[j++] = ch;
        if (temp->children[ch]->children.size() == 1)
        {
            break;
        }
        else
            temp = temp->children[ch];
    }
    pre[j] = '\0';
    cout << pre << endl;
}
int main()
{
    Trie t;
    char words[][10] = {"bad", "dad", "mad"};
    char w[10];
    for (int i = 0; i < 5; i++)
        t.insert(words[i]);

    cout << "Enter word : ";
    cin >> w;
    // t.uniquePrefix(w);
    if (t.find(w))
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;
    return 0;
}