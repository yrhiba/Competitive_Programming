/*

Codeforces Round 166 (Div. 2)

B. Prime Matrix

link to the problem:
https://codeforces.com/contest/271/problem/B

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

set<ll> prime_numbers;

void generate_primes()
{
	vector< bool > is_prime(2e5+1, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i <= 2e5; i++)
	{
		if (is_prime[i] == false) continue;
		prime_numbers.insert(i);
		for (ll j = i*i; j <= 2e5; j+=i)
			is_prime[j] = false;
	}
}

void solve()
{
	ll n, m; cin >> n >> m;

	vector< vector<ll> > g(n, vector<ll>(m, 0));
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			cin >> g[i][j];

	generate_primes();

	ll ans = -1;
	for (ll i = 0; i < n; i++)
	{
		ll cost_line = 0;

		for (ll j = 0; j < m; j++)
			cost_line += *prime_numbers.lower_bound(g[i][j]) - g[i][j];

		if (ans == -1)
			ans = cost_line;
		else
			ans = min(ans, cost_line);
	}

	for (ll i = 0; i < m; i++)
	{
		ll cost_colum = 0;

		for (ll j = 0; j < n; j++)
			cost_colum += *prime_numbers.lower_bound(g[j][i]) - g[j][i];

		if (ans == -1)
			ans = cost_colum;
		else
			ans = min(ans, cost_colum);
	}

	cout << ans << endl;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
