/*
link to the problem:
https://www.spoj.com/problems/AGGRCOW/
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

ll n, c;

vector<ll> a;

bool good(ll ans)
{
	ll cows_puted = 1;
	ll last_cow_puted_corridanate = a[0];

	for (ll i = 1; i < n; i++)
	{
		if (a[i] - last_cow_puted_corridanate >= ans)
		{
			cows_puted += 1;
			last_cow_puted_corridanate = a[i];

			if (cows_puted >= c)
				return (true);
		}
	}
	return (false);
}

void solve()
{
	cin >> n >> c;

	a.resize(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	ll start = 0;
	ll end = 1e9 + 1;
	ll ans = 0;
	ll mid;

	while (start <= end)
	{
		mid = start + ((end - start) / 2);

		if (good(mid))
		{
			start = mid + 1;
			ans = mid;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << ans << "\n";
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
