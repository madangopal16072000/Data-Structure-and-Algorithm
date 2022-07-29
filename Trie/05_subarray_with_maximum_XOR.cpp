#include <iostream>
#include <vector>

using namespace std;
struct node
{
    node *left;
    node *right;
};

class Trie
{
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(int n)
    {
        node *temp = root;
        for (int i = 4; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else
            {
                if(temp->right == nullptr)
                temp->right = new node();

                temp = temp->right;
            }
        }
    }

    int maxXORHelper(int val)
    {
        int currentAns = 0;
        node *temp = root;
        for(int i = 4; i>=0; i--)
        {
            int bit = (val >> i) & 1;
            if(bit == 0)
            {
                if(temp->right)
                {
                    currentAns += (1 << i);
                    temp = temp->right;
                }
                else
                temp = temp->left;
            }
            else
            {
                if(temp->left)
                {
                    currentAns += (1 << i);
                    temp = temp->left;
                }
                else
                temp = temp->right;
            }
        }
        return currentAns;
    }

    int maxXOR(vector<int> input)
    {
        vector<int> cumXOR;
        int cxor = 0;
        cumXOR.push_back(0);
        for(int x : input)
        {
            cxor = cxor^x;
            cumXOR.push_back(cxor);
        }

        // for(int x : cumXOR)
        // cout << x << " ";
        // cout << endl;

        int maxXR = 0;
        for(int i = 0; i<cumXOR.size(); i++)
        {
            int val = cumXOR[i];
            insert(val);
            int currentAns = maxXORHelper(val);
            // cout << currentAns << " ";
            maxXR = max(maxXR, currentAns);
        }
        return maxXR;
    }
}; 
int main()
{
    vector<int> input{1, 2, 3, 4};
    Trie t;
    cout << t.maxXOR(input) << endl;
    return 0;
}