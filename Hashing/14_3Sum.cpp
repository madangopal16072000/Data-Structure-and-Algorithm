#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int a, b, c;

    for (int i = 0; i < nums.size(); i++)
    {
        a = nums[i];
        unordered_map<int, int> m;
        for (int j = i + 1; j < nums.size(); j++)
        {
            vector<int> row;
            b = nums[j];
            c = -a - b;
            if (m[c])
            {
                row = {a, b, c};
                ans.push_back(row);
            }
            m[nums[j]]++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, 4};
    vector<vector<int>> ans = threeSum(nums);
    for (vector<int> row : ans)
    {
        cout << "[ ";
        for (int x : row)
            cout << x << " ";
        cout << "]" << endl;
    }
}