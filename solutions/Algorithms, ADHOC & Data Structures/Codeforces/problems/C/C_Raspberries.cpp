/*
Codeforces Round 905 (Div. 3)
C. Raspberries
link to the problem:
https://codeforces.com/contest/1883/problem/C
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

	ll ans = 100;
	ll even_ans = 0;

	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	for (ll i = 0; i < n; i++)
	{
		if (a[i] % k == 0)
		{
			cout << "0\n";
			return ;
		}
		ans = min(ans, (k - (a[i] % k)));
		even_ans += (a[i]%2 == 0);
	}

	if (k != 4)
	{
		cout << ans << "\n";
		return ;
	}
	else
	{
		if (even_ans >= 2)
			cout << "0\n";
		else if (even_ans >= 1)
			cout << "1\n";
		else
		{
			cout << min(ans, 2ll) << "\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	for (ll i = 0; i < t; i++)
		solve();
}
