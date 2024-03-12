/*

Codeforces Round 909 (Div. 3)

C. Yarik and Array

link to the problem:
https://codeforces.com/contest/1899/problem/C

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
	for (ll &i : a)
		cin >> i;

	ll ans = *max_element(a.begin(), a.end()), cur = 0;

	ll j = 0;
	while (j < a.size())
	{
		cur = max(cur+a[j], a[j]);

		if (j && (ll)(a[j]+1e5)%2 == (ll)(a[j-1]+1e5)%2)
			cur = a[j];

		ans = max(ans, cur);
		j++;
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
