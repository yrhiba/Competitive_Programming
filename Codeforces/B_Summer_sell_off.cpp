/*
link to the problem:
https://codeforces.com/contest/810/problem/B
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
	ll n, f; cin >> n >> f;

	vector< pair<ll, ll> > days(n); // products, customer
	vector< pair<ll, ll> > cost(n);

	for (ll i = 0; i < n; i++)
	{
		cin >> days[i].first >> days[i].second;

		cost[i].first = min(days[i].first*2, days[i].second) - min(days[i].second, days[i].first);
		cost[i].second = i;
	}

	sort(cost.rbegin(), cost.rend());

	for (int i = 0; i < f; i++)
		days[cost[i].second].first *= 2;

	ll ans = 0;

	for (int i = 0; i < n; i++)
		ans += min(days[i].first, days[i].second);

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
