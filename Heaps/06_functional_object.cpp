#include<iostream>
#include<string>
using namespace std;

class Fun
{
    public:
    void operator()(string s)
    {
        cout << "Having Fun in Class Fun with " << s << endl;
    }
};

int main()
{
    Fun f;
    f("C++");
    return 0;
}