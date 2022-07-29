#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int stall_index[], int N, int C, int min_distance)
{
	int last_index = stall_index[0];
	int cowCount = 1;;
	for(int i=1; i<N; i++)
	{
		if(stall_index[i] - last_index >= min_distance)
		{
			last_index = stall_index[i];
			cowCount++;
			if(cowCount == C)
			return true;
		}
	}
	return false;
}
int largest_distance_bw_cows(int stall_index[], int N, int C)
{
	int s = 1;
	sort(stall_index, stall_index + N);
	int e = stall_index[N-1] - stall_index[0];
	int min_distance;
	int ans = -1;
	while(s <= e)
	{
		min_distance = (s + e)/2;

		bool CowRakhPaye = isPossible(stall_index, N, C, min_distance);
		if(CowRakhPaye)
		{
			ans = min_distance;
			s = min_distance + 1;
		}
		else
		e = min_distance - 1;
	}
	return ans;
}
int main() {
	int N, C;
	cin >> N >> C;
	int *stall_index = new int[N];
	for(int i=0; i<N; i++)
	cin >> stall_index[i];
	cout << largest_distance_bw_cows(stall_index, N, C) << endl;
	return 0;
}