/*
D. Double Strings

link to the problem:
https://codeforces.com/contest/1703/problem/D
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
	vector<string> a(n);
	map<string, bool> mp;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]] = true;
	}

	string ans;

	for (ll i = 0; i < n; i++)
	{
		bool f = false;
		for (ll k = 1; k < a[i].size(); k++)
		{
			if (mp.count(a[i].substr(0, k)) && mp.count(a[i].substr(k, a[i].size())))
			{
				ans += '1';
				f = true;
				break;
			}
		}
		if (!f)
			ans += '0';
	}

	cout << ans << "\n";
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
