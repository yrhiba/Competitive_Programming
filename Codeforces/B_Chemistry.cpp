/*
Codeforces Round 905 (Div. 3)
B. Chemistry
link to the problem:
https://codeforces.com/contest/1883/problem/B
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

	string s; cin >> s;

	ll even_pairs = 0;
	ll odd_pairs = 0;

	vector<ll> letters_count(26, 0);

	for (ll i = 0; i < s.size(); i++)
	{
		letters_count[s[i] - 'a'] += 1;

		if (letters_count[s[i] - 'a'] == 2)
		{
			even_pairs += 1;
			odd_pairs -= 1;
			letters_count[s[i] - 'a'] = 0;
		}
		else
		{
			odd_pairs += 1;
		}
	}

	ll target_len = n - k;

	if (target_len % 2 == 0)
	{
		ll need_pair = target_len / 2;

		if (even_pairs >= need_pair)
		{
			cout << "YES\n";
			return ;
		}
		else
		{
			cout << "NO\n";
			return ;
		}
	}
	else
	{
		ll need_pair = (target_len - 1) / 2;
		ll need_odd = 1;

		if (even_pairs >= need_pair
			&& (odd_pairs >= need_odd || even_pairs - need_pair > 0))
		{
			cout << "YES\n";
			return ;
		}
		else
		{
			cout << "NO\n";
			return ;
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
