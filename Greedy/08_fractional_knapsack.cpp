#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
class compare
{
public:
    bool operator()(Item &a, Item &b)
    {
        if ((double)a.value / a.weight >= (double)b.value / b.weight)
            return true;

        return false;
    }
};
class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, vector<Item> arr, int n)
    {
        // Your code here
        sort(arr.begin(), arr.end(), compare());
        double ans = 0;
        for (int i = 0; i < n && W > 0; i++)
        {
            if (W >= arr[i].weight)
            {
                W = W - arr[i].weight;
                ans = ans + arr[i].value;
            }
            else
            {
                ans = ans + W * ((double)arr[i].value / arr[i].weight);
                W = 0;
            }
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
    int n, W;
    cin >> n >> W;
    vector<Item> arr;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Item a;
        a.value = x;
        a.weight = y;
        arr.push_back(a);
    }

    Solution sln;
    cout << sln.fractionalKnapsack(W, arr, n) << endl;
    return 0;
}