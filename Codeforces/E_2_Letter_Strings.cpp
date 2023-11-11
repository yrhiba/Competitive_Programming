/*
E. 2-Letter Strings

link to the problem:
https://codeforces.com/contest/1669/problem/E
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

	vector< vector<ll> > count(256, vector<ll>(256, 0));

	ll ans = 0;

	for (ll i = 0; i < n; i++)
	{
		string s; cin >> s;

		for (char c = 'a'; c <= 'k'; c++)
		{
			if (c == s[1]) continue;
			ans += count[s[0]][c];
		}

		for (char c = 'a'; c <= 'k'; c++)
		{
			if (c == s[0]) continue;
			ans += count[c][s[1]];
		}

		count[s[0]][s[1]] += 1;
	}

	cout << ans << endl;
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
