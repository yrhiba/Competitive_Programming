/*
Codeforces Round 247 (Div. 2) div-2
problem name: C. k-Tree
link to the problem:
https://codeforces.com/contest/431/problem/C
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
#include <numeric>
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;
ll powermod(ll x, ll p, ll m)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2, m) % m;
	if (p%2)
		return ((((res * res) % m) * (x % m)) % m);
	return ((res * res) % m);
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
	return ((a*b)/gcd(a,b));
}
ll inverse(ll x, ll m)
{
	return (powermod(x, m-2, m));
}

map< pair<ll, ll> , ll > dp;

ll n, k, d;


ll bf(ll sum = 0, ll x = 0)
{
	if (sum == n && x)
		return (1);
	
	if (sum >= n)
		return (0);

	if (dp.find(make_pair(sum, x)) != dp.end())
		return (dp[make_pair(sum, x)]);

	ll ans = 0;

	for (ll i = 1; i <= k; i++)
	{
		if (x || i >= d)
			ans = (ans%mod + bf(sum + i, 1) % mod) %mod;
		else
			ans = (ans%mod + bf(sum + i, 0) %mod) %mod;
	}

	dp[make_pair(sum, x)] = ans;
	return (ans);
}

void solve()
{
	cin >> n >> k >> d;

	cout << bf() << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}