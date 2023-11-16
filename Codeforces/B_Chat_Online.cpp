/*
Codeforces Round 268 (Div. 2)

B. Chat Online

link to the problem:
https://codeforces.com/contest/469/problem/B
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
	ll p, q; cin >> p >> q;

	ll l, r; cin >> l >> r;

	vector< pair<ll, ll> > ab(p);
	vector< pair<ll, ll> > cd(q);

	vector<ll> time(2e3, 0);

	for (auto &[i, j] : ab)
	{
		cin >> i >> j;

		time[i] += 1;
		time[j+1] -= 1;
	}

	for (auto &[i, j] : cd)
		cin >> i >> j;

	for (ll i = 1; i < time.size(); i++)
		time[i] += time[i - 1];


	ll ans = 0;

	for (ll t = l; t <= r; t++)
	{
		bool suite = false;

		for (auto &[i, j] : cd)
		{
			for (ll x = i + t; x <= j + t; x++)
			{
				if (time[x] > 0)
				{
					suite = true;
					break;
				}
			}
			if (suite) break;
		}

		ans += suite;
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
