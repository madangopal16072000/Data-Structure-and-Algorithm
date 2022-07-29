#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main()
{
    unordered_map<string, vector<string>> phonebook;
    phonebook["Rahul"].push_back("9110");
    phonebook["Rahul"].push_back("9111");
    phonebook["Rahul"].push_back("9112");
    phonebook["Rohit"].push_back("8115");
    phonebook["Rohit"].push_back("8116");
    phonebook["Rita"].push_back("7890");

    for(pair p : phonebook)
    {
        cout << p.first << " : ";
        for(string s : p.second)
        cout << s << " ";
        cout << endl;
    }
}