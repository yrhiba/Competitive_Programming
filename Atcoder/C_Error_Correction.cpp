/*
link to the problem:
https://atcoder.jp/contests/abc324/tasks/abc324_c
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
# define ull unsigned long long
# define ll long long
ll mod = 1000000007;
using namespace std;
ll powermod(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2) % mod;
	if (p%2)
		return ((((res * res) % mod) * (x % mod)) % mod);
	return ((res * res) % mod);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}

void solve()
{
	string s;
	ll n; cin >> n >> s;

	vector<int> ans; ans.reserve(n);

	string t;
	for (ll i = 0; i < n; i++)
	{
		cin >> t;

		if (abs((int)t.size() - (int)s.size()) > 1)
			continue;

		int x = 0;
		int	y = 0;
		int d = 0;

		while (x < s.size() && y < t.size())
		{
			if (s[x] == t[y])
			{	
				x++;
				y++;
			}
			else
			{
				if (t.size() < s.size())
					x++;
				else if (t.size() == s.size())
				{
					x++;
					y++;
				}
				else if (t.size() > s.size())
					y++;
				d++;
			}

			if (d > 1)
				break;
		}

		if (d <= 1)
			ans.push_back(i + 1);
	}

	if (ans.empty())
	{
		cout << 0 << endl;
		return ;
	}
	cout << ans.size() << endl;
	for (ll i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i+1 < ans.size())
			cout << " ";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
