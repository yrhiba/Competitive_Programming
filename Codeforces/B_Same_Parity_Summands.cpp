/*
link to the problem:
https://codeforces.com/contest/1352/problem/B
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

	if ((n-(k-1)) > 0 && (n-(k-1)) % 2)
	{
		cout << "YES\n";
		for (ll i = 0; i < k; i++)
		{
			if (i==0)
				cout << n-(k-1);
			else cout << 1;

			if (i+1 < k)
				cout << " ";
		}
		cout << "\n";
		return ;
	}

	if ((n-(2*(k-1))) > 0 && (n-(2*(k-1))) % 2 == 0)
	{
		cout << "YES\n";
		for (ll i = 0; i < k; i++)
		{
			if (i==0)
				cout << n-(2*(k-1));
			else cout << 2;

			if (i+1 < k)
				cout << " ";
		}
		cout << "\n";
		return ;
	}

	cout << "NO\n";
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
