#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


struct Node
{
    char data;
    unordered_map<char, Node*> children;
    bool terminal;
    int freq;
    Node(char data)
    : data(data), terminal(false), freq(1) {}
};

class Trie
{
    Node *root;
    int cnt;

    public:
    Trie()
    {
        root = new Node('\0');
        root->freq++;
        cnt = 0;
    }

    void insert(char *w);
    bool find(char *w);
    void uniquePrefix(char *w);
};

void Trie::insert(char *w)
{
    Node *temp = root;
    for(int i=0; w[i] != '\0'; i++)
    {
        char ch = w[i];
        if(temp->children.count(ch))
        {
            temp->freq++;
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
    for(int i = 0; w[i] != '\0'; i++)
    {
        char ch = w[i];
        if(temp->children.count(ch) == 0)
        return false;
        else
        temp = temp->children[ch];
    }
    return temp->terminal;
}

void Trie::uniquePrefix(char *w)
{
    Node *temp = root->children[w[0]];
    char pre[10];
    int j = 0;
    for(int i=0; w[i] != '\0'; i++)
    {
        char ch = w[i];
        pre[j++] = ch;
        if(temp->freq == 1)
        break;
        else
        temp = temp->children[ch];
    }
    pre[j] = '\0';
    cout << pre << endl;
}
int main()
{
    Trie t;
    char words[][10] = {"cobra", "dog", "duck", "dove", "ducken"};
    char w[10];
    cout << "Enter word : ";
    cin >> w;
    for(int i=0; i<5; i++)
    t.insert(words[i]);

    t.uniquePrefix(w);
    if(t.find(w))
    cout << "Present" << endl;
    else
    cout << "Absent" << endl;
    return 0;

    
}