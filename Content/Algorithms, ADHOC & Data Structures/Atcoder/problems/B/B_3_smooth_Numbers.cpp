/*
link to the problem:
https://atcoder.jp/contests/abc324/tasks/abc324_b
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

bool divides_f(ll n)
{
	while (n > 1 && (n % 2 == 0 || n % 3 == 0))
	{
		while (n % 2 == 0)
			n /= 2;
		while (n % 3 == 0)
			n /= 3;
	}
	if (n > 1)
		return (false);
	return (true);
}

void solve()
{
	ll n; cin >> n;

	if (divides_f(n))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
