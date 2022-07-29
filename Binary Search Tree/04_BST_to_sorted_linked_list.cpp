#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int data)
        : data(data), left(nullptr), right(nullptr) {}
};

node *insertInBST(node *root, int d)
{
    if (root == nullptr)
        return new node(d);

    // rec case
    if (root->data >= d)
        root->left = insertInBST(root->left, d);
    else
        root->right = insertInBST(root->right, d);

    return root;
}
node *build(int arr[], int n)
{
    node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insertInBST(root, arr[i]);
    }

    return root;
}
void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *f = q.front();
        if (f == nullptr)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            if (f->left)
                q.push(f->left);

            if (f->right)
                q.push(f->right);
        }
    }
}
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        cout << p->data << " ";

        if (p->left)
            q.push(p->left);

        if (p->right)
            q.push(p->right);
    }
}
void inorder(node *root)
{
    if(root == nullptr)
    return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

struct LinkedList
{
    node *head;
    node *tail;
};

LinkedList flatten(node *root)
{
    LinkedList l;
    if(root == nullptr)
    {
        l.head = l.tail = nullptr;
        return l;
    }

    // for leaf node
    if(root->left == nullptr && root->right == nullptr)
    {
        l.head = l.tail = root;
        return l;
    }
    // when right node is null
    if(root->left && root->right == nullptr)
    {
        LinkedList leftLL = flatten(root->left);

        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    // when left node is null
    if(root->right && root->left == nullptr)
    {
        LinkedList rightLL = flatten(root->right);

        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    // when both side exists
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}
int main()
{
    int arr[] = {8, 10, 3, 1, 6, 14, 9, 7, 13};
    int n = sizeof(arr) / sizeof(int);

    node *root = build(arr, n);
    levelOrder(root);
    LinkedList l = flatten(root);
    node *temp = l.head;

    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }

    return 0;
}