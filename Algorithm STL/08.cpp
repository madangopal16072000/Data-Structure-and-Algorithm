#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int main() {
	int T, N;
	cin >> T;
	while(T--)
	{
        int a, b;
		cin >> N;
		vector<pair<int, int>> vec(N);
		for(int i=0; i<N; i++)
		{
			cin >> a >> b;
            vec[i].first = a;
            vec[i].second = b;
		}

		sort(vec.begin(), vec.end(), compare);
		int j = 0;
		int count = 1;
		for(int i=1; i<N; i++)
		{
			if(vec[i].first > vec[i].second)
			{
				count++;
				j = i;
			}
		}
		cout << count << endl;


	}
		return 0;
	
}