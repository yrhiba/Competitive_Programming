/*

Alter Ego

link to the problem:
https://www.codechef.com/problems/ALT

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

ll calc_x(ll a, ll b)
{
	return ((a + b) / 2);
}

ll calc_y(ll x, ll b)
{
	return (x - b);
}

void solve()
{
	ll n; cin >> n;

	vector<ll> odds;
	vector<ll> evens;

	odds.reserve(n);
	evens.reserve(n);

	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		if (t%2)
			odds.push_back(t);
		else
			evens.push_back(t);
	}

	if (odds.size() % 2 || evens.size() % 2)
	{
		cout << "-1\n";
		return ;
	}

	vector<ll> ans(n);

	ll k = 0;

	sort(odds.begin(), odds.end());
	sort(evens.begin(), evens.end());

	for (ll i = 0; i < evens.size() / 2; i++)
	{
		ll x = calc_x(evens[i], evens[i + evens.size()/2]);
		ll y = calc_y(x, evens[i + evens.size()/2]);

		ans[k] = abs(x);
		ans[k + n/2] = abs(y);

		k++;
	}
	for (ll i = 0; i < odds.size() / 2; i++)
	{
		ll x = calc_x(odds[i], odds[i + odds.size()/2]);
		ll y = calc_y(x, odds[i + odds.size()/2]);

		ans[k] = abs(x);
		ans[k + n/2] = abs(y);

		k++;
	}

	for (ll i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
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
