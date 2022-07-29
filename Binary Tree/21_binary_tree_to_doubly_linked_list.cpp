#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    : data(data), left(nullptr), right(nullptr) {}
};

Node* build()
{
    int d;
    cin >> d;
    if(d == -1)
    return nullptr;

    Node *root = new Node(d);
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cin >> d;
        if(d != -1)
        {
            f->left = new Node(d);
            q.push(f->left);
        }
        cin >> d;
        if(d != -1)
        {
            f->right = new Node(d);
            q.push(f->right);
        }
    }
    return root;
}
void levelOrder(Node *root)
{
    if(root == nullptr)
    return;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        Node *f = q.front();
        if(f == nullptr)
        {
            q.pop();
            cout << endl;
            if(!q.empty())
            q.push(nullptr);
        }
        else
        {
            q.pop();
            cout << f->data << " ";
            if(f->left)
            q.push(f->left);
            if(f->right)
            q.push(f->right);
        }
    }
}
void inorder(Node *root)
{
    if(root == nullptr)
    return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}
struct LinkedList
{
    Node *head;
    Node *tail;
};

LinkedList binaryToDLL(Node* root)
{
    LinkedList l;
    if(root == nullptr)
    {
        l.head = l.tail = nullptr;
        return l;
    }

    if(root->left == nullptr && root->right == nullptr)
    {
        l.head = l.tail = root;
        return l;
    }
    if(root->left && root->right == nullptr)
    {
        LinkedList leftLL = binaryToDLL(root->left);
        leftLL.tail->right = root;
        
        root->left = leftLL.tail;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    if(root->right && root->left == nullptr)
    {
        LinkedList rightLL = binaryToDLL(root->right);
        root->right = rightLL.head;
        rightLL.head->left = root;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    LinkedList leftLL = binaryToDLL(root->left);
    LinkedList rightLL = binaryToDLL(root->right);

    leftLL.tail->right = root;
    root->left = leftLL.tail;

    root->right = rightLL.head;
    rightLL.head->left = root;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main()
{
    Node *root = build();
    inorder(root);

    LinkedList l = binaryToDLL(root);
    Node *temp = l.head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    return 0;

    
}