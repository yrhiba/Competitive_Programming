/*
Mixing Milk
Bronze - Easy

link to the problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=855
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
	vector< pair<ll, ll> > ans(3);

	for (ll i = 0; i < 3; i++)
		cin >> ans[i].first >> ans[i].second;

	for (ll j = 0; j < 100; j++)
	{
		ll amount = (ans[(j+1)%3].first - ans[(j+1)%3].second);

		if (amount >= ans[j%3].second)
		{
			ans[(j+1)%3].second += ans[j%3].second;
			ans[j%3].second = 0;
		}
		else
		{
			ans[(j+1)%3].second += amount;
			ans[j%3].second -= amount;
		}
	}

	for (ll i = 0; i < 3; i++)
		cout << ans[i].second << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	setIO("mixmilk");
	solve();
}
