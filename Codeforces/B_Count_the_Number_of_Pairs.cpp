/*
link to the problem:
https://codeforces.com/contest/1800/problem/B
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

	vector<ll> a(26, 0);
	vector<ll> A(26, 0);

	string s; cin >> s;

	ll res = 0;

	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] <= 'Z' && s[i] >= 'A')
			A[s[i] - 'A'] += 1;
		else if (s[i] <= 'z' && s[i] >= 'a')
			a[s[i] - 'a'] += 1;
	}

	for (ll i = 0; i < 26; i++)
	{
		res += min(a[i], A[i]);

		ll t = min(a[i], A[i]);

		a[i] -= t;
		A[i] -= t;

		if (k==0) continue;

		if (!(a[i] >= 2 || A[i] >= 2)) continue;

		ll can =  (a[i] / 2) + (A[i] / 2);

		if (can < k)
		{
			res += can;
			k -= can;
		}
		else
		{
			res += k;
			k = 0;
		}
	}

	cout << res << "\n";
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
