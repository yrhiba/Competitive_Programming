/*
B. Parity Sort

link to the problem:
https://codeforces.com/contest/1851/problem/B
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

	vector< ll > ods;
	vector< ll > evs;
	vector< ll > ods_i;
	vector< ll > evs_i;

	ods.reserve(n);
	evs.reserve(n);

	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];

		if (a[i] % 2)
		{
			ods.push_back(a[i]);
			ods_i.push_back(i);
		}
		else
		{
			evs.push_back(a[i]);
			evs_i.push_back(i);
		}
	}


	if (ods.empty() || evs.empty())
	{
		cout << "YES\n";
		return ;
	}

	sort(ods.begin(), ods.end());
	sort(evs.begin(), evs.end());
	sort(ods_i.begin(), ods_i.end());
	sort(evs_i.begin(), evs_i.end());


	for (ll i = 0; i < evs.size(); i++)
	{
		a[evs_i[i]] = evs[i];
	}
	for (ll i = 0; i < ods.size(); i++)
	{
		a[ods_i[i]] = ods[i];
	}

	if (is_sorted(a.begin() , a.end()))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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
