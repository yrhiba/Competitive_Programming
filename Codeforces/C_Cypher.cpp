/*
C. Cypher

link to the problem:
https://codeforces.com/contest/1703/problem/C
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
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	vector<ll> s(n, 0);
	for (ll i = 0; i < n; i++)
	{
		ll x; cin >> x;
		string r; cin >> r;

		for (char c : r)
		{
			if (c == 'D')
			{
				s[i] += 1;
				s[i] %= 10;
			}
			else
			{
				s[i] -= 1;
				s[i] += 20;
				s[i] %= 10;
			}
		}
	}


	for (ll i = 0; i < n; i++)
		cout << (a[i] + s[i] + 20) % 10 << " ";
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
