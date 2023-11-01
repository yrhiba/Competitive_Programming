/*
link to the problem:
https://codeforces.com/contest/451/problem/B
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
	ll n; cin >> n;

	vector<ll> a(n);
	vector<ll> b(n);

	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		a[i] = b[i] = t;
	}

	sort(b.begin(), b.end());


	ll first = -1, last = -1;

	for (ll i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			if (first == -1)
				first = i;
	
			last = i;
		}
	}

	if (first == -1)
	{
		cout << "yes\n";
		cout << 1 << ' ' << 1 << endl;
		return ;
	}

	for (ll i = first; i <= last; i++)
	{
		if (a[i] != b[(last - i) + first])
		{
			cout << "no\n";
			return ;
		}
	}

	cout << "yes\n";
	cout << first + 1 << " " << last + 1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
