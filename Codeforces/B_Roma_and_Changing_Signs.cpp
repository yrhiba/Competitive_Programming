/*

Codeforces Round 160 (Div. 2)

B. Roma and Changing Signs

link to the problem:
https://codeforces.com/contest/262/problem/B

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

	multiset<ll> ms;

	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		ms.insert(t);
	}

	while (k--)
	{
		ll k = *ms.begin();

		ms.erase(ms.begin());
		ms.insert(k * -1);
	}

	ll sum = 0;
	for (auto &i : ms)
		sum += i;

	cout << sum << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
