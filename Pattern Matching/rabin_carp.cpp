#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
	const int p = 83, mod = 1e9 + 7;

	int poly_hash(string s)
	{
		int hash = 0;
		int p_power = 1;

		for (int i = 0; i < s.size(); i++)
		{
			hash += (s[i] - 'a' + 1) * p_power;
			p_power *= p;

			hash %= mod;
			p_power %= mod;
		}

		return hash;
	}

	int powr(int a, int b)
	{
		// (a^b)%mod
		int res = 1;
		while (b)
		{
			if (b & 1)
				res *= a;
			b /= 2;
			a *= a;

			a %= mod;
			res %= mod;
		}
		return res;
	}

	int inv(int x)
	{
		return powr(x, mod - 2);
	}

public:
	vector<int> search(string pattern, string text)
	{
		// code here.
		int pat_hash = poly_hash(pattern);

		int n = text.size(), m = pattern.size();

		int text_hash = poly_hash(text.substr(0, m));
		vector<int> ans;
		if (pat_hash == text_hash)
		{
			ans.push_back(1);
		}

		for (int i = 1; i + m <= n; i++)
		{
			// remove last character
			text_hash = (text_hash - (text[i - 1] - 'a' + 1) + mod) % mod;

			text_hash = (text_hash * inv(p)) % mod;

			text_hash = (text_hash + (text[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % mod;

			// cout << pat_hash << " " << text_hash << '\n';

			if (text_hash == pat_hash)
			{
				ans.push_back(i + 1);
			}
		}
		if (ans.size() == 0)
		{
			ans.push_back(-1);
		}
		return ans;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("./input.txt", "r", stdin);
	freopen("./output.txt", "w", stdout);
#endif
	string pat;
	string txt;
	cin >> txt >> pat;
	Solution sln;
	vector<int> ans = sln.search(pat, txt);
	for (int x : ans)
	{
		cout << x << " ";
	}
	return 0;
}