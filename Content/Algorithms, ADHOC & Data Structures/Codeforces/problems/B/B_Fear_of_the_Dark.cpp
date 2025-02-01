/*
link to the problem:
https://codeforces.com/contest/1886/problem/B
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

// global var
ll px, py;
ll ax, ay;
ll bx, by;

double distance(ll x1, ll y1, ll x2, ll y2)
{
	return (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}

double dap;
double dao;
double dbp;
double dbo;
double dab;

bool good(double w)
{
	if (dap <= w && dao <= w)
		return (true);

	if (dbp <= w && dbo <= w)
		return (true);

	if (dap > w && dbp > w)
		return (false);

	if (dao >= w && dbo >= w)
		return (false);

	if (w + w >= dab)
		return (true);

	return (false);
}

void solve()
{
	cin >> px >> py;
	cin >> ax >> ay;
	cin >> bx >> by;

	dap = distance(ax, ay, px, py);
	dao = distance(ax, ay, 0, 0);
	dbp = distance(bx, by, px, py);
	dbo = distance(bx, by, 0, 0);
	dab = distance(ax, ay, bx, by);

	double prs = 1e-6;
	double start = 0;
	double end = 1e12 * 2;
	double mid;

	while (abs(end - start) > prs)
	{
		mid = start + ((end - start) / 2);

		if (good(mid))
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}

	cout << fixed << setprecision(10) << mid << endl;
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
