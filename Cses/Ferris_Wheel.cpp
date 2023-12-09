/*

CSES Problem Set

Ferris Wheel

link to the problem:
https://cses.fi/problemset/task/1090/

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

void solve()
{
	ll n, x; cin >> n >> x;

	multiset<ll, greater<ll> > a;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		a.insert(t);
	}

	ll ans = 0;

	while (a.size())
	{
		ll cur = *a.begin();
		a.erase(a.begin());

		auto u = a.lower_bound(x - cur);
		if (u != a.end())
			a.erase(u);

		ans += 1;
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
