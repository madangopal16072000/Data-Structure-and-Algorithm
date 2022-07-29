#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    vector<string> vec;
    vec.push_back("BG");
    vec.push_back("GB");
    string str = "BGB";
    for(auto s : vec)
    {
        if(str.find(s) == string::npos)
        {
            cout << "NOT FOUND" << endl;
            break;
        }
        else
        cout << "FOUND" << endl;
    }
}