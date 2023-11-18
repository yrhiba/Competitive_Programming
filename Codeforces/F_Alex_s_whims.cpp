/*

Codeforces Round 909 (Div. 3)

F. Alex's whims

link to the problem:
https://codeforces.com/contest/1899/problem/F

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
	ll n, q; cin >> n >> q;

	vector<ll> days(q);
	for (ll &d : days)
		cin >> d;

	for (ll i = 1; i < (n-1); i++)
		cout << i << ' ' << i+1 << "\n";

	ll last_node = days.front();

	cout << last_node << " " << n << "\n";

	for (ll i = 0; i < days.size(); i++)
	{
		if (days[i] == last_node)
			cout << -1 << ' ' << -1 << ' ' << -1 << "\n";
		else
		{
			cout << n << ' ' << last_node << ' ' << days[i] << "\n";
			last_node = days[i];
		}
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
