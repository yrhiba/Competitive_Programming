/*
E. Mirror Grid

link to the problem:
https://codeforces.com/contest/1703/problem/E
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

ll dc[] = {1, 0, -1, 0};
ll dr[] = {0, 1, 0, -1};

void solve()
{
	ll n; cin >> n;

	vector<string> g(n);
	for (string &s : g)
		cin >> s;

	ll ans = 0;

	for (ll i = 0; i < (n+1)/2; i++)
	{
		vector<string> v(4);

		ll r = i, c = i;

		for (ll d = 0; d < 4; d++)
		{
			for (ll x = i, j = 0; j < n - (2*i); x++, j++)
			{
				if (j)
				{
					r += dr[d];
					c += dc[d];
				}
				v[d] += g[r][c];
			}
		}

		for (ll c = 0; c < (n - (2*i)) - 1; c++)
		{
			ll z, o; z = o = 0;

			for (ll i = 0; i < 4; i++)
			{
				z += (v[i][c] == '0');
				o += (v[i][c] == '1');
			}

			ans += min(z, o);
		}
	}

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
		solve();
}
