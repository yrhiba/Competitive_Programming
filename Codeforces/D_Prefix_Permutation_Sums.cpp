/*
D. Prefix Permutation Sums

link to the problem:
https://codeforces.com/contest/1851/problem/D
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

void solve(ll t)
{
	ll n; cin >> n;

	vector<ll> a(n, 0), f(n+1, 0);
	for (ll i = 1; i < n; i++)
		cin >> a[i];

	ll invalid = -1;

	for (ll i = 1; i < n; i++)
	{
		if (a[i] - a[i - 1] > n || f[a[i] - a[i - 1]])
		{
			if (invalid == -1)
			{
				invalid = a[i] - a[i - 1];
			}
			else
			{
				cout << "NO\n";
				return ;
			}
			continue;
		}
		f[a[i] - a[i - 1]] += 1;

	}


	vector<ll> missing_numbers;
	for (ll i = 1; i <= n; i++)
	{
		if (f[i] == 0)
			missing_numbers.push_back(i);
	}


	if (missing_numbers.empty() || missing_numbers.size() == 1)
	{
		cout << "YES\n";
		return ;
	}

	if (missing_numbers.size() != 2)
	{
		cout << "NO\n";
		return ;
	}

	if (missing_numbers.front() + missing_numbers.back() == invalid)
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
	for (ll i = 1; i <= t; i++)
		solve(i);
}
