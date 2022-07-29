#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while(start <= end)
    {
        if(s[start++] != s[end--])
        return false;
    }
    return true;
}
void func(int index, string s, vector<string> &out, vector<vector<string>> &res)
{
    // base case;
    if(index == s.size())
    {
        res.push_back(out);
        return;
    }

    // rec case
    for(int i = index; i<s.size(); i++)
    {
        if(isPalindrome(s, index, i))
        {
            out.push_back(s.substr(index, i-index + 1));
            func(i+1, s, out, res);
            out.pop_back();
        }
    }
}
int main()
{
    string s;
    cin >> s;
    vector<vector<string>> res;
    vector<string> out;
    func(0, s, out, res);
    for(auto vec : res)
    {
        cout << "[ ";
        for(auto s : vec)
        {
            cout << s << ", ";
        }
        cout << "]" << ", ";
    }
    return 0;

}