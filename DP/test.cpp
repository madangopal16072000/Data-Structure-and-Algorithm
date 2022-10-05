#include <bits/stdc++.h>
long long dp[1000007];
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}
	for (int i = 0; i <= x; i++)
	{
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			if (j - coins[i] >= 0)
			{
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
	}
	cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
}