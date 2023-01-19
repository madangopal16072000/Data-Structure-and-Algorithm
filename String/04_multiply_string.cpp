#include <bits/stdc++.h>
using namespace std;
class Solution
{
    string f(int cnt, string s, bool left)
    {
        if (left)
        {
            while (cnt--)
            {
                s = '0' + s;
            }
        }
        else
        {
            while (cnt--)
            {
                s = s + '0';
            }
        }

        return s;
    }

public:
    string multiply(string num1, string num2)
    {

        vector<string> products;
        int len1 = num1.size();
        int len2 = num2.size();

        for (int i = len2 - 1; i >= 0; i--)
        {
            int m = num2[i] - '0';

            int carry = 0;
            string temp = "";
            for (int j = len1 - 1; j >= 0; j--)
            {
                int n = num1[j] - '0';

                int prod = m * n + carry;
                int val = prod % 10;
                carry = prod / 10;

                char ch = '0' + val;
                temp = ch + temp;
            }
            if (carry > 0)
            {

                char ch = '0' + carry;
                temp = ch + temp;
            }
            cout << temp << endl;
            products.push_back(temp);
        }

        string ans = products[0];
        for (int i = 1; i < len2; i++)
        {
            string s = f(i, products[i], false);

            if (ans.size() > s.size())
            {
                s = f(ans.size() - s.size(), s, true);
            }
            else if (ans.size() < s.size())
            {
                ans = f(s.size() - ans.size(), ans, true);
            }

            int len = ans.size();
            int carry = 0;
            string temp = "";

            for (int j = len - 1; j >= 0; j--)
            {
                int m = ans[j] - '0';
                int n = s[j] - '0';

                int add = m + n + carry;
                int val = add % 10;
                carry = add / 10;

                char ch = '0' + val;
                temp = ch + temp;
            }
            ans = temp;
        }
        string temp = ans;
        int k = 0;
        while (k < temp.size()-1 && temp[k] == '0')
        {
            k++;
        }
        ans = "";
        while (k < temp.size())
        {
            ans = ans + temp[k];
            k++;
        }
        return ans;
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //   freopen("./input.txt", "r", stdin);
    //   freopen("./output.txt", "w", stdout);
    // #endif
    string num1 = "9133";
    string num2 = "0";
    Solution sln;
    cout << sln.multiply(num1, num2) << endl;
    return 0;
}