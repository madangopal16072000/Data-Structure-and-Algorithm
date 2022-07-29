#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKSortedArray(vector<vector<int>> &arr)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq;
    // push the first element of each array in priority queue
    for(int i=0; i<arr.size(); i++)
    {
        pq.push(make_pair(arr[i][0], make_pair(i, 0)));
    }

    // remove the element from the array one by one and insert in result vector
    while(!pq.empty())
    {
        pair p = pq.top();
        pq.pop();
        int element = p.first;
        int x = p.second.first; // row of element
        int y = p.second.second; // col of element

        result.push_back(element);

        // pushing the next of element of current array in pq
        if(y+1 < arr[x].size())
        {
            pq.push(make_pair(arr[x][y+1], make_pair(x, y+1)));
        }
    }
    return result;
}
int main()
{
    vector<vector<int>> arr{
        {2, 6, 12, 15},
        {1, 3, 14, 20},
        {3, 5, 8, 10}
    };

    for(auto x : arr)
    {
        for(auto y : x)
        cout << y << " ";
        cout << endl;
    }
    vector<int> result = mergeKSortedArray(arr);
    for(int x : result)
    cout << x << " ";

    cout << endl;
    return 0;
}