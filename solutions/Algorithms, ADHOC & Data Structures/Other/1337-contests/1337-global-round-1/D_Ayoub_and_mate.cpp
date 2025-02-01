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
# define ull unsigned long long
# define ll long long
ll mod = 1000000007;
using namespace std;
ll powermod(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2) % mod;
	if (p%2)
		return ((((res * res) % mod) * (x % mod)) % mod);
	return ((res * res) % mod);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}

void solve()
{
	ll n, m, q;
	cin >> n >> m >> q;

	vector<ll> c(200002, 0);
	vector<ll> d(200002, 0);

	for (ll i = 0; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;

		c[a] += 1;
		c[b+1] -= 1;
	}

	for (ll i = 1; i <= 200001; i++)
	{
		c[i] += c[i - 1];
		if (c[i] >= m)
			d[i] += 1;
		d[i] += d[i - 1];
	}

	for (ll i = 0; i < q; i++)
	{
		ll a, b;
		cin >> a >> b;
		cout << d[b] - d[a-1] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
