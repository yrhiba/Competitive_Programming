/*
Weekend Contest

L. Leaderboard Prediction

link to the problem:
find problems.pdf
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


void solve()
{
	ll n, h; cin >> n >> h;

	vector<ll> a(n);
	for (ll &i : a)
		cin >> i;

	h *= 60;

	sort(a.begin(), a.end());

	ll c = 0;

	ll ans[] = {0, 0};

	for (ll i = 0; i < n; i++)
	{
		if (a[i] + c <= h)
		{
			c += a[i];
			ans[0] += 1;
			ans[1] += c;
		}
		else
			break;
	}

	cout << ans[0] << " " << ans[1] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}