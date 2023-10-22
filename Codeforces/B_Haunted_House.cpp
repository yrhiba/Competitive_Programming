/*
Codeforces Round 904 (Div. 2)
B. Haunted House
link to the problem:
https://codeforces.com/contest/1884/problem/B
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

	string r; cin >> r;

	reverse(r.begin(), r.end());

	vector<ll> zero_pos;
	vector<ll> one_pos;

	zero_pos.reserve(n+1);
	one_pos.reserve(n+1);

	for (ll i = 0; i < n; i++)
	{
		if (r[i] == '0')
			zero_pos.push_back(i);
		else
			one_pos.push_back(i);
	}

	vector<ll> costs(n+1, 0);

	for (ll i = 0; i < zero_pos.size(); i++)
		costs[i+1] = zero_pos[i] - i + costs[i];

	for (ll i = 1; i <= zero_pos.size(); i++)
	{
		cout << costs[i];
		if (i < n)
			cout << " ";
	}
	for (ll i = 1; i <= one_pos.size(); i++)
	{	
		cout << -1;
		if (i < n)
			cout << " ";
	}
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
