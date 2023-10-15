/*
link to the problem:
https://cses.fi/problemset/task/1619/
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
	ll n; cin >> n;

	vector< pair<ll, ll> > times;

	times.push_back(make_pair(0, 0));

	for (ll i = 0; i < n; i++)
	{
		ll a, b; cin >> a >> b;

		times.push_back(make_pair(a, 1));
		times.push_back(make_pair(b, -1));
	}

	sort(times.begin(), times.end());

	ll ans = 0;

	for (ll i = 1; i < times.size(); i++)
	{
		times[i].second += times[i-1].second;
		ans = max(ans, times[i].second);
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
