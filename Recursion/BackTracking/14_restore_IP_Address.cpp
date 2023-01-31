#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(string str, int start, int end)
{
    string sub = str.substr(start, end - start + 1);

    if (sub.length() > 3)
        return false;
    if (stoi(sub) > 255)
        return false;
    if (sub.length() > 1 && sub[0] == '0')
        return false;

    return true;
}
void f(string str, vector<string> &res, int index, int k, string out)
{
    if (k == 4 && index == str.length())
    {
        out.pop_back();
        res.push_back(out);
        return;
    }

    if (k > 4)
        return;

    // rec case
    for (int i = index; i < str.length(); i++)
    {
        if (isValid(str, index, i))
        {
            string sub = str.substr(index, i - index + 1);
            out.append(sub + ".");
            f(str, res, i + 1, k + 1, out);
            out.erase(index, i - index + 2);
        }
    }
    return;
}
int main()
{
    string str;
    cin >> str;
    vector<string> res;
    f(str, res, 0, 0, "");
    for (auto s : res)
    {
        cout << s << endl;
    }
    return 0;
}
