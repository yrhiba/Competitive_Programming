/*

1337 Competitive Programming Club - 1337 Global Round 2

C. Magical land

link to the problem:
find problems.pdf

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
#include <fstream>
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}

void solve()
{
	ll n, m; cin >> n >> m;

	vector<string> g(n);
	vector<string> ans(n, string(m, '.'));

	for (ll i = 0; i < n; i++)
		cin >> g[i];

	for (ll i = 0; i < m; i++)
	{
		ll cur = 0;
		for (ll j = 0; j < n; j++)
		{
			if (g[j][i] == '*')
				cur += 1;

			if (g[j][i] == 'o')
			{
				ans[j][i] = 'o';

				ll k = 0, x = j-1;
				while (k < cur)
				{
					ans[x][i] = '*';
					x--;
					k++;
				}
				cur = 0;
			}
			else if (j == n-1)
			{
				ll k = 0, x = j;
				while (k < cur)
				{
					ans[x][i] = '*';
					x--;
					k++;
				}
			}
		}
	}

	for (auto &line : ans)
		cout << line << '\n';

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
}
