#include <bits/stdc++.h>
using namespace std;
class compare
{
public:
    bool operator()(const string &a, const string &b)
    {
        if (a[0] < b[0])
        {
            return false;
        }
        else if (a[0] > b[0])
        {
            return true;
        }
        else
        {
            int i = 0, j = 0;
            int n = a.size();
            int m = b.size();

            while (i < n && j < m)
            {
                if (a[i] == b[j])
                {
                    i++;
                    j++;
                }
                else if (a[i] < b[j])
                    return false;
                else if (a[i] > b[j])
                {
                    return true;
                }
            }

            while (i < n)
            {
                if (a[i] > b[j - 1])
                    return true;
                else if (a[i] < b[j - 1])
                {
                    return false;
                }
                else
                {
                    while (i < n && a[i] == b[j - 1])
                    {
                        i++;
                    }

                    if (i == n)
                        return true;
                }
            }

            while (j < m)
            {
                if (a[i - 1] < b[j])
                    return false;
                else if (a[i - 1] > b[j])
                    return true;
                else
                {
                    while (j < m && a[i - 1] == b[j])
                        j++;

                    if (j == m)
                        return false;
                }
            }
            return false;
        }
    }
};
class Solution
{
public:
    // The main function that returns the arrangement with the largest value as
    // string.
    // The function accepts a vector of strings
    string printLargest(vector<string> &arr)
    {
        // code here
        sort(arr.begin(), arr.end(), compare());

        for (string s : arr)
            cout << s << " ";
        string ans = "";
        for (string str : arr)
            ans = ans + str;

        return ans;
    }
};

bool cmp(string a, string b)
{
    if (a[0] < b[0])
    {
        return false;
    }
    else if (a[0] > b[0])
    {
        return true;
    }
    else
    {
        int i = 0, j = 0;
        int n = a.size();
        int m = b.size();

        while (i < n && j < m)
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else if (a[i] < b[j])
                return false;
            else if (a[i] > b[j])
            {
                return true;
            }
        }

        while (i < n)
        {
            if (a[i] > b[j - 1])
                return true;
            else if (a[i] < b[j - 1])
            {
                return false;
            }
            else
            {
                while (i < n && a[i] == b[j - 1])
                {
                    i++;
                }

                if (i == n)
                    return true;
            }
        }

        while (j < m)
        {
            if (a[i - 1] < b[j])
                return false;
            else if (a[i - 1] > b[j])
                return true;
            else
            {
                while (j < m && a[i - 1] == b[j])
                    j++;

                if (j == m)
                    return false;
            }
        }
        return false;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<string> arr;

    // cmp("30", "3");

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
    }
    Solution sln;
    string ans = sln.printLargest(arr);
    cout << ans << endl;
    return 0;
}