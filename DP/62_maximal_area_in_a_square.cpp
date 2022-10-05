#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        int *leftSmall = new int[n];
        int *rightSmall = new int[n];
        // generating left small
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = st.top() + 1;

            st.push(i);
        }

        // clearing st for right small
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                rightSmall[i] = n - 1;
            else
                rightSmall[i] = st.top() - 1;

            st.push(i);
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int area = heights[i] * (rightSmall[i] - leftSmall[i] + 1);
            maxi = max(maxi, area);
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(n, 0);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                heights[j]++;
                else
                heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    int m,n;
    cin >> n;
    vector<vector<char>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<char> row;
        for (int j = 0; j < m; j++)
        {
            char d;
            cin >> d;
            row.push_back(d);
        }
        matrix.push_back(row);
    }

    Solution s;
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}