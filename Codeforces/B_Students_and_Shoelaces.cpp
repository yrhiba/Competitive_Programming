/*

B. Students and Shoelaces

link to the problem:
https://codeforces.com/contest/129/problem/B

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
	ll n, k; cin >> n >> k;

	vector< set<ll> > g(n);

	while (k--)
	{
		ll a, b; cin >> a >> b;
		a--; b--;

		g[a].insert(b);
		g[b].insert(a);
	}

	ll res = 0;

	while (true)
	{
		set<ll> to_kick;

		for (ll s = 0; s < n; s++)
			if (g[s].size() == 1)
				to_kick.insert(s);

		if (to_kick.empty()) break;

		res += 1;

		for (auto &i : to_kick)
		{
			for (auto &s : g[i])
				g[s].erase(i);

			g[i].clear();
		}
	}

	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
