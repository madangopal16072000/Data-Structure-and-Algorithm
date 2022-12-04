#include <bits/stdc++.h>
using namespace std;
class Solution
{
    unordered_map<int, string> mp{{1, "I"}, {10, "X"}, {100, "C"}, {1000, "M"}, {5, "V"}, {50, "L"}, {500, "D"}, {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}, {2, "II"}, {3, "III"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {20, "XX"}, {30, "XXX"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {200, "CC"}, {300, "CCC"}, {600, "DC"}, {700, "DCC"}, {800, "DCC"}};

public:
    string intToRoman(int num)
    {

        int temp = num;
        int r;
        int place = 0;
        string digit = "";
        string ans = "";

        r = temp % 10;
        if(r != 0)
        {
        digit = digit + mp[r];
        reverse(digit.begin(), digit.end());
        ans = ans + digit;
        digit.clear();
        }
        temp = temp / 10;
        place = 1;
        int m;
        while (temp != 0)
        {
            r = temp % 10;
            if(r != 0)
            {
            place = place * 10;
            m = place * r;
            digit = digit + mp[m];
            reverse(digit.begin(), digit.end());
            ans = ans + digit;
            digit.clear();
            }
            temp = temp / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //   freopen("./input.txt", "r", stdin);
    //   freopen("./output.txt", "w", stdout);
    // #endif
    int n = 190;
    Solution sln;
    cout << sln.intToRoman(n) << endl;
    return 0;
}