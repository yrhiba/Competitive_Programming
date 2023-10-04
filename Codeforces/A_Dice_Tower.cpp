/*
link to the problem:
https://codeforces.com/contest/225/problem/A
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
	ll n, t; cin >> n >> t;

	for (ll i = 0; i < n; i++)
	{
		bool x[] = {0, 0, 0, 0, 0, 0, 0};
		ll a, b; cin >> a >> b;
		x[a] = x[7 - a] = 1;
		x[b] = x[7 - b] = 1;
		if (x[t] == 1)
		{
			cout << "NO" << endl;
			return ;
		}
	}
	cout << "YES" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
