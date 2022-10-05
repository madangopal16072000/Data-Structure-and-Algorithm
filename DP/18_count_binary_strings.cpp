#include<iostream>
#include<vector>
#include<string>
using namespace std;


void countStrings(int i, vector<string> &res, string ans, int n, int lastDigit)
{
    if(i == n)
    {
        res.push_back(ans);
        return;
    }

    if(lastDigit == 0)
    {
        countStrings(i+1, res, ans + "0", n, 0);
        countStrings(i+1, res, ans + "1", n, 1);
    }
    else
    countStrings(i+1, res, ans + "0", n, 0);
}

int main()
{
    int n;
    cin >> n;
    vector<string> res;
    string ans = "";
    countStrings(0, res, ans, n, 0);
    cout << res.size() << endl;
    return 0;
}