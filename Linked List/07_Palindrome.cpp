#include<iostream>
#include<list>
using namespace std;

bool isPalindrome(list<int> l)
{
	int i = 1;
	while(i <= l.size()/2)
	{
		if(l.front() != l.back())
        {
            return false;
        }
        else
        {
            l.pop_back();
            l.pop_front();
        }
        i++;
	}
    return true;
}
int main() {
	int N;
	cin >> N;
	list<int> l;
	for(int i=1; i<=N; i++)
	{
		int d;
		cin >> d;

		l.push_back(d);
	}
    if(!isPalindrome(l))
	cout << "false";
    else
    cout << "true";
    cout << endl;
    for(auto x : l)
    cout << x << " ";
	return 0;
}