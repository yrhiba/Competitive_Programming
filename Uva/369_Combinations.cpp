/*
link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=305
link to the problem (pdf):
https://onlinejudge.org/external/3/369.pdf
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

void solve(ll n, ll m)
{
	vector<ll> baset;
	vector<ll> ma9am;

	for (ll i = 1; i <= n; i++)
		baset.push_back(i);

	for (ll i = 1; i <= (n - m); i++)
		ma9am.push_back(i);

	for (ll i = 1; i <= m; i++)
		ma9am.push_back(i);

	for (ll i = 0; i < baset.size(); i++)
	{
		for (ll j = 0; j < ma9am.size(); j++)
		{
			ll g = gcd(baset[i], ma9am[j]);

			baset[i] /= g;
			ma9am[j] /= g;
		}
	}

	ll baset_value = baset[0];
	for (ll i = 1; i < baset.size(); i++)
		baset_value *= baset[i];

	ll ma9am_value = ma9am[0];
	for (ll i = 1; i < ma9am.size(); i++)
		ma9am_value *= ma9am[i];


	cout << n << " things taken " << m << " at a time is " << baset_value / ma9am_value << " exactly.\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, x;
	while (cin >> a >> x)
	{
		if (a == 0 && x == 0) break;
		solve(a, x);
	}
}
