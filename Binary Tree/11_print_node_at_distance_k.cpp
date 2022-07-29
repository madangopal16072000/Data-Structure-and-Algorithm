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

node *createTree(int arr[], int n)
{
    queue<node *> q;
    node *root = new node(arr[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n)
    {
        node *p = q.front();
        q.pop();

        if (arr[i] != -1)
        {
            p->left = new node(arr[i]);
            q.push(p->left);
        }
        i++;

        if (arr[i] != -1)
        {
            p->right = new node(arr[i]);
            q.push(p->right);
        }
        i++;
    }

    return root;
}
void newlineBFS(node *root)
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
            {
                q.push(nullptr);
            }
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
void printAtLevelK(node *root, int k)
{
    if (!root)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
}

int printAtDistanceK(node *root, node *target, int k)
{
    if (!root)
        return -1;

    if (root == target)
    {
        printAtLevelK(root, k);
        return 0;
    }

    // left subtree
    int DL = printAtDistanceK(root->left, target, k);

    if (DL != -1)
    {
        if (DL + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printAtLevelK(root->right, k - DL - 2);
        }
        return DL + 1;
    }

    // right subtree targe
    int DR = printAtDistanceK(root->right, target, k);

    if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printAtLevelK(root->left, k - DR - 2);
        }
        return DR + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, -1, -1, 6, 7, 8, 9, -1, -1, 10, 11, -1, -1, -1, -1};
    int n = sizeof(arr) / sizeof(int);

    node *root = createTree(arr, n);
    cout << "Displaying Tree : " << endl;
    newlineBFS(root);
    cout << "Printing Right View : " << endl;
    int maxlevel = -1;

    // printing node at distance k
    int k;
    cout << "Enter k : ";
    cin >> k;
    cout << "printing node at distance " << k << endl;
    node *target = root->left->left;
    printAtDistanceK(root, target, k);

    return 0;
}