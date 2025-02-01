/*
link to the problem:
https://codeforces.com/contest/1692/problem/E
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
# define all(x) (x.begin(), x.end())
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
	ll n; cin >> n;
	ll k; cin >> k;

	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll i = 0;
	ll j = 0;
	ll ans = -1;
	ll sum = 0;

	while (j < n)
	{
		if (sum <= k)
		{
			sum += a[j];
			j += 1;
		}
		else if (sum > k)
		{
			sum -= a[i];
			i += 1;
		}

		if (sum == k)
		{
			ans = max(ans, j - i);
		}
	}

	if (ans == -1)
		cout << -1 << "\n";
	else
		cout << n - ans << "\n";
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
