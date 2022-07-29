#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
int main() {

	int N;
	int input[100000];
	for(int i = 0; i < N; i++)
	{
		cin >> input[i];
	}
	unordered_map<int, int> m;
	for(int i = 0; i < N; i++)
	{
		int d;
		cin >> d;
		m[d]++;
	}
	multiset<int> s;
	for(int i = 0; i < N; i++)
	{
		if(m[input[i]] > 0)
		{
			s.insert(input[i]);
			m[input[i]]--;
		}
	}
	for(int x : s)
	cout << x << " ";
	return 0;
}